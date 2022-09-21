#pragma once


// Transpose:
template<size_t M, size_t N, typename NUM>
inline mat<N, M, NUM> transpose(const mat<M, N, NUM>& in) {
	mat<N, M, NUM> out;

	for(size_t i = 0; i < M; i++)
		for(size_t j = 0; j < N; j++)
			out.at(j, i) = in.at(i, j);

	return out;
}


// Addition / Subtraction / Multiplication:
template<size_t M, size_t N, typename NUM>
inline mat<M, N, NUM>& operator+=(mat<M, N, NUM>& a, const mat<M, N, NUM>& b) {
	for(size_t i = 0; i < M; i++)
		for(size_t j = 0; j < N; j++)
			a.at(i, j) += b.at(i, j);
	return a;
}

template<size_t M, size_t N, typename NUM>
inline mat<M, N, NUM>& operator-=(mat<M, N, NUM>& a, const mat<M, N, NUM>& b) {
	for(size_t i = 0; i < M; i++)
		for(size_t j = 0; j < N; j++)
			a.at(i, j) -= b.at(i, j);
	return a;
}

template<size_t M, size_t N, typename NUM>
inline mat<M, N, NUM> operator+(const mat<M, N, NUM>& a, const mat<M, N, NUM>& b) {
	mat<M, N, NUM> res = a;
	a += b;
	return res;
}

template<size_t M, size_t N, typename NUM>
inline mat<M, N, NUM> operator-(const mat<M, N, NUM>& a, const mat<M, N, NUM>& b) {
	mat<M, N, NUM> res = a;
	a -= b;
	return res;
}


template<size_t M, size_t N, size_t N_O, typename NUM>
inline mat<M, N_O, NUM> operator*(const mat<M, N, NUM>& a, const mat<N, N_O, NUM>& b) {
	mat<M, N_O, NUM> out(0);

	for(size_t z = 0; z < M; z++) { // output-zeile
		for(size_t s = 0; s < N_O; s++) { // output-spalte
			for(size_t  n = 0; n < N; n++)
				out.at(z, s) += a.at(z, n) * b.at(n, s);
		}
	}

	return out;
}


// Comparison:
template<size_t M, size_t N, typename NUM>
inline bool operator==(const mat<M, N, NUM>& a, const mat<M, N, NUM>& b) {
	for(size_t i = 0; i < M; i++)
		for(size_t j = 0; j < N; j++)
			if(a.at(i, j) != b.at(i, j))
				return false;
	return true;
}

template<size_t M, size_t N, typename NUM>
inline bool operator!=(const mat<M, N, NUM>& a, const mat<M, N, NUM>& b) {
	return !(a == b);
}


// High-Level Functions:
template<size_t N, typename NUM>
inline mat<N, N, NUM> inverse(const mat<N, N, NUM>& m) {
	mat<N, N, NUM> out(0);

	// Adjunkten fuellen:
	for(size_t i = 0; i < N; i++)
		for(size_t k = 0; k < N; k++)
			out.at(i, k) = adj(m, k, i);
	
	const NUM d = det(m);
	for(size_t i = 0; i < N; i++)
		for(size_t k = 0; k < N; k++)
			out.at(i, k) /= d;

	return out;
}


template<size_t N, typename NUM>
inline bool isOrthogonal(const mat<N, N, NUM>& m, const NUM error) {
	static const mat<N, N, NUM> unit = mat<N, N, NUM>(1.);
	const mat<N, N, NUM> res = m * transpose(m); // m ist orthogonal falls m * transpose(m) == unit

	for(size_t i = 0; i < N; i++)
		for(size_t k = 0; k < N; k++)
			if(fabsf(res.at(i, k) - unit.at(i, k)) > error)
				return false;

	return true;
}
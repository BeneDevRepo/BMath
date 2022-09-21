#pragma once


// Determinante einer 1x1 Matrix:
template<typename NUM>
inline NUM det(const mat<1, 1, NUM>& m) {
	return m.at(0, 0);
}

template<size_t M, size_t N, typename NUM>
inline mat<M-1, N-1, NUM> skipIK(const mat<M, N, NUM>& in, const size_t iSkip, const size_t kSkip) {
	mat<M-1, N-1, NUM> out(0);

	size_t kOut = 0;

	for(size_t k = 0; k < M; k++) {
		if(k == kSkip) continue;

		size_t iOut = 0;

		for(size_t i = 0; i < N; i++) {
			if(i == iSkip) continue;

			out.at(iOut, kOut) = in.at(i, k);

			++iOut;
		}

		++kOut;
	}

	return out;
}

// template<size_t M, size_t N, size_t N_OUT=std::min<size_t>(M, N), typename NUM>
// inline mat<N_OUT, N_OUT, NUM> subSquare(const mat<M, N, NUM>& in, const size_t iOff, const size_t kOff) {
// 	mat<N_OUT, N_OUT, NUM> out(0);

// 	for(size_t i = 0; i < N_OUT; i++)
// 		for(size_t k = 0; k < N_OUT; k++)
// 			out.at(i, k) = in.at(iOff + i, kOff + k);

// 	return out;
// }


// Unterdeterminante D_ik:
template<size_t N, typename NUM>
inline NUM subDet(const mat<N, N, NUM>& m, const size_t iSkip, const size_t kSkip) {
	return det(skipIK(m, iSkip, kSkip));
}

// Adjunkte A_ik:
template<size_t N, typename NUM>
inline NUM adj(const mat<N, N, NUM>& m, const size_t i, const size_t k) {
	const NUM adjFac = ((i + k) % 2 == 0) ? 1 : -1;
	const NUM sDet = subDet(m, i, k);
	return adjFac * sDet;
}


template<size_t N, typename NUM>
inline NUM det(const mat<N, N, NUM>& m) {
	constexpr size_t i = 0;
	
	NUM res = 0;

	for(size_t k = 0; k < N; k++) {
		const NUM A_ik = adj(m, i, k);
		const NUM a_ik = m.at(i, k);

		res += a_ik * A_ik;
	}
	return res;
}
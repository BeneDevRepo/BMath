#pragma once


// Printing:
template<size_t M, size_t N, typename NUM>
inline std::ostream& operator<<(std::ostream& cout, const mat<M, N, NUM>& m) {
	for(size_t i = 0; i < M; i++) {
		printf("| ");

		for(size_t j = 0; j < N; j++) {
			NUM val = m.at(i, j);

			if(-0.000001f < val && val < 0.f) val = 0; // prevent negative 0

			printf("% 5.3f", val);

			if(j != N - 1)
				printf("  ");
		}

		printf(" |\n");
	}
	return cout;
}


// Constructor:
template<size_t M, size_t N, typename NUM>
inline mat<M, N, NUM>::mat(const NUM val)
		requires (M == N):
		values{} {
	for(size_t i = 0; i < M; i++)
		this->at(i, i) = val;
}

template<size_t M, size_t N, typename NUM>
inline mat<M, N, NUM>::mat(const NUM val)
		requires (M != N):
		values{} {
}

template<size_t M, size_t N, typename NUM>
inline mat<M, N, NUM>::mat(std::initializer_list<NUM> init) {
	size_t i = 0, j = 0;

	for(const NUM& val : init) {
		at(i, j) = val;
		if(++j == N) {
			j = 0;
			++i;
		}
	}
}


// Copy:
template<size_t M, size_t N, typename NUM>
inline mat<M, N, NUM>::mat(const mat<M, N, NUM>& other) {
	memcpy(values, other.values, M * N * sizeof(NUM));
}

template<size_t M, size_t N, typename NUM>
inline mat<M, N, NUM>& mat<M, N, NUM>::operator=(const mat<M, N, NUM>& other) {
	if(this == &other) return *this; // guard self-assignment
	memcpy(values, other.values, M * N * sizeof(NUM));
	return *this;
}


// Move:
template<size_t M, size_t N, typename NUM>
inline mat<M, N, NUM>::mat(mat<M, N, NUM>&& other) {
	memcpy(values, other.values, M * N * sizeof(NUM));
}

template<size_t M, size_t N, typename NUM>
inline mat<M, N, NUM>& mat<M, N, NUM>::operator=(mat<M, N, NUM>&& other) {
	if(this == &other) return *this; // guard self-assignment
	memcpy(values, other.values, M * N * sizeof(NUM));
	return *this;
}


// Indexing:
template<size_t M, size_t N, typename NUM>
inline NUM mat<M, N, NUM>::at(const size_t i, const size_t j) const { // i=row, j=column
	return values[j * M + i]; // column major
}

template<size_t M, size_t N, typename NUM>
inline NUM& mat<M, N, NUM>::at(const size_t i, const size_t j) { // i=row, j=column
	return values[j * M + i]; // column major
}
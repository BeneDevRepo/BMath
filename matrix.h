#pragma once

#include <cmath>
#include <cstdint>
#include <iostream>
#include <algorithm>
#include <initializer_list>


NAMESPACE_BMATH_START

template<size_t M, size_t N, typename NUM=float> // rows(Zeilen), columns(Spalten)
struct mat {
private:
	NUM values[M * N]; // column major array

public:
	// Constructor:
	inline mat(const NUM val = 1) requires (M == N); // Default: Identity Matrix
	inline mat(const NUM val = 0) requires (M != N); // ignores val
	inline mat(std::initializer_list<NUM> init);

	// Copy:
	inline mat(const mat<M, N, NUM>& other);
	inline mat<M, N, NUM>& operator=(const mat<M, N, NUM>& other);

	// Move:
	inline mat(mat<M, N, NUM>&& other);
	inline mat<M, N, NUM>& operator=(mat<M, N, NUM>&& other);

	// Indexing:
	inline NUM at(const size_t i, const size_t j) const; // i=row, j=column
	inline NUM& at(const size_t i, const size_t j); // i=row, j=column
};

#include "matrix_impl.h" // Implementation of mat<M, N> class


// Print:
template<size_t M, size_t N, typename NUM>
inline std::ostream& operator<<(std::ostream& cout, const mat<M, N, NUM>& m);


// Transpose:
template<size_t M, size_t N, typename NUM>
inline mat<N, M, NUM> transpose(const mat<M, N, NUM>& in);


// Addition / Subtraction / Multiplication:
template<size_t M, size_t N, typename NUM>
inline mat<M, N, NUM>& operator+=(mat<M, N, NUM>& a, const mat<M, N, NUM>& b);

template<size_t M, size_t N, typename NUM>
inline mat<M, N, NUM>& operator-=(mat<M, N, NUM>& a, const mat<M, N, NUM>& b);

template<size_t M, size_t N, typename NUM>
inline mat<M, N, NUM> operator+(const mat<M, N, NUM>& a, const mat<M, N, NUM>& b);

template<size_t M, size_t N, typename NUM>
inline mat<M, N, NUM> operator-(const mat<M, N, NUM>& a, const mat<M, N, NUM>& b);


template<size_t M, size_t N, size_t N_O, typename NUM>
inline mat<M, N_O, NUM> operator*(const mat<M, N, NUM>& a, const mat<N, N_O, NUM>& b);


// Comparison:
template<size_t M, size_t N, typename NUM>
inline bool operator==(const mat<M, N, NUM>& a, const mat<M, N, NUM>& b);

template<size_t M, size_t N, typename NUM>
inline bool operator!=(const mat<M, N, NUM>& a, const mat<M, N, NUM>& b);


template<size_t N, typename NUM>
inline NUM det(const mat<N, N, NUM>& m);

template<size_t M, size_t N, typename NUM>
inline size_t rank(const mat<M, N, NUM>& mat);


// High-Level functions:
template<size_t N, typename NUM>
inline mat<N, N, NUM> inverse(const mat<N, N, NUM>& m);

template<size_t N, typename NUM>
inline bool isOrthogonal(const mat<N, N, NUM>& m, const NUM error = .0001);


#include "matrix_impl_ex.h" // Implementation of methods operating on matrices

#include "matrix_impl_ex_det.h" // Implementation of det() (determinant)

#include "matrix_impl_ex_rank.h" // Implementation of rank()

NAMESPACE_BMATH_END
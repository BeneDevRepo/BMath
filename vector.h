#pragma once

#include "bmath_general.h"

#include <cmath>
#include <cstdint>
#include <iostream>
#include <initializer_list>


NAMESPACE_BMATH_START

template<size_t DIM, typename NUM=float> // Number of Dimensions, Number-Type
struct vec {
private:
	NUM values[DIM];

public:
	// Constructors:
	inline vec();
	inline vec(const NUM val);
	inline vec(std::initializer_list<NUM> _values);

	// Index operators
	inline NUM operator[](const size_t index) const;
	inline NUM& operator[](const size_t index);

	// -----------------  + and -
	inline vec& operator+=(const vec& other);
	inline vec& operator-=(const vec& other);
	inline vec operator+(const vec& other) const;
	inline vec operator-(const vec& other) const;

	// -----------------  * and /
	inline vec& operator*=(const NUM fac);
	inline vec& operator/=(const NUM fac);
	inline vec operator*(const NUM fac) const;
	inline vec operator/(const NUM fac) const;

	// Skalarprodukt:
	inline NUM operator*(const vec& other) const;
};

template<size_t DIM, typename NUM>
inline vec<DIM, NUM> operator*(const NUM fac, const vec<DIM, NUM>& v);

template<size_t DIM, typename NUM>
inline vec<DIM, NUM> operator/(const NUM fac, const vec<DIM, NUM>& v);

template<size_t DIM, typename NUM>
inline std::ostream& operator<<(std::ostream& cout, const vec<DIM, NUM>& v);

using vec2 = vec<2>;
using vec3 = vec<3>;
using vec4 = vec<4>;

#include "vector_impl.h"
#include "vector_impl_ex.h"

NAMESPACE_BMATH_END
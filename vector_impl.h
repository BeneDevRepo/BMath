#pragma once


// ------------------  Constructors:
template<size_t DIM, typename NUM>
inline vec<DIM, NUM>::vec():
		values{} { }

template<size_t DIM, typename NUM>
inline vec<DIM, NUM>::vec(const NUM val) {
	for(size_t i = 0; i < DIM; i++)
		values[i] = val;
}

template<size_t DIM, typename NUM>
inline vec<DIM, NUM>::vec(std::initializer_list<NUM> _values) {
	size_t i = 0;
	for(const NUM& value : _values)
		values[i++] = value;
}


// ---------------------  Index operators
template<size_t DIM, typename NUM>
inline NUM vec<DIM, NUM>::operator[](const size_t index) const {
	return values[index];
}

template<size_t DIM, typename NUM>
inline NUM& vec<DIM, NUM>::operator[](const size_t index) {
	return values[index];
}


// -----------------  + and -
template<size_t DIM, typename NUM>
inline vec<DIM, NUM>& vec<DIM, NUM>::operator+=(const vec& other) {
	for(size_t i = 0; i < DIM; i++)
		values[i] += other[i];
	return *this;
}

template<size_t DIM, typename NUM>
inline vec<DIM, NUM>& vec<DIM, NUM>::operator-=(const vec& other) {
	for(size_t i = 0; i < DIM; i++)
		values[i] -= other[i];
	return *this;
}

template<size_t DIM, typename NUM>
inline vec<DIM, NUM> vec<DIM, NUM>::operator+(const vec& other) const {
	vec<DIM, NUM> out = *this;
	out += other;
	return out;
}

template<size_t DIM, typename NUM>
inline vec<DIM, NUM> vec<DIM, NUM>::operator-(const vec& other) const {
	vec<DIM, NUM> out = *this;
	out -= other;
	return out;
}


// -----------------  * and /
template<size_t DIM, typename NUM>
inline vec<DIM, NUM>& vec<DIM, NUM>::operator*=(const NUM fac) {
	for(size_t i = 0; i < DIM; i++)
		values[i] *= fac;
	return *this;
}

template<size_t DIM, typename NUM>
inline vec<DIM, NUM>& vec<DIM, NUM>::operator/=(const NUM fac) {
	for(size_t i = 0; i < DIM; i++)
		values[i] /= fac;
	return *this;
}

template<size_t DIM, typename NUM>
inline vec<DIM, NUM> vec<DIM, NUM>::operator*(const NUM fac) const {
	vec<DIM, NUM> out = *this;
	out *= fac;
	return out;
}

template<size_t DIM, typename NUM>
inline vec<DIM, NUM> vec<DIM, NUM>::operator/(const NUM fac) const {
	vec<DIM, NUM> out = *this;
	out /= fac;
	return out;
}


// ------------------   Skalarprodukt:
template<size_t DIM, typename NUM>
inline NUM vec<DIM, NUM>::operator*(const vec& other) const {
	NUM out = 0.f;
	for(size_t i = 0; i < DIM; i++)
		out += values[i] * other[i];
	return out;
}
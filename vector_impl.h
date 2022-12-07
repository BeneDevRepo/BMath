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


// ---------------------  Magnitude
template<size_t DIM, typename NUM>
inline NUM vec<DIM, NUM>::magSquared() const {
	NUM out = 0;
	for(size_t i = 0; i < DIM; i++)
		out += values[i] * values[i];
	return out;
}
template<size_t DIM, typename NUM>
inline NUM vec<DIM, NUM>::mag() const {
	return std::sqrt(magSquared());
}


// ---------------------  unary -
template<size_t DIM, typename NUM>
inline vec<DIM, NUM> vec<DIM, NUM>::operator-() const {
	vec<DIM, NUM> out;
	for(size_t i = 0; i < DIM; i++)
		out[i] = -values[i];
	return out;
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


// -----------------  * and /  (componentwise)
template<size_t DIM, typename NUM>
inline vec<DIM, NUM>& vec<DIM, NUM>::operator*=(const vec& fac) {
	for(size_t i = 0; i < DIM; i++)
		values[i] *= fac[i];
	return *this;
}

template<size_t DIM, typename NUM>
inline vec<DIM, NUM>& vec<DIM, NUM>::operator/=(const vec& fac) {
	for(size_t i = 0; i < DIM; i++)
		values[i] /= fac[i];
	return *this;
}

template<size_t DIM, typename NUM>
inline vec<DIM, NUM> vec<DIM, NUM>::operator*(const vec& fac) const {
	vec<DIM, NUM> out = *this;
	out *= fac;
	return out;
}

template<size_t DIM, typename NUM>
inline vec<DIM, NUM> vec<DIM, NUM>::operator/(const vec& fac) const {
	vec<DIM, NUM> out = *this;
	out /= fac;
	return out;
}


// ------------------   dot product:
template<size_t DIM, typename NUM>
inline NUM vec<DIM, NUM>::dot(const vec& other) const {
	NUM res = 0.f;
	for(size_t i = 0; i < DIM; i++)
		res += values[i] * other[i];
	return res;
}

// ------------------   cross product:
template<size_t DIM, typename NUM>
inline NUM vec<DIM, NUM>::cross(const vec& other) const requires (DIM == 2) {
	return (values[0]*other[1]) - (values[1]*other[0]);
}

template<size_t DIM, typename NUM>
inline vec<DIM, NUM> vec<DIM, NUM>::cross(const vec& other) const requires (DIM == 3) {
	return {
		values[1] * other[2] - values[2] * other[1],
		values[2] * other[0] - values[0] * other[2],
		values[0] * other[1] - values[1] * other[0]
	};
}
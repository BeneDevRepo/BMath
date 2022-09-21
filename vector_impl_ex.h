#pragma once


// ----------------------  Non-Member Functions:
template<size_t DIM, typename NUM>
inline vec<DIM, NUM> operator*(const NUM fac, const vec<DIM, NUM>& v) {
	return v * fac;
}

template<size_t DIM, typename NUM>
inline vec<DIM, NUM> operator/(const NUM fac, const vec<DIM, NUM>& v) {
	return v / fac;
}

template<size_t DIM, typename NUM>
inline std::ostream& operator<<(std::ostream& cout, const vec<DIM, NUM>& v) {
	cout << "(";
	for(size_t i = 0; i < DIM; i++) {
		cout << v[i];
		if(i != DIM - 1)
			cout << ", ";
	}
	cout << ")";
	return cout;
}
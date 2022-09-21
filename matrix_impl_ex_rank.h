#pragma once


template<size_t M, size_t N, typename NUM>
inline mat<M-1, N, NUM> skipI(const mat<M, N, NUM>& in, const size_t iSkip) {
	mat<M-1, N, NUM> out(0);

	for(size_t k = 0; k < M; k++) {
		size_t iOut = 0;

		for(size_t i = 0; i < N; i++) {
			if(i == iSkip) continue;

			out.at(iOut, k) = in.at(i, k);

			iOut++;
		}
	}

	return out;
}

template<size_t M, size_t N, typename NUM>
inline mat<M, N-1, NUM> skipK(const mat<M, N, NUM>& in, const size_t kSkip) {
	mat<M, N-1, NUM> out(0);

	size_t kOut = 0;

	for(size_t k = 0; k < M; k++) {
		if(k == kSkip) continue;

		for(size_t i = 0; i < N; i++)
			out.at(i, kOut) = in.at(i, k);

		++kOut;
	}

	return out;
}



template<size_t N, typename NUM>
inline size_t subRank(const mat<N, N, NUM>& mat) {
	size_t biggestRankFound = 0;

	for(size_t i = 0; i < N; i++) {
		for(size_t k = 0; k < N; k++) {
			if constexpr (N > 1) {
				bmath::mat<N-1, N-1, NUM> sub = skipIK(mat, i, k);

				if(std::abs(det(sub)) >= .0001) // det(sub) != 0
					return N-1;

				biggestRankFound = std::max<size_t>(biggestRankFound, subRank(sub));
			} else {
				biggestRankFound = std::max<size_t>(biggestRankFound, std::abs(mat.at(0, 0)) > 0.0001);
			}
		}
	}

	return biggestRankFound;
}


template<size_t M, size_t N, typename NUM>
inline size_t rankM(const mat<M, N, NUM>& mat) { // M > N
	size_t biggestRankFound = 0;

	for(size_t i = 0; i < M; i++) {
		bmath::mat<M-1, N, NUM> sub = skipI(mat, i);

		if constexpr (M-1 == N) {
			if(std::abs(det(sub)) >= .0001) // det(sub) != 0
				return N;

			biggestRankFound = std::max(biggestRankFound, subRank(sub));
		} else
			biggestRankFound = std::max(biggestRankFound, rankM(sub));
	}

	return biggestRankFound;
}

template<size_t M, size_t N, typename NUM>
inline size_t rankN(const mat<M, N, NUM>& mat) { // N > M
	size_t biggestRankFound = 0;

	for(size_t k = 0; k < M; k++) {
		bmath::mat<M, N-1, NUM> sub = skipK(mat, k);

		if constexpr (M == N-1) {
			if(std::abs(det(sub)) >= .0001) // det(sub) != 0
				return M;

			biggestRankFound = std::max(biggestRankFound, subRank(sub));
		} else
			biggestRankFound = std::max(biggestRankFound, rankN(sub));
	}

	return biggestRankFound;
}


template<size_t M, size_t N, typename NUM>
inline size_t rank(const mat<M, N, NUM>& mat) {
	if constexpr (M > N)
		return rankM(mat);

	if constexpr (N > M)
		return rankN(mat);

	if(std::abs(det(mat)) > 0.0001)
		return M;

	return subRank(mat);
}
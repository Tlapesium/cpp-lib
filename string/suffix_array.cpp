#pragma once
#include <vector>
#include <string>
#include <utility>
#include <iostream>

struct SuffixArray {
	std::vector<int> sa;
	const std::string S;

	std::vector<int> sa_is(const std::vector<int>& str, int k) {

		auto induced_sort = [](const std::vector<int>& str, const std::vector<int>& LMSs, const std::vector<bool>& is_S, int k) {
			int N = str.size();
			std::vector<int> buckets(N);
			std::vector<int> chars(k + 1, 0);
			std::vector<int> count(k, 0);
			for (int i = 0; i < N; i++)chars[str[i] + 1]++;
			for (int i = 0; i < k; i++)chars[i + 1] += chars[i];
			for (int i = LMSs.size() - 1; i >= 0; i--) {
				int c = str[LMSs[i]];
				buckets[chars[c + 1] - 1 - count[c]++] = LMSs[i];
			}
			count = std::vector<int>(k, 0);
			for (int i = 0; i < N; i++) {
				if (buckets[i] == 0 || is_S[buckets[i] - 1]) continue;
				int c = str[buckets[i] - 1];
				buckets[chars[c] + count[c]++] = buckets[i] - 1;
			}
			count = std::vector<int>(k, 0);
			for (int i = N - 1; i >= 0; i--) {
				if (buckets[i] == 0 || !is_S[buckets[i] - 1]) continue;
				int c = str[buckets[i] - 1];
				buckets[chars[c + 1] - 1 - count[c]++] = buckets[i] - 1;
			}
			return buckets;
		};

		int N = str.size();
		std::vector<bool> is_S(N), is_LMS(N);
		std::vector<int> LMSs;
		is_S[N - 1] = true;
		for (int i = N - 2; i >= 0; i--) {
			is_S[i] = str[i] < str[i + 1] || (str[i] == str[i + 1] && is_S[i + 1]);
		}

		for (int i = 0; i < N; i++) {
			if (is_S[i] && (i == 0 || !is_S[i - 1])) {
				is_LMS[i] = true;
				LMSs.push_back(i);
			}
		}

		auto pseudo_sa = induced_sort(str, LMSs, is_S, k);

		std::vector<int> orderedLMSs(LMSs.size());
		for (int index = 0, i = 0; i < pseudo_sa.size(); i++) {
			if (is_LMS[pseudo_sa[i]])orderedLMSs[index++] = pseudo_sa[i];
		}

		pseudo_sa[orderedLMSs[0]] = 0;
		int rank = 0;
		if (orderedLMSs.size() > 1) pseudo_sa[orderedLMSs[1]] = ++rank;
		for (int i = 1; i < orderedLMSs.size() - 1; i++) {
			bool is_diff = false;
			for (int j = 0; j < N; j++) {
				int p = orderedLMSs[i] + j;
				int q = orderedLMSs[i + 1] + j;
				if (str[p] != str[q] || is_LMS[p] != is_LMS[q]) {
					is_diff = true; break;
				}
				if (j > 0 && is_LMS[p]) break;
			}
			pseudo_sa[orderedLMSs[i + 1]] = is_diff ? ++rank : rank;
		}

		std::vector<int> LMS_sa;
		if (rank + 1 == LMSs.size()) {
			LMS_sa = orderedLMSs;
		}
		else {
			std::vector<int> new_str(LMSs.size());
			for (int index = 0, i = 0; i < N; i++) {
				if (is_LMS[i])new_str[index++] = pseudo_sa[i];
			}
			LMS_sa = sa_is(new_str, rank + 1);
			for (auto&& x : LMS_sa) x = LMSs[x];
		}

		return induced_sort(str, LMS_sa, is_S, k);
	}

	SuffixArray(std::string S) : S(S) {
		S += "$";
		std::vector<int> str(S.size());
		for (int i = 0; i < S.size(); i++) { str[i] = S[i] - '$'; }
		sa = sa_is(str, 128);
		sa.erase(sa.begin());
	}

	bool lt_substr(const std::string& T, int si = 0, int ti = 0) {
		int sn = S.size(), tn = T.size();
		while (si < sn && ti < tn) {
			if (S[si] < T[ti])return true;
			if (S[si] > T[ti])return false;
			si++, ti++;
		}
		return si >= sn && ti < tn;
	}

	auto get_range(std::string& T) {
		int low = -1, high = sa.size();
		while (high - low > 1) {
			int mid = (low + high) / 2;
			if (lt_substr(T, sa[mid]))low = mid;
			else high = mid;
		}
		int tmp = high;
		low = tmp - 1, high = sa.size();
		T.back()++;
		while (high - low > 1) {
			int mid = (low + high) / 2;
			if (lt_substr(T, sa[mid]))low = mid;
			else high = mid;
		}
		T.back()--;
		return std::make_pair(tmp, high);
	}

	void dump() {
		for (int i = 0; i < sa.size(); i++)std::cout << sa[i] << (i == sa.size() - 1 ? "\n" : " ");
	}
};
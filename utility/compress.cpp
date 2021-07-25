#pragma once

template<class T>
struct Compress {
	std::vector<T> data;
	void add(T x) {
		data.push_back(x);
	}
	void build() {
		std::sort(data.begin(), data.end());
		data.erase(std::unique(data.begin(), data.end()), data.end());
	}

	const int operator[](int x) const {
		return std::lower_bound(data.begin(), data.end(), x) - data.begin();
	}

	const int operator()(int k) const {
		return data[k];
	}
};
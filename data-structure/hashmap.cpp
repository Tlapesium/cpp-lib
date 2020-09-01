#pragma once
#include <functional>
#include <utility>

/**
 * @title HashMap
 * @docs data_structure/hashmap.md
 */
template<typename KeyType, typename ValType, typename HashFunc = std::hash<KeyType>, typename isEqual = std::equal_to<KeyType>>
struct HashMap {
	int BucketSize = 0; // バケットの数
	int MaxSize = 0; // MaxSize < DataSize のときリハッシュする
	int DataSize = 0; // 保存されているデータの数

	struct Record {
		// 0 -> empty  1 -> used  2 -> deleted
		int used = 0;
		std::pair<KeyType, ValType> data;
	};

	Record* Buckets;

	struct Iterator {
		int idx;
		HashMap& p;
		Iterator(int i, HashMap& Parent) : p(Parent) {
			idx = i;
			while (p.Buckets[idx].used != 1 && idx < p.BucketSize)idx++;
		}
		Iterator& operator++() {
			if (idx < p.BucketSize)idx++;
			while (p.Buckets[idx].used != 1 && idx < p.BucketSize)idx++;
			return *this;
		}
		Iterator operator++(int) {
			Iterator t = *this;
			++(*this);
			return t;
		}
		bool operator!=(const Iterator& r) { return idx != r.idx; };
		std::pair<KeyType, ValType>& operator*() { return p.Buckets[idx].data; }

	};
	Iterator begin() { return Iterator(0, static_cast<HashMap&>(*this)); }
	Iterator end() { return Iterator(BucketSize, static_cast<HashMap&>(*this)); }

	HashMap(int InitialBucketSize = 100000) {
		resize(1 << (32 - __builtin_clz(InitialBucketSize)));
	}

	unsigned long long Hasher(const KeyType& a) {
		unsigned long long x = HashFunc()(a);
		x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9ULL;
		x = (x ^ (x >> 27)) * 0x94d049bb133111ebULL;
		x = x ^ (x >> 31);
		return x;
	}

	void resize(int NewBucketSize) {
		int OldBucketSize = BucketSize;
		BucketSize = NewBucketSize;
		MaxSize = BucketSize * 0.7;
		DataSize = 0;
		Record* tmp = Buckets;

		Buckets = new Record[BucketSize];
		for (int i = 0; i < OldBucketSize; i++) {
			if (tmp[i].used != 1)continue;
			insert(tmp[i].data.first, tmp[i].data.second);
		}
		if (OldBucketSize) delete[] tmp;
	}

	ValType& insert(const KeyType& a, const ValType& b) {
		if (DataSize + 1 > MaxSize)resize(BucketSize << 1);
		unsigned long long Hash = Hasher(a);
		while (Buckets[Hash & (BucketSize - 1)].used != 0) {
			if (Buckets[Hash & (BucketSize - 1)].used == 1 && isEqual()(Buckets[Hash & (BucketSize - 1)].data.first, a)) {
				return Buckets[Hash & (BucketSize - 1)].data.second;
			}
			Hash++;
		}
		Buckets[Hash & (BucketSize - 1)] = { 1,{a,b} };
		DataSize++;
		return Buckets[Hash & (BucketSize - 1)].data.second;
	}

	void erase(const KeyType& key) {
		unsigned long long Hash = Hasher(key);
		while (Buckets[Hash & (BucketSize - 1)].used != 0) {
			if (Buckets[Hash & (BucketSize - 1)].used == 1 && isEqual()(Buckets[Hash & (BucketSize - 1)].data.first, key)) {
				Buckets[Hash & (BucketSize - 1)].used = 2;
				return;
			}
			Hash++;
		}
		throw "Not Found";
	}

	ValType& at(const KeyType& key) {
		unsigned long long Hash = Hasher(key);
		while (Buckets[Hash & (BucketSize - 1)].used != 0) {
			if (Buckets[Hash & (BucketSize - 1)].used == 1 && isEqual()(Buckets[Hash & (BucketSize - 1)].data.first, key)) {
				return Buckets[Hash & (BucketSize - 1)].data.second;
			}
			Hash++;
		}
		throw "Not Found";
	}

	ValType& operator[] (KeyType key) {
		if (DataSize + 1 > MaxSize)resize(BucketSize << 1);
		unsigned long long Hash = Hasher(key);
		while (Buckets[Hash & (BucketSize - 1)].used != 0) {
			if (Buckets[Hash & (BucketSize - 1)].used == 1 && isEqual()(Buckets[Hash & (BucketSize - 1)].data.first, key)) {
				return Buckets[Hash & (BucketSize - 1)].data.second;
			}
			Hash++;
		}
		Buckets[Hash & (BucketSize - 1)] = { 1,{key,ValType()} };
		DataSize++;
		return Buckets[Hash & (BucketSize - 1)].data.second;
	}

	const ValType& operator[] (KeyType key) const {
		return (*this)[key];
	}
};
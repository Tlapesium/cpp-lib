#pragma once

template<typename KeyType, typename ValType, typename HashFunc = std::hash<KeyType>, typename isEqual = std::equal_to<KeyType>>
struct HashMap {
	int BucketSize = 0; // バケットの数

	int MaxSize = 0; // MaxSize < DataSize のときリハッシュする

	int DataSize = 0; // 保存されているデータの数

	int TombSize = 0; // 削除されたデータの個数


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

	auto Hasher(const KeyType& a) {
		unsigned long long x = HashFunc()(a);
		x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9ULL;
		x = (x ^ (x >> 27)) * 0x94d049bb133111ebULL;
		x = x ^ (x >> 31);
		return x;
	}

	int size() { return DataSize - TombSize; }

	void resize(int NewBucketSize) {
		int OldBucketSize = BucketSize;
		BucketSize = NewBucketSize;
		MaxSize = BucketSize * 0.7;
		TombSize = DataSize = 0;
		Record* tmp = Buckets;

		Buckets = new Record[BucketSize];
		for (int i = 0; i < OldBucketSize; i++) {
			if (tmp[i].used != 1)continue;
			insert(tmp[i].data.first, tmp[i].data.second);
		}
		if (OldBucketSize) delete[] tmp;
	}

	bool insert(const KeyType& a, const ValType& b) {
		if (DataSize + 1 > MaxSize)resize(BucketSize << 1);
		auto Hash = Hasher(a);
		auto TombHash = Hash;
		bool TombFlag = false;

		while (Buckets[Hash & (BucketSize - 1)].used != 0) {
			if (Buckets[Hash & (BucketSize - 1)].used == 1 && isEqual()(Buckets[Hash & (BucketSize - 1)].data.first, a)) {
				return false;
			}
			if (!TombFlag && Buckets[Hash & (BucketSize - 1)].used == 2)TombFlag = true, TombHash = Hash;
			Hash++;
		}
		if (TombFlag) Hash = TombHash, DataSize--, TombSize--;
		Buckets[Hash & (BucketSize - 1)] = { 1,{a,b} };
		DataSize++;
		return true;
	}

	bool erase(const KeyType& key) {
		auto Hash = Hasher(key);
		while (Buckets[Hash & (BucketSize - 1)].used != 0) {
			if (Buckets[Hash & (BucketSize - 1)].used == 1 && isEqual()(Buckets[Hash & (BucketSize - 1)].data.first, key)) {
				Buckets[Hash & (BucketSize - 1)].used = 2;
				TombSize++;
				return true;
			}
			Hash++;
		}
		return false;
	}

	bool contains(const KeyType& key) {
		auto Hash = Hasher(key);
		while (Buckets[Hash & (BucketSize - 1)].used != 0) {
			if (Buckets[Hash & (BucketSize - 1)].used == 1 && isEqual()(Buckets[Hash & (BucketSize - 1)].data.first, key)) {
				return true;
			}
			Hash++;
		}
		return false;
	}

	ValType& at(const KeyType& key) {
		auto Hash = Hasher(key);
		while (Buckets[Hash & (BucketSize - 1)].used != 0) {
			if (Buckets[Hash & (BucketSize - 1)].used == 1 && isEqual()(Buckets[Hash & (BucketSize - 1)].data.first, key)) {
				return Buckets[Hash & (BucketSize - 1)].data.second;
			}
			Hash++;
		}
		throw "Not Found";
	}

	ValType& operator[] (const KeyType& key) {
		if (DataSize + 1 > MaxSize)resize(BucketSize << 1);
		auto Hash = Hasher(key);
		auto TombHash = Hash;
		bool TombFlag = false;

		while (Buckets[Hash & (BucketSize - 1)].used != 0) {
			if (Buckets[Hash & (BucketSize - 1)].used == 1 && isEqual()(Buckets[Hash & (BucketSize - 1)].data.first, key)) {
				return Buckets[Hash & (BucketSize - 1)].data.second;
			}
			if (!TombFlag && Buckets[Hash & (BucketSize - 1)].used == 2)TombFlag = true, TombHash = Hash;
			Hash++;
		}
		if (TombFlag) Hash = TombHash, DataSize--, TombSize--;
		Buckets[Hash & (BucketSize - 1)] = { 1,{key,ValType()} };
		DataSize++;
		return Buckets[Hash & (BucketSize - 1)].data.second;
	}

	const ValType& operator[] (const KeyType& key) const {
		return at(key);
	}
};
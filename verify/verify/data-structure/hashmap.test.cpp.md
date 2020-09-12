---
layout: default
---

<!-- mathjax config similar to math.stackexchange -->
<script type="text/javascript" async
  src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.5/MathJax.js?config=TeX-MML-AM_CHTML">
</script>
<script type="text/x-mathjax-config">
  MathJax.Hub.Config({
    TeX: { equationNumbers: { autoNumber: "AMS" }},
    tex2jax: {
      inlineMath: [ ['$','$'] ],
      processEscapes: true
    },
    "HTML-CSS": { matchFontHeight: false },
    displayAlign: "left",
    displayIndent: "2em"
  });
</script>

<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/jquery/3.4.1/jquery.min.js"></script>
<script src="https://cdn.jsdelivr.net/npm/jquery-balloon-js@1.1.2/jquery.balloon.min.js" integrity="sha256-ZEYs9VrgAeNuPvs15E39OsyOJaIkXEEt10fzxJ20+2I=" crossorigin="anonymous"></script>
<script type="text/javascript" src="../../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../../assets/css/copy-button.css" />


# :heavy_check_mark: verify/data-structure/hashmap.test.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#9883497098c636ad7eea3c1a0d797cd1">verify/data-structure</a>
* <a href="{{ site.github.repository_url }}/blob/master/verify/data-structure/hashmap.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-12 18:00:28+09:00


* see: <a href="https://judge.yosupo.jp/problem/associative_array">https://judge.yosupo.jp/problem/associative_array</a>


## Depends on

* :heavy_check_mark: <a href="../../../library/data-structure/hashmap.cpp.html">HashMap</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://judge.yosupo.jp/problem/associative_array"
#include <bits/stdc++.h>
#include "data-structure/hashmap.cpp"
using namespace std;
typedef long long ll;


int main() {
	HashMap<ll, ll> hm;
	int Q;
	cin >> Q;
	ll t, k, v;
	for (int i = 0; i < Q; i++) {
		cin >> t >> k;
		if (t) {
			cout << hm[k] << endl;
		}
		else {
			cin >> v;
			hm[k] = v;
		}
	}
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "verify/data-structure/hashmap.test.cpp"
#define PROBLEM "https://judge.yosupo.jp/problem/associative_array"
#include <bits/stdc++.h>
#line 4 "data-structure/hashmap.cpp"

/**
 * @title HashMap
 * @docs documents/hashmap.md
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

	ValType& operator[] (const KeyType& key) {
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

	const ValType& operator[] (const KeyType& key) const {
		return at(key);
	}
};
#line 4 "verify/data-structure/hashmap.test.cpp"
using namespace std;
typedef long long ll;


int main() {
	HashMap<ll, ll> hm;
	int Q;
	cin >> Q;
	ll t, k, v;
	for (int i = 0; i < Q; i++) {
		cin >> t >> k;
		if (t) {
			cout << hm[k] << endl;
		}
		else {
			cin >> v;
			hm[k] = v;
		}
	}
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>


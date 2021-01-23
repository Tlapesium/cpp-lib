---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data-structure/hashmap.cpp
    title: HashMap
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/associative_array
    links:
    - https://judge.yosupo.jp/problem/associative_array
  bundledCode: "#line 1 \"verify/data-structure/associative_array.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/associative_array\"\r\n#include <bits/stdc++.h>\r\
    \n#line 4 \"data-structure/hashmap.cpp\"\n\r\n/**\r\n * @title HashMap\r\n * @docs\
    \ documents/hashmap.md\r\n */\r\n\r\ntemplate<typename KeyType, typename ValType,\
    \ typename HashFunc = std::hash<KeyType>, typename isEqual = std::equal_to<KeyType>>\r\
    \nstruct HashMap {\r\n\tint BucketSize = 0; // \u30D0\u30B1\u30C3\u30C8\u306E\u6570\
    \r\n\tint MaxSize = 0; // MaxSize < DataSize \u306E\u3068\u304D\u30EA\u30CF\u30C3\
    \u30B7\u30E5\u3059\u308B\r\n\tint DataSize = 0; // \u4FDD\u5B58\u3055\u308C\u3066\
    \u3044\u308B\u30C7\u30FC\u30BF\u306E\u6570\r\n\r\n\tstruct Record {\r\n\t\t//\
    \ 0 -> empty  1 -> used  2 -> deleted\r\n\t\tint used = 0;\r\n\t\tstd::pair<KeyType,\
    \ ValType> data;\r\n\t};\r\n\r\n\tRecord* Buckets;\r\n\r\n\tstruct Iterator {\r\
    \n\t\tint idx;\r\n\t\tHashMap& p;\r\n\t\tIterator(int i, HashMap& Parent) : p(Parent)\
    \ {\r\n\t\t\tidx = i;\r\n\t\t\twhile (p.Buckets[idx].used != 1 && idx < p.BucketSize)idx++;\r\
    \n\t\t}\r\n\t\tIterator& operator++() {\r\n\t\t\tif (idx < p.BucketSize)idx++;\r\
    \n\t\t\twhile (p.Buckets[idx].used != 1 && idx < p.BucketSize)idx++;\r\n\t\t\t\
    return *this;\r\n\t\t}\r\n\t\tIterator operator++(int) {\r\n\t\t\tIterator t =\
    \ *this;\r\n\t\t\t++(*this);\r\n\t\t\treturn t;\r\n\t\t}\r\n\t\tbool operator!=(const\
    \ Iterator& r) { return idx != r.idx; };\r\n\t\tstd::pair<KeyType, ValType>& operator*()\
    \ { return p.Buckets[idx].data; }\r\n\r\n\t};\r\n\tIterator begin() { return Iterator(0,\
    \ static_cast<HashMap&>(*this)); }\r\n\tIterator end() { return Iterator(BucketSize,\
    \ static_cast<HashMap&>(*this)); }\r\n\r\n\tHashMap(int InitialBucketSize = 100000)\
    \ {\r\n\t\tresize(1 << (32 - __builtin_clz(InitialBucketSize)));\r\n\t}\r\n\r\n\
    \tunsigned long long Hasher(const KeyType& a) {\r\n\t\tunsigned long long x =\
    \ HashFunc()(a);\r\n\t\tx = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9ULL;\r\n\t\tx\
    \ = (x ^ (x >> 27)) * 0x94d049bb133111ebULL;\r\n\t\tx = x ^ (x >> 31);\r\n\t\t\
    return x;\r\n\t}\r\n\r\n\tvoid resize(int NewBucketSize) {\r\n\t\tint OldBucketSize\
    \ = BucketSize;\r\n\t\tBucketSize = NewBucketSize;\r\n\t\tMaxSize = BucketSize\
    \ * 0.7;\r\n\t\tDataSize = 0;\r\n\t\tRecord* tmp = Buckets;\r\n\r\n\t\tBuckets\
    \ = new Record[BucketSize];\r\n\t\tfor (int i = 0; i < OldBucketSize; i++) {\r\
    \n\t\t\tif (tmp[i].used != 1)continue;\r\n\t\t\tinsert(tmp[i].data.first, tmp[i].data.second);\r\
    \n\t\t}\r\n\t\tif (OldBucketSize) delete[] tmp;\r\n\t}\r\n\r\n\tValType& insert(const\
    \ KeyType& a, const ValType& b) {\r\n\t\tif (DataSize + 1 > MaxSize)resize(BucketSize\
    \ << 1);\r\n\t\tunsigned long long Hash = Hasher(a);\r\n\t\twhile (Buckets[Hash\
    \ & (BucketSize - 1)].used != 0) {\r\n\t\t\tif (Buckets[Hash & (BucketSize - 1)].used\
    \ == 1 && isEqual()(Buckets[Hash & (BucketSize - 1)].data.first, a)) {\r\n\t\t\
    \t\treturn Buckets[Hash & (BucketSize - 1)].data.second;\r\n\t\t\t}\r\n\t\t\t\
    Hash++;\r\n\t\t}\r\n\t\tBuckets[Hash & (BucketSize - 1)] = { 1,{a,b} };\r\n\t\t\
    DataSize++;\r\n\t\treturn Buckets[Hash & (BucketSize - 1)].data.second;\r\n\t\
    }\r\n\r\n\tvoid erase(const KeyType& key) {\r\n\t\tunsigned long long Hash = Hasher(key);\r\
    \n\t\twhile (Buckets[Hash & (BucketSize - 1)].used != 0) {\r\n\t\t\tif (Buckets[Hash\
    \ & (BucketSize - 1)].used == 1 && isEqual()(Buckets[Hash & (BucketSize - 1)].data.first,\
    \ key)) {\r\n\t\t\t\tBuckets[Hash & (BucketSize - 1)].used = 2;\r\n\t\t\t\treturn;\r\
    \n\t\t\t}\r\n\t\t\tHash++;\r\n\t\t}\r\n\t\tthrow \"Not Found\";\r\n\t}\r\n\r\n\
    \tValType& at(const KeyType& key) {\r\n\t\tunsigned long long Hash = Hasher(key);\r\
    \n\t\twhile (Buckets[Hash & (BucketSize - 1)].used != 0) {\r\n\t\t\tif (Buckets[Hash\
    \ & (BucketSize - 1)].used == 1 && isEqual()(Buckets[Hash & (BucketSize - 1)].data.first,\
    \ key)) {\r\n\t\t\t\treturn Buckets[Hash & (BucketSize - 1)].data.second;\r\n\t\
    \t\t}\r\n\t\t\tHash++;\r\n\t\t}\r\n\t\tthrow \"Not Found\";\r\n\t}\r\n\r\n\tValType&\
    \ operator[] (const KeyType& key) {\r\n\t\tif (DataSize + 1 > MaxSize)resize(BucketSize\
    \ << 1);\r\n\t\tunsigned long long Hash = Hasher(key);\r\n\t\twhile (Buckets[Hash\
    \ & (BucketSize - 1)].used != 0) {\r\n\t\t\tif (Buckets[Hash & (BucketSize - 1)].used\
    \ == 1 && isEqual()(Buckets[Hash & (BucketSize - 1)].data.first, key)) {\r\n\t\
    \t\t\treturn Buckets[Hash & (BucketSize - 1)].data.second;\r\n\t\t\t}\r\n\t\t\t\
    Hash++;\r\n\t\t}\r\n\t\tBuckets[Hash & (BucketSize - 1)] = { 1,{key,ValType()}\
    \ };\r\n\t\tDataSize++;\r\n\t\treturn Buckets[Hash & (BucketSize - 1)].data.second;\r\
    \n\t}\r\n\r\n\tconst ValType& operator[] (const KeyType& key) const {\r\n\t\t\
    return at(key);\r\n\t}\r\n};\n#line 4 \"verify/data-structure/associative_array.test.cpp\"\
    \nusing namespace std;\r\ntypedef long long ll;\r\n\r\n\r\nint main() {\r\n\t\
    HashMap<ll, ll> hm;\r\n\tint Q;\r\n\tcin >> Q;\r\n\tll t, k, v;\r\n\tfor (int\
    \ i = 0; i < Q; i++) {\r\n\t\tcin >> t >> k;\r\n\t\tif (t) {\r\n\t\t\tcout <<\
    \ hm[k] << endl;\r\n\t\t}\r\n\t\telse {\r\n\t\t\tcin >> v;\r\n\t\t\thm[k] = v;\r\
    \n\t\t}\r\n\t}\r\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/associative_array\"\r\n\
    #include <bits/stdc++.h>\r\n#include \"data-structure/hashmap.cpp\"\r\nusing namespace\
    \ std;\r\ntypedef long long ll;\r\n\r\n\r\nint main() {\r\n\tHashMap<ll, ll> hm;\r\
    \n\tint Q;\r\n\tcin >> Q;\r\n\tll t, k, v;\r\n\tfor (int i = 0; i < Q; i++) {\r\
    \n\t\tcin >> t >> k;\r\n\t\tif (t) {\r\n\t\t\tcout << hm[k] << endl;\r\n\t\t}\r\
    \n\t\telse {\r\n\t\t\tcin >> v;\r\n\t\t\thm[k] = v;\r\n\t\t}\r\n\t}\r\n}"
  dependsOn:
  - data-structure/hashmap.cpp
  isVerificationFile: true
  path: verify/data-structure/associative_array.test.cpp
  requiredBy: []
  timestamp: '2021-01-24 02:08:41+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/data-structure/associative_array.test.cpp
layout: document
redirect_from:
- /verify/verify/data-structure/associative_array.test.cpp
- /verify/verify/data-structure/associative_array.test.cpp.html
title: verify/data-structure/associative_array.test.cpp
---

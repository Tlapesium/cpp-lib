---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/data-structure/associative_array.test.cpp
    title: verify/data-structure/associative_array.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"data-structure/hashmap.cpp\"\n\r\ntemplate<typename KeyType,\
    \ typename ValType, typename HashFunc = std::hash<KeyType>, typename isEqual =\
    \ std::equal_to<KeyType>>\r\nstruct HashMap {\r\n\tint BucketSize = 0; // \u30D0\
    \u30B1\u30C3\u30C8\u306E\u6570\r\n\tint MaxSize = 0; // MaxSize < DataSize \u306E\
    \u3068\u304D\u30EA\u30CF\u30C3\u30B7\u30E5\u3059\u308B\r\n\tint DataSize = 0;\
    \ // \u4FDD\u5B58\u3055\u308C\u3066\u3044\u308B\u30C7\u30FC\u30BF\u306E\u6570\r\
    \n\tint TombSize = 0; // \u524A\u9664\u3055\u308C\u305F\u30C7\u30FC\u30BF\u306E\
    \u500B\u6570\r\n\r\n\tstruct Record {\r\n\t\t// 0 -> empty  1 -> used  2 -> deleted\r\
    \n\t\tint used = 0;\r\n\t\tstd::pair<KeyType, ValType> data;\r\n\t};\r\n\r\n\t\
    Record* Buckets;\r\n\r\n\tstruct Iterator {\r\n\t\tint idx;\r\n\t\tHashMap& p;\r\
    \n\t\tIterator(int i, HashMap& Parent) : p(Parent) {\r\n\t\t\tidx = i;\r\n\t\t\
    \twhile (p.Buckets[idx].used != 1 && idx < p.BucketSize)idx++;\r\n\t\t}\r\n\t\t\
    Iterator& operator++() {\r\n\t\t\tif (idx < p.BucketSize)idx++;\r\n\t\t\twhile\
    \ (p.Buckets[idx].used != 1 && idx < p.BucketSize)idx++;\r\n\t\t\treturn *this;\r\
    \n\t\t}\r\n\t\tIterator operator++(int) {\r\n\t\t\tIterator t = *this;\r\n\t\t\
    \t++(*this);\r\n\t\t\treturn t;\r\n\t\t}\r\n\t\tbool operator!=(const Iterator&\
    \ r) { return idx != r.idx; };\r\n\t\tstd::pair<KeyType, ValType>& operator*()\
    \ { return p.Buckets[idx].data; }\r\n\r\n\t};\r\n\tIterator begin() { return Iterator(0,\
    \ static_cast<HashMap&>(*this)); }\r\n\tIterator end() { return Iterator(BucketSize,\
    \ static_cast<HashMap&>(*this)); }\r\n\r\n\tHashMap(int InitialBucketSize = 100000)\
    \ {\r\n\t\tresize(1 << (32 - __builtin_clz(InitialBucketSize)));\r\n\t}\r\n\r\n\
    \tunsigned long long Hasher(const KeyType& a) {\r\n\t\tunsigned long long x =\
    \ HashFunc()(a);\r\n\t\tx = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9ULL;\r\n\t\tx\
    \ = (x ^ (x >> 27)) * 0x94d049bb133111ebULL;\r\n\t\tx = x ^ (x >> 31);\r\n\t\t\
    return x;\r\n\t}\r\n\r\n\tint size() { return DataSize - TombSize; }\r\n\r\n\t\
    void resize(int NewBucketSize) {\r\n\t\tint OldBucketSize = BucketSize;\r\n\t\t\
    BucketSize = NewBucketSize;\r\n\t\tMaxSize = BucketSize * 0.7;\r\n\t\tDataSize\
    \ = 0;\r\n\t\tRecord* tmp = Buckets;\r\n\r\n\t\tBuckets = new Record[BucketSize];\r\
    \n\t\tfor (int i = 0; i < OldBucketSize; i++) {\r\n\t\t\tif (tmp[i].used != 1)continue;\r\
    \n\t\t\tinsert(tmp[i].data.first, tmp[i].data.second);\r\n\t\t}\r\n\t\tif (OldBucketSize)\
    \ delete[] tmp;\r\n\t}\r\n\r\n\tValType& insert(const KeyType& a, const ValType&\
    \ b) {\r\n\t\tif (DataSize + 1 > MaxSize)resize(BucketSize << 1);\r\n\t\tunsigned\
    \ long long Hash = Hasher(a);\r\n\t\twhile (Buckets[Hash & (BucketSize - 1)].used\
    \ != 0) {\r\n\t\t\tif (Buckets[Hash & (BucketSize - 1)].used == 1 && isEqual()(Buckets[Hash\
    \ & (BucketSize - 1)].data.first, a)) {\r\n\t\t\t\treturn Buckets[Hash & (BucketSize\
    \ - 1)].data.second;\r\n\t\t\t}\r\n\t\t\tHash++;\r\n\t\t}\r\n\t\tBuckets[Hash\
    \ & (BucketSize - 1)] = { 1,{a,b} };\r\n\t\tDataSize++;\r\n\t\treturn Buckets[Hash\
    \ & (BucketSize - 1)].data.second;\r\n\t}\r\n\r\n\tvoid erase(const KeyType& key)\
    \ {\r\n\t\tunsigned long long Hash = Hasher(key);\r\n\t\twhile (Buckets[Hash &\
    \ (BucketSize - 1)].used != 0) {\r\n\t\t\tif (Buckets[Hash & (BucketSize - 1)].used\
    \ == 1 && isEqual()(Buckets[Hash & (BucketSize - 1)].data.first, key)) {\r\n\t\
    \t\t\tBuckets[Hash & (BucketSize - 1)].used = 2;\r\n\t\t\t\tTombSize++;\r\n\t\t\
    \t\treturn;\r\n\t\t\t}\r\n\t\t\tHash++;\r\n\t\t}\r\n\t\tthrow \"Not Found\";\r\
    \n\t}\r\n\r\n\tValType& at(const KeyType& key) {\r\n\t\tunsigned long long Hash\
    \ = Hasher(key);\r\n\t\twhile (Buckets[Hash & (BucketSize - 1)].used != 0) {\r\
    \n\t\t\tif (Buckets[Hash & (BucketSize - 1)].used == 1 && isEqual()(Buckets[Hash\
    \ & (BucketSize - 1)].data.first, key)) {\r\n\t\t\t\treturn Buckets[Hash & (BucketSize\
    \ - 1)].data.second;\r\n\t\t\t}\r\n\t\t\tHash++;\r\n\t\t}\r\n\t\tthrow \"Not Found\"\
    ;\r\n\t}\r\n\r\n\tValType& operator[] (const KeyType& key) {\r\n\t\tif (DataSize\
    \ + 1 > MaxSize)resize(BucketSize << 1);\r\n\t\tunsigned long long Hash = Hasher(key);\r\
    \n\t\twhile (Buckets[Hash & (BucketSize - 1)].used != 0) {\r\n\t\t\tif (Buckets[Hash\
    \ & (BucketSize - 1)].used == 1 && isEqual()(Buckets[Hash & (BucketSize - 1)].data.first,\
    \ key)) {\r\n\t\t\t\treturn Buckets[Hash & (BucketSize - 1)].data.second;\r\n\t\
    \t\t}\r\n\t\t\tHash++;\r\n\t\t}\r\n\t\tBuckets[Hash & (BucketSize - 1)] = { 1,{key,ValType()}\
    \ };\r\n\t\tDataSize++;\r\n\t\treturn Buckets[Hash & (BucketSize - 1)].data.second;\r\
    \n\t}\r\n\r\n\tconst ValType& operator[] (const KeyType& key) const {\r\n\t\t\
    return at(key);\r\n\t}\r\n};\n"
  code: "#pragma once\r\n\r\ntemplate<typename KeyType, typename ValType, typename\
    \ HashFunc = std::hash<KeyType>, typename isEqual = std::equal_to<KeyType>>\r\n\
    struct HashMap {\r\n\tint BucketSize = 0; // \u30D0\u30B1\u30C3\u30C8\u306E\u6570\
    \r\n\tint MaxSize = 0; // MaxSize < DataSize \u306E\u3068\u304D\u30EA\u30CF\u30C3\
    \u30B7\u30E5\u3059\u308B\r\n\tint DataSize = 0; // \u4FDD\u5B58\u3055\u308C\u3066\
    \u3044\u308B\u30C7\u30FC\u30BF\u306E\u6570\r\n\tint TombSize = 0; // \u524A\u9664\
    \u3055\u308C\u305F\u30C7\u30FC\u30BF\u306E\u500B\u6570\r\n\r\n\tstruct Record\
    \ {\r\n\t\t// 0 -> empty  1 -> used  2 -> deleted\r\n\t\tint used = 0;\r\n\t\t\
    std::pair<KeyType, ValType> data;\r\n\t};\r\n\r\n\tRecord* Buckets;\r\n\r\n\t\
    struct Iterator {\r\n\t\tint idx;\r\n\t\tHashMap& p;\r\n\t\tIterator(int i, HashMap&\
    \ Parent) : p(Parent) {\r\n\t\t\tidx = i;\r\n\t\t\twhile (p.Buckets[idx].used\
    \ != 1 && idx < p.BucketSize)idx++;\r\n\t\t}\r\n\t\tIterator& operator++() {\r\
    \n\t\t\tif (idx < p.BucketSize)idx++;\r\n\t\t\twhile (p.Buckets[idx].used != 1\
    \ && idx < p.BucketSize)idx++;\r\n\t\t\treturn *this;\r\n\t\t}\r\n\t\tIterator\
    \ operator++(int) {\r\n\t\t\tIterator t = *this;\r\n\t\t\t++(*this);\r\n\t\t\t\
    return t;\r\n\t\t}\r\n\t\tbool operator!=(const Iterator& r) { return idx != r.idx;\
    \ };\r\n\t\tstd::pair<KeyType, ValType>& operator*() { return p.Buckets[idx].data;\
    \ }\r\n\r\n\t};\r\n\tIterator begin() { return Iterator(0, static_cast<HashMap&>(*this));\
    \ }\r\n\tIterator end() { return Iterator(BucketSize, static_cast<HashMap&>(*this));\
    \ }\r\n\r\n\tHashMap(int InitialBucketSize = 100000) {\r\n\t\tresize(1 << (32\
    \ - __builtin_clz(InitialBucketSize)));\r\n\t}\r\n\r\n\tunsigned long long Hasher(const\
    \ KeyType& a) {\r\n\t\tunsigned long long x = HashFunc()(a);\r\n\t\tx = (x ^ (x\
    \ >> 30)) * 0xbf58476d1ce4e5b9ULL;\r\n\t\tx = (x ^ (x >> 27)) * 0x94d049bb133111ebULL;\r\
    \n\t\tx = x ^ (x >> 31);\r\n\t\treturn x;\r\n\t}\r\n\r\n\tint size() { return\
    \ DataSize - TombSize; }\r\n\r\n\tvoid resize(int NewBucketSize) {\r\n\t\tint\
    \ OldBucketSize = BucketSize;\r\n\t\tBucketSize = NewBucketSize;\r\n\t\tMaxSize\
    \ = BucketSize * 0.7;\r\n\t\tDataSize = 0;\r\n\t\tRecord* tmp = Buckets;\r\n\r\
    \n\t\tBuckets = new Record[BucketSize];\r\n\t\tfor (int i = 0; i < OldBucketSize;\
    \ i++) {\r\n\t\t\tif (tmp[i].used != 1)continue;\r\n\t\t\tinsert(tmp[i].data.first,\
    \ tmp[i].data.second);\r\n\t\t}\r\n\t\tif (OldBucketSize) delete[] tmp;\r\n\t\
    }\r\n\r\n\tValType& insert(const KeyType& a, const ValType& b) {\r\n\t\tif (DataSize\
    \ + 1 > MaxSize)resize(BucketSize << 1);\r\n\t\tunsigned long long Hash = Hasher(a);\r\
    \n\t\twhile (Buckets[Hash & (BucketSize - 1)].used != 0) {\r\n\t\t\tif (Buckets[Hash\
    \ & (BucketSize - 1)].used == 1 && isEqual()(Buckets[Hash & (BucketSize - 1)].data.first,\
    \ a)) {\r\n\t\t\t\treturn Buckets[Hash & (BucketSize - 1)].data.second;\r\n\t\t\
    \t}\r\n\t\t\tHash++;\r\n\t\t}\r\n\t\tBuckets[Hash & (BucketSize - 1)] = { 1,{a,b}\
    \ };\r\n\t\tDataSize++;\r\n\t\treturn Buckets[Hash & (BucketSize - 1)].data.second;\r\
    \n\t}\r\n\r\n\tvoid erase(const KeyType& key) {\r\n\t\tunsigned long long Hash\
    \ = Hasher(key);\r\n\t\twhile (Buckets[Hash & (BucketSize - 1)].used != 0) {\r\
    \n\t\t\tif (Buckets[Hash & (BucketSize - 1)].used == 1 && isEqual()(Buckets[Hash\
    \ & (BucketSize - 1)].data.first, key)) {\r\n\t\t\t\tBuckets[Hash & (BucketSize\
    \ - 1)].used = 2;\r\n\t\t\t\tTombSize++;\r\n\t\t\t\treturn;\r\n\t\t\t}\r\n\t\t\
    \tHash++;\r\n\t\t}\r\n\t\tthrow \"Not Found\";\r\n\t}\r\n\r\n\tValType& at(const\
    \ KeyType& key) {\r\n\t\tunsigned long long Hash = Hasher(key);\r\n\t\twhile (Buckets[Hash\
    \ & (BucketSize - 1)].used != 0) {\r\n\t\t\tif (Buckets[Hash & (BucketSize - 1)].used\
    \ == 1 && isEqual()(Buckets[Hash & (BucketSize - 1)].data.first, key)) {\r\n\t\
    \t\t\treturn Buckets[Hash & (BucketSize - 1)].data.second;\r\n\t\t\t}\r\n\t\t\t\
    Hash++;\r\n\t\t}\r\n\t\tthrow \"Not Found\";\r\n\t}\r\n\r\n\tValType& operator[]\
    \ (const KeyType& key) {\r\n\t\tif (DataSize + 1 > MaxSize)resize(BucketSize <<\
    \ 1);\r\n\t\tunsigned long long Hash = Hasher(key);\r\n\t\twhile (Buckets[Hash\
    \ & (BucketSize - 1)].used != 0) {\r\n\t\t\tif (Buckets[Hash & (BucketSize - 1)].used\
    \ == 1 && isEqual()(Buckets[Hash & (BucketSize - 1)].data.first, key)) {\r\n\t\
    \t\t\treturn Buckets[Hash & (BucketSize - 1)].data.second;\r\n\t\t\t}\r\n\t\t\t\
    Hash++;\r\n\t\t}\r\n\t\tBuckets[Hash & (BucketSize - 1)] = { 1,{key,ValType()}\
    \ };\r\n\t\tDataSize++;\r\n\t\treturn Buckets[Hash & (BucketSize - 1)].data.second;\r\
    \n\t}\r\n\r\n\tconst ValType& operator[] (const KeyType& key) const {\r\n\t\t\
    return at(key);\r\n\t}\r\n};"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/hashmap.cpp
  requiredBy: []
  timestamp: '2021-03-12 03:00:04+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/data-structure/associative_array.test.cpp
documentation_of: data-structure/hashmap.cpp
layout: document
title: HashMap
---

## 説明
開番地法によるハッシュテーブルの実装。キーの重複を許さない。
イテレータで全要素を取得することも可能。

## 操作
### HashMap<$KeyType,ValType$> HashMap($N$)
キーの型が $KeyType$ 、値の型が $ValType$ で、バケットサイズが $N$ のハッシュテーブルを構築する。計算量はO($N$)。
### insert($a,b$)
キーが $a$ 、値が $b$ の要素を追加する。計算量はO(1)。
### erase($a$)
キーが $a$ であるような要素を削除する。計算量はO(1)。
### operator[] ($a$)
キーが $a$ であるような要素の値の参照を取得する。計算量はO(1)。
キーが $a$ であるような要素が無く要素を追加できるとき、自動で要素が追加される。
### size()
現在の要素数を取得する。
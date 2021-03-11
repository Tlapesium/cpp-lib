---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: string/suffix_array.cpp
    title: Suffix Array
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/suffixarray
    links:
    - https://judge.yosupo.jp/problem/suffixarray
  bundledCode: "#line 1 \"verify/string/suffix_array.test.cpp\"\n#define PROBLEM \"\
    https://judge.yosupo.jp/problem/suffixarray\"\r\n#line 2 \"string/suffix_array.cpp\"\
    \n#include <vector>\r\n#include <string>\r\n#include <utility>\r\n\r\nstruct SuffixArray\
    \ {\r\n\tstd::vector<int> sa;\r\n\tconst std::string S;\r\n\r\n\tstd::vector<int>\
    \ sa_is(const std::vector<int>& str, int k) {\r\n\r\n\t\tauto induced_sort = [](const\
    \ std::vector<int>& str, const std::vector<int>& LMSs, const std::vector<bool>&\
    \ is_S, int k) {\r\n\t\t\tint N = str.size();\r\n\t\t\tstd::vector<int> buckets(N);\r\
    \n\t\t\tstd::vector<int> chars(k + 1, 0);\r\n\t\t\tstd::vector<int> count(k, 0);\r\
    \n\t\t\tfor (int i = 0; i < N; i++)chars[str[i] + 1]++;\r\n\t\t\tfor (int i =\
    \ 0; i < k; i++)chars[i + 1] += chars[i];\r\n\t\t\tfor (int i = LMSs.size() -\
    \ 1; i >= 0; i--) {\r\n\t\t\t\tint c = str[LMSs[i]];\r\n\t\t\t\tbuckets[chars[c\
    \ + 1] - 1 - count[c]++] = LMSs[i];\r\n\t\t\t}\r\n\t\t\tcount = std::vector<int>(k,\
    \ 0);\r\n\t\t\tfor (int i = 0; i < N; i++) {\r\n\t\t\t\tif (buckets[i] == 0 ||\
    \ is_S[buckets[i] - 1]) continue;\r\n\t\t\t\tint c = str[buckets[i] - 1];\r\n\t\
    \t\t\tbuckets[chars[c] + count[c]++] = buckets[i] - 1;\r\n\t\t\t}\r\n\t\t\tcount\
    \ = std::vector<int>(k, 0);\r\n\t\t\tfor (int i = N - 1; i >= 0; i--) {\r\n\t\t\
    \t\tif (buckets[i] == 0 || !is_S[buckets[i] - 1]) continue;\r\n\t\t\t\tint c =\
    \ str[buckets[i] - 1];\r\n\t\t\t\tbuckets[chars[c + 1] - 1 - count[c]++] = buckets[i]\
    \ - 1;\r\n\t\t\t}\r\n\t\t\treturn buckets;\r\n\t\t};\r\n\r\n\t\tint N = str.size();\r\
    \n\t\tstd::vector<bool> is_S(N), is_LMS(N);\r\n\t\tstd::vector<int> LMSs;\r\n\t\
    \tis_S[N - 1] = true;\r\n\t\tfor (int i = N - 2; i >= 0; i--) {\r\n\t\t\tis_S[i]\
    \ = str[i] < str[i + 1] || (str[i] == str[i + 1] && is_S[i + 1]);\r\n\t\t}\r\n\
    \r\n\t\tfor (int i = 0; i < N; i++) {\r\n\t\t\tif (is_S[i] && (i == 0 || !is_S[i\
    \ - 1])) {\r\n\t\t\t\tis_LMS[i] = true;\r\n\t\t\t\tLMSs.push_back(i);\r\n\t\t\t\
    }\r\n\t\t}\r\n\r\n\t\tauto pseudo_sa = induced_sort(str, LMSs, is_S, k);\r\n\r\
    \n\t\tstd::vector<int> orderedLMSs(LMSs.size());\r\n\t\tfor (int index = 0, i\
    \ = 0; i < pseudo_sa.size(); i++) {\r\n\t\t\tif (is_LMS[pseudo_sa[i]])orderedLMSs[index++]\
    \ = pseudo_sa[i];\r\n\t\t}\r\n\r\n\t\tpseudo_sa[orderedLMSs[0]] = 0;\r\n\t\tint\
    \ rank = 0;\r\n\t\tif (orderedLMSs.size() > 1) pseudo_sa[orderedLMSs[1]] = ++rank;\r\
    \n\t\tfor (int i = 1; i < orderedLMSs.size() - 1; i++) {\r\n\t\t\tbool is_diff\
    \ = false;\r\n\t\t\tfor (int j = 0; j < N; j++) {\r\n\t\t\t\tint p = orderedLMSs[i]\
    \ + j;\r\n\t\t\t\tint q = orderedLMSs[i + 1] + j;\r\n\t\t\t\tif (str[p] != str[q]\
    \ || is_LMS[p] != is_LMS[q]) {\r\n\t\t\t\t\tis_diff = true; break;\r\n\t\t\t\t\
    }\r\n\t\t\t\tif (j > 0 && is_LMS[p]) break;\r\n\t\t\t}\r\n\t\t\tpseudo_sa[orderedLMSs[i\
    \ + 1]] = is_diff ? ++rank : rank;\r\n\t\t}\r\n\r\n\t\tstd::vector<int> LMS_sa;\r\
    \n\t\tif (rank + 1 == LMSs.size()) {\r\n\t\t\tLMS_sa = orderedLMSs;\r\n\t\t}\r\
    \n\t\telse {\r\n\t\t\tstd::vector<int> new_str(LMSs.size());\r\n\t\t\tfor (int\
    \ index = 0, i = 0; i < N; i++) {\r\n\t\t\t\tif (is_LMS[i])new_str[index++] =\
    \ pseudo_sa[i];\r\n\t\t\t}\r\n\t\t\tLMS_sa = sa_is(new_str, rank + 1);\r\n\t\t\
    \tfor (auto&& x : LMS_sa) x = LMSs[x];\r\n\t\t}\r\n\r\n\t\treturn induced_sort(str,\
    \ LMS_sa, is_S, k);\r\n\t}\r\n\r\n\tSuffixArray(std::string S) : S(S) {\r\n\t\t\
    S += \"$\";\r\n\t\tstd::vector<int> str(S.size());\r\n\t\tfor (int i = 0; i <\
    \ S.size(); i++) { str[i] = S[i] - '$'; }\r\n\t\tsa = sa_is(str, 128);\r\n\t\t\
    sa.erase(sa.begin());\r\n\t}\r\n\r\n\tbool lt_substr(const std::string& T, int\
    \ si = 0, int ti = 0) {\r\n\t\tint sn = S.size(), tn = T.size();\r\n\t\twhile\
    \ (si < sn && ti < tn) {\r\n\t\t\tif (S[si] < T[ti])return true;\r\n\t\t\tif (S[si]\
    \ > T[ti])return false;\r\n\t\t\tsi++, ti++;\r\n\t\t}\r\n\t\treturn si >= sn &&\
    \ ti < tn;\r\n\t}\r\n\r\n\tauto get_range(std::string& T) {\r\n\t\tint low = -1,\
    \ high = sa.size();\r\n\t\twhile (high - low > 1) {\r\n\t\t\tint mid = (low +\
    \ high) / 2;\r\n\t\t\tif (lt_substr(T, sa[mid]))low = mid;\r\n\t\t\telse high\
    \ = mid;\r\n\t\t}\r\n\t\tint tmp = high;\r\n\t\tlow = tmp - 1, high = sa.size();\r\
    \n\t\tT.back()++;\r\n\t\twhile (high - low > 1) {\r\n\t\t\tint mid = (low + high)\
    \ / 2;\r\n\t\t\tif (lt_substr(T, sa[mid]))low = mid;\r\n\t\t\telse high = mid;\r\
    \n\t\t}\r\n\t\tT.back()--;\r\n\t\treturn std::make_pair(tmp, high);\r\n\t}\r\n\
    \r\n\tvoid dump() {\r\n\t\tfor (int i = 0; i < sa.size(); i++)std::cout << sa[i]\
    \ << (i == sa.size() - 1 ? \"\\n\" : \" \");\r\n\t}\r\n};\n#line 3 \"verify/string/suffix_array.test.cpp\"\
    \n#include <bits/stdc++.h>\r\nusing namespace std;\r\ntypedef long long ll;\r\n\
    \r\nint main() {\r\n\tstring S;\r\n\tcin >> S;\r\n\tSuffixArray SA(S);\r\n\tSA.dump();\r\
    \n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/suffixarray\"\r\n#include\
    \ \"string/suffix_array.cpp\"\r\n#include <bits/stdc++.h>\r\nusing namespace std;\r\
    \ntypedef long long ll;\r\n\r\nint main() {\r\n\tstring S;\r\n\tcin >> S;\r\n\t\
    SuffixArray SA(S);\r\n\tSA.dump();\r\n}"
  dependsOn:
  - string/suffix_array.cpp
  isVerificationFile: true
  path: verify/string/suffix_array.test.cpp
  requiredBy: []
  timestamp: '2021-03-12 00:08:16+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: verify/string/suffix_array.test.cpp
layout: document
redirect_from:
- /verify/verify/string/suffix_array.test.cpp
- /verify/verify/string/suffix_array.test.cpp.html
title: verify/string/suffix_array.test.cpp
---

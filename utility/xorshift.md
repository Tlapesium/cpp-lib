## 説明
SIMDを用いて高速化したXORShift。
乱数がボトルネックになることはあんまりない気がするが、早くて困ることはなさそう。

#### xorshift_32_4
周期が $2^{32} - 1$ の32bit乱数を生成する。SSE2が必要。

#### xorshift_32_8
周期が $2^{32} - 1$ の32bit乱数を生成する。AVX2が必要。

#### xorshift_64_4
周期が $2^{64} - 1$ の64bit乱数を生成する。AVX2が必要。

## ベンチマーク
{10^9} 回の生成に掛かった時間を計測。

| アルゴリズム  | 実行時間 | 拡張命令セット | 
| ------------- | :------- | :------------- | 
| [xorshift_32](https://ja.wikipedia.org/wiki/Xorshift)   | 1796ms   |                | 
| xorshift_32_4 | 932ms    | SSE2           | 
| xorshift_32_8 | 612ms    | AVX2           | 
| [xorshift_64](https://ja.wikipedia.org/wiki/Xorshift)   | 1220ms   |                | 
| xorshift_64_4 | 844ms    | AVX2           | 
# algorithm-test-usage

[algorithm-test](https://github.com/yosupo06/algorithm-test)を使ってみるサンプル
このリポジトリの内容はユーザーが準備するという想定

```
src/ ライブラリ本体たち
    base.h : 基本のやつ(#include <bits/stdc++.h>とか)
    fenwick.h : fenwick treeのライブラリが入っている
    prime.h : is_prime(素数判定)とfactor(素因数分解)が入っている
test/
    algorithm-test : algorithm-test(submodule)
    fenwick_test.cpp : fenwick treeをテストするソースコード
    prime_test.cpp : is_prime / factorをテストするソースコード
    CMakeLists.txt : cmakeのコンフィグファイル, おまじないのかたまり
```

### 準備

```
git submodule update --init --recursive
```

`--recursive`ないと動かないので注意

### テストの仕方

```
cd test
mkdir build # お好きな名前で
cd build
cmake ..
make
make test # ctestが走る
```

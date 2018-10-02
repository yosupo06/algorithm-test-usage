# algorithm-test-usage

[algorithm-test](https://github.com/yosupo06/algorithm-test)を使ってみるサンプル
このリポジトリの内容はユーザーが準備するという想定

```
src/ ライブラリ本体たち
    base.h : 基本のやつ(#include <bits/stdc++.h>とか)
    lca.h : lcaのライブラリが入っている
test/
    algorithm-test : algorithm-test(submodule)
    lca_test.cpp : lcaをテストするソースコード
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

# algorithm-test-usage

algorithm-testを使ってみるサンプル

```
src/
    base.h : 基本のやつ(#include <bits/stdc++.h>とか)
    lca.h : lcaのライブラリが入っている
test/
    algorithm-test : algorithm-test(submodule)
    lca_test.cpp : lcaをテストするソースコード
    CMakeLists.txt : cmakeのコンフィグファイル, おまじないのかたまり
```

### 準備

```
git submodule --init --recursive
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
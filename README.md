# algorithm-test-usage

[algorithm-test](https://github.com/yosupo06/algorithm-test)のサンプル
このリポジトリの内容はユーザーが準備するという想定

```
src/ ライブラリ本体たち
    fenwick.h : fenwick treeのライブラリが入っている
    prime.h : is_prime(素数判定)とfactor(素因数分解)が入っている
    base.h : テンプレート(#includeとかll(long long)の定義とか)
test/
    fenwick_test.cpp : fenwick treeをテストするソースコード
    prime_test.cpp : is_prime / factorをテストするソースコード
    algorithm-test : algorithm-test(submodule)
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
ctest # ctestが走る
```

詳しいログを出したい場合

```
export GTEST_COLOR=1 # 無くても良いが、ログに色がつく
ctest -VV
```

ちなみにこのリポジトリのテスト走らすと、以下のような出力が出てくる(はず)

```
Test project /home/yosupo/Documents/algorithm-test-usage/test/build
    Start 1: MyWavelet/FenwickTest/FenwickTester.StressTest
1/5 Test #1: MyWavelet/FenwickTest/FenwickTester.StressTest ...   Passed    0.00 sec
    Start 2: MyPrime/PrimeTest/PrimeTester.IsPrimeTest
2/5 Test #2: MyPrime/PrimeTest/PrimeTester.IsPrimeTest ........***Failed    0.00 sec
    Start 3: MyPrime/PrimeTest/PrimeTester.PollardTest
3/5 Test #3: MyPrime/PrimeTest/PrimeTester.PollardTest ........   Passed    0.00 sec
    Start 4: MyPrime/PrimeTest/PrimeTester.IsPrimeBigTest
4/5 Test #4: MyPrime/PrimeTest/PrimeTester.IsPrimeBigTest .....***Exception: Child aborted  0.10 sec
    Start 5: MyPrime/PrimeTest/PrimeTester.PollardBigTest
5/5 Test #5: MyPrime/PrimeTest/PrimeTester.PollardBigTest .....***Timeout   2.01 sec

40% tests passed, 3 tests failed out of 5

Total Test time (real) =   2.12 sec

The following tests FAILED:
	  2 - MyPrime/PrimeTest/PrimeTester.IsPrimeTest (Failed)
	  4 - MyPrime/PrimeTest/PrimeTester.IsPrimeBigTest (Child aborted)
	  5 - MyPrime/PrimeTest/PrimeTester.PollardBigTest (Timeout)
Errors while running CTest
```

2番はWAのサンプルで4, 5はTLEを回避するためのサンプルです。

詳しくログを出して，赤文字でFAILEDと書いてあるところの周りを見れば、

```
2: /home/yosupo/Documents/algorithm-test-usage/test/algorithm-test/algotest/math/prime_test.h:42: Failure
2: Value of: your_prime.is_prime(1)
2:   Actual: true
2: Expected: false
```
という出力が発見できて，is_primeのバグはis_prime(1)がtrueを返すことだとわかる。

4番と5番が失敗しているのは意図的なもので,O(sqrt)で動くアルゴリズムに10^18オーダーの値を入力するとすごい時間がかかるから打ち切っている。

4番ではassertで強制終了していて、5番では明示的に打ち切ることはせずTimeoutまでぶん回している(test/CMakeLists.txtで指定可能，指定しないとTimeoutなし)。

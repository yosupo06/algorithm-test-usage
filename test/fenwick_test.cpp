#include "gtest/gtest.h" // googletestのinclude
#include "algotest/datastructure/fenwick_test.h"

using namespace algotest;

#include "base.h" // ../src/base.h
#include "fenwick.h" // ../src/fenwick.h

struct FenwickTester : public FenwickTesterBase {
    Fenwick<ll> fw;
    void setup(vector<ll> a) final {
        int n = int(a.size());
        fw = Fenwick<ll>(n);
        for (int i = 0; i < n; i++) {
            fw.add(i, a[i]);
        }
    }
    void add(int k, ll x) final {
        fw.add(k, x);
    }
    ll sum(int l, int r) final {
        // [0..k)のsumしか用意していないためラップする
        return fw.sum(r) - fw.sum(l);
    }
};

using FenwickTypes = ::testing::Types<FenwickTester>;
INSTANTIATE_TYPED_TEST_CASE_P(MyWavelet, FenwickTest, FenwickTypes);

#include "gtest/gtest.h"
#include "algotest/math/prime_test.h"

using namespace algotest;

#include "base.h"
#include "prime.h"

struct PrimeTester : public PrimeTesterBase {
    bool is_prime(ll x) final {
        assert(x <= 1e12);
        return ::is_prime(x);
    }
    vector<ll> factor(ll x) final {
        EXPECT_LE(x, ll(1e12)) << "x = " << x << " is too big, factor work with O(sqrt(x))";
        return ::factor(x);
    }
};

using PrimeTypes = ::testing::Types<PrimeTester>;
INSTANTIATE_TYPED_TEST_CASE_P(MyPrime, PrimeTest, PrimeTypes);

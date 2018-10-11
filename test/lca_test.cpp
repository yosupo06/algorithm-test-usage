#include "gtest/gtest.h" // なにはともあれgoogletestをincludeする
#include "algotest/tree/lca_test.h" // algorithm-testのなかから使いたいテストを

using namespace algotest;

#include "base.h"
#include "lca.h"

// ユーザーはLCAをTestするためのインターフェースとなるクラスを定義する
// Testerクラスの雛形もalgorithm-testに入れて継承するようにしてもいいかも？
struct LCATester : public LCATesterBase {
    LCA lca;

    /*
     * setup関数はvector<vector<struct E { int to; }>>とroot vertexを引数にとり、色々準備する
     */
    void setup(VV<LCAEdge> g, int r) final {
        lca = get_lca(g, r);
    }

    /*
     * query関数はu, vが与えられるので、lcaを返す
     */
    int query(int u, int v) final {
        return lca.query(u, v);
    }
};

/*
 * 愚直LCAのテスト
 */
struct LCANaiveTester : public LCATesterBase {
    VV<int> g;
    V<int> depth, par;

    void dfs(int p, int b, int now_depth = 0) {
        par[p] = b;
        depth[p] = now_depth;
        for (int d: g[p]) {
            if (d == b) continue;
            dfs(d, p, now_depth + 1);
        }
    }

    void setup(VV<LCAEdge> _g, int r) final {
        int n = int(_g.size());
        g = VV<int>(n);
        for (int i = 0; i < n; i++) {
            for (auto e: _g[i]) {
                g[i].push_back(e.to);
            }
        }
        depth = V<int>(n);
        par = V<int>(n);
        dfs(r, -1);
    }

    int query(int u, int v) final {
        while (u != v) {
            if (depth[u] < depth[v]) swap(u, v);
            u = par[u];
        }
        return u;
    }
};

using LCATypes = ::testing::Types<LCATester, LCANaiveTester>;
INSTANTIATE_TYPED_TEST_CASE_P(MyLCA, LCATest, LCATypes);

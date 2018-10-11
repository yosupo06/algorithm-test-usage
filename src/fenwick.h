template<class T>
struct Fenwick {
    int N;
    vector<T> a;
    Fenwick() {}
    Fenwick(int _N) : N(_N), a(N+1, T()) {}
    /// a[i] += x
    void add(int i, T x) {
        i++;
        while (i <= N) {
            a[i] += x;
            i += i & -i;
        }
    }
    /// a[0, i)のsum
    T sum(int i) {
        T s = T(0);
        while (i > 0) {
            s += a[i];
            i -= i & -i;
        }
        return s;
    }
};
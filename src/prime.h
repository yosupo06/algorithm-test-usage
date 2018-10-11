// Nが素数か判定する, O(sqrt(N))
bool is_prime(ll n) {
    for (ll i = 2; i*i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

// Nを素因数分解する, O(sqrt(N))
vector<ll> factor(ll n) {
    vector<ll> result;
    for (ll i = 2; i*i <= n; i++) {
        while (n % i == 0) {
            result.push_back(i);
            n /= i;
        }
    }
    if (n > 1) result.push_back(n);
    return result;
}

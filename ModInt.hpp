template<int MOD> struct modint {
    int x;
    modint(int x = 0): x(norm(x % MOD)) {}
    modint(long long x): x(norm(int(x % MOD))) {}
    modint& operator/=(const modint &o) { 
        return *this *= inv(o); }
    modint& operator+=(const modint &o) { 
        x = norm(x + o.x); return *this; }
    modint& operator-=(const modint &o) { 
        x = norm(x - o.x); return *this; }
    modint& operator*=(const modint &o) { 
        x = 1LL * x * o.x % MOD; return *this; }
    modint& operator++() { return *this += 1; }
    modint& operator--() { return *this -= 1; }
    modint operator-() const { return modint(-x); }
    friend modint inv(const modint &v) { 
        assert(v.x != 0); return ksm(v, MOD - 2); }
    friend modint ksm(modint v, long long p) {
        modint res = 1; 
        for (; p; p >>= 1, v *= v) if (p & 1) res *= v; 
        return res; }
    friend istream &operator>>(istream &is, modint &v) { 
        long long a; is >> a; v = modint(a); return is; }
    friend ostream &operator<<(ostream &os, const modint &v) { 
        return os << v.x; }
    static int norm(int v) {
        if (v >= MOD) { v -= MOD; } if (v < 0) { v += MOD; } return v; }
    friend modint operator+(modint l, const modint &r) { return l += r; }
    friend modint operator-(modint l, const modint &r) { return l -= r; }
    friend modint operator*(modint l, const modint &r) { return l *= r; }
    friend modint operator/(modint l, const modint &r) { return l /= r; }
};
using mint = modint<998244353>;
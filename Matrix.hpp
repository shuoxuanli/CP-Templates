template<class T, int D> struct mat {
    array<array<T, D>, D> x{};
    friend mat operator+(mat l, const mat &r) {
        for (int i = 0; i < D; i++)
            for (int j = 0; j < D; j++)
                l.x[i][j] += r.x[i][j];
        return l;
    }
    friend mat operator-(mat l, const mat &r) {
        for (int i = 0; i < D; i++)
            for (int j = 0; j < D; j++)
                l.x[i][j] -= r.x[i][j];
        return l;
    }
    friend mat operator*(const mat &l, const mat &r) {
        mat res;
        for (int i = 0; i < D; i++)
            for (int j = 0; j < D; j++)
                for (int k = 0; k < D; k++)
                    res.x[i][j] += l.x[i][k] * r.x[k][j];
        return res;
    }
    friend mat ksm(mat b, long long p) {
        mat res;
        for (int i = 0; i < D; i++) res.x[i][i] = T(1);
        for (; p; p >>= 1, b *= b) if (p & 1) res *= b;
        return res;
    }
    T get(int i, int j) { return x[i][j]; }
    void set(int i, int j, T v) { x[i][j] = v; }
    mat& operator+=(const mat &o) { return *this = *this + o; }
    mat& operator-=(const mat &o) { return *this = *this - o; }
    mat& operator*=(const mat &o) { return *this = *this * o; }
};
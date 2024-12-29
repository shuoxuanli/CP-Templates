template<class T> struct seg {
    const T ID = numeric_limits<T>::max();
    const int n;
    vector<T> c;
    seg(int n): n(n), c(n << 1, ID) {}
    T cmb(T a, T b) {
        return min(a, b);
    }
    void upd(int i, T v) {
        for (c[i += n] = v; i > 1; i >>= 1) 
            c[i >> 1] = cmb(c[i], c[i ^ 1]);
    }
    T qry(int l, int r) {
        T res = ID;
        for (l += n, r += n + 1; l < r; l >>= 1, r >>= 1) {
            if (l & 1) res = cmb(res, c[l++]);
            if (r & 1) res = cmb(res, c[--r]);
        }
        return res;
    }
};
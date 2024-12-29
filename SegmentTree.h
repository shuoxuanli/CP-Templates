template<class T> struct seg {
    const int n;
    vector<T> c;
    seg(int n): n(n), c(n << 2) {}
    void pull(int i) { 
        c[i] = c[i * 2] + c[i * 2 + 1]; 
    }
    void bld(vector<T> a) { bld(1, 0, n - 1, a); }
    void bld(int i, int l, int r, const vector<T> &a) {
        if (l == r) {
            c[i] = a[l];
        } else {
            int m = (l + r) / 2;
            bld(i * 2, l, m, a);
            bld(i * 2 + 1, m + 1, r, a);
            pull(i);
        }
    }
    void upd(int x, T v) { upd(1, 0, n - 1, x, v); }
    void upd(int i, int l, int r, int x, const T &v) {
        if (l == r) {
            c[i] = v;
        } else {
            int m = (l + r) / 2;
            if (x <= m) upd(i * 2, l, m, x, v);
            else upd(i * 2 + 1, m + 1, r, x, v);
            pull(i);
        }
    }
    T qry(int x, int y) { return qry(1, 0, n - 1, x, y); }
    T qry(int i, int l, int r, int x, int y) {
        if (l > y || r < x) return T();
        if (l >= x && r <= y) return c[i];
        int m = (l + r) / 2;
        return qry(i * 2, l, m, x, y) + qry(i * 2 + 1, m + 1, r, x, y);
    }
};

struct node {
    node(): {}
    node operator+(const node &o) {}
};
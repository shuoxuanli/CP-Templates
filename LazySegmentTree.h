template<class T, class U> struct seg {
    const int n;
    vector<T> c;
    vector<U> z;
    seg(int n): n(n), c(n << 2), z(n << 2) {}
    void app(int i, U v) { 
        c[i].app(v), z[i].app(v); 
    }
    void pull(int i) { 
        c[i] = c[i * 2] + c[i * 2 + 1]; 
    }
    void push(int i) {
        app(i * 2, z[i]), app(i * 2 + 1, z[i]);
        z[i] = U();
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
    void mdf(int x, T v) { mdf(1, 0, n - 1, x, v); }
    void mdf(int i, int l, int r, int x, const T &v) {
        if (l == r) {
            c[i] = v;
        } else {
            int m = (l + r) / 2;
            push(i);
            if (x <= m) mdf(i * 2, l, m, x, v);
            else mdf(i * 2 + 1, m + 1, r, x, v);
            pull(i);
        }
    }
    void upd(int x, int y, U v) { upd(1, 0, n - 1, x, y, v); }
    void upd(int i, int l, int r, int x, int y, const U &v) {
        if (l > y || r < x) return;
        if (l >= x && r <= y) {
            app(i, v);
        } else {
            int m = (l + r) / 2;
            push(i);
            upd(i * 2, l, m, x, y, v);
            upd(i * 2 + 1, m + 1, r, x, y, v);
            pull(i);
        }
    }
    T qry(int x, int y) { return qry(1, 0, n - 1, x, y); }
    T qry(int i, int l, int r, int x, int y) {
        if (l > y || r < x) return T();
        if (l >= x && r <= y) return c[i];
        int m = (l + r) / 2;
        push(i);
        return qry(i * 2, l, m, x, y) + qry(i * 2 + 1, m + 1, r, x, y);
    }
};

struct tag {
    tag(): {}
    void app(const tag &t) {}
};

struct node {
    node(): {}
    void app(const tag &t) {}
    node operator+(const node &o) {}
};
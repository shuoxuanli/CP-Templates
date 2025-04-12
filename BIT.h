template<class T> struct bit {
    const int n;
    vector<T> c;
    bit(int n): n(n), c(n) {}
    void upd(int x, T v) {
        for (int i = x + 1; i <= n; i += i & -i)
            c[i - 1] += v;
    }
    T qry(int x) {
        T res = 0;
        for (int i = x + 1; i > 0; i -= i & -i)
            res += c[i - 1];
        return res;
    }
    T qry(int x, int y) { 
        return qry(y) - qry(x - 1); 
    }
};
struct dsu {
    vector<int> f, siz;
    dsu(int n): f(n), siz(n, 1) {
        iota(f.begin(), f.end(), 0);
    }
    int find(int x) {
        if (f[x] == x) return x;
        return f[x] = find(f[x]);
    }
    bool join(int x, int y) {
        x = find(x), y = find(y);
        if (x == y) return false;
        if (siz[x] < siz[y]) swap(x, y);
        siz[x] += siz[y], f[y] = x;
        return true;
    }
    int size(int x) { 
        return siz[find(x)]; 
    }
    bool same(int x, int y) { 
        return find(x) == find(y); 
    }
};
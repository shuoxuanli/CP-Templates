template<class T> struct kruskal {
    struct edge {
        int u, v; T w;
        bool operator<(const edge &o) const {
            return w < o.w;
        }
    };
    const int n;
    vector<edge> a;
    kruskal(int n): n(n) {}
    void add(int u, int v, T w) {
        a.push_back({u, v, w});
    }
    T get(dsu &d) {
        T res = 0;
        sort(a.begin(), a.end());
        for (const auto &[u, v, w] : a) {
            if (d.join(u, v)) {
                res += w;
            }
        }
        return d.size(0) == n ? res : -1;
    }
};
template<class T> struct prim {
    struct edge {
        int to; T w;
        bool operator<(const edge &o) const {
            return w > o.w;
        }
    };
    const int n;
    vector<bool> vis;
    vector<vector<edge>> adj;
    prim(int n): n(n), vis(n), adj(n) {}
    void add(int u, int v, T w) {
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    T get() {
        priority_queue<edge> pq;
        T res = 0; int cnt = 0;
        pq.push({0, 0});
        while (!pq.empty()) {
            auto [u, w] = pq.top();
            pq.pop();
            if (vis[u]) continue;
            vis[u] = true;
            res += w, cnt++;
            for (const edge &v : adj[u]) {
                pq.push(v);
            }
        }
        return cnt == n ? res : -1;
    }
};
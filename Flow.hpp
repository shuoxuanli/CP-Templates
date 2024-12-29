template<class T> struct flow {
    struct edge {
        int to; T f, c;
    };
    const T ID = numeric_limits<T>::max();
    const int n;
    vector<edge> e;
    vector<int> h, p;
    vector<vector<int>> adj;
    flow(int n): n(n), adj(n) {}
    void add(int u, int v, T c) {
        adj[u].push_back(e.size());
        e.push_back({v, 0, c});
        adj[v].push_back(e.size());
        e.push_back({u, 0, 0});
    }
    bool bfs(int s, int t) {
        queue<int> q;
        h.assign(n, -1);
        q.push(s); h[s] = 0;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int i : adj[u]) {
                auto [v, f, c] = e[i];
                if (f < c && h[v] == -1) {
                    h[v] = h[u] + 1;
                    q.push(v);
                }
            }
        }
        return h[t] != -1;
    }
    T dfs(int u, int t, T f) {
        if (u == t) return f;
        for (; p[u] < (int)adj[u].size(); p[u]++) {
            auto [v, r, c] = e[adj[u][p[u]]];
            if (r < c && h[v] == h[u] + 1) {
                T x = dfs(v, t, min(f, c - r));
                if (x) {
                    e[adj[u][p[u]]].f += x;
                    e[adj[u][p[u]] ^ 1].f -= x;
                    return x;
                }
            }
        }
        return 0;
    }
    T get(int s, int t) {
        T res = 0;
        while (bfs(s, t)) {
            p.assign(n, 0);
            while (T x = dfs(s, t, ID)) {
                res += x;
            }
        }
        return res;
    }
};
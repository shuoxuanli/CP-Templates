struct lca {
    const int n;
    vector<int> dep;
    vector<vector<int>> up, adj;
    lca(int n): n(n), dep(n), adj(n) {
        up = vector(n, vector<int>(21));
    }
    void add(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    void dfs(int u = 0) {
        for (int i = 1; i <= 20; i++)
            up[u][i] = up[up[u][i - 1]][i - 1];
        for (int v : adj[u]) {
            if (v != up[u][0]) {
                dep[v] = dep[up[v][0] = u] + 1;
                dfs(v);
            }
        }
    }
    int jmp(int u, int d) {
        for (int i = 0; i <= 20; i++) {
            if (d >> i & 1) u = up[u][i];
        }
        return u;
    }
    int qry(int u, int v) {
        if (dep[u] < dep[v]) swap(u, v);
        u = jmp(u, dep[u] - dep[v]);
        if (u == v) return u;
        for (int i = 20; i >= 0; i--) {
            if (up[u][i] != up[v][i]) 
                u = up[u][i], v = up[v][i];
        }
        return up[u][0];
    }
    int dis(int u, int v) {
        return dep[u] + dep[v] - 2 * dep[qry(u, v)];
    }
};

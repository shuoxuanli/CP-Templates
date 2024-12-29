struct scc {
    const int n;
    int t, cnt;
    stack<int> stk;
    vector<vector<int>> adj;
    vector<int> low, dfn, bel;
    scc(int n): n(n), adj(n), low(n) {
        t = cnt = 0;
        dfn.assign(n, -1);
        bel.assign(n, -1);
    }
    void add(int u, int v) {
        adj[u].push_back(v);
    }
    void dfs(int u) {
        stk.push(u);
        dfn[u] = low[u] = t++;
        for (int v : adj[u]) {
            if (dfn[v] == -1) {
                dfs(v);
                low[u] = min(low[u], low[v]);
            } else if (bel[v] == -1) {
                low[u] = min(low[u], dfn[v]);
            }
        }
        if (dfn[u] == low[u]) {
            int v;
            do {
                v = stk.top();
                bel[v] = cnt;
                stk.pop();
            } while (u != v);
            cnt++;
        }
    }
    vector<int> get() {
        for (int i = 0; i < n; i++) {
            if (dfn[i] == -1) dfs(i);
        }
        return bel;
    }
};
struct topo {
    const int n;
    vector<int> deg;
    vector<vector<int>> adj;
    topo(int n): n(n), deg(n), adj(n) {}
    void add(int u, int v) {
        adj[u].push_back(v), deg[v]++;
    }
    vector<int> sort() {
        vector<int> q;
        for (int i = 0; i < n; i++) {
            if (!deg[i]) q.push_back(i);
        }
        for (int i = 0; i < (int)q.size(); i++) {
            for (int x : adj[q[i]]) {
                if (!(--deg[x])) {
                    q.push_back(x);
                }
            }
        }
        return (int)q.size() == n ? q : vector<int>();
    }
};
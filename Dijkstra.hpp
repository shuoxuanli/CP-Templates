template<class T> struct dijkstra {
    struct edge {
        int to; T w;
        bool operator<(const edge &o) const {
            return w > o.w;
        }
    };
    const T ID = numeric_limits<T>::max();
    vector<T> dis; 
    vector<vector<edge>> adj;
    dijkstra(int n): dis(n, ID), adj(n) {}
    void add(int u, int v, T w) {
        adj[u].push_back({v, w});
    }
    void run(int s) {
        priority_queue<edge> pq;
        dis[s] = 0, pq.push({s, 0});
        while (!pq.empty()) {
            auto [u, d] = pq.top();
            pq.pop();
            if (dis[u] != d) continue;
            for (const auto &[v, w] : adj[u]) {
                if (dis[u] + w < dis[v]) {
                    dis[v] = dis[u] + w;
                    pq.push({v, dis[v]});
                }
            }
        }
    }
    T get(int i) { return dis[i] == ID ? -1 : dis[i]; }
};
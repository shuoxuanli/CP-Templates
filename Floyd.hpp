template<class T> struct floyd {
    const T ID = numeric_limits<T>::max() / 2;
    const int n;
    vector<vector<T>> dis;
    floyd(int n): n(n), dis(n, vector<T>(n, ID)) {
        for (int i = 0; i < n; i++) dis[i][i] = 0;
    }
    void add(int u, int v, T w) {
        dis[u][v] = min(dis[u][v], w);
    }
    void run() {
        for (int k = 0; k < n; k++) 
        for (int i = 0; i < n; i++) 
        for (int j = 0; j < n; j++)
            dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
    }
    T get(int i, int j) {
        return dis[i][j] == ID ? -1 : dis[i][j];
    }
};
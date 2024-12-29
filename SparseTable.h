template<class T> struct rmq {
    const int n;
    vector<int> lg;
    vector<vector<T>> mx, mn;
    rmq(int n): n(n), lg(n + 1, -1) {
        for (int i = 1; i <= n; i++) 
            lg[i] = lg[i >> 1] + 1;
        mx = vector(n, vector<T>(lg[n] + 1));
        mn = vector(n, vector<T>(lg[n] + 1));
    }
    void add(int i, T v) {
        mx[i][0] = mn[i][0] = v;
    }
    void init() {
        for (int j = 1; j <= lg[n]; j++) {
            for (int i = 0; i + (1 << j) <= n; i++) {
                mx[i][j] = max(mx[i][j - 1], mx[i + (1 << (j - 1))][j - 1]);
                mn[i][j] = min(mn[i][j - 1], mn[i + (1 << (j - 1))][j - 1]);
            }
        }
    }
    T qmax(int l, int r) {
        int i = lg[r - l + 1];
        return max(mx[l][i], mx[r - (1 << i) + 1][i]);
    }
    T qmin(int l, int r) {
        int i = lg[r - l + 1];
        return min(mn[l][i], mn[r - (1 << i) + 1][i]);
    }
};
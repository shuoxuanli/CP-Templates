struct trie {
    int tot = 0;
    vector<bool> last;
    vector<vector<int>> node;
    trie(int n): last(n + 1) {
        node = vector(n + 1, vector<int>(26));
    }
    void add(string s) {
        int p = 0;
        for (int i = 0; i < (int)s.size(); i++) {
            int c = s[i] - 'a';
            if (!node[p][c]) node[p][c] = ++tot;
            p = node[p][c];
        }
        last[p] = true;
    }
    int find(string s) {
        int p = 0;
        for (int i = 0; i < (int)s.size(); i++) {
            int c = s[i] - 'a';
            if (!node[p][c]) return -1;
            p = node[p][c];
        }
        return last[p];
    }
};
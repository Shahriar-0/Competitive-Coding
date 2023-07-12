#include <bits/stdc++.h>

using namespace std;

struct Dinic {
    #define MAXN 100010
    int n = 0, m = 0, turn = 0;
    vector < int > a, b, h, mark, pos, adj[MAXN];
    vector < int64_t > c, d;
    queue < int > q;
    void add_edge(int u, int v, int64_t w = 1) {
        u--, v--;
        adj[u].push_back(m);
        adj[v].push_back(m);
        a.push_back(u);
        b.push_back(v);
        c.push_back(w);
        m++;
        n = max(n, max(u, v) + 1);
    }
    void bfs(int v) {
        mark[v] = turn;
        int l = 0, r = 0;
        pos[r++] = v;
        h[v] = 0;
        while (l < r) {
            int v = pos[l++];
            for (int w: adj[v]) {
                if (a[w] == v and mark[b[w]] ^ turn and c[w] - d[w] > 0) {
                    mark[b[w]] = turn, h[b[w]] = h[v] + 1;
                    pos[r++] = b[w];
                }
                if (b[w] == v and mark[a[w]] ^ turn and d[w] > 0) {
                    mark[a[w]] = turn, h[a[w]] = h[v] + 1;
                    pos[r++] = a[w];
                }
            }
        }
    }
    int64_t pump(int v, int source, int sink, int64_t cap = (1LL << 62)) {
        int64_t ans = 0;
        if (v == sink)
            return cap;
        if (v == source)
            turn++, bfs(v), fill(pos.begin(), pos.end(), 0);
        mark[v] = turn;
        for (; pos[v] < int(adj[v].size()); pos[v]++) {
            int w = adj[v][pos[v]];
            if (a[w] == v) {
                if (c[w] - d[w] == 0) continue;
                if (h[b[w]] ^ (h[v] + 1)) continue;
                int64_t res = pump(b[w], source, sink, min(cap, c[w] - d[w]));
                ans += res;
                cap -= res;
                d[w] += res;
            }
            if (b[w] == v) {
                if (d[w] == 0) continue;
                if (h[a[w]] ^ (h[v] + 1)) continue;
                int64_t res = pump(a[w], source, sink, min(cap, d[w]));
                ans += res;
                cap -= res;
                d[w] -= res;
            }
        }
        return ans;
    }
    int64_t solve(int source, int sink) {
        source--, sink--;
        int64_t ans = 0;
        d.resize(m), fill(d.begin(), d.end(), 0);
        mark.resize(n), fill(mark.begin(), mark.end(), 0);
        h.resize(n);
        pos.resize(n);
        while (int64_t pumped = pump(source, source, sink))
            ans += pumped;
        return ans;
    }
};

int n, m;

Dinic crap;

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for (int i = 1, a, b, c; i <= m; i++)
        cin >> a >> b >> c, crap.add_edge(a, b, c);
    cout << crap.solve(1, n);
    return (0);
}

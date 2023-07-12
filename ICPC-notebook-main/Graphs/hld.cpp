void dfs_sz(int v = 0) {
    sz[v] = 1;
    for(auto &u: g[v]) {
        dfs_sz(u);
        sz[v] += sz[u];
        if(sz[u] > sz[g[v][0]]) {
            swap(u, g[v][0]);
        }
    }
}

void dfs_hld(int v = 0) {
    if(!head[v])head[v] = v;
    if(g[v].size())
        head[g[v][0]] = head[v];
    in[v] = ++t;
    for(auto u: g[v]) {
        dfs_hld(u);
    }
    out[v] = t+1;
}
int pointer[MAXN];
vector<pii> adj[MAXN];
bool mark[MAXN];

void tour(int v){
    while(pointer[v] < (int)adj[v].size()){
        if(!mark[adj[v][pointer[v]].S]){
            mark[adj[v][pointer[v]].S] = 1;
            tour(adj[v][pointer[v]].F);
        }
        pointer[v]++;
    }
    ans.push_back(v);
}
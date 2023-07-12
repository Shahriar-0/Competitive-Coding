int n , m , cnt = 1 ;
vector < int >  adj[maxn] , radj[maxn] , order;
int mark[maxn] , c[maxn];

void sfd(int v){
    c[v] = cur;
    for (auto u : radj[v])
        if(!c[u])
            sfd(u);
}

void dfs(int v){
    mark[v] = 1;
    for (auto u : adj[v])
        if(!mark[u])
            dfs(u);
    order.pb(v);
}

int32_t main(){
    for (int i = 1 ; i <= n ; i ++)
        if(!mark[i])
            dfs(i);
    reverse(order.begin() , order.end());
    for (int i = 0 ; i < n ; i ++)
        if(!c[order[i]])
            ++cnt, sfd(order[i]);
    return(0);
}
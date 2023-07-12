void plant(int v , int par = 0){
	sz[v] = 1;
	for(auto u : adj[v]) if(u != par and !hide[u])
		plant(u , v) , sz[v] += sz[u];
}
int cen(int v , int n , int par = 0 , bool found = 0){
	while(!found){
		found = 1;
		for(auto u : adj[v]) if(u!=par and !hide[u] and sz[u] * 2 > n){
			par = v , v = u , found = 0;
			break;
		}
	}
	return(v);
}
void add(int v , int par ,  int c){
	if(hide[v])return;
	for(auto u : adj[v])
		if(u!=par)
			add(u , v , c);
}
void rem(int v , int par ,  int c){
	if(hide[v])return;
	for(auto u : adj[v])
		if(u!=par)
			rem(u , v , c);
}
void calc(int v , int par){
	if(hide[v])return;
	for(auto u : adj[v])if(u!=par)
		calc(u , v);
}
void calc(int v){
	for(auto u : adj[v])
		add(u , v , a[v]);
	for(auto u : adj[v])
		rem(u , v , a[v]) , calc(u , v) , add(u , v , a[v]);
	for(auto u : adj[v])
		rem(u , v , a[v]);
}
void solve(int v){
	plant(v);
	v = cen(v , sz[v]);
	hide[v] = 1;
	calc(v);
	for(auto u : adj[v])
		if(!hide[u])
			solve(u);
}
int getpar(int v){
	return (par[v] ? par[v] = getpar(par[v]) : v);
}

void merge(int u ,int v){
	u = getpar(u) , v = getpar(v);
	if(u == v)return;
	par[u]=v;
}
struct sat{ //v = 2*v , ~v = 2*v + 1 ==> ~v = v^1
	int n, c;
	vector < vector < int > > in , out;
	vector < int > col , topo;
	sat(int N):
		n(N) , c(0) , in(2*n + 5) , out(2*n + 5) , col(2*n + 5){}
	bool operator [] (int x) { return(col[2*x] > col[2*x + 1]); }
	void add_e(int v , int u){in[u].pb(v) , out[v].pb(u);}
	void add(int v , int u){add_e(u^1 , v) , add_e(v^1 , u);}
	void sfd(int v){
		col[v] = c;
		for(auto u : in[v]) if(!col[u])
			sfd(u);
	}
	void dfs(int v){
		col[v] = 1;
		for(auto u : out[v]) if(!col[u])
			dfs(u);
		topo.pb(v);
	}
	bool validate(){
		for(int i = 1 ; i <= 2*n+1 ; i ++ ) if(!col[i]) dfs(i);
		reverse(topo.begin() , topo.end());
		fill(col.begin() , col.end() , 0 );
		for(auto v : topo)
			if(!col[v])
				++c , sfd(v);
		for(int i = 1 ; i <= n ; i ++) if(col[i * 2] == col[i * 2 + 1])return(0);
	return(1);
	}
};

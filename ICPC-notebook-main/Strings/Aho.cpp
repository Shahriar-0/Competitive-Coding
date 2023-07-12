#define SIGMA 26

int nxt[SIGMA][MAXN] , f[MAXN] , ext[MAXN] , sz = 0;
bool endpoint[MAXN];

int add(string &s){
	int cur = 0;
	for(char c : s){
		if(!nxt[c - 'a'][cur])nxt[c - 'a'][cur] = ++sz;
		cur = nxt[c - 'a'][cur];
	}
	endpoint[cur] = 1;
	return cur;
}

void build(){//q is a queue
	for(int i = 0 ; i < SIGMA ; i ++)if(nxt[i][0])q.push(nxt[i][0]);
	while(q.size()){
		int v = q.front();
		q.pop();
		if(endpoint[f[v]])ext[v] = f[v];
		else ext[v] = ext[f[v]];
		for(int i = 0 ; i < SIGMA ; i ++)
			if(nxt[i][v])f[nxt[i][v]] = nxt[i][f[v]] , q.push(nxt[i][v]);
			else nxt[i][v] = nxt[i][f[v]];
	}
}
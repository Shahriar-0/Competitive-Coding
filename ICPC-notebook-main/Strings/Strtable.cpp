struct strtable{
	#define MAXN 500010
	#define LG 20
	
	int rnk[LG][MAXN], n;
	int tmp[MAXN];
	int LST[MAXN], NXT[MAXN];
	int lg[MAXN];	
	void build(string s){
		n = s.size();
		for(int i = 0 ; i < n ; i ++)
			tmp[i] = s[i] - 'a';  
		sort(tmp , tmp + n);
		int sz = unique(tmp , tmp + n) - tmp;
		for(int i = 0 ; i < sz ; i ++)
			LST[tmp[i]] = i;
		for(int i = 0 ; i < n ; i ++)
			rnk[0][i] = LST[s[i] - 'a'];
		for(int j = 1 ; (1 << j) - 1 < n ; j ++){
			for(int i = 0 ; i + (1 << (j-1)) - 1 < n ; i ++)LST[i] = -1;
			for(int i = n - (1 << j) ; ~i ; i --)
				NXT[i] = LST[rnk[j - 1][i + (1 << (j - 1))]] , LST[rnk[j - 1][i + (1 << (j - 1))]] = i;
			int pos = 0;
			for(int i = 0 ; i + (1 << (j-1)) - 1 < n ; i ++)
				for(int k = LST[i] ; ~k ; k = NXT[k])
					tmp[pos++] = k;
			for(int i = 0 ; i + (1 << (j-1)) - 1 < n ; i ++)LST[i] = -1;
			for(int i = n - (1 << j) ; ~i ; i --)
				NXT[i] = LST[rnk[j - 1][tmp[i]]] , LST[rnk[j - 1][tmp[i]]] = i;
			pos = 0;
			for(int i = 0 ; i + (1 << (j-1)) - 1 < n ; pos += (LST[i] > -1) , i ++)
				for(int k = LST[i] ; ~k ; k = NXT[k])
					rnk[j][tmp[k]] = pos ,
					pos = ((~NXT[k]) ? ((rnk[j - 1][tmp[k] + (1 << (j - 1))] ^ rnk[j - 1][tmp[NXT[k]] + (1 << (j - 1))]) ? pos + 1 : pos) : pos);
		}
		for(int i = 2 ; i <= n ; i ++)
			lg[i] = lg[i >> 1] + 1;
	}
	pair < int , int > get(int l , int r){
		return pair < int , int > (rnk[lg[r - l]][l] , rnk[lg[r - l]][r - (1 << lg[r - l]) + 1]);
	}
	bool cmp(int l, int r, int L, int R){
		int sz = min(r - l , R - L);
		if(get(l , l + sz) == get(L , L + sz))
			return (r - l) < (R - L);
		return get(l , l + sz) < get(L , L + sz);
	}
	int Lcp(int l , int r , int L , int R){
		int ans = 0;
		for(int i = 0 ; i < n ; i ++){
			for(int j = LG ; ~j ; j --)if(l + (1 << j) -1 <= r and L + (1 << j) - 1 <= R){
				if(rnk[j][l] == rnk[j][L]){
					ans += (1 << j);
					l += (1 << j);
					L += (1 << j);
				}
			} 
		}
		return ans;
	}
};

int sa[MAXN];
strtable *st;
bool SAcmp(int i , int j){
	return st->cmp(i , st->n - 1 , j , st->n - 1);
}
void SA(strtable *ST){
	st = ST;
	for(int i = 0 ; i < st->n ; i ++) sa[i] = i;
	sort(sa , sa + st->n , SAcmp);
}

int lcp[MAXN];
void LCP(strtable *st){
	for(int i = 1 ; i < st->n ; i ++){
		int u = sa[i - 1], v = sa[i];
		for(int j = LG ; ~j ; j --)if(u + (1 << j) - 1 < st->n and v + (1 << j) - 1 < st->n){
			if(st->rnk[j][u] == st->rnk[j][v]){
				lcp[i] += (1 << j);
				u += (1 << j);
				v += (1 << j);
			}
		}
	}
}
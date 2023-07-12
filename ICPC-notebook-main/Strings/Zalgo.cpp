int zlcp[MAXN]; //zlcp[i] == lcp(s[i , .... , n-1] , s[0 , ... , n-1])
void ZAlgo(strtable *st){
	for(int i = 0 ; i < st-> n ; i ++){
		int u = i , v = 0;
		for(int j = LG ; ~j ; j --)if(u + (1 << j) -1 < st->n and v + (1 << j) - 1 < st->n){
			if(st->rnk[j][u] == st->rnk[j][v]){
				zlcp[i] += (1 << j);
				u += (1 << j);
				v += (1 << j);
			}
		} 
	}
}

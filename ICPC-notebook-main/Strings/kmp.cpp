//1 indexed
vector < int > kmp(string s){
    int i = -1 ;
    vector < int > f(s.size() + 1);
    f[0] = -1;
    for (int j = 0 ; j < s.size() ; j ++){
        while(s[j]!=s[i] and i!=-1)
            i = f[i];
        f[j + 1] = ++i;
    }
    return(f);
}
//0 indexed
vector < int > kmp(string s){
	int n = s.size();
    vector < int > f(n);
    for(int i = 1; i < n ; i ++){
		int j = f[i-1];
		while(j and s[i]!=s[j])
			j = f[j-1];
		j+=(s[i]==s[j]) , f[i] = j;
	}
    return(f);
}
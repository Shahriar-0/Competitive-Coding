void add(int pos,int x){
    for(;pos<maxn;pos+=pos&(-pos))
        fen[pos]+=x;
}
int get(int pos){
    int ans = 0;
    for(;pos;pos-=pos&(-pos))
        ans+=fen[pos];
    return(ans);
}

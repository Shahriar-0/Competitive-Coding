#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;
 
template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

struct oset{ // just don't use with numbers <= 0
    int maxn;
    vector < int > fen;
    oset(int n):
        maxn(n+100),
        fen(maxn){}
        
    void add(int x , int pos){
        for( ; pos < maxn ; pos += pos & -pos)
            fen[pos] += x;
    }
    int get(int pos){
        int sum = 0 ;
        for( ; pos ; pos -= pos & -pos)
            sum += fen[pos];
        return(sum);
    }
    
    void insert(int x , int cnt = 1){
        add(cnt , x);
    }
    void erase(int x , int cnt = 1){
        add(-cnt , x);
    }
    
    int find_by_order(int k){ // k-th element
        int sum = 0 , pos = 0;
        for(int i = log2(maxn) ; i >= 0 ; i --)
            if(pos + (1 << i) < maxn and sum + fen[pos + (1 << i)] < k)
                pos += (1 << i),
                sum += fen[pos];
        return(pos + 1);
    }
    int order_of_key(int key){ // number of elements <= key
        return(get(key));
    }
};

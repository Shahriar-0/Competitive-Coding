int LIS(vector <int> &vec){
    multiset <int> st;
    for(int x : vec){
        st.insert(x);
        auto it = st.lower_bound(x);
        it++;
        if(it != st.end())
            st.erase(it);
    }
    return st.size();
}
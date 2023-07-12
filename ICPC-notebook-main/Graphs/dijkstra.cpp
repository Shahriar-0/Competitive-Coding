void djk(int source){
    ms(dist, 63);
    dist[source] = 0;
    pq.push({-dist[source], source});
    while(pq.size()){
        auto [d, v] = pq.top();
        pq.pop();
        if(mark[v])continue;
        mark[v] = 1;
        for(auto [u, w] : adj[v]){
            if(dist[u] > dist[v] + w)
                dist[u] = dist[v] + w, pq.push({-dist[u], u});
        }
    }
}
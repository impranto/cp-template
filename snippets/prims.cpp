lli prims(vvl &graph, lli n){
    lli cost = 0;
    vl dist(n, INF);
    vl parent(n, -1);
    vl visited(n, 0);
    dist[0] = 0;
    priority_queue<pl, vector<pl>, greater<pl>> pq;
    pq.push({0, 0});
    while(!pq.empty()){
        lli u = pq.top().second;
        pq.pop();
        visited[u] = 1;
        for(auto it: graph[u]){
            lli v = it.first;
            lli w = it.second;
            if(!visited[v] && dist[v] > w){
                dist[v] = w;
                pq.push({dist[v], v});
                parent[v] = u;
            }
        }
    }
    for(lli i=0; i<n; i++){
        cost += dist[i];
    }
    return cost;
}
void dijkstra(vvl &graph, vl &dist, lli node){
    priority_queue<pl, vector<pl>, greater<pl>> pq;
    pq.push({0, node});
    dist[node] = 0;
    while(!pq.empty()){
        lli curr = pq.top().second;
        lli curr_d = pq.top().first;
        pq.pop();
        for(auto it: graph[curr]){
            lli next = it.first;
            lli next_d = it.second;
            if(dist[next] > dist[curr] + next_d){
                dist[next] = dist[curr] + next_d;
                pq.push({dist[next], next});
            }
        }
    }
}
void bellman_ford(vvl &graph, vl &dist, lli node){
    dist[node] = 0;
    for(lli i=0; i<graph.size()-1; i++){
        for(lli j=0; j<graph.size(); j++){
            for(auto it: graph[j]){
                lli next = it.first;
                lli next_d = it.second;
                if(dist[next] > dist[j] + next_d){
                    dist[next] = dist[j] + next_d;
                }
            }
        }
    }
}
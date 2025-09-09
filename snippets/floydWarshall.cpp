void floyd_warshall(vvl &graph, vvl &dist){
    for(lli i=0; i<graph.size(); i++){
        for(lli j=0; j<graph.size(); j++){
            dist[i][j] = graph[i][j];
        }
    }
    for(lli k=0; k<graph.size(); k++){
        for(lli i=0; i<graph.size(); i++){
            for(lli j=0; j<graph.size(); j++){
                if(dist[i][k] + dist[k][j] < dist[i][j]){
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
}
void dfs(vvl &graph, vl &visited, lli node){
    visited[node] = 1;
    for(auto it: graph[node]){
        if(!visited[it]){
            dfs(graph, visited, it);
        }
    }
}
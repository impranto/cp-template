void bfs(vvl &graph, vl &visited, vl &dist, lli node){
    queue<lli> q;
    q.push(node);
    visited[node] = 1;
    dist[node] = 0;
    while(!q.empty()){
        lli curr = q.front();
        q.pop();
        for(auto it: graph[curr]){
            if(!visited[it]){
                visited[it] = 1;
                dist[it] = dist[curr] + 1;
                q.push(it);
            }
        }
    }
}
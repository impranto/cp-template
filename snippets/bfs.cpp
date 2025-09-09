void bfs(vvl &graph, vl &visited, lli node){
    queue<lli> q;
    q.push(node);
    visited[node] = 1;
    while(!q.empty()){
        lli curr = q.front();
        q.pop();
        for(auto it: graph[curr]){
            if(!visited[it]){
                visited[it] = 1;
                q.push(it);
            }
        }
    }
}
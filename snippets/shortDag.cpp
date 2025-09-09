// Find the shortest path in a DAG
void dfs(vvl &graph, vl &visited, stack<lli> &st, lli node){
    visited[node] = 1;
    for(auto it: graph[node]){
        if(!visited[it]){
            dfs(graph, visited, st, it);
        }
    }
    st.push(node);
}
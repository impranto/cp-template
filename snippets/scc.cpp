// Find the strongly connected components in a graph
void dfs(vvl &graph, vl &visited, stack<lli> &st, lli node){
    visited[node] = 1;
    for(auto it: graph[node]){
        if(!visited[it]){
            dfs(graph, visited, st, it);
        }
    }
    st.push(node);
}

void dfs(vvl &graph, vl &visited, lli node){
    visited[node] = 1;
    for(auto it: graph[node]){
        if(!visited[it]){
            dfs(graph, visited, it);
        }
    }
}

void kosaraju(vvl &graph, vvl &rev_graph, lli n){
    stack<lli> st;
    vl visited(n, 0);
    for(lli i=0; i<n; i++){
        if(!visited[i]){
            dfs(graph, visited, st, i);
        }
    }
    vl visited2(n, 0);
    while(!st.empty()){
        lli node = st.top();
        st.pop();
        if(!visited2[node]){
            dfs(rev_graph, visited2, node);
        }
    }
}
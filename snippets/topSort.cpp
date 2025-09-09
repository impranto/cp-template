// Find the topological sort of a graph
void dfs(vvl &graph, vl &visited, stack<lli> &st, lli node){
    visited[node] = 1;
    for(auto it: graph[node]){
        if(!visited[it]){
            dfs(graph, visited, st, it);
        }
    }
    st.push(node);
}

void topological_sort(vvl &graph, lli n){
    stack<lli> st;
    vl visited(n, 0);
    for(lli i=0; i<n; i++){
        if(!visited[i]){
            dfs(graph, visited, st, i);
        }
    }
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
}
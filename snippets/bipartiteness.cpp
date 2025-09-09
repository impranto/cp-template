void dfs(vvl &graph, vl &color, lli node, lli c){
    color[node] = c;
    if(c==1) setA.pb(node);
    else setB.pb(node);

    for(auto it: graph[node]){
        if(color[it]==-1){
            dfs(graph, color, it, 1-c);
        }
    }
}
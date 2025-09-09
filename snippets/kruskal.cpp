lli kruskal(vvl &graph, lli n){
    lli cost = 0;
    vl parent(n, -1);
    vector<pair<lli, pl>> edges;
    for(lli i=0; i<n; i++){
        for(auto it: graph[i]){
            edges.pb({it.second, {i, it.first}});
        }
    }
    sort(edges.begin(), edges.end());
    for(auto it: edges){
        lli w = it.first;
        lli u = it.second.first;
        lli v = it.second.second;
        lli set_u = find_set(parent, u);
        lli set_v = find_set(parent, v);
        if(set_u != set_v){
            cost += w;
            union_set(parent, u, v);
        }
    }
    return cost;
}
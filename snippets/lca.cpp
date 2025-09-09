struct BinaryLiftingLCA {
    lli n, LOG;
    vector<vl> up;
    vl depth;
    vector<vl> adj;

    BinaryLiftingLCA(lli n) {
        this->n = n;
        LOG = 1;
        while ((1LL << LOG) <= n) LOG++;
        up.assign(n, vl(LOG, -1));
        depth.assign(n, 0);
        adj.assign(n, vl());
    }

    void add_edge(lli u, lli v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void dfs(lli v, lli p) {
        up[v][0] = p;
        for (lli i = 1; i < LOG; i++) {
            if (up[v][i - 1] != -1)
                up[v][i] = up[up[v][i - 1]][i - 1];
        }
        for (lli u : adj[v]) {
            if (u != p) {
                depth[u] = depth[v] + 1;
                dfs(u, v);
            }
        }
    }

    void preprocess(lli root = 0) {
        dfs(root, -1);
    }

    lli lift(lli v, lli k) {
        for (lli i = 0; i < LOG; i++) {
            if ((k >> i) & 1) v = up[v][i];
            if (v == -1) break;
        }
        return v;
    }

    lli lca(lli u, lli v) {
        if (depth[u] < depth[v]) swap(u, v);
        u = lift(u, depth[u] - depth[v]);
        if (u == v) return u;
        for (lli i = LOG - 1; i >= 0; i--) {
            if (up[u][i] != -1 && up[u][i] != up[v][i]) {
                u = up[u][i];
                v = up[v][i];
            }
        }
        return up[u][0];
    }

    lli distance(lli u, lli v) {
        return depth[u] + depth[v] - 2 * depth[lca(u, v)];
    }
};

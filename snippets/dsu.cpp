struct DSU {
    vl parent, size;
    lli n;

    DSU(lli n) {
        this->n = n;
        parent.resize(n);
        size.assign(n, 1);
        for (lli i = 0; i < n; i++) parent[i] = i;
    }

    lli find(lli x) {
        if (parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }

    void unite(lli x, lli y) {
        x = find(x);
        y = find(y);
        if (x == y) return;
        if (size[x] < size[y]) swap(x, y);
        parent[y] = x;
        size[x] += size[y];
    }

    bool same(lli x, lli y) {
        return find(x) == find(y);
    }
};

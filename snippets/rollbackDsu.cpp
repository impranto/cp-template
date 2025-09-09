struct RollbackDSU {
    vl parent, size;
    stack<pair<lli, lli>> history;
    lli n;

    RollbackDSU(lli n) {
        this->n = n;
        parent.resize(n);
        size.assign(n, 1);
        for (lli i = 0; i < n; i++) parent[i] = i;
    }

    lli find(lli x) {
        while (parent[x] != x) x = parent[x];
        return x;
    }

    bool unite(lli x, lli y) {
        x = find(x);
        y = find(y);
        if (x == y) return false;
        if (size[x] < size[y]) swap(x, y);
        history.push({y, size[x]});
        parent[y] = x;
        size[x] += size[y];
        return true;
    }

    void rollback() {
        if (history.empty()) return;
        auto [y, sz] = history.top();
        history.pop();
        size[parent[y]] = sz;
        parent[y] = y;
    }

    bool same(lli x, lli y) {
        return find(x) == find(y);
    }
};

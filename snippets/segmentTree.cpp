struct SegmentTree {
    lli n;
    vl tree;

    SegmentTree(lli n) {
        this->n = n;
        tree.assign(4 * n, 0);
    }

    void build(vl &a, lli node, lli start, lli end) {
        if (start == end) {
            tree[node] = a[start];
            return;
        }
        lli mid = (start + end) / 2;
        build(a, node * 2, start, mid);
        build(a, node * 2 + 1, mid + 1, end);
        tree[node] = tree[node * 2] + tree[node * 2 + 1]; // combine
    }

    void build(vl &a) {
        build(a, 1, 0, n - 1);
    }

    void update(lli node, lli start, lli end, lli idx, lli val) {
        if (start == end) {
            tree[node] = val;
            return;
        }
        lli mid = (start + end) / 2;
        if (idx <= mid) update(node * 2, start, mid, idx, val);
        else update(node * 2 + 1, mid + 1, end, idx, val);
        tree[node] = tree[node * 2] + tree[node * 2 + 1]; // combine
    }

    void update(lli idx, lli val) {
        update(1, 0, n - 1, idx, val);
    }

    lli query(lli node, lli start, lli end, lli l, lli r) {
        if (r < start || end < l) return 0; // neutral
        if (l <= start && end <= r) return tree[node];
        lli mid = (start + end) / 2;
        return query(node * 2, start, mid, l, r) +
               query(node * 2 + 1, mid + 1, end, l, r);
    }

    lli query(lli l, lli r) {
        return query(1, 0, n - 1, l, r);
    }
};

struct LazySegmentTree {
    lli n;
    vl tree, lazy;

    LazySegmentTree(lli n) {
        this->n = n;
        tree.assign(4 * n, 0);
        lazy.assign(4 * n, 0);
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

    void push(lli node, lli start, lli end) {
        if (lazy[node] != 0) {
            tree[node] += (end - start + 1) * lazy[node];
            if (start != end) {
                lazy[node * 2] += lazy[node];
                lazy[node * 2 + 1] += lazy[node];
            }
            lazy[node] = 0;
        }
    }

    void updateRange(lli node, lli start, lli end, lli l, lli r, lli val) {
        push(node, start, end);
        if (r < start || end < l) return;
        if (l <= start && end <= r) {
            lazy[node] += val;
            push(node, start, end);
            return;
        }
        lli mid = (start + end) / 2;
        updateRange(node * 2, start, mid, l, r, val);
        updateRange(node * 2 + 1, mid + 1, end, l, r, val);
        tree[node] = tree[node * 2] + tree[node * 2 + 1]; // combine
    }

    void updateRange(lli l, lli r, lli val) {
        updateRange(1, 0, n - 1, l, r, val);
    }

    lli query(lli node, lli start, lli end, lli l, lli r) {
        push(node, start, end);
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

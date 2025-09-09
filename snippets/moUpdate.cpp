struct Query {
    lli l, r, t, idx; // t = time (number of updates before this query)
    bool operator<(const Query &other) const {
        lli block_size = 320; // ~cbrt(N*Q) works well
        if (l / block_size != other.l / block_size) return l < other.l;
        if (r / block_size != other.r / block_size) return r < other.r;
        return t < other.t;
    }
};

struct Update {
    lli pos, prev, new_val;
};

struct MoWithUpdates {
    lli n, q;
    vl a;
    vector<Query> queries;
    vector<Update> updates;
    vl ans;
    lli curL, curR, curT, curAns;

    MoWithUpdates(lli n, lli q) {
        this->n = n;
        this->q = q;
        a.assign(n, 0);
        ans.assign(q, 0);
        curL = 0;
        curR = -1;
        curT = 0;
        curAns = 0;
    }

    void add_query(lli l, lli r, lli idx) {
        queries.push_back({l, r, (lli)updates.size(), idx});
    }

    void add_update(lli pos, lli val) {
        updates.push_back({pos, a[pos], val});
        a[pos] = val;
    }

    void add(lli pos) {
        // custom add logic
        curAns += a[pos]; // example
    }

    void remove(lli pos) {
        // custom remove logic
        curAns -= a[pos]; // example
    }

    void apply_update(lli t) {
        lli pos = updates[t].pos;
        lli val = updates[t].new_val;
        if (curL <= pos && pos <= curR) remove(pos);
        swap(a[pos], updates[t].new_val);
        if (curL <= pos && pos <= curR) add(pos);
    }

    void rollback_update(lli t) {
        lli pos = updates[t].pos;
        if (curL <= pos && pos <= curR) remove(pos);
        swap(a[pos], updates[t].new_val);
        if (curL <= pos && pos <= curR) add(pos);
    }

    void process() {
        sort(queries.begin(), queries.end());
        for (auto &q : queries) {
            while (curT < q.t) apply_update(curT++);
            while (curT > q.t) rollback_update(--curT);
            while (curL > q.l) add(--curL);
            while (curR < q.r) add(++curR);
            while (curL < q.l) remove(curL++);
            while (curR > q.r) remove(curR--);
            ans[q.idx] = curAns;
        }
    }
};

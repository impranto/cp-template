struct Query {
    lli l, r, idx;
    bool operator<(const Query &other) const {
        lli block_size = 450; // ~ sqrt(N), adjust accordingly
        if (l / block_size != other.l / block_size)
            return l < other.l;
        return (l / block_size & 1) ? (r < other.r) : (r > other.r);
    }
};

struct MoAlgorithm {
    lli n, q;
    vl a;                 // input array
    vector<Query> queries;
    vl ans;               // answers
    lli curL, curR, curAns;

    MoAlgorithm(lli n, lli q) {
        this->n = n;
        this->q = q;
        a.assign(n, 0);
        queries.reserve(q);
        ans.assign(q, 0);
        curL = 0;
        curR = -1;
        curAns = 0;
    }

    void add_query(lli l, lli r, lli idx) {
        queries.push_back({l, r, idx});
    }

    void add(lli pos) {
        // custom add logic
        // Example: frequency counting
        curAns += a[pos]; 
    }

    void remove(lli pos) {
        // custom remove logic
        // Example: frequency counting
        curAns -= a[pos];
    }

    void process() {
        sort(queries.begin(), queries.end());
        for (auto &q : queries) {
            while (curL > q.l) add(--curL);
            while (curR < q.r) add(++curR);
            while (curL < q.l) remove(curL++);
            while (curR > q.r) remove(curR--);
            ans[q.idx] = curAns;
        }
    }
};

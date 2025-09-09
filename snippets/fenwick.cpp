struct BIT{
    lli n;
    vl bit;

    BIT(lli n){
        this->n = n;
        bit.resize(n+1, 0);
    }

    void update(lli idx, lli val){
        for(; idx <= n; idx += (idx & -idx)){
            bit[idx] += val;
        }
    }

    void range_update(lli l, lli r, lli val){
        update(l, val);
        update(r + 1, -val);
    }

    lli query(lli idx){
        lli sum = 0;
        for(; idx > 0; idx -= (idx & -idx)){
            sum += bit[idx];
        }
        return sum;
    }
};
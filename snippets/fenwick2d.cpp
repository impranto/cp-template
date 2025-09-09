struct BIT2D{
    lli n, m;
    vvl bit;

    BIT2D(lli n, lli m){
        this->n = n;
        this->m = m;
        bit.assign(n+1, vl(m+1, 0));
    }

    void update(lli x, lli y, lli val){
        for(lli i=x; i<=n; i+=(i&-i)){
            for(lli j=y; j<=m; j+=(j&-j)){
                bit[i][j] += val;
            }
        }
    }

    lli query(lli x, lli y){
        lli sum = 0;
        for(lli i=x; i>0; i-=(i&-i)){
            for(lli j=y; j>0; j-=(j&-j)){
                sum+=bit[i][j];
            }
        }
        return sum;
    }

    lli range_query(lli x1, lli y1, lli x2, lli y2){
        return query(x2, y2)-query(x1-1, y2)-query(x2, y1-1) + query(x1-1, y1-1);
    }
};
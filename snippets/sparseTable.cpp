struct SparseTable{
    vvl st;
    vl logTable;

    SparseTable(const vl &arr){
        lli n = arr.size();
        lli maxLog = log2(n)+1;

        logTable.assign(n+1, 0);
        for(int i=2; i<=n; i++){
            logTable[i] = logTable[i/2]+1;
        }

        st.assign(maxLog, vl(n, LLONG_MAX));

        for(int i=0; i<n; i++) st[0][i] = arr[i];

        for(int i=1; (1<<i)<=n; i++){
            for(int j=0; j+(1<<i)<=n; j++){
                st[i][j] = min(st[i-1][j], st[i-1][j+(1<<(i-1))]);
            }
        }
    }

    lli query(lli L, lli R){
        lli len = R-L+1;
        lli lg = logTable[len];
        return min(st[lg][L], st[lg][R-(1<<lg)+1]);
    }
};
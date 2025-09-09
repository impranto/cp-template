lli nCr(lli n, lli r){
    if(r>n or r<0) return 0;
    lli a = fact[n];
    lli b = (fact[r]*fact[n-r])%MOD;
    return (a*modInverse(b, MOD))%MOD;
}
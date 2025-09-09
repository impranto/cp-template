const lli N = 1e6+5;

lli fact[N];


void factorial(lli n){
    fact[0] = 1;
    fact[1] = 1;
    for(lli i = 2; i <= n; i++){
        fact[i] = (fact[i-1] * i) % MOD;
    }
}
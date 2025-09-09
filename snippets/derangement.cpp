const lli N = 22;

lli fact[N], der[N];


void factorial(lli n){
    fact[0] = 1;
    fact[1] = 1;
    for(lli i = 2; i <= n; i++){
        fact[i] = (fact[i-1] * i);
    }

    der[0] = 1;
    der[1] = 0;
    for(int i=2; i<=N; i++){
        der[i] = ((i-1)*(der[i-1]+der[i-2]));
    }
}
ull mulmod(ull a, ull b, ull mod){
    ull result = 0;
    a%=mod;
    while(b){
        if(b&1) result = (result+a)%mod;
        a = (a+a)%mod;
        b>>=1;
    }
    return result;
}

ull modpow(ull base, ull exp, ull mod){
    ull result = 1;
    base%=mod;
    while(exp){
        if(exp&1) result = mulmod(result, base, mod);
        base = mulmod(base, base, mod);
        exp>>=1;
    }
    return result;
}

ull millerTest(ull n, ull a){
    if(n%a==0) return false;

    ull d = n-1;
    int s = 0;
    while((d&1)==0){
        d>>=1;
        s++;
    }

    ull x = modpow(a, d, n);
    if(x==1 or x==n-1) return true;

    for(int i=1; i<s; i++){
        x = mulmod(x, x, n);
        if(x==n-1) return true;
    }

    return false;
}

bool isPrime(ull n){
    if(n<2) return false;
    if(n<4) return true;
    if(n%2==0) return false;

    ull bases[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};
    for(ull a:bases){
        if(a>=n) break;
        if(!millerTest(n, a)) return false;
    }
    return true;
}
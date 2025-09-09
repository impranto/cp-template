lli N = 5000;

vl isPrime(N+1, 1);

void sieve(){
    isPrime[0] = isPrime[1] = 0;
    for(lli i=2; i*i<=N; i++){
        if(isPrime[i]){
            for(lli j=i*i; j<=N; j+=i){
                isPrime[j] = 0;
            }
        }
    }
}
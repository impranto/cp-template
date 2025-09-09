lli calcCoprime(lli x, lli g, lli k){
    lli xPrime = x/g;
    lli limit = k/g;

    vl primes;
    lli temp = xPrime;

    for(int i=2; i*i<=temp; i++){
        if(temp%i==0){
            primes.push_back(i);
            while(temp%i==0) temp/=i;
        }
    }

    if(temp>1) primes.push_back(temp);

    lli size = primes.size();
    lli non = 0;

    for(int i=1; i<(1<<size); i++){
        lli lcm = 1;
        lli bits = 0;
        for(int j=0; j<size; j++){
            if(i&(1<<j)){
                bits++;
                lcm*=primes[j];
                if(lcm>limit) break;
            }
        }

        if(lcm>limit) continue;

        lli cnt = limit/lcm;
        if(bits%2==1) non+=cnt;
        else non-=cnt;
    }

    return limit - non;
}
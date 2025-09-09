const lli N = 10005;
vector<ld> logFact(N);

void pre(){
    logFact[0] = 0.0;
    for(int i=1; i<N; i++){
        logFact[i] = logFact[i-1] + log(i);
    }
}
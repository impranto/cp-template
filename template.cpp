#include<bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "debug.h"
#else 
#define dbg(x...)
#endif

#define lli long long 
#define ld long double
#define vl vector<lli>
#define vpi vector<pair<int, int>>
#define vpl vector<pair<lli, lli>>
#define vi vector<int>
#define vvl vector<vector<lli>>
#define vvi vector<vector<int>>
#define ml map<lli, lli>
#define sl set<lli>
#define ff first
#define ss second
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define maxA(a) *max_element(all(a))
#define minA(a) *min_element(all(a))
#define asort(a) sort(all(a))
#define dsort(a) sort(all(a), greater<lli>())
#define endl "\n"
#define line cout << "\n";
#define print(a) cout << a << endl
#define take(a) cin >> a
#define err(a) cerr << a << endl

#define MOD 1000000007
#define PI acos(-1)
#define EPS 1e-9
#define inf 1e18
#define MAX LLONG_MAX
#define MIN LLONG_MIN





void solve(){
    
}

void file(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE
        file();
    #endif

    int _t = 1;
    cin >> _t;

    for(int i=1; i<=_t; i++){
        // cout << "Case " << i << ": ";
        solve();
    }
}
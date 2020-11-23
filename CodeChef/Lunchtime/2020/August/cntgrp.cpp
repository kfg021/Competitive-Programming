/*
During the contest, I only managed to solve subtask 1, where m = n-1.
This solution, however, works for both subtasks.

Let's first count the number of possible trees. We can store a frequency
array that counts the number of times we see each distance. Notice that
all nodes a distance l away from the root must be connected to a exactly one
node that is l-1 away. This is in order to satisfy the uniquness constraint
in the problem. We can determine the number of possible connections between nodes
of distance l and distance l-1 with the formula freq[l-1] ^ freq[l], where freq is
the freqency array. We multiply all of these together to get the total number of
trees. Notice that if freq[l] is ever 0, our total answer will be 0. 

We might still have some edges left at this point; m-(n-1) of them to be exact. We can
only use these edges to connect nodes of the same distance. Therefore, the number of
possible edges is sum(i=0, max_distance)(freq[i] choose 2).

Our final answer will be ( number_of_trees * (possible_edges choose m-(n-1)) ) % (10^9 + 7).

Implementation details: (a ^ b) % MOD can be calculated with with binary exponentiation,
and (a choose b) % MOD can be calculated with modulo inverses.
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define F first
#define S second

const int MOD = 1e9+7;
inline int add(int a, int b){ return (a+b)%MOD; }
inline int sub(int a, int b){ return ((a-b)%MOD + MOD)%MOD; }
inline int mul(int a, int b){ return ((ll)a*b)%MOD; }
int pwr(int a, int b){
    if(!b) return 1;
    int temp = pwr(a, b/2);
    if(b%2) return mul(mul(temp, temp), a);
    return mul(temp, temp);
}
inline int dvd(int a, int b){ return mul(a, pwr(b, MOD-2)); }
int choose(int n, int k){
    if(k > n) return 0;
    if(k*2 > n) k = n-k;
    if(!k) return 1;

    int ans = n;
    for(int i = 2; i <= k; ++i){
        ans = mul(ans, (n-i+1));
        ans = dvd(ans, i);
    }
    return ans;
}

void solve(){
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for(int i = 0; i < n-1; ++i){
        cin >> a[i];
    }

    map<int, int> freq;
    freq[0] = 1;
    for(int i = 0; i < n-1; ++i){
        ++freq[a[i]];
    }

    int mx = (--freq.end())->F;
    for(int i = 0; i <= mx; ++i){
        if(!freq[i]){
            cout << "0\n";
            return;
        }
    }

    int numtrees = 1;
    for(int i = 1; i <= mx; ++i){
        numtrees = mul(numtrees, pwr(freq[i-1], freq[i]));
    }

    int extra = m-(n-1);
    int sideedges = 0;
    for(int i = 0; i <= mx; ++i){
        sideedges = add(sideedges, choose(freq[i], 2));
    }

    int ans = mul(numtrees, choose(sideedges, extra));
    cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T; cin >> T;
    for(int i = 0; i < T; ++i){
        solve();
    }
    return 0;
}

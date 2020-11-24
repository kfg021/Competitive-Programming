/*
The goal of this problem is to find a set of K numbers with LCM X and minimum
sum. In order to do this, we need to distribute the prime factors of X into K
groups. In order for the LCM to be X, we must put all repeated prime factors in
the same group. In the worst case, there can only be 7 distinct primes
(2*3*5*7*11*13*17*19 > 10^6), so we can generate all possible groupings and
pick the one with minimal sum.
*/

#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second

void gengroups(vector<int>& aval, vector<int>& groups, set<set<int>>& finished){
    int numgroups = groups.size();
    int s = aval.size();
    if(s==0){
        bool ok = true;
        for(int i : groups){
            if(i==1){
                ok=false;
            }
        }
        if(ok){
            finished.insert(set<int>(groups.begin(), groups.end()));
        }
        return;
    }

    int first = aval.back();
    aval.pop_back();
    for(int j = 0; j < numgroups; ++j){
        groups[j] *= first;
        gengroups(aval, groups, finished);
        groups[j] /= first;
    }
    aval.push_back(first);
}

void solve(){
    int k, x;
    cin >> k >> x;

    map<int,int> primes;
    int n = x;
    for(int i = 2; i*i <= x; ++i){
        while(n%i == 0){
            ++primes[i];
            n /= i;
        }
    }
    if(n > 1){
        ++primes[n];
    }

    vector<int> nums;
    for(auto a : primes){
        int p = a.F, num = a.S;
        int prod = 1;
        for(int i = 0; i < num; ++i){
            prod *= p;
        }
        nums.push_back(prod);
    }
    int s = nums.size();

    int ans = 1e9;
    int numgroups = min(k, s);
    vector<int> groups(numgroups, 1);
    set<set<int>> finished;
    gengroups(nums, groups, finished);
    for(auto a : finished){
        int sum = 0;
        for(auto l : a){
            sum += l;
        }
        if(numgroups < k){
            sum += k-numgroups;
        }
        ans = min(ans, sum);
    }
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
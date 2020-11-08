/* 
Iterate over all possible subsets of the digits of number n. Call a subset
valid if its sum is divisible by 3. Take the largest valid subset as the
answer. Since n has at most 18 digits, there are only 2^18 subsets at maximum.
*/

#include <bits/stdc++.h> 
using namespace std;

void solve(){
    string s;
    cin >> s;
    int n = s.size();

    int best = -1;
    for(int i = 0; i < (1<<n); ++i){
        int sum = 0;
        int amt = 0;
        for(int j = 0; j < n; ++j){
            if((i>>j) & 1){
                sum += s[j]-'0';
                ++amt;
            }
        }
        if(sum%3==0){
            best = max(best, amt);
        }
    }

    if(best==0){
        cout << "-1\n";
    }
    else{
        cout << n-best << "\n";
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}
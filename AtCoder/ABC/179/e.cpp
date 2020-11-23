/*
By the pigeonhole principle, there can be at most m distinct values of
a. After this, the sequence must begin a cycle. We first calculate the
first few terms of the sum. After this, we figure out how long the cycle
is, and how many times it will repeat. We calculate the final answer
from this information.
*/

#include <bits/stdc++.h> 
using namespace std;
using ll = long long;

void solve(){
    ll n;
    int x, m;
    cin >> n >> x >> m;

    vector<int> order;
    order.push_back(x);
    vector<bool> seen(m, false);

    for(int i = 0; i < n-1; ++i){
        int next = ((ll)order.back()*order.back())%m;

        if(!seen[next]){
            seen[next] = true;
            order.push_back(next);
        }
        else{
            int s = order.size();
            int j = s-1;
            while(order[j] != next) --j;

            vector<int> front, loop;
            for(int k = 0; k < j; ++k){
                front.push_back(order[k]);
            }
            ll loopsum = 0;
            for(int k = j; k < s; ++k){
                loop.push_back(order[k]);
                loopsum += order[k];
            }

            ll sum = 0;
            for(int j : front) sum += j;

            ll left = n-(int)front.size();

            sum += (left/(int)loop.size()) * loopsum;

            int mod = (int)(left%(int)loop.size());

            for(int j = 0; j < mod; ++j){
                sum += loop[j];
            }

            cout << sum << "\n";
            return;
        }
    }

    ll sum = 0;
    for(int i : order){
        sum += i;
    }
    cout << sum << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}
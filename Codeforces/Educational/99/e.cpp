/*
Consider the case where the size of the square is 0. In this case, it is
simply a point. We can minimize the distance by placing the square at the
median positions of both x and y.

We can emulate this same idea with a square of size s by subtracting the vectors
([0, 0], [s, 0], [s, s], [0, s]) from the points (a, b, c, d) and doing the same
process.

The one issue is that we need to consider how to map the points (a, b, c, d)
to the corners of the square. Since there are only 4! = 24 possible pairings,
we can try them all and take the minimum.

Let f(s) = the minimum answer for a square of size s. It can be proven that f(s)
is a convex function. Because of this, we can ternary serach the minimum value of s
for the answer.

Note:
This problem is similar to Rugby (Problem C on Google Kick Start Round H 2020).
https://codingcompetitions.withgoogle.com/kickstart/round/000000000019ff49/000000000043b027
*/

#include <bits/stdc++.h> 
using namespace std;
using ll = long long;
template<typename T> using v2 = vector<vector<T>>;
template<typename T> inline v2<T> fill(int r, int c, const T& t){
    return v2<T>(r, vector<T>(c, t));
}

v2<int> permutations(const vector<int>& v){
    int s = v.size();
    if(s==0) return {{}};
    
    v2<int> ans;
    for(int i = 0; i < s; ++i){
        vector<int> next = {};
        for(int j = 0; j < s; ++j){
            if(i==j) continue;
            next.push_back(v[j]);
        }
        for(vector<int>& perm : permutations(next)){
            perm.insert(perm.begin(), v[i]);
            ans.push_back(perm);
        }
    }
    return ans;
}

const v2<int> perms = permutations({0,1,2,3});
int x[4], y[4];

ll dist(int s){
    int deltas[4][2] = {{0,0}, {-s,0}, {-s,-s}, {0,-s}};
    ll ans = 1e18;

    int my_x[4], my_y[4];
    for(auto& perm : perms){
        for(int i = 0; i < 4; ++i){
            my_x[i] = x[i] + deltas[perm[i]][0];
            my_y[i] = y[i] + deltas[perm[i]][1];
        }

        sort(my_x, my_x+4);
        sort(my_y, my_y+4);

        ll my_ans = 0;
        for(int i : my_x){
            my_ans += abs(i-my_x[1]);
        }
        for(int i : my_y){
            my_ans += abs(i-my_y[1]);
        }
        ans = min(ans, my_ans);
    }

    return ans;
}

void solve(){
    for(int i = 0; i < 4; ++i){
        cin >> x[i] >> y[i];
    }

    int lo = 0;
    int hi = 1e9+100;
    ll ans = 1e18;
    while(lo <= hi){
        int mid = (lo+hi)/2;

        ll dm = dist(mid);
        ans = min(ans, dm);
        ll diff = dist(mid+1)-dm;
        if(diff > 0){
            hi = mid-1;
        }
        else if(diff==0){
            break;
        }
        else{
            lo = mid+1;
        }
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
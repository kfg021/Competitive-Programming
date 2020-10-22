/*
First, lets consider all possible ways to split the group into equal sized
subsets. There are n choose n/2 to do that. Next, we can permute each one of
these groups in any way, so we will need to multiply the answer by (n/2)! ^ 2.
However, not all permutations are valid. Namely, for each permutation, there
are n/2 cyclic shifts that are equivalent to it, so we need to divide the
answer by (n/2)^2. Lastly, we have overcounted by a factor of 2 because we
don't care about the order of the two round dances ([1,2], [3,4] is the same
as [3,4], [1,2]).

The final formula is f(n) = 1/2 * (n choose n/2) * ((n/2)! / (n/2))^2.
*/

#include <bits/stdc++.h> 
using namespace std;
using ll = long long;

ll fact(int a){
    ll ans = 1;
    for(int i = 1; i <= a; ++i){
        ans *= i;
    }
    return ans;
}

ll ch(int a, int b){
    return fact(a)/(fact(b) * fact(a-b));
}

void solve(){
    int n;
    cin >> n;

    ll x = (fact(n/2)*2)/n;
    ll ans = (ch(n, n/2) * x*x) / 2;
    cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}
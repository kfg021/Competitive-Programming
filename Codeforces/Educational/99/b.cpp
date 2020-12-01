/*
First, consider only using jumps of type 1. We can find the first a such that
1 + 2 + 3 + ... + a >= x. Define b to be this value. If b = x, then the answer
is a.

Otherwise, b > x. Let c = b - x. We know that c must be < a. 
We can replace one of the numbers in b with -1. If we replace some d with -1,
it will subtract d+1 from the answer.

We will need a operations when c >= 2. However, when c = 1, we will
need a+1 operations, since we will have to add -1 as the first operation
(there is no "jump 0" to replace).
*/

#include <bits/stdc++.h> 
using namespace std;

void solve(){
    int x;
    cin >> x;

    int i;
    int score = 0;
    for(i = 1; score < x; ++i){
        score += i;
    }
    --i;

    if(x+1==score){
        cout << i+1 << "\n";
    }
    else{
        cout << i << "\n";
    }
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
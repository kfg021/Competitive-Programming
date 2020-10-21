/*
The key observation is that we can use 1's to create seperate "clauses".
For example to make x+y, we can use the array [x+2, x+1, 1, y+2, y+1].
Pick some divisior div. We can represent d as floor(d/div)*div + d%div.
let q = floor(d/div) and let r = d%div.

For the first part, we can use the array [q+2] + [q+1, ... , q+1] (div times).
(using + to represent array concatenation)

For the second part, we can use the array [r+2, r+1].

We will simply combine these two arrays with a 1 for the final answer.
Make sure to choose a div near 10^5 as to make sure that the number of
elements is small enough.
*/

#include <bits/stdc++.h>
using namespace std;

void solve(){
    int d;
    cin >> d;

    if(d==0){
        cout << "1\n1\n";
        return;
    }

    vector<int> ans;
    const int DIV = 1e5-5;
    int q = d/DIV;
    int r = d%DIV;

    ans.push_back(DIV+2);
    for(int i = 0; i < q; ++i){
        ans.push_back(DIV+1);
    }

    ans.push_back(1);

    ans.push_back(r+2);
    ans.push_back(r+1);

    int s = ans.size();
    assert(s <= 1e5);
    cout << s << "\n";
    for(int i : ans){
        cout << i << " ";
    }
    cout << "\n";
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

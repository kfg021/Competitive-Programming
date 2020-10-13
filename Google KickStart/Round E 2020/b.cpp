/*
Lets redefine a to be a-c, and b to be b-c. This way, a and b represent the
number of buildings which can be ONLY seen from the left and right sides,
respectivley. If a+b+c > n, the answer must be IMPOSSIBLE, since that
would imply the total number of buildings is greater than n.
If not, we will try to construct the answer. The number of buildings
which can't be seen from either side is equal to n-(a+b+c). We will
try to "hide" these buildings between some of the taller buildings.
If we cannot do this, the answer will be IMPOSSIBLE.
*/

#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n, a, b, c;
    cin >> n >> a >> b >> c;
    
    a-=c; b-=c;
    if(a+b+c > n){
        cout << "IMPOSSIBLE\n";
    }
    else{
        int ext = n-(a+b+c);
        bool good = false;
        if(ext==0) good = true;
        vector<int> ans;
        for(int i = 0; i < a; ++i) ans.push_back(n-1);
        if(a>0){
            good = true;
            for(int i = 0; i < ext; ++i) ans.push_back(1);
        }
        if(c>=2&&!good){
            good = true;
            ans.push_back(n);
            for(int i = 0; i < ext; ++i) ans.push_back(1);
            for(int i = 1; i < c; ++i) ans.push_back(n);
        }
        else{
            for(int i = 0; i < c; ++i) ans.push_back(n);
        }
        if(b>0&&!good){
            good = true;
            for(int i = 0; i < ext; ++i) ans.push_back(1);
        }
        for(int i = 0; i < b; ++i) ans.push_back(n-1);

        if(!good) cout << "IMPOSSIBLE\n";
        else{
            for(int i : ans) cout << i << " ";
            cout << '\n';
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T; cin >> T;
    for(int i = 1; i <= T; ++i){
        cout << "Case #" << i << ": ";
        solve();
    }
    return 0;
}

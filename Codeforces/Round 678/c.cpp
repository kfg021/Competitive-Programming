/*
When doing binary search, we only check a subset of the elements.
Let's simulate binary search to determine which elements we will
encounter on our way to index p. Let L be the list of such indicies. In 
order for us to end up at the right position, all indicies in L greater than
p must have values greater than x, and all indicies less than p must have
values less than x. We can use some basic combinatorics to determine the
number of ways this can occur (note that it may be impossible, in which case
the answer will be 0). We can permute the remaining elements however we wish,
so we multiply the answer by (n-len(L))! .
*/

#include <bits/stdc++.h> 
using namespace std;
using ll = long long;

const int MOD = 1e9+7;
inline int add(int a, int b){ return (a+b)%MOD; }
inline int sub(int a, int b){ return ((a-b)%MOD + MOD)%MOD; }
inline int mul(int a, int b){ return ((ll)a*b)%MOD; }

int fact(int n){
    int ans = 1;
    for(int i = 2; i <= n; ++i){
        ans = mul(ans, i);
    }
    return ans;
}

vector<int> search(int n, int p){
    int left = 0;
    int right = n;
    vector<int> seen;
    while(left < right){
        int mid = (left+right)/2;
        seen.push_back(mid);
        if(mid <= p){
            left = mid+1;
        }
        else{
            right = mid;
        }
    }
    return seen;
}

void solve(){
    int n, x, p;
    cin >> n >> x >> p;

    vector<int> seen = search(n, p);

    int less = x-1;
    int more = n-x;

    int ans = 1;
    for(int i : seen){
        if(i > p){
            ans = mul(ans, more);
            --more;
        }
        else if(i < p){
            ans = mul(ans, less);
            --less;
        }
    }

    ans = mul(ans, fact(n-(int)seen.size()));
    cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}
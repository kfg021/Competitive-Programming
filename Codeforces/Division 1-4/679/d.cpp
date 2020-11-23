/*
Consider the elements from least to greatest, since we know that the smallest
element must be taken immediately after it is added to the shop. We determine
the latest add operation which occurs before this element was removed. If
there have been any elements added between these two times, the answer must
be NO, since that would imply we took a greater element before a smaller
element. If not, repeat this process with the remaining elements.
*/

#include <bits/stdc++.h> 
using namespace std;
#define F first
#define S second

void solve(){
    int n;
    cin >> n;
    set<int> plus, elems;
    vector<int> pos(n);
    for(int i = 0; i < 2*n; ++i){
        char c;
        cin >> c;
        if(c=='+'){
            plus.insert(i);
        }
        else{
            int d;
            cin >> d;
            --d;
            pos[d] = i;
            elems.insert(i);
        }
    }

    vector<pair<int, int>> loc;
    for(int i = 0; i < n; ++i){
        elems.erase(elems.find(pos[i]));

        //find last plus less than pos[i]
        auto it = plus.upper_bound(pos[i]);
        if(it == plus.begin()){
            cout << "NO\n";
            return;
        }
        --it;

        //if there are elements btwn pos[i] and the last, BAD
        int lb = *it;
        int ub = pos[i];
        bool btwn = elems.lower_bound(lb) != elems.upper_bound(ub);
        if(btwn){
            cout << "NO\n";
            return;
        }

        loc.push_back({lb, i});
        plus.erase(plus.find(lb));
    }

    sort(loc.begin(), loc.end());
    cout << "YES\n";
    for(auto& i : loc){
        cout << i.S+1 << " ";
    }
    cout << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}
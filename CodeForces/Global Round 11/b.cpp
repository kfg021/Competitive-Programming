/*
This problem can be solved with a greedy approach. Let's define a "gap" to be a
streak of one or greater consecutive Ls between two Ws. It turns out it is
sufficient to repeatedly add Ws to the ends of one of the streaks with minimum 
size. We can perform this operation efficently with a priority queue. After this is
done, if we still have some letters we need to flip, we can use them on the Ls not 
part of any gap (meaning they are on the ends of the string).
*/

#include <bits/stdc++.h> 
using namespace std;
#define F first
#define S second
 
void solve(){
    int n,k;
    string s;
    cin >> n >> k >> s;
 
    using P = pair<int, pair<int, int>>;
    priority_queue<P, vector<P>, greater<P>> pq;
 
    int lastwin = -1;
    for(int i = 0; i < n; ++i){
        if(s[i]=='W'){
            if(lastwin!=-1){
                if(lastwin != i-1){
                    pq.push({i-lastwin-1, {lastwin+1, i-1}});
                }
                lastwin = i;
            }
            else{
                lastwin = i;
            }
        }
    }
 
    int fixed = 0;
    while(fixed < k && !pq.empty()){
        P top = pq.top();
        pq.pop();
        if(top.F>0){
            s[top.S.F] = 'W';
            ++fixed;
            pq.push({top.F-1, {top.S.F+1, top.S.S}});
        }
    }
 
    for(int i = lastwin; i < n; ++i){
        if(fixed<k && s[i]=='L'){
            s[i] = 'W';
            ++fixed;
        }
    }
    for(int i = lastwin-1; i>=0; --i){
        if(fixed<k && s[i]=='L'){
            s[i] = 'W';
            ++fixed;
        }
    }
 
    int ans = 0;
    for(int i = 0; i < n; ++i){
        if(s[i]=='W'){
            if(i-1 >= 0 && s[i-1]=='W'){
                ans += 2;
            }
            else{
                ans += 1;
            }
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
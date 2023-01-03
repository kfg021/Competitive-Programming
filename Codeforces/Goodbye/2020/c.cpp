/*
All palindromes of length greater than 3 must contain a palindrome of
length 2 of 3, so this problem is equivalent to removing all palindromes
of lengths 2 and 3. We can use a greedy approach where we move through
the string from left to right, changing the rightmost character in each
length 2 or 3 palindrome we encounter.
*/

#include <bits/stdc++.h> 
using namespace std;

void solve(){
    string s;
    cin >> s;
    int n = s.size();

    set<int> seen;

    for(int i = 0; i < n; ++i){
        if(i < n-1 && s[i] == s[i+1]){
            if(!seen.count(i) && !seen.count(i+1)){
                seen.insert(i+1);
            }
        }

        if(i < n-2 && s[i] == s[i+2]){
            if(!seen.count(i) && !seen.count(i+2)){
                seen.insert(i+2);
            }
        }
    }

    cout << seen.size() << "\n";
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
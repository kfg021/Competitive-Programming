/*
We can solve this problem with a stack. Maintain the current index of "fox"
that we are looking at. If we hit an 'f' (first letter of fox) push that onto
the stack and reset the index. If we ever make it to the end of the word, pop
the letters off the stack and add 3 to the score. If we ever hit an invalid
letter, remove everything from the stack.
The answer will be n - score.
*/

#include <bits/stdc++.h> 
using namespace std;

void solve(){
    int n;
    string s;
    cin >> n >> s;

    int ans = 0;
    int ind = 0;
    string word = "fox";
    stack<int> st;
    for(int i = 0; i < n; ++i){
        if(s[i] != word[ind]){
            ind = 0;
            if(s[i] == word[0]){
                st.push(ind);
                ++ind;
            }
            else{
                while(!st.empty()){
                    st.pop();
                }
            }
        }
        else{
            st.push(ind);
            ++ind;
            if(ind==(int)word.size()){
                while(ind){
                    st.pop();
                    ++ans;
                    --ind;
                }
                if(!st.empty()){
                    ind = st.top()+1; 
                }
            }
        }
    }

    cout << n-ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}
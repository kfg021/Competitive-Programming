/*
Two points, (a, b) and (c, d) will have a slope between -1 and 1 if
abs(d-b) <= abs(c-a). Loop through all points and add to the answer.
*/

#include <bits/stdc++.h> 
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> x(n), y(n);
    for(int i = 0; i < n; ++i){
        cin >> x[i] >> y[i];
    }

    int ans = 0;
    for(int i = 0; i < n; ++i){
        for(int j = i+1; j < n; ++j){
            if(abs(y[i]-y[j]) <= abs(x[i]-x[j])){
                ++ans;
            }
        }
    }
    cout << ans << "\n";

    return 0;
}
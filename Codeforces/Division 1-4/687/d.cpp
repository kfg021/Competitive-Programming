/*
An important observation is that if we have three numbers with the same
most signifigant bit, the answer will be 1. We can do the operation on
the two greater numbers and end up with a number without this bit set.

Since the numbers are only up to 10^9, each number has 30 bits. Due to the
pigeonhole principle, if we have more than 60 numbers, there must be a
triple of numbers with the same most signifigant bit, making the answer 1.

Otherwise, we can assume n <= 60. We can use an O(n^3) brute force algorithm.
We iterate over:
    The number of operations to preform
    The position in the array
    How many elements we should remove to the left of this position, and how
    many to the right.

We can check whether the condition is satisfied (xor of left range is greater
than xor of right range) in constant time using prefix arrays. (Likely, a O(n^4) solution
without prefix arrays would also pass).
*/

#include <bits/stdc++.h> 
using namespace std;

void solve(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }

    if(n > 60){
        cout << "1\n";
        return;
    }

    vector<int> pref(n);
    pref[0] = a[0];
    for(int i = 1; i < n; ++i){
        pref[i] = a[i] ^ pref[i-1];
    }

    for(int operations = 1; operations < n-1; ++operations){
        int rangesize = operations+2;
        for(int i = 0; i < n; ++i){
            for(int left = 1; left < rangesize; ++left){
                int right = rangesize-left;
                if(left > i+1 || right > n-1-i) continue;

                int xorl = pref[i] ^ (i-left >= 0 ? pref[i-left] : 0) ;
                int xorr = pref[i+right] ^ pref[i];
                if(xorl > xorr){      
                    cout << operations << "\n";
                    return;
                }
            }
        }
    }

    cout << "-1\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}
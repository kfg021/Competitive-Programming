/*
The answer will be one of {0, 1, 2, 3}. If the two squares are the same,
the answer is 0. If the second square can be reached using the rules
described in the statement, then the answer is 1. The answer is 2
if the two squares have the same parity (x1+y1) = (x2+y2) (mod 2),
or the second square is sufficiently close to a diagonal passing
through the first square (a manhattan distance of at most 3 away).
Otherwise, the answer is 3.
*/

#include <bits/stdc++.h> 
using namespace std;

bool inrange(int a, int b, int c, int d){
   return (a+b == c+d) || (a-b == c-d) || (abs(a-c)+abs(b-d) <= 3);
}

void solve(){
    int a,b,c,d;
    cin>>a>>b>>c>>d;

    if(a==c && b==d){
        cout << "0\n";
    }
    else if(inrange(a,b,c,d)){
        cout << "1\n";
    }
    else if((a+b)%2 == (c+d)%2){
        cout << "2\n";
    }
    else{
        for(int i = -3; i <= 3; ++i){
            for(int j = -3; j <= 3; ++j){
                if(abs(i)+abs(j) > 3) continue;
                int x = c+i, y = d+j;
                if(inrange(a, b, x, y)){
                    cout << "2\n";
                    return;
                }
            }
        }

        cout << "3\n";
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}
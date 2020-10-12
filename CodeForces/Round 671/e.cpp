/*
I really enjoyed this problem!

If n is the product of 2 primes, the answer is 1.
This is because thses two primes are forced to be ajdacent, meaning that
we have to add their lcm between them.

If n has only two prime factors but at least one is repeated, the answer
is 0. Let p and q be the two factors. We know that pq is a factor of n,
and is less than n (since either p or q is a repeated factor). 
Therefore, our circle will look like [p, p*q, q, n]. 
We might have extra factors of p or q to insert, and we can just put
them next to p or q, respectivley.

If n has three or more factors, the answer is 0. Let {p1, p2, ... pk}
represent the prime factors of n. We start by placing the primes
in the circle: [p1, p2, ... pk]. We then insert the products of adjacent
primes: [p1, p1p2, p2, p2p3, ... pk, pkp1]. These all must be factors
of n and all must be unique. After this, we might have extra factors left.
These extra factors must be divisible by at least one of the primes in our
circle. We place each extra factor next to one of those primes.
*/

#include <bits/stdc++.h> 
using namespace std;
using ll = long long;
template<typename T> using v2 = vector<vector<T>>;
template<typename T> inline v2<T> fill(int r, int c, const T& t){ return v2<T>(r, vector<T>(c, t)); }

void solve(){
    int n;
    cin >> n;
    int t = n;

    vector<int> pf;
    if(t%2==0) pf.push_back(2);
    while(t%2==0){
        t/=2;
    }
    for(int i = 3; i*i <= t; i+=2){
        if(t%i==0) pf.push_back(i);
        while(t%i==0){
            t/=i;
        }
    }
    if(t>2) pf.push_back(t);

    set<int> factors;
    for(int i = 2; i*i <= n; ++i){
        if(n%i==0){
            factors.insert(i);
            factors.insert(n/i);
        }
    }
    factors.insert(n);

    int s = pf.size();
    if(s > 2){
        vector<int> trans(s);
        for(int i = 0; i < s-1; ++i){
            trans[i] = pf[i]*pf[i+1];
            factors.erase(factors.find(pf[i]*pf[i+1]));
        }
        trans[s-1] = pf[s-1]*pf[0];
        factors.erase(factors.find(pf[s-1]*pf[0]));

        v2<int> divis(s);
        for(int i : factors){
            for(int j = 0; j < s; ++j){
                if(i%pf[j]==0){
                    divis[j].push_back(i);
                    break;
                }
            }
        }

        for(int i = 0; i < s; ++i){
            for(int j : divis[i]){
                cout << j << " ";
            }
            cout << trans[i] << " ";
        }
        cout << "\n";
        cout << "0\n";
    }
    else{
        if(s==1){
            for(int i : factors) cout << i << " ";
            cout << "\n";
            cout << "0\n";
        }
        else if(pf[0]*pf[1] == n){
            cout << pf[0] << " " << n << " " << pf[1] << "\n";
            cout << "1\n";
        }
        else{
            vector<int> trans(s);
            for(int i = 0; i < s-1; ++i){
                trans[i] = pf[i]*pf[i+1];
                factors.erase(factors.find(pf[i]*pf[i+1]));
            }
            trans[s-1] = n;
            factors.erase(n);

            v2<int> divis(s);
            for(int i : factors){
                for(int j = 0; j < s; ++j){
                    if(i%pf[j]==0){
                        divis[j].push_back(i);
                        break;
                    }
                }
            }

            for(int i = 0; i < s; ++i){
                for(int j : divis[i]){
                    cout << j << " ";
                }
                cout << trans[i] << " ";
            }
            cout << "\n";
            cout << "0\n";
            }
        }
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
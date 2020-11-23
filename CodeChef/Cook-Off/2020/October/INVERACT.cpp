/*
I had a solution idea during the contest, but not enough time to implement
the details.

The main idea for this problem is to use binary search. First, let's binary
search the largest element in the sequence by preforming operations at the end
of the array (k = n+1). From this answer, we can also determine how many
elements of this size exist. For each if these elements, we can do another 
binary search to determine where each one must lie. We can repeat this process
for the 2nd largest elements, the 3rd largest elements, and so on.
We might run out of queries with this approach, so we can save answers for
queries we have already computed with a map, as to not recompute answers.

Implementation details are a bit complicated, but this is the general idea.
*/

#include <bits/stdc++.h>
using namespace std;

map<pair<int, int>, int> m;
int qs;

int query(int k, int x){
    ++k;
    
    if(m.count({k,x})){
        return m[{k,x}];
    }

    ++qs;
    assert(qs<=2222);

    cout << "? " << k << " " << x << endl;
    int q;
    cin >> q;
    return m[{k,x}] = q;
}

void solve(){
    m.clear();
    qs = 0;

    int n;
    cin >> n;

    int invs = query(0, 1);

    vector<int> a(n, -1);
    int found = 0;
    int possible = 1e6;

    while(found < n){
        int hi = 1e6;
        int lo = 1;
        int largest = -1;
        while(lo <= hi){
            int mid = (lo+hi)/2;
            if(mid > possible){
                hi = mid-1;
                continue;
            }
            int q = query(n, mid);
            if(q - invs - found == 0){
                largest = mid;
                hi = mid-1;
            }
            else{
                lo = mid+1;
            }
        }

        if(largest == 1){
            for(int i = 0; i < n; ++i){
                if(a[i] == -1){
                    a[i] = 1;
                }
            }
            break;
        }

        int freq = query(n, largest-1) - invs - found;

        for(int t = 0; t < freq; ++t){
            int lo = 0;
            int hi = n;
            int loc = -1;

            while(lo <= hi){
                int mid = (lo+hi)/2;
                int bigleft = 0;
                int smallright = 0;
                for(int i = 0; i < mid; ++i){
                    if(a[i] > largest) ++bigleft;
                }
                for(int i = mid; i < n; ++i){
                    if(a[i] < largest) ++smallright;
                }

                int q = query(mid, largest);
                if(q - invs - bigleft == smallright){
                    hi = mid-1;
                    loc = mid;
                }
                else{
                    lo = mid+1;
                }
            }

            --loc;
            a[loc] = largest;
            ++found;
        }

        possible = largest-1;
    }

    cout << "! ";
    for(int i : a){
        cout << i << " ";
    }
    cout << endl;
}

int main(){
    int T;
    cin >> T;
    for(int i = 0; i < T; ++i){
        solve();
    }
    return 0;
}

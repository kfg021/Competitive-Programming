/*
My solution for this problem is very implementation heavy and has a lot of case work,
so I will gloss over some of the details. Basically the idea is use each operation to place
one element in its correct relative position. Since there are n elements in the array,
this will require at most n-1 steps (since the first element doesn't need to be moved). 
After this is done, the array will be sorted, but possibly in reverse order.
In that case, we will use our leftover operation to flip the array.
*/

#include <bits/stdc++.h> 
using namespace std;
template<typename T> using v2 = vector<vector<T>>;
template<typename T> inline v2<T> fill(int r, int c, const T& t){ return v2<T>(r, vector<T>(c, t)); }
#define F first
#define S second

vector<int> a, loc;
v2<int> ans;

void operation(vector<int>& g){
    v2<int> v;
    int i = 0;
    for(int l : g){
        vector<int> add;
        for(int j = i; j < i+l; ++j){
            add.push_back(a[j]);
        }
        v.push_back(add);
        i += l;
    }

    vector<int> next;
    reverse(v.begin(), v.end());
    for(auto& a : v){
        for(int i : a){
            next.push_back(i);
        }
    }
    a = next;

    ans.push_back(g);
}

void add(int x, vector<int>& g){
    assert(x>=0);
    if(x>0) g.push_back(x);
}

void solve(){
    int n;
    cin >> n;
    a = vector<int>(n), loc = vector<int>(n);
    for(int i = 0; i < n; ++i){
        cin >> a[i];
        --a[i];
        loc[a[i]] = i;
    }

    int front=loc[0], back=loc[0];
    for(int t = 1; t < n; ++t){
        int next = loc[t];
        if(front<=back){
            //fowards
            if(next!=back+1){
                if(next < front){
                    //before
                    vector<int> g;
                    add(next, g);
                    add(front-next, g);
                    add(back-front+1, g);
                    add(n-1-back, g);
                    operation(g);
                }
                else{
                    //after
                    vector<int> g;
                    add(front, g);
                    for(int i = front; i <= back; ++i){
                        add(1, g);
                    }
                    add(next-back, g);
                    add(n-1-next, g);
                    operation(g);
                }
            }
        }
        else{
            //backwards
            if(next != front-1){
                if(next < back){
                    //before
                    vector<int> g;
                    add(next, g);
                    add(back-next, g);
                    for(int i = back; i <= front; ++i){
                        add(1, g);
                    }
                    add(n-1-front, g);
                    operation(g);
                    }
                else{
                    //after
                    vector<int> g;
                    add(back, g);
                    add(front-back+1, g);
                    add(next-front, g);
                    add(n-1-next, g);
                    operation(g);
                }
            }
        }

        //update loc vector
        for(int i = 0; i < n; ++i){
            loc[a[i]] = i;
        }

        front = loc[0];
        back = loc[t];
    }

    if(front!=0){
        vector<int> g(n, 1);
        operation(g);
    }

    int s = ans.size();
    assert(s<=n);
    cout << s << "\n";
    for(auto v : ans){
        cout << (int)v.size() << " ";
        for(int i : v) cout << i << " ";
        cout << "\n";
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}
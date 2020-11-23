/*
During the contest, I only managed to solve test set 1, where s = 2.
This code, however, works for both test sets.

Because of the small constraints (s <= 6 in test set 2), a brute force
solution seems likely. The state of the game can be represented by the
avalible rooms, the positions of the two players, whose turn it
is, and the score of the game. We use a recursive algorithm to determine
the best possible move in the current board state (the greatest possible
score if it is player 1's turn, and the smallest possible score if it is
player 2's turn).
*/

#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second

using P = pair<int, int>;

map<P, vector<P>> nei;

const int INF = 1e9;

void calcnei(int s){
    nei.clear();

    for(int i = 0; i < s; ++i){
        for(int j = 0; j < 2*i+1; ++j){
            if(j != 0){
                nei[{i,j}].push_back({i,j-1});
            }
            if(j != 2*i){
                nei[{i,j}].push_back({i,j+1});
            }
            if(j%2==0 && i!=s-1){
                nei[{i,j}].push_back({i+1,j+1});
            }
            if(j%2==1){
                nei[{i,j}].push_back({i-1,j-1});
            }
        }
    }
}

struct state{
    set<P> taken;
    P apos, bpos;
    bool turn;
    int score;
};

int f(state& st){
    // check if game is over
    vector<P> avalA = nei[st.apos];
    vector<P> avalB = nei[st.bpos];
    bool gameover = true;
    for(P& p : avalA){
        if(!st.taken.count(p)) gameover = false;
    }
    for(P& p : avalB){
        if(!st.taken.count(p)) gameover = false;
    }
    if(gameover){
        return st.score;
    }
    
    if(st.turn){
        // check all moves for player 1
        int bestscore = -INF;
        for(P& p : avalA){
            if(!st.taken.count(p)){
                state next = st;
                next.taken.insert(p);
                next.apos = p;
                next.turn = !next.turn;
                ++next.score;
                bestscore = max(bestscore, f(next));
            }
        }

        if(bestscore == -INF){
            state next = st;
            next.turn = !next.turn;
            return f(next);
        }
        else{
            return bestscore;
        }
    }
    else{
        // check all moves for player 2
        int bestscore = INF;
        for(P& p : avalB){
            if(!st.taken.count(p)){
                state next = st;
                next.taken.insert(p);
                next.bpos = p;
                next.turn = !next.turn;
                --next.score;
                bestscore = min(bestscore, f(next));
            }
        }

        if(bestscore == INF){
            state next = st;
            next.turn = !next.turn;
            return f(next);
        }
        else{
            return bestscore;
        }
    }
}

void solve(){
    P a, b;
    int s, c;
    cin >> s >> a.F >> a.S >> b.F >> b.S >> c;
    --a.F, --a.S, --b.F, --b.S;

    calcnei(s);

    state start;
    start.taken.insert(a);
    start.taken.insert(b);
    for(int i = 0; i < c; ++i){
        P con;
        cin >> con.F >> con.S;
        --con.F, --con.S;
        start.taken.insert(con);
    }
    start.apos = a;
    start.bpos = b;
    start.turn = true;
    start.score = 0;

    int ans = f(start);
    cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T; cin >> T;
    for(int i = 1; i <= T; ++i){
        cout << "Case #" << i << ": ";
        solve();
    }
    return 0;
}
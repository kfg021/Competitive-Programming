/*
We will build a graph to represent the grid, starting by connecting all
adjacent squares. However, we cannot connect all, potentially O(n^2),
teleporters of the same letter to each other, as this would be too
slow.

However, we can make a slight modification to the problem:
For each node with a teleporter, we will store two nodes, one for
teleportation and one for normal travel. We connect the normal node
to the teleportation node with a cost of 1, and the teleportation node
to the normal node with a cost of 0. Teleportation nodes are attached to
a spanning tree with all other teleporation nodes of the same letter. These
connections are of cost 0.
All regular connections between adjacent nodes are of cost 1.

Then, just run Dijkstra's algorithm (or a 0-1 BFS) on the modified graph
for the answer.
*/

#include <bits/stdc++.h> 
using namespace std;
#define F first
#define S second

int h, w;

char g[2000][2000];

using Node = array<int,3>;
vector<Node> adj[2000][2000][2];
vector<Node> letters[26];

int d[2000][2000][2];

bool valid(int i, int j){
    return i>=0 && i<h && j>=0 && j<w && g[i][j] != '#';
}

vector<Node>& getadj(Node& node){
    return adj[node[0]][node[1]][node[2]];
}

int& getd(Node& node){
    return d[node[0]][node[1]][node[2]];
}

void solve(){
    cin >> h >> w;
    for(int i = 0; i < h; ++i){
        for(int j = 0; j < w; ++j){
            cin >> g[i][j];
        }
    }

    Node start, end;
    for(int i = 0; i < h; ++i){
        for(int j = 0; j < w; ++j){
            if(g[i][j]>='a' && g[i][j]<='z'){
                adj[i][j][1].push_back({i, j, 0});
                adj[i][j][0].push_back({i, j, 1});

                letters[g[i][j]-'a'].push_back({i, j, 1});
            }

            if(g[i][j]!='#'){
                if(valid(i, j+1)) adj[i][j][0].push_back({i, j+1, 0});
                if(valid(i, j-1)) adj[i][j][0].push_back({i, j-1, 0});
                if(valid(i+1, j)) adj[i][j][0].push_back({i+1, j, 0});
                if(valid(i-1, j)) adj[i][j][0].push_back({i-1, j, 0});
            }

            if(g[i][j]=='S'){
                start = {i, j, 0};
            }

            if(g[i][j]=='G'){
                end = {i, j, 0};
            }
        }
    }

    for(vector<Node>& l : letters){
        int s = l.size();
        for(int i = 0; i < s-1; ++i){
            getadj(l[i]).push_back(l[i+1]);
            getadj(l[i+1]).push_back(l[i]);
        }
    }

    priority_queue<pair<int,Node>, vector<pair<int,Node>>, greater<pair<int,Node>>> pq;
    pq.push({0, start});

    for(int i = 0; i < h; ++i){
        for(int j = 0; j < w; ++j){
            for(int k = 0; k < 2; ++k){
                d[i][j][k] = 1e9;
            }
        }
    }
    getd(start) = 0;

    while(!pq.empty()){
        pair<int,Node> top = pq.top();
        pq.pop();
        int dist = top.F;
        Node& node = top.S;
        if(dist > getd(node)){
            continue;
        }

        for(Node& next : getadj(node)){
            int w;
            if(node[2]){
                w = 0;
            }
            else{
                w = 1;
            }

            int newdist = getd(node) + w;
            if(newdist < getd(next)){
                getd(next) = newdist;
                pq.push({newdist, next});
            }
        }
    }
    
    int ans = getd(end);
    if(ans == 1e9){
        cout << "-1\n";
    }
    else{
        cout << ans << "\n";
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}
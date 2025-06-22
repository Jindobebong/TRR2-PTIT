#include <bits/stdc++.h>
#define ll long long
#define maxn 105
#define endl "\n"
using namespace std;

int n, s, a[maxn][maxn];
vector<pair<int, int>>adj[maxn];
void nhap(){
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= n; ++j){
            cin >> a[i][j];
            if(a[i][j] != 0 && a[i][j] != 10000){
                adj[i].push_back({j, a[i][j]});
                adj[j].push_back({i, a[i][j]});
            }
        }
    }
}

bool vis[maxn];
vector<vector<int>>res;
int sum;
void prim(int s){
    vis[s] = true;
    while(res.size() < n - 1){
        int min_w = 1000, x, y;
        for(int i = 1; i <= n; ++i){
            if(vis[i]){
                for(auto [v, w] : adj[i]){
                    if(!vis[v]){
                        if(w < min_w){
                            min_w = w; 
                            x = i, y = v;
                        }
                    }
                }
            }
        }
        res.push_back({min(x, y), max(x, y), min_w});
        sum += min_w;
        vis[y] = true;
    }
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    // freopen("CK.INP", "r", stdin);
    // freopen("CK.OUT", "w", stdout);
    cin >> n >> s; 
    nhap();
    prim(s);
    cout << sum << endl;
    for(auto x : res){
        for(int i : x)
            cout << i << " ";
        cout << endl;
    }
    return 0;
}
/*
4 4
0 1 2 1
1 0 1 1 
2 1 0 -1
1 1 -1 0
*/
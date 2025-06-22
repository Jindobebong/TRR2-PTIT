#include <bits/stdc++.h>
#define ll long long
#define maxn 105
#define endl "\n"
using namespace std;

int n;
vector<int>adj[maxn];
bool vis[maxn];
vector<int>res;
vector<vector<int>>ans;

void dfs(int u){
    vis[u] = true;
    res.push_back(u);
    for(int v : adj[u]){
        if(!vis[v])
            dfs(v);
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("TK.INP", "r", stdin);
    freopen("TK.OUT", "w", stdout);
    cin >> n; 
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= n; ++j){
            int x; cin >> x; 
            if(x == 1){
                adj[i].push_back(j);
            }
        }
    }
    for(int i = 1; i <= n; ++i){
        if(!vis[i]){
            dfs(i);
            ans.push_back(res);
            res.clear();
        }
    }
    cout << ans.size() << endl;
    for(auto x : ans){
        sort(x.begin(), x.end());
        for(int i : x)
            cout << i << " ";
        cout << endl;
    }
    return 0;
}
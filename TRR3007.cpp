#include <bits/stdc++.h>
#define ll long long
#define maxn 105
#define endl "\n"
using namespace std;

int n, u, a[maxn][maxn];
vector<vector<int>>ans;
vector<int>res;
bool vis[maxn];

void backtrack(int cur, int cnt){
    if(cnt == n){
        if(a[cur][u]){
            res.push_back(u);
            ans.push_back(res);
            res.pop_back();
        }
        return;
    }
    for(int v = 1; v <= n; ++v){
        if(a[cur][v] && !vis[v]){
            vis[v] = true;
            res.push_back(v);
            backtrack(v, cnt + 1);
            vis[v] = false;
            res.pop_back();
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("CT.INP", "r", stdin);
    freopen("CT.OUT", "w", stdout);
    cin >> n >> u; 
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= n; ++j)
            cin >> a[i][j];
    
    res.push_back(u);
    vis[u] = true;
    backtrack(u, 1);
    for(auto x : ans){
        for(int i : x)
            cout << i << " ";
        cout << endl;
    }
    cout << ans.size();
    return 0;
}
#include <bits/stdc++.h>
#define ll long long
#define maxn 1000005
#define endl "\n"
using namespace std;

int a[105][105];
bool vis[105];
vector<int>path;
vector<vector<int>>ans;
int n, m, u;

void backtrack(int current, int cnt){
    if(cnt == n){
        if(a[current][u]){
            path.push_back(u);
            ans.push_back(path);
            path.pop_back();
        }
        return;
    }
    for(int v = 1; v <= n; ++v){
        if(!vis[v] && a[current][v]){
            vis[v] = true;
            path.push_back(v);
            backtrack(v, cnt + 1);
            vis[v] = false;
            path.pop_back();
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m >> u; 
    memset(a, 0, sizeof a);
    for(int i = 1; i <= m; ++i){
        int x, y; cin >> x >> y; 
        a[x][y] = 1;
        a[y][x] = 1;
    }
    path.push_back(u);
    vis[u] = true;
    backtrack(u, 1);

    cout << ans.size() << endl;
    for(auto x : ans){
        for(auto y : x)
            cout << y << " ";
        cout << endl;
    }
    return 0;
}
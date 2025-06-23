#include <bits/stdc++.h>
#define ll long long
#define maxn 1000005
#define endl "\n"
using namespace std;

int n, u, adj[105][105], path[105], cnt;
bool vis[105];
vector<vector<int>>ans;
vector<int>ke[105];
void hamilton(int i){
    int pre = path[i - 1];
    for(int j : ke[pre]){
        if(!vis[j]){
            vis[j] = true;
            path[i] = j;

            if(i == n){
                bool check = 0;
                for(int i : ke[path[n]]){
                    if(i == u){
                        check = true;
                        break;
                    }
                }
                if(check){
                    vector<int>res;
                    for(int k = 1; k <= n; ++k)
                        res.push_back(path[k]);
                    res.push_back(path[1]);
                    ans.push_back(res);
                }
            }
            else hamilton(i + 1);
            vis[j] = false;
        }
    }
}
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	freopen("CT.INP", "r", stdin);
    freopen("CT.OUT", "w", stdout);
    cin >> n >> u;
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= n; ++j){
            int x; cin >> x; 
            if(x == 1) ke[i].push_back(j);
        }
    }
    path[1] = u;
    vis[u] = true;
    hamilton(2);
    if(ans.size()){
        for(auto x : ans){
            for(int i : x)
                cout << i << " ";
            cout << endl;
        }
        cout << ans.size();
    }
    else cout << 0;
	return 0;
}
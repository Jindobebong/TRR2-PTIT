#include <bits/stdc++.h>
#define ll long long
#define maxn 1000005
#define endl "\n"
using namespace std;

int n, u, path[105];
vector<vector<int>>ans; 
vector<int>ke[105];
bool vis[105];

void hamilton(int i){
    int pre = path[i - 1];
    for(int j : ke[pre]){
        if(!vis[j]){
            path[i] = j; 
            vis[j] = true; 

            if(i == n){
                bool check = false;
                for(int i : ke[path[n]]){
                    if(i == u){
                        check = true; 
                        break;
                    }
                }
                if(check){
                    vector<int>res;
                    for(int i = 1; i <= n; ++i)
                        res.push_back(path[i]);
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
    // freopen("CT.INP", "r", stdin);
    // freopen("CT.OUT", "w", stdout);
    cin >> n >> u; 
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= n; ++j){
            int x; cin >> x; 
            if(x == 1){
                ke[i].push_back(j);
            }
        }
    }
    path[1] = u; 
    vis[u] = true;
    hamilton(2);
    cout << ans.size() << endl;
    for(auto x : ans){
        for(int i : x)
            cout << i << " ";
        cout << endl;
    }
    return 0;
}
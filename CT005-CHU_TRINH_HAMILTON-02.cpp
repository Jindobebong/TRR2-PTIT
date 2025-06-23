#include <bits/stdc++.h>
#define ll long long
#define maxn 1000005
#define endl "\n"
using namespace std;

int n, m, u, path[105];
vector<int>ke[105];
bool vis[105];
vector<vector<int>>ans;

void hamilton(int i){
    int pre = path[i - 1];
    for(int j : ke[pre]){
        if(!vis[j]){
            vis[j] = true; 
            path[i] = j;

            if(i == n){
                bool check = false;
                for(int x : ke[path[n]]){
                    if(x == u){
                        check = true;
                        break;
                    }
                }
                if(check){
                    vector<int>res;
                    for(int i = 1; i <= n; ++i){
                        res.push_back(path[i]);
                    }
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
    cin >> n >> m >> u; 
    for(int i = 0; i < m; ++i){
        int ui, vi; cin >> ui >> vi; 
        ke[ui].push_back(vi);
        ke[vi].push_back(ui);
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
#include <bits/stdc++.h>
#define ll long long
#define maxn 1000005
#define endl "\n"
using namespace std;

int n, u;
vector<pair<int, int>>ke[105];
int path[105], a[105][105];
bool vis[105];
vector<vector<int>>ans;

void hamilton(int i){
    int pre = path[i - 1];
    for(auto [j, w] : ke[pre]){
        if(!vis[j]){
            path[i] = j; 
            vis[j] = true; 
            bool check = false;
            if(i == n){
                for(auto [x, y] : ke[path[n]]){
                    if(x == u){
                        check = true;
                        break;
                    }
                }
                vector<int>res;
                if(check){
                    for(int i = 1; i <= n; ++i)
                        res.push_back(path[i]);
                    res.push_back(u);
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
    cin >> n >> u; 
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= n; ++j){
            cin >> a[i][j];
            if(a[i][j] != 10000 && a[i][j] != 0){
                ke[i].push_back({j, a[i][j]});
            }
        }
    }
    path[1] = u; 
    vis[u] = true;
    hamilton(2);
    if(ans.size() == 0) cout << 0; 
    else{
        vector<int>res;
        int mini = 10000;
        for(auto x : ans){
            int sum = 0;
            // for(int i : x)
            //     cout << i << " ";
            // cout << endl;
            for(int i = 1; i < x.size(); ++i){
                sum += a[x[i - 1]][x[i]];
            }
            //cout << sum << endl;
            if(mini > sum){
                mini = sum; 
                res = x;
            }
        }
        cout << mini << endl; 
        for(auto x : res)
            cout << x << " ";
    }
    return 0;
}
/*
5 2
0 2 10000 10000 10000
2 0 3 1 10000
10000 3 0 4 5
10000 1 4 0 5
10000 10000 5 5 0


*/
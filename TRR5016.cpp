#include <bits/stdc++.h>
#define ll long long
#define maxn 1000005
#define endl "\n"
using namespace std;
int n;
const int INF = 10000;
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("DN.INP", "r", stdin);
    freopen("DN.OUT", "w", stdout);
    cin >> n; 
    vector<vector<int>>d(n + 1, vector<int>(n + 1, INF));
    vector<vector<int>>nex(n + 1, vector<int>(n + 1, -1));
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= n; ++j){
            int x; cin >> x; 
            if(i == j){
                d[i][j] = 0; 
                nex[i][j] = j;
            }
            else if(x != 0 && x != 10000){
                d[i][j] = x;
                nex[i][j] = j;
            }
        }
    }
    for(int k = 1; k <= n; ++k){
        for(int i = 1; i <= n; ++i){
            for(int j = 1; j <= n; ++j){
                if(d[i][k] != INF && d[k][j] != INF && d[i][j] > d[i][k] + d[k][j]){
                    d[i][j] = d[i][k] + d[k][j];
                    nex[i][j] = nex[i][k];
                }
            }
        }
    }
    int u, v; 
    int maxi = -INF;
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= n; ++j){
            if(d[i][j] && d[i][j] != INF && d[i][j] > maxi){
                maxi = d[i][j];
                u = i; v = j;
            }
        }
    }
    cout << u << " " << v << " " << d[u][v] << endl;
    while(u != v){
        cout << u << " ";
        u = nex[u][v];
    }
    cout << v;
    return 0;
}
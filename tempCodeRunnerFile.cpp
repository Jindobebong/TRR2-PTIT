#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
#define oo 10000
using namespace std;

int n, s, t; 
struct edge{
    int u, v, w;
};
vector<edge>adj;

vector<vector<int>>d(105, vector<int>(105, oo));
vector<vector<int>>nex(105, vector<int>(105, -1));

void floyd(){
    for(int k = 1; k <= n; ++k){
        for(int i = 1; i <= n; ++i){
            for(int j = 1; j <= n; ++j){
                if(d[i][k] != oo && d[k][j] != oo && d[i][j] > d[i][k] + d[k][j]){
                    d[i][j] = d[i][k] + d[k][j];
                    nex[i][j] = nex[i][k];
                }
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    // freopen("BN.INP", "r", stdin);
    // freopen("BN.OUT", "w", stdout);
    cin >> n; 
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= n; ++j){
            int x; cin >> x; 
            if(i == j){
                d[i][j] = 0; 
                nex[i][j] = j;
            }
            else if(x && x != oo){
                d[i][j] = x;
                nex[i][j] = j;
            }
        }
    }
    floyd();
    int maxi = -oo, x, y;
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= n; ++j){
            if(maxi < d[i][j] && d[i][j] != oo){
                maxi = d[i][j]; 
                x = i; 
                y = j;
            }
        }
    }
    cout << x << " " << y << " " << d[x][y] << endl;
    vector<int>res;
    while(x != y){
        res.push_back(x);
        x = nex[x][y];
    }
    res.push_back(y);
    for(auto x : res)
        cout << x << ' ';
    return 0;
}
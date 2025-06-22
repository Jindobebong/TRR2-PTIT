#include <bits/stdc++.h>
#define ll long long
#define maxn 105
#define endl "\n"
using namespace std;

int t, n, m, in[maxn], out[maxn], cnt;
vector<vector<int>>a(105, vector<int>(105, 0));
vector<pair<int, int>>adj;
void nhap(){
    cin >> n;
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= n; ++j){
            int x; cin >> x; 
            if(x == 1){
                out[i]++;
                in[j]++;
                adj.push_back({i, j});
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("DT.INP", "r", stdin);
    freopen("DT.OUT", "w", stdout);
    cin >> t; 
    nhap();
    if(t == 1){
        for(int i = 1; i <= n; ++i)
            cout << in[i] << " " << out[i] << endl;
    }
    else{
        cout << n << " " << adj.size() << endl;
        for(auto [x, y] : adj)
            cout << x << " " << y << endl;
    }
    return 0;
}
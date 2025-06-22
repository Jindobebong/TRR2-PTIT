#include <bits/stdc++.h>
#define ll long long
#define maxn 105
#define endl "\n"
using namespace std;

int t, n, m, in[maxn], out[maxn], cnt;
vector<vector<int>>a(105, vector<int>(105, 0));
vector<int>adj[maxn];
void nhap(){
    cin >> n >> m;
    for(int i = 1; i <= m; ++i){
        int x, y; cin >> x >> y;
        out[x]++;
        in[y]++;
        adj[x].push_back(y);
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
        cout << n << endl;
        for(int i = 1; i <= n; ++i){
            cout << adj[i].size() << " ";
            for(int i : adj[i])
                cout << i << " ";
            cout << endl;
        }
    }
    return 0;
}
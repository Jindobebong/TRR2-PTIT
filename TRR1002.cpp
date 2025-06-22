#include <bits/stdc++.h>
#define ll long long
#define maxn 1000005
#define endl "\n"
using namespace std;

vector<int>adj[105];
int a[105][105];
int deg[105];
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("DT.INP", "r", stdin);
    freopen("DT.OUT", "w", stdout);
    int t, n; cin >> t >> n;
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= n; ++j){
            cin >> a[i][j];
            if(a[i][j] == 1){
                deg[i]++;
                if(i < j) adj[i].push_back(j);
                if(i < j) adj[j].push_back(i);
            }
        }
    }
    if(t == 1){
        for(int i = 1; i <= n; ++i)
            cout << deg[i] << " ";
    }
    else if(t == 2){
        cout << n << endl;
        for(int i = 1; i <= n; ++i){
            sort(adj[i].begin(), adj[i].end());
            cout << adj[i].size() << " ";
            for(auto x : adj[i])
                cout << x << " ";
            cout << endl;
        }
    }
    return 0;
}
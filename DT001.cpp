#include <bits/stdc++.h>
#define ll long long
#define maxn 1000005
#define endl "\n"
using namespace std;

vector<pair<int, int>>adj;
int a[105][105];
int deg[105];
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t, n; cin >> t >> n;
    int canh = 0;
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= n; ++j){
            cin >> a[i][j];
            if(a[i][j] == 1){
                ++canh;
                deg[i]++;
                if(i < j) adj.push_back({i, j});
            }
        }
    }
    if(t == 1){
        for(int i = 1; i <= n; ++i)
            cout << deg[i] << " ";
    }
    else if(t == 2){
        cout << n << " " << canh / 2 << endl;
        for(auto [x, y] : adj)
            cout << x << " " << y << endl;
    }
    return 0;
}
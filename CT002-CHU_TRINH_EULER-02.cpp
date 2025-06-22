#include <bits/stdc++.h>
#define ll long long
#define maxn 1000005
#define endl "\n"
using namespace std;

int a[105][105];
vector<vector<int>>adj(1005);
map<pair<int, int>, int>edgeCount;
vector<int>path;

void findEuler(int u){
    stack<int>st;
    st.push(u);
    while(!st.empty()){
        int v = st.top();
        bool check = false;
        for(int i = 0; i < adj[v].size(); ++i){
            int to = adj[v][i];
            if(edgeCount[{to, v}] > 0){
                edgeCount[{to, v}]--;
                edgeCount[{v, to}]--;
                st.push(to);
                check = true;
                break;
            }
        }
        if(!check){
            path.push_back(v);
            st.pop();
        }
    }
    reverse(path.begin(), path.end());
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin >> t; 
    if(t == 1){
        int n; cin >> n; 
        vector<int>deg(n + 5, 0);
        for(int i = 1; i <= n; ++i){
            for(int j = 1; j <= n; ++j){
                cin >> a[i][j];
                adj[i].push_back(j);
                adj[j].push_back(i);
                if(a[i][j] == 1){
                    deg[i]++;
                    deg[j]++;
                }
            }
        }
        int odd = 0;
        for(int i = 1; i <= n; ++i){
            deg[i] /= 2;
            if(deg[i] % 2) ++odd;
        }
        if(odd == 2) cout << 2; 
        else if(odd == 0) cout << 1; 
        else cout << 0;
    }
    else if(t == 2){
        int n, u; cin >> n >> u; 
        for(int i = 1; i <= n; ++i){
            for(int j = 1; j <= n; ++j){
                cin >> a[i][j];
            }
        }
        for(int i = 1; i <= n; ++i){
            for(int j = i; j <= n; ++j){
                if(a[i][j] == 1){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                    edgeCount[{i, j}]++;
                    edgeCount[{j, i}]++;
                }
            }
        }
        
        findEuler(u);

        for(auto x : path)
            cout << x << ' ';
    }
    return 0;
}
/*
2
4 2
0 1 0 1
1 0 1 0
0 1 0 1
1 0 1 0
*/
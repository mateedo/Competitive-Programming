#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pi;
typedef pair<ll,int> node;
int n, m, a, b, required;
vector< pair<int ,pair<int,int>>>adj[100001];
ll dist[100001];
priority_queue<node, vector<node>, greater<node>>pq;

bool dijkstra(int pass, int maxTime, int start, int end) {
    for(int i = 0; i < n+1; i++) {
        dist[i] = LLONG_MAX;
    }
    pq.push( {0ll,start});
    
    while(!pq.empty()) {
        int time = pq.top().first; 
        ll cur = pq.top().second;
        pq.pop();
        // cout << "ben" << endl;
        if(dist[cur] != LLONG_MAX) continue;
        dist[cur] = time;
        for(int i = 0; i < adj[cur].size(); i++){
            if(adj[cur][i].first > pass) continue;
            pq.push({adj[cur][i].second.first+time, adj[cur][i].second.second});
        }
    }
    if(dist[end]>maxTime){
        return false;
    }else{
        return true;
    }

}

void solve() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        cin >> a >> b >> required;
        adj[a].push_back( {i+1, {required,b}});
        adj[b].push_back( {i+1, {required,a}});
    }
    cin >> a >> b >> required;
    int left = 0;
    int right = m;
    while(left != right) {
        int middle = (left + right)/2;
        if( dijkstra(middle, required, a, b)){
            right= middle;
        }else{
            left = middle+1;
        }
    }

    if(dijkstra(m,required,a,b)){
        cout << left << endl;
    }else{
        cout << "-1" << endl;
    }

    

}

int main() {
    
    solve();
}
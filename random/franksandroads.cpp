//VMSS '15 #4 - Frank and Roads
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pi;
int main() {
  int t, n, m, g;
  cin >> t >> n >> m >> g;
  priority_queue<pi, vector<pi>, greater<pi>>pq;
  vector<pi> adj[n+1];
  int dist[n+1];
  int fbnodes[g];
  
  for(int i = 0; i < g; i++){
    cin >> fbnodes[i];
  }
  
  for(int i = 0; i < n+1; i++){
    dist[i] = INT_MAX;  
  }
  int a, b, length;
  for(int i = 0; i < m; i++){
    cin >> a >> b >> length;
    adj[a].push_back({length,b});
  }
  
  pq.push({0,0});
  
  while(!pq.empty()){
    int cur = pq.top().second, distance = pq.top().first;
    pq.pop();

    if(dist[cur] != INT_MAX) continue;
    dist[cur] = distance;
    for(auto&[i,j]:adj[cur]){
      pq.push( {i+distance, j});
    }
  }
  int am = 0;
  for(int i = 0; i < g; i++){
    if(dist[ fbnodes[i]] > t)continue;
    am++;
  }
  cout << am << endl;
  
  
}
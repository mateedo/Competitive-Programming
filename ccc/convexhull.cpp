//CCC '15 S4 - Convex Hull
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef tuple<int, int,int> ti;
int main() {
  int k, n, m;
  cin >> k >> n >> m;
  priority_queue< ti, vector<ti>, greater<ti>> pq;
  vector<ti> adj[n+1];
  int dist[k+1][n+1];

  int a, b, len, broke;
  for(int i =0; i < m; i++){
    cin >> a >> b >> len >> broke;
    adj[a].push_back( {len, b, broke});
    adj[b].push_back( {len, a, broke});
  }
  for(int i = 0; i < k+1; i++){
    for(int a = 0; a < n+1; a++){
      dist[i][a] = INT_MAX;
    }
  }
  int start, end;
  cin >> start >> end;
  pq.push( {0,start,k});

  while(!pq.empty()){
    int distance = get<0>(pq.top()), cur = get<1>(pq.top()), hull = get<2>(pq.top());
    pq.pop();

    if(dist[hull][cur] != INT_MAX) continue;
    dist[hull][cur] = distance;
    for(auto&[i,j,h]:adj[cur]){
      if(hull-h<=0)continue;
      pq.push( {distance+i,j,hull-h} );
    }
    
  }
  int optimal = INT_MAX;
  for(int i = 1; i < k+1; i++){
    optimal = min( optimal, dist[i][end]);
  }
  if(optimal == INT_MAX){
    cout << "-1" << endl;
  }else{
    cout << optimal << endl;
  }
  

}
//GFSSOC '15 Fall S4 - Mostly Talking
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pi;
typedef tuple<int, int, int> ti;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, m;
  cin >> n >> m;
  priority_queue< ti, vector<ti>, greater<ti>>pq;
  vector<pi> adj[n+1];
  int a, b, length;
  for(int i = 0; i < m; i++){
    cin >> a >> b >> length;
    adj[a].push_back({length, b});
  }
  int d;
  cin >> d;
  vector<pi> adjCindy[n+1];
  for(int i = 0; i < d; i++){
    cin >> a >> b >> length;
    adjCindy[a].push_back({length, b});
  }

  int dist[n+1];
  int distCindy[n+1];
  for(int i = 0; i < n+1; i++){
    dist[i] = INT_MAX;
    distCindy[i] = INT_MAX;
  }
  pq.push( {0,1,0});
  while(!pq.empty()){
    int distance = get<0>(pq.top()), cur = get<1>(pq.top()), used = get<2>(pq.top());
    pq.pop();

    
    if(used==0){
      if(dist[cur] != INT_MAX)continue;
      dist[cur] = distance;
      for(auto&[i,j]:adj[cur]){
        pq.push( {distance+i,j,0});
      }
      for(auto&[i,j]:adjCindy[cur]){
        pq.push( {distance+i,j,1});
      }
    }else{
      if(distCindy[cur] != INT_MAX)continue;
      distCindy[cur] = distance;
      for(auto&[i,j]:adj[cur]){
        pq.push( {distance+i,j,1});
      }
    }
  }
  int output = min( dist[n], distCindy[n]);

  if(output == INT_MAX){
    cout << "-1" << endl;
  }else{
    cout << output << endl;
  }
  
  
}
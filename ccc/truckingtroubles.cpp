//CCC '03 S5 - Trucking Troubles
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int c, r, d;
const int lol = 1e5;
int si[lol];
int parent[lol];
void initialize() {
  for(int i = 0; i < c; i++){
    parent[i] = i;
    si[i] = 1;
  }
}

int findRoot(int a) {
  if(parent[a] == a) return a;
  return parent[a] = findRoot(parent[a]);
}

void connect(int a, int b) {
  a = findRoot(a);
  b = findRoot(b);
  if(si[a] < si[b]) swap(a,b);
  si[a] += si[b];
  parent[b] = a;
}

int main() {
  cin >> c >> r >> d;
  int a, b, weight;
  initialize();
  vector< pair<int , pair<int, int>>>edges;
  for(int i = 0; i < r; i++) {
    cin >> a >> b >> weight;
    a--;
    b--;
    edges.push_back( {weight, {a,b}});
  }
  sort(edges.begin(), edges.end(), greater<pair<int,pair<int,int>>>());

  
  vector< pair<int,int>> adj[c];
  for(int i = 0; i < edges.size(); i++) {
    
    int first = edges[i].second.first;
    int second = edges[i].second.second;
    int weight = edges[i].first;
    
    if(findRoot(first) == findRoot(second)) continue;
    connect(first, second);
    adj[first].push_back( {second,weight});
    adj[second].push_back( {first,weight});
  }
  
  int des[d];
  int temp;
  
  for(int i = 0; i < d; i++) {
    cin >> temp;
    temp--;
    des[i] = temp;
  }

  int dist[c];
  for(int i = 0; i < c; i++) {
    dist[i] = INT_MAX;
  }



  
  queue<int>bfs;
  bfs.push(0);

  
  while(!bfs.empty()) {
    int cur = bfs.front();
    bfs.pop();
    for(int i = 0; i < adj[cur].size(); i++) {
      int nx = adj[cur].at(i).first;
      int heavy = adj[cur].at(i).second;
      if(dist[nx] != INT_MAX)continue;
      dist[nx] = min( dist[cur], heavy);
      bfs.push(nx);
      
    }
    
  }

  int output = INT_MAX;
  for(int i = 0; i < d; i++) {
    output = min(dist[des[i]] , output);
  }
  cout << output << endl;
}
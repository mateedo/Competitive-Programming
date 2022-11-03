//CCO '03 P6 - Cheap Gas
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int>pi;
typedef tuple<double, int, pi> node;


void solve(){
  int r, c, f, k;
  cin >> r >> c >> f >> k;
  double gas[100][100];
  double dist[100][100][201];
  for(int i = 0; i < 100; i++){
    for(int o = 0; o < 100; o++){
      gas[i][o] = -1;
      for(int p = 0; p < 201; p++){
        dist[i][o][p] = INT_MAX;
      }
    }
  }

  for(int i = 0; i < k; i++){
    int gr, gc;
    double price;
    cin >> gr >> gc >> price;
    if(gas[gr-1][gc-1] < price && gas[gr-1][gc-1] != -1)continue;
    gas[gr-1][gc-1] = price;
  }
  
  int dx[] = {-1,1,0,0};
  int dy[] = {0,0,-1,1};
  
  priority_queue< node, vector<node>, greater<node>>pq;
  pq.push( {0,f,{0,0}});

  while(!pq.empty()){
    double cost = get<0>(pq.top());
    int fuel = get<1>(pq.top());
    int curr = get<2>(pq.top()).first, curc = get<2>(pq.top()).second;
    pq.pop();
    if(dist[curr][curc][fuel] != INT_MAX) continue;
    dist[curr][curc][fuel] = cost;

  
    for(int i = 0; i < 4; i++){
      int nx = curr + dx[i], ny = curc + dy[i];
      if(nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
      if(fuel == 0) continue;
      pq.push( {cost,fuel-1, {nx,ny}});
    }
    if(gas[curc][curr] == -1) continue;
    if(fuel + 1 > f) continue;
    pq.push( {cost + gas[curc][curr], fuel + 1, {curr,curc}});
    
  }
  
  double ef = INT_MAX;
  for(int i = 0; i < 201; i++){
    ef= min(ef,dist[r-1][c-1][i]);
  }

  if(ef==INT_MAX){
    cout << "Stranded on the shoulder" << endl;
  }else{
    cout<<fixed<<setprecision(2)<<ef<<"\n";
  }
}

int main() {
  int t;
  cin >> t;
  for(int i = 0; i < t; i++){
    solve();
  }
}
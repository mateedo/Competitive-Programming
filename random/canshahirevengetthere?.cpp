//VM7WC '16 #3 Silver - Can Shahir even get there?!
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, a, b;
  cin >> n >> m >> a >> b;
  int h1, h2;
  int bfsmap[n+1];
  queue<int> bfs;
  vector<int> adjacent[n+1];
  for(int i = 0; i < m; i++){
    cin >> h1 >> h2;
    adjacent[h1].push_back(h2);
    adjacent[h2].push_back(h1);
  }
  for(int i = 0; i < n; i++){
    bfsmap[i] = INT_MAX;
  }
  
  bfsmap[a] = 0;
  bfs.push(a);
  
  while(!bfs.empty()){
    int cur = bfs.front();
    bfs.pop();
    for(int i: adjacent[cur]){
      if(bfsmap[i] <= bfsmap[cur] +1)continue;
      bfsmap[i] = bfsmap[cur] +1;
      bfs.push(i);
    }
  }
  if(bfsmap[b] == INT_MAX){
    cout << "NO SHAHIR!" << endl;
  }else{
    cout << "GO SHAHIR!" << endl;
  }
  
}
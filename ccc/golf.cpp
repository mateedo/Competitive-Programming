//CCC '00 S4 - Golf
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main() {
  int dist, n;
  cin >> dist >> n;
  int clubs[n];
  for(int i = 0; i < n; i++){
    cin >> clubs[i];
  }
  int bfsmap[dist+1];
  for(int i = 0; i <= dist; i++){
    bfsmap[i] = INT_MAX;
  }
  queue<int> bfs;
  bfs.push(0);
  bfsmap[0] = 0;
  while(!bfs.empty()){
    int x = bfs.front();
    bfs.pop();
    for(int i = 0; i < n; i++){

      if(x+clubs[i] <= dist){
        if(bfsmap[x+clubs[i]] > bfsmap[x] + 1){
          bfsmap[x+clubs[i]] = bfsmap[x]+1;
          bfs.push(x+clubs[i]);
        }
      }
      
    }
  }

  if(bfsmap[dist] == INT_MAX){
    cout << "Roberta acknowledges defeat.";
  }else{
    cout << "Roberta wins in " << bfsmap[dist] <<  " strokes." << endl;
  }
}
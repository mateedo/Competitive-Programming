//CCC '20 S2 - Escape Room
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
bool visited[1000001];
int main() {
  ios_base::sync_with_stdio(false);
    cin.tie(NULL);
  int r, c;
  cin >> r >> c;
  int map[r][c];
  int distance[r][c];
  queue< pair<int,int>>bfs;
  for(int i = 0; i < r; i++){
    for(int k = 0; k < c; k++){
      cin >> map[i][k];
      distance[i][k] = INT_MAX;
    }
  }

  distance[0][0] = 0;
  bfs.push({0,0});
  while(!bfs.empty()){
    int x = bfs.front().first, y = bfs.front().second;
    bfs.pop();

    if(!visited[map[x][y]]){
      for(int i = 1; i <= sqrt(map[x][y]); i++){
      if(map[x][y]%i == 0){
        int q = map[x][y]/i;

        if(i <= r && q <= c)
        {
          if(distance[i-1][q-1] > distance[x][y] + 1){
            distance[i-1][q-1] = distance[x][y] + 1;
            bfs.push({i-1,q-1});
          }
        }
        if( i <=c &&q<=r)
        {
          if(distance[q-1][i-1] > distance[x][y] + 1){
            distance[q-1][i-1] = distance[x][y] + 1;
            bfs.push({q-1,i-1});
          }
        }
        
        }
      
      }
    visited[map[x][y]]= true;
    }
    
  }
    
  
  
  if(distance[r-1][c-1] == INT_MAX){
    cout << "no" << endl;
  }else{
    cout << "yes" << endl;
  }
}
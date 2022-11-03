//DMOPC '14 Contest 1 P5 - Surprise Teleport
#include <iostream>
#include <bits/stdc++.h>
#include <string.h>

using namespace std;
int main() {
  int r, c, sx, sy, ox, oy, t, tx, ty;
  string line;
  cin >> r >> c;
  cin >> sx >> sy;
  cin >> ox >> oy;
  char map[r][c];
  int bfsmap[r][c];
  queue< pair<int,int>>bfs;
  for(int i = 0; i < r; i++){
    for(int k = 0; k < c; k++){
      cin >> map[i][k];
      bfsmap[i][k] = INT_MAX;
    }
  }
  cin >> t;
  pair<int,int> tel[t];
  for(int i = 0; i < t; i++){
    cin >> tx >> ty;
    tel[i] = {tx,ty};
  }
  
  bfs.push( {sx,sy});
  bfsmap[sx][sy] = 0;
  while(!bfs.empty()){
    int x = bfs.front().first, y = bfs.front().second;
    bfs.pop();
    if(x+1<r){
     if(map[x+1][y] != 'X'){
        if(bfsmap[x+1][y] > bfsmap[x][y] + 1){
          bfsmap[x+1][y] = bfsmap[x][y]+1;
          bfs.push({x+1,y});
         
        }
      } 
    }
    if(x-1>=0){
      if(map[x-1][y] != 'X'){
        if(bfsmap[x-1][y] > bfsmap[x][y] + 1){
          bfsmap[x-1][y] = bfsmap[x][y]+1;
          bfs.push({x-1,y});
        }
      } 
    }
    if(y+1<c){
      if(map[x][y+1] != 'X'){
        if(bfsmap[x][y+1] > bfsmap[x][y] + 1){
          bfsmap[x][y+1] = bfsmap[x][y]+1;
          bfs.push({x,y+1});
        }
      }
    } 
    if(y-1>=0){
      if(map[x][y-1] != 'X'){
        if(bfsmap[x][y-1] > bfsmap[x][y] + 1){
          bfsmap[x][y-1] = bfsmap[x][y]+1;
          bfs.push({x,y-1});
        }  
      }
    } 
    
    
    
  }

  int minDistance = bfsmap[ox][oy];
  for(int i = 0; i < t; i++){
    pair<int,int>temp;
    temp = tel[i];
    int p = temp.first, o = temp.second;
    minDistance = min(bfsmap[p][o], minDistance);
    
  }
  cout <<  bfsmap[ox][oy] - minDistance << endl;
}
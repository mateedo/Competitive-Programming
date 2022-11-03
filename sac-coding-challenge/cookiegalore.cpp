//SAC '22 Code Challenge 2 P4 - Cookie Galore
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main() {
  int r , c;

  cin >> r >> c;
  char map[r][c];
  int bfsmap[r][c];
  string cringe;
  for(int i = 0; i < r; i++){
    cin >> cringe;
    for(int k = 0; k < c; k++){
      map[i][k] = cringe[k];
      bfsmap[i][k] = INT_MAX;
    }
  }
  deque< pair<int,int> > bfs;
  bfs.push_front( {0,0});
  if(map[0][0] == 'C'){
    bfsmap[0][0] = 1;
  }else{
    bfsmap[0][0] = 0;
  }

  while(!bfs.empty()){
    int x = bfs.front().first, y = bfs.front().second;
    bfs.pop_front();

    if(x + 1 < r){
      
      if(map[x+1][y] == '.'){
        
        if(bfsmap[x+1][y] > bfsmap[x][y]){
          bfsmap[x+1][y] = bfsmap[x][y];
          bfs.push_front( {x+1,y});
          }
        
      }else if(bfsmap[x+1][y] > bfsmap[x][y]+1){
        bfsmap[x+1][y] = bfsmap[x][y] + 1;
        bfs.push_back( {x+1,y});
      }
    }
    if(x - 1 >= 0){
      
      if(map[x-1][y] == '.'){
        
        if(bfsmap[x-1][y] > bfsmap[x][y]){
          bfsmap[x-1][y] = bfsmap[x][y];
          bfs.push_front( {x-1,y});
          }
        
      }else if(bfsmap[x-1][y] > bfsmap[x][y]+1){
        bfsmap[x-1][y] = bfsmap[x][y] + 1;
        bfs.push_back( {x-1,y});
      }
    }

     if(y + 1 < c){
       if(map[x][y+1] == '.'){
         if(bfsmap[x][y+1] > bfsmap[x][y]){
          bfsmap[x][y+1] = bfsmap[x][y];
          bfs.push_front( {x,y+1});
        }
       }
      else if(bfsmap[x][y+1] > bfsmap[x][y]+1){
        bfsmap[x][y+1] = bfsmap[x][y] + 1;
        bfs.push_back( {x,y+1});
      }
      }
     if(y - 1 >= 0){
       if(map[x][y-1] == '.'){
         if(bfsmap[x][y-1] > bfsmap[x][y]){
          bfsmap[x][y-1] = bfsmap[x][y];
          bfs.push_front( {x,y-1});
        }
       }
      else if(bfsmap[x][y-1] > bfsmap[x][y]+1){
        bfsmap[x][y-1] = bfsmap[x][y] + 1;
        bfs.push_back( {x,y-1});
      }
      }
    }
   cout << bfsmap[r-1][c-1] << endl;
  }
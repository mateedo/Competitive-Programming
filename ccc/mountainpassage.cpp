//CCC '98 S5 - Mountain Passage
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main() {
  int trips, n;
  cin >> trips;
     
  deque< pair<int,int> >bfs;
  for(int i = 0; i < trips; i++) {
  int map[25][25];
  int bfsmap[25][25];
  cin >> n;
    for(int r = 0; r < n; r++) {
      for(int c = 0; c < n; c++) {
        cin >> map[r][c];
        bfsmap[r][c] = INT_MAX; 
      }
    }
  bfs.push_front({0,0});
  bfsmap[0][0] = 0;

  while(!bfs.empty()) {
    int x = bfs.front().first, y = bfs.front().second;
    bfs.pop_front();

      if( x +1 < n && abs(map[x+1][y] - map[x][y]) <=2){

        if(map[x+1][y] > map[0][0] || map[x][y] > map[0][0]){
          if(bfsmap[x+1][y] > bfsmap[x][y] + 1){
            bfsmap[x+1][y] = bfsmap[x][y] + 1;
            bfs.push_back( {x+1,y});
          }
        }else if(bfsmap[x+1][y] > bfsmap[x][y]){
          bfsmap[x+1][y] = bfsmap[x][y];
          bfs.push_front( {x+1,y});
        }
      }
      if( x -1 >= 0 && abs(map[x-1][y] - map[x][y]) <=2){

        if(map[x-1][y] > map[0][0] || map[x][y] > map[0][0]){
          if(bfsmap[x-1][y] > bfsmap[x][y] + 1){
            bfsmap[x-1][y] = bfsmap[x][y] + 1;
            bfs.push_back( {x-1,y});
          }
        }else if(bfsmap[x-1][y] > bfsmap[x][y]){
          bfsmap[x-1][y] = bfsmap[x][y];
          bfs.push_front( {x-1,y});
        }
      }
      if( y +1 < n && abs(map[x][y+1] - map[x][y]) <=2){

        if(map[x][y+1] > map[0][0] || map[x][y] > map[0][0]){
          if(bfsmap[x][y+1] > bfsmap[x][y] + 1){
            bfsmap[x][y+1] = bfsmap[x][y] + 1;
            bfs.push_back( {x,y+1});
          }
        }else if(bfsmap[x][y+1] > bfsmap[x][y]){
          bfsmap[x][y+1] = bfsmap[x][y];
          bfs.push_front( {x,y+1});
        }
      }
      if( y -1 >= 0 && abs(map[x][y-1] - map[x][y]) <=2){

        if(map[x][y-1] > map[0][0] || map[x][y] > map[0][0]){
          if(bfsmap[x][y-1] > bfsmap[x][y] + 1){
            bfsmap[x][y-1] = bfsmap[x][y] + 1;
            bfs.push_back( {x,y-1});
          }
        }else if(bfsmap[x][y-1] > bfsmap[x][y]){
          bfsmap[x][y-1] = bfsmap[x][y];
          bfs.push_front( {x,y-1});
        }
      }

      
      
      
      }




      
    if(bfsmap[n-1][n-1] == INT_MAX) cout << "CANNOT MAKE THE TRIP" << endl << endl;
    else cout << bfsmap[n-1][n-1] << endl << endl;
  }
  
}
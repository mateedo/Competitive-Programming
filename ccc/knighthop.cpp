//CCC '10 J5 - Knight Hop
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main() {
  int bfsmap[8][8];
  int sx, sy, ex, ey;
  cin >> sx >> sy;
  cin >> ex >> ey;
  for(int i = 0;i < 8; i++)
    {
      for(int k = 0; k < 8; k++){
        bfsmap[i][k] = INT_MAX;
      }
    }
  sx--;
  sy--;
  ex--;
  ey--;
  queue < pair<int,int>> bfs;
  bfsmap[sx][sy] = 0;
  bfs.push( {sx,sy});
  int dx[] = {2,2,1,1,-1,-1,-2,-2};
  int dy[] = {1,-1,2,-2,2,-2,1,-1};
  while(!bfs.empty()){
    int x = bfs.front().first, y = bfs.front().second;
    bfs.pop();
        for(int i = 0 ; i < 8; i++){
            int nx =  x + dx[i], ny = y + dy[i];
            if(nx < 0 || nx >= 8 || ny < 0 || ny >= 8) continue;
            if(bfsmap[nx][ny] <= bfsmap[x][y] + 1) continue;
            bfsmap[nx][ny] = bfsmap[x][y] + 1;
            bfs.push( {nx,ny});
        }
    }
    cout << bfsmap[ex][ey] << endl;
  }
//CCC '18 S3 - RoboThieves
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
bool camera[100][100];
int main() {
  int r, c;
  string temp;
  cin >> r >> c;
  char map[r][c];
  int bfsmap[r][c];
  int dx[] = {-1,1,0,0};
  int dy[] = {0,0,1,-1};
  
  deque< pair<int, int>>bfs;
  queue< pair<int, int>> coords;
  queue< pair<int, int>> cameracoord;
  
  int sx, sy;
  
  for(int i = 0; i < r; i++){
    cin >> temp;
    for(int k = 0; k < c; k++){
      map[i][k] = temp[k];
      bfsmap[i][k] = INT_MAX;

      if(temp[k] == '.'){
        coords.push( {i,k});
      }else if(temp[k] == 'C'){
        cameracoord.push( {i,k});
      }else if(temp[k] == 'S') sx=i,sy=k;
      }
  }
  bfsmap[sx][sy] = 0;

  bfs.push_front( {sx,sy});



  
  while(!cameracoord.empty()){
    int x = cameracoord.front().first, y = cameracoord.front().second;
    cameracoord.pop();
    
    for(int i = x; i >= 0; i--){
      if(map[i][y] == '.' || map[i][y] == 'C' || map[i][y] == 'S'){
        camera[i][y] = true;
      }
      if(map[i][y] == 'W') break;
    }
    for(int i = x; i < r; i++){
      if(map[i][y] == '.' || map[i][y] == 'C'|| map[i][y] == 'S'){
        camera[i][y] = true;
      }
      if(map[i][y] == 'W') break;
    }
    for(int i = y; i >= 0; i--){
      if(map[x][i] == '.' || map[x][i] == 'C'|| map[x][i] == 'S'){
        camera[x][i] = true;
      }
      if(map[x][i] == 'W') break;
    }
    for(int i = y; i < c; i++){
      if(map[x][i] == '.' || map[x][i] == 'C'|| map[x][i] == 'S'){
        camera[x][i] = true;
      }
      if(map[x][i] == 'W') break;
    }
  }



  
  while(!bfs.empty()){
    int x = bfs.front().first, y = bfs.front().second;
    bfs.pop_front();
    
    if(map[x][y] == 'L' && map[x][y-1] != 'W'){
      if(bfsmap[x][y-1] > bfsmap[x][y] && !camera[x][y-1]){
        bfsmap[x][y-1] = bfsmap[x][y];

      bfs.push_front( {x,y-1});
      }

    }else if(map[x][y] == 'D' && map[x+1][y] != 'W'){
      if(bfsmap[x+1][y] > bfsmap[x][y] && !camera[x+1][y]){
        bfsmap[x+1][y] = bfsmap[x][y];
        bfs.push_front( {x+1,y});
      }
    }else if(map[x][y] == 'U' && map[x-1][y] != 'W'){
      if(bfsmap[x-1][y] > bfsmap[x][y] && !camera[x-1][y]){
        bfsmap[x-1][y] = bfsmap[x][y];

      bfs.push_front( {x-1,y});
      }
    }else if(map[x][y] == 'R' && map[x][y+1] != 'W'){
      if(bfsmap[x][y+1] > bfsmap[x][y] && !camera[x][y+1]){
        bfsmap[x][y+1] = bfsmap[x][y];

      bfs.push_front( {x,y+1});
      }
    }else if(map[x][y] == '.' || map[x][y] == 'S'){
      
      for(int i = 0; i < 4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx < 0 || nx >= r || ny < 0 || ny >= c)continue;
        if(map[nx][ny] == 'W') continue;
        if(camera[nx][ny]) continue;
        if(bfsmap[nx][ny] <= bfsmap[x][y] + 1) continue;
        bfsmap[nx][ny] = bfsmap[x][y] + 1;
        bfs.push_back( {nx,ny});
        
        
      }
    }
    
    
  }

  while(!coords.empty()){
    int x = coords.front().first, y = coords.front().second;
    coords.pop();

    if(camera[sx][sy]){
      cout << "-1" << endl;
    }else{
      
      if(bfsmap[x][y] == INT_MAX){
      cout << "-1" << endl;
    }else{
      cout << bfsmap[x][y] << endl;
    }
    }

    }

  
  
}
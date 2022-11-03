//CCC '00 S2 - Babbling Brooks
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main() {
  double n, input, ratio;
  int index;
  cin >> n;
  double streams[100];
  for(int i =0; i < 100; i++){
    streams[i] = INT_MAX;
  }
  for(int i = 0; i < n; i++){
    cin >> streams[i];
  }
  input = 0;
  while(input != 77){
    cin >> input;
    if(input == 99){
      cin >> index >> ratio;
      index--;
      for(int i = 99; i > index + 1; i--){
        streams[i] = streams[i-1];
      }
      double left = streams[index]*ratio/100;
      double right = streams[index] - left;
      streams[index] = left;
      streams[index+1] = right;
    }else if(input == 88){
      cin >> index;
      index--;
      streams[index]+=streams[index+1];
      for(int i = index + 1; i < 99; i++){
        streams[i] = streams[i+1];
      }
    }
  }
  for(int i = 0; i < 100; i++){
    if(streams[i] == INT_MAX) break;
    cout << round(streams[i]) << " ";
  }
}
#include <bits/stdc++.h>
using namespace std;
using P = pair<int,int>;
vector<P> vec{{1,0}, {0,-1}, {-1,0}, {0,1}};

int main(){
  int R, C, sy, sx, gy, gx;
  vector<vector<char>> c(52, vector<char>(52, '#'));
  vector<vector<int>> distance(52, vector<int>(52, -1));
  cin >> R >> C >> sy >> sx >> gy >> gx;
  for(int i=1; i<=R; ++i){
    for(int j=1; j<=C; ++j){
      cin >> c[i][j];
    }
  }
  
  queue<P> BFS;
  BFS.push({sy,sx});
  c[sy][sx] = '#';
  distance[sy][sx] = 0;
  c[gy][gx] = 'g';
  while(true){
    P prev = BFS.front();
    BFS.pop();
    for(auto v : vec){
      int y = prev.first + v.first;
      int x = prev.second + v.second;
      if(c[y][x] == '.'){
        BFS.push({y,x});
        c[y][x] = '#';
        distance[y][x] = distance[prev.first][prev.second] + 1;
      }
      if(c[y][x] == 'g'){
        cout << distance[prev.first][prev.second] +1 << endl;
        return 0;
      }
    }
  }
  

  return 0;
}

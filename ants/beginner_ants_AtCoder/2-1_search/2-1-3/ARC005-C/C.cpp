#include <bits/stdc++.h>
using namespace std;
using P = pair<int,int>;
vector<P> vec = {{1,0}, {0,1}, {-1,0}, {0,-1}};

int main(){
  int H, W;
  cin >> H >> W;
  vector<vector<char>> c(500, vector<char>(500));
  vector<vector<int>> broken(500, vector<int>(500,3));
  P start, goal;
  queue<P> BFS;
  for(int i=0; i<H; ++i){
    for(int j=0; j<W; ++j){
      cin >> c[i][j];
      if(c[i][j] == 's'){
        start = {i,j};
        broken[i][j] = 0;
        BFS.push({i,j});
        c[i][j] = '.';
      }
      if(c[i][j] == 'g'){
        goal = {i,j};
        c[i][j] = '.';
      }
    }
  }

  while(!BFS.empty()){
    P prev = BFS.front();
    BFS.pop();
    if(goal.first == prev.first && goal.second == prev.second){
      cout << "YES" << endl;
      return 0;
    }
    for(P v : vec){
      int b = broken[prev.first][prev.second];
      int h = prev.first + v.first;
      int w = prev.second + v.second;
      if(h<0 || h>=H || w<0 || w>=W) continue;
      if(c[h][w] == '#') ++b;
      if(b < broken[h][w]){
        broken[h][w] = b;
        BFS.push({h,w});
      }
    }
  }

  cout << "NO" << endl;

  return 0;
}

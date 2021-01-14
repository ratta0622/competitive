#include <bits/stdc++.h>
using namespace std;
using P = pair<int,int>;
vector<P> vec{{1,0}, {0,1}, {-1,0}, {0,-1}};


int main(){
  int H, W;
  cin >> H >> W;
  vector<vector<char>> A(1002, vector<char>(1002, ','));
  vector<vector<int>> distance(1002,vector<int>(1002,-1));
  queue<P> BFS;
  for(int i=1; i<=H; ++i){
    for(int j=1; j<=W; ++j){
      cin >> A[i][j];
      if(A[i][j] == '#'){
        BFS.push({i,j});
        distance[i][j] = 0;
      }
    }
  }

  int ans = INT_MIN;
  while(!BFS.empty()){
  
    P prev = BFS.front();
    BFS.pop();
    for(auto v : vec){
      int x = prev.first + v.first;
      int y = prev.second + v.second;
      if(distance[x][y] != -1) continue;
      if(A[x][y] == '.'){
        distance[x][y] = distance[prev.first][prev.second] + 1;
        BFS.push({x,y});
      }
    }
  }
  
    /* cout << endl; */
  /* for(int i=1; i<=H; ++i){ */
    /* for(int j=1; j<=W; ++j){ */
    /*   cout << A[i][j]; */
    /* } */
    /* cout << endl; */
  /* } */
  /* return 0; */

  for(int i=1; i<=H; ++i){
    for(int j=1; j<=W; ++j){
      if(distance[i][j] > ans) ans = distance[i][j];
    }
  }


  cout << ans << endl;
  
  return 0;
}

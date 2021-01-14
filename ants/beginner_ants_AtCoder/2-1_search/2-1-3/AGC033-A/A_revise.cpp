#include <bits/stdc++.h>
using namespace std;
using P = pair<int,int>;
vector<P> vec{{1,0}, {0,1}, {-1,0}, {0,-1}};

vector<vector<char>> A(1002, vector<char>(1002, ','));
int H, W;

bool check_white(){
  for(int i=1; i<=H; ++i){
    for(int j=1; j<=W; ++j){
      if(A[i][j] == '.') return true;
    }
  }
  return false;
}

int main(){
  cin >> H >> W;
  for(int i=1; i<=H; ++i){
    for(int j=1; j<=W; ++j){
      cin >> A[i][j];
    }
  }

  int ans = INT_MIN;
  for(int i=1; i<=H; ++i){
    for(int j=1; j<=W; ++j){
      if(A[i][j] != '.') continue;
      vector<vector<int>> distance(1002,vector<int>(1002,-1));
      queue<P> BFS;
      BFS.push({i,j});
      distance[i][j] = 0;
      while(!BFS.empty()){
        P prev = BFS.front();
        BFS.pop();
        for(auto v : vec){
          int x = prev.first + v.first;
          int y = prev.second + v.second;
          if(distance[x][y] != -1) continue;
          distance[x][y] = distance[prev.first][prev.second] + 1;
          if(A[x][y] == '#'){
            if(distance[x][y] > ans) ans = distance[x][y];
            while(!BFS.empty()) BFS.pop();
            break;
          }else if(A[x][y] == '.'){
            BFS.push({x,y});
          }
        }
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


  cout << ans << endl;
  
  return 0;
}

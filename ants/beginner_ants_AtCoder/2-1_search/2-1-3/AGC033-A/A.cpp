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
 
  int ans = 0;
  while(check_white()){
    ++ans;
    for(int i=1; i<=H; ++i){
      for(int j=1; j<=W; ++j){
        if(A[i][j] == '^') A[i][j] = '#';
      }
    }
    for(int i=1; i<=H; ++i){
      for(int j=1; j<=W; ++j){
        if(A[i][j] == '#'){
          for(P v : vec){
            if(A[i+v.first][j+v.second] == '.') A[i+v.first][j+v.second] = '^';
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
 
  }
 
  cout << ans << endl;
  
  return 0;
}

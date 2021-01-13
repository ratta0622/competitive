#include <bits/stdc++.h>
using namespace std;
using P = pair<int,int>;
vector<P> vec{{1,0}, {1,-1}, {0,-1}, {-1,-1}, {-1,0}, {-1,1}, {0,1}, {1,1}};

int main(){
  int W, H;
  int c[52][52]={};
  cin >> W >> H;
  for(int i=1; i<=H; ++i){
    for(int j=1; j<=W; ++j){
      cin >> c[i][j];
    }
  }
  /* for(int i=1; i<=H; ++i){ */
  /*   for(int j=1; j<=W; ++j){ */
  /*     cout << c[i][j]; */
  /*   } */
  /*   cout << endl; */
  /* } */
  
  int ans = 0;
  for(int i=1; i<=H; ++i){
    for(int j=1; j<=W; ++j){
      if(c[i][j]==0) continue;
      stack<P> DFS;
      DFS.push({i,j});
      c[i][j] = 0;
      /* cout << "start:" << i << j << endl; */
      while(!DFS.empty()){
        P prev = DFS.top();
        DFS.pop();
        /* cout << "start_loop:" << prev.first << prev.second << endl; */
        for(P v : vec){
          int x = prev.first + v.first;
          int y = prev.second + v.second;
          cout << x << " " << y;
          if(c[x][y]==1){
            /* cout << " is land"; */
            DFS.push({x,y});
            c[x][y] = 0;
          }
          cout << endl;
        }
      }
      /* cout << "++ans" << endl; */
      ++ans;
    }
  }

  cout << ans << endl;

  return 0;
}

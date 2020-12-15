#include <bits/stdc++.h>
using namespace std;

int H, W;
char grid[50][50];
pair<int, int> vec[4] = {make_pair(1,0), make_pair(-1,0), make_pair(0,1), make_pair(0,-1)};

int walk(int white);

int main(void){
  int white = 0; //answer is white - the number of grids where Sunuke walked
  cin >> H >> W;
  for(int i=0; i<50; ++i){
    for(int j=0; j<50; ++j){
      grid[i][j] = '#';
    }
  }
  for(int i=0; i<H; ++i){
    for(int j=0; j<W; ++j){
      cin >> grid[i][j];
      if(grid[i][j]=='.') ++white;
    }
  }
  
  /* search */

  int answer = walk(white);


  cout << answer << endl;
  
  return 0;
}

int walk(int white){
  grid[0][0] = '*';
  int walked = 1;
  bool flag;

  while(true){
    flag = false;
    ++walked;
    for(int i=0; i<H; ++i){
      for(int j=0; j<W; ++j){
        if(grid[i][j] == '*'){
          for(auto k=vec; k!=vec+4; ++k){
            if(i+ k->first < 0 || i+ k->first >= H || j + k->second < 0 || j + k->second >= W) continue;
            if(grid[i + k->first][j + k->second] == '.'){
              grid[i + k->first][j + k->second] = '_';
            }
          }
        }
      }
    }
    for(int i=0; i<H; ++i){
      for(int j=0; j<W; ++j){
        if(grid[i][j] == '_') {
          grid[i][j] = '*';
          flag = true;
        }
      }
    }

    if(grid[H-1][W-1] == '*') return white-walked;
    if(!flag) return -1;
  }
}

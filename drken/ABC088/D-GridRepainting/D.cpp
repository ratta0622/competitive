#include <bits/stdc++.h>
using namespace std;

int H, W;
char grid[50][50];

void search()

int main(void){
  int white = 0;
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
  while(true){
      
  }
  
  return 0;
}

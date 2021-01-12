#include <bits/stdc++.h>
using namespace std;
using P = pair<int, int>;
vector<P> vec{{1,0}, {-1,0}, {0,1}, {0,-1}};

int main(){
  vector<vector<char>> A(12, vector<char>(12, 'x'));
  for(int i=1; i<11; ++i){
    for(int j=1; j<11; ++j){
      cin >> A[i][j];
    }
  }

  /* choose a single grid filled */
  for(int i=1; i<11; ++i){
    for(int j=1; j<11; ++j){
      vector<vector<char>> B;
      B=A;
      B[i][j] = 'o';
      bool skip=false;
      bool flag = false;
      for(int k=1; k<11; ++k){
        for(int l=1; l<11; ++l){
          if(B[k][l] == 'x') continue;
          queue<P> BFS;
          BFS.push({k,l});
          while(!BFS.empty()){
            if(flag){
              skip = true;
              break;
            }
            if(skip) break;
            P prev = BFS.front();
            B[prev.first][prev.second] = 'x';
            BFS.pop();
            for(P v : vec){
              int x = prev.first+v.first;
              int y = prev.second+v.second;
              switch(B[x][y]){
                case 'x':
                  break;
                case 'o':
                  BFS.push({x,y});
              }
            }
          }
          flag = true;
          if(skip) break;
        }
        if(skip) break;
      }
      if(!skip){
        cout << "YES" << endl;
        return 0;
      }
    }
  }

  cout << "NO" << endl;

  return 0;
}

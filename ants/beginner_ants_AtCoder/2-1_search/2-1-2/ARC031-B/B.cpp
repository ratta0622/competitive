#include <bits/stdc++.h>
using namespace std;
using P = pair<int, int>;
vector<P> vec{{1,0}, {-1,0}, {0,1}, {0,-1}};

int main(){
  vector<vector<char>> A(10, vector<char>(10));
  for(int i=0; i<10; ++i){
    for(int j=0; j<10; ++j){
      cin >> A[i][j];
    }
  }

  /* choose a single grid filled */
  bool not_fill_checked = false;
  for(int i=0; i<10; ++i){
    for(int j=0; j<10; ++j){
      if(A[i][j] == 'o' && not_fill_checked) continue;
      if(A[i][j] == 'o') not_fill_checked = true;
      vector<vector<char>> B;
      B=A;
      B[i][j] = 'o';
      bool skip=false;
      for(int k=0; k<10; ++k){
        for(int l=0; l<10; ++l){
          if(B[k][l] == 'x') continue;
          queue<P> BFS;
          BFS.push({k,l});
          bool flag = false;
          while(!BFS.empty()){
            if(flag){
              skip = true;
              break;
            }
            if(skip) break;
            flag = true;
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

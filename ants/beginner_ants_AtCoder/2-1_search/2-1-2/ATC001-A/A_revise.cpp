#include <bits/stdc++.h>
#include <utility>
using namespace std;
using P = pair<int, int>;
vector<P> vec{{1,0}, {-1,0}, {0,1}, {0,-1}};
 
int main(){
  int H, W;
  char c[502][502];
  for(int i=0; i<502; ++i){
    for(int j=0; j<502; ++j){
      c[i][j] = '#';
    }
  }
  cin >> H >> W;
  P home;
  for(int i=1; i<H+1; ++i){
    for(int j=1; j<W+1; ++j){
      cin >> c[i][j];
      if(c[i][j]=='s') home = make_pair(i,j);
    }
  }
 
  stack<P> DFS;
  DFS.push(home);
  while(!DFS.empty()){
    P prev = DFS.top();
    c[prev.first][prev.second] = '#';
    DFS.pop();
    for(auto v : vec){
      /* cout << "v:" << v.first << " " << v.second << " "; */
      switch(c[prev.first + v.first][prev.second + v.second]){
        case '#':
          /* cout << "case:#" << endl; */
          break;
        case '.':
          /* cout << "case:." << endl; */
          DFS.push({prev.first+v.first, prev.second+v.second});
          break;
        case 'g':
          /* cout << "case:g" << endl; */
          cout << "Yes" << endl;
          return 0;
      }
    }
  }
 
  cout << "No" << endl;
 
  return 0;
}

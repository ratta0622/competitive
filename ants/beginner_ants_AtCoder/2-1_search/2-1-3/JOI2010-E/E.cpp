#include <bits/stdc++.h>
using namespace std;
using P = pair<int, int>;
vector<P> vec{{1,0}, {0,1}, {-1,0}, {0,-1}};

int main(){
  int H, W, N;
  cin >> H >> W >> N;
  vector<vector<char>> c(1002, vector<char>(1002,'X'));
  vector<P> cheese(10);
  for(int i=1; i<=H; ++i){
    for(int j=1; j<=W; ++j){
      char temp;
      cin >> temp;
      if(temp == '.' || temp == 'X'){
        c[i][j] = temp;
      }else if(temp == 'S'){
        cheese[0] = {i,j};
        c[i][j] = '.';
      }else{
        int num = temp-'0';
        cheese[num] = {i,j};
        c[i][j] = '.';
      }
    }
  }

  int ans = 0;
  for(int i=1; i<=N; ++i){
    vector<vector<int>> distance(1002, vector<int>(1002, -1));
    queue<P> BFS;
    P start = cheese[i-1];
    P goal = cheese[i];
    BFS.push(start);
    distance[start.first][start.second] = 0;
    while(!BFS.empty()){
      P prev = BFS.front();
      BFS.pop();
      for(auto v : vec){
        int h = prev.first + v.first;
        int w = prev.second + v.second;
        if(h == goal.first && w == goal.second){
          ans += distance[prev.first][prev.second] + 1;
          while(!BFS.empty()) BFS.pop();
          break;
        }
        if(distance[h][w] == -1 && c[h][w] == '.'){
          BFS.push({h,w});
          distance[h][w] = distance[prev.first][prev.second] + 1;
        }
      }
    }
  }
  
  cout << ans << endl;

  return 0;
}

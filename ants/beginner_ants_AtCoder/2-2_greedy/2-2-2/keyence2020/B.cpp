#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
  int N;
  cin >> N;
  map<ll,ll> robot;
  for(int i=0; i<N; ++i){
    ll X, L;
    cin >> X >> L;
    robot[X+L] = X-L;
  }

  for(auto i=robot.begin(); i!=prev(robot.end(),1); ++i){
    if(i == robot.end()) break;
    for(auto j=next(i,1); j!=robot.end(); ++j){
      if(i->first > j->second){
        robot.erase(j);
        --j;
      }
    }
  }

  cout << endl;
  for(auto i=robot.begin(); i!=robot.end(); ++i){
    cout << i->second << " " << i->first << endl;
  }
  cout << endl;

  cout << robot.size() << endl;

  return 0;
}

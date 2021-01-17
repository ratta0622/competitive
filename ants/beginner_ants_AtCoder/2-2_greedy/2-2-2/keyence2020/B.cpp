#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll,ll>;

int main(){
  int N;
  cin >> N;
  vector<P> robot(N);
  for(int i=0; i<N; ++i){
    ll X, L;
    cin >> X >> L;
    robot[i] = {X+L, X-L};
  }

  sort(robot.begin(), robot.end());

  /* for(auto i=robot.begin(); i!=prev(robot.end(),1); ++i){ */
  /*   if(i == robot.end()) break; */
  /*   for(auto j=next(i,1); j!=robot.end(); ++j){ */
  /*     if(i->first > j->second){ */
  /*       robot.erase(j); */
  /*       --j; */
  /*     } */
  /*   } */
  /* } */
  
  int ans = 1;
  ll comp = robot[0].first;
  for(auto i=next(robot.begin(),1); i!=robot.end(); ++i){
    if(comp > i->second) continue;
    ++ans;
    comp = i->first;
  }

  /* cout << endl; */
  /* for(auto i=robot.begin(); i!=robot.end(); ++i){ */
  /*   cout << i->second << " " << i->first << endl; */
  /* } */
  /* cout << endl; */

  cout << ans << endl;

  return 0;
}

#include <bits/stdc++.h>
using namespace std;
using P = pair<int, int>;

bool comp(P a, P b){
  int max_a = max(a.first, a.second);
  int max_b = max(b.first, b.second);
  int min_a = min(a.first, a.second);
  int min_b = min(b.first, b.second);
  if(max_a != max_b){
    return max_a < max_b; //bigger element
  }else{
    return min_a < min_b;
  }
}

int main(){
  int N;
  cin >> N;
  vector<P> wh(N);
  for(int i=0; i<N; ++i){
    int w,h;
    cin >> w >> h;
    wh[i].first = w;
    wh[i].second = h;
  }

  sort(wh.begin(), wh.end(), comp);

  /* for(auto i : wh){ */
  /*   cout << i.first << " " << i.second << endl; */
  /* } */

  int max_w=0;
  int max_h=0;
  int ans = 0;
  for(auto i : wh){
    if(i.first<=max_w || i.second<=max_h) continue;
    ++ans;
    max_w = i.first;
    max_h = i.second;
  }

  cout << ans << endl;


  return 0;
}

#include <bits/stdc++.h>
using namespace std;
using P = pair<int, int>;

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


  return 0;
}

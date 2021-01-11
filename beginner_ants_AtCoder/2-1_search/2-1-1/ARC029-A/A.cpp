#include <bits/stdc++.h>
#include <climits>
using namespace std;
#define rep(i,n) for(int i=0; i<(int)(n); ++i)

int main(){
  int N;
  cin >> N;
  int t[N];
  rep(i,N){
    cin >> t[i];
  }

  int ans = INT_MAX;
  for(int bit=0; bit<1<<N; ++bit){
    int time1=0, time2=0;
    for(int j=0; j<N; ++j){
      if(bit & (1<<j)) time1 += t[j];
      else time2 += t[j];
    }
    if(ans > max(time1,time2)) ans = max(time1, time2);
  }

  cout << ans << endl;

  return 0;
}

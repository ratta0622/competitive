#include <bits/stdc++.h>
#include <climits>
using namespace std;
using ll = long long;

int main(){
  int D;
  ll G;
  cin >> D >> G;
  int p[D];
  int c[D];
  for(int i=0; i<D; ++i){
    cin >> p[i] >> c[i];
  }

  int answer = INT_MAX;
  /* 1 -> solve all, 0 -> don't solve */ 
  for(int bit=0; bit<(1<<D); ++bit){
    ll point = 0;
    int times = 0;
    int max_0 = 0;
    for(int i=0; i<D; ++i){
      /* i th digit is 1 */
      if(bit>>i & 1){
        point += 100*(i+1)*p[i]+c[i];
        times += p[i];
      }else if(p[i]!=0){
        max_0 = i;
      }
    }
    for(int i=0; i<p[max_0]-1 && point<G; ++i){
      point += 100*(max_0+1);
      times += 1;
    }
    if(times<answer && point>=G) answer=times;
  }
  
  cout << answer << endl;

  return 0;
}

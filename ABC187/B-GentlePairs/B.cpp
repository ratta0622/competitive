#include <bits/stdc++.h>
using namespace std;

int main(){
  int answer = 0;
  int N;
  cin >> N;
  int x[N], y[N];
  for(int i=0; i<N; ++i){
    cin >> x[i] >> y[i];
  }
  
  int dx, dy;
  for(int j=1; j<N; ++j){
    for(int i=0; i<j; ++i){
      dx = x[i] - x[j];
      dy = y[i] - y[j];
      if(abs((double)dy/(double)dx)<=1) ++answer;
    }
  }

  cout << answer << endl;

  return 0;
}

#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin >> N;
  int A[2][N];
  int over[N] = {};
  int under[N] = {};
  int candy[N];
  for(int i=0;i<2;++i){
    for(int j=0;j<N;++j){
      cin >> A[i][j];
    }
  }
  
  over[0] = A[0][0];
  under[N-1] = A[1][N-1];
  for(int i=1; i<N; ++i){
    over[i] = over[i-1] + A[0][i];
    under[N-1-i] = under[N-i] + A[1][N-1-i];
  }

  for(int i=0; i<N; ++i){
    candy[i] = over[i] + under[i];
  }

  cout << *max_element(candy, candy+N) << endl;

  

  return 0;
}

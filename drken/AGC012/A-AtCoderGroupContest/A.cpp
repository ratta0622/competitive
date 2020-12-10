#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(void){
  int N;
  cin >> N;
  int a[3*N];
  for (int i=0; i<3*N; i++){
    cin >> a[i];
  }

  ll sum = 0;
  int team[N][3];
  
  sort(a, a+3*N, greater<int>());

  /* for(int i=0; i<N; i++){ */
  /*   team[i][0] = a[i]; //minimum */
  /* } */
  for(int i=0; i<N; i++){
    sum += a[2*i+1];
  }

  cout << sum << endl;

  return 0;
}

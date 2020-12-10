#include <bits/stdc++.h>
#include <climits>
using namespace std;

int main(void){
  int N;
  cin >> N;
  int X[N];
  for(int i=0; i<N; i++){
    cin >> X[i];
  }

  int min = INT_MAX;
  int sum;
  for(int i=1; i<=100; i++){
    sum = 0;
    for(int j=0; j<N; j++){
      sum += pow( (X[j]-i), 2);
    }
    if(sum < min) min = sum;
  }

  cout << min << endl;

  return 0;
}

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
  int A[3];
  for(int i=0; i<3; ++i){
    cin >> A[i];
  }
  sort(A, A+3);

  int count = 0;
  int diff = A[2]-A[1];
  count += diff;
  A[1] += diff;
  A[0] += diff;

  diff = A[2]-A[0];
  count += diff/2;
  A[0] += 2*(diff/2);
  
  if(A[0]!=A[2]) count += 2;

  cout << count << endl;

  return 0;
}

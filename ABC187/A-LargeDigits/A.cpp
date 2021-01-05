#include <bits/stdc++.h>
using namespace std;

int main(){
  int A, B;
  cin >> A >> B;
  int SA=0, SB=0;
  while(A!=0 || B!=0){
    SA += A%10;
    SB += B%10;
    A /= 10;
    B /= 10;
  }
  
  cout << max(SA, SB) << endl;

  return 0;
}

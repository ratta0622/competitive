#include <bits/stdc++.h>
using namespace std;

int main(void){
  int N, K;
  cin >> N >> K;
  int digit=0;
  while(true){
    ++digit;
    if(pow(K, digit)>N) break;
  }

  cout << digit << endl;

  return 0;
}

#include <bits/stdc++.h>

using namespace std;
using ll = long long;


int main(void){
  ll X, K, D;
  cin >> X >> K >> D;
  
  X = abs(X);
  
  ll straight_move = min(X/D, K); //move to x=0 point

  K -= straight_move;
  X -= straight_move*D;

  if(K%2==0){
    cout << X << endl;
  }else{
    cout << D-X << endl;
  }

  return 0;
}

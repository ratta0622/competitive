#include <bits/stdc++.h>
#include <climits>
using namespace std;
using ll = long long;

int main(){
  int A, B, C, X, Y;
  cin >> A >> B >> C >> X >> Y;

  int ABmax = max(X,Y);
  int value = 0;
  int min = INT_MAX;
  
  for(int i=0; i<=ABmax; ++i){
    value = 2*i*C;
    if(X>i){
      value += A*(X-i);
    }
    if(Y>i){
      value += B*(Y-i);
    }
    if(value < min) min = value;
  }

  cout << min << endl;

  return 0;
}

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
  ll X,Y;
  cin >> X >> Y;

  if(abs(X-Y)>1){
    cout << "Alice" << endl;
  }else{
    cout << "Brown" << endl;
  }

  return 0;
}

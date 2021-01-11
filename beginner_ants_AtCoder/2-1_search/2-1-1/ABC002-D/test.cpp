#include <bits/stdc++.h>
using namespace std;

int main(){
  int a=1;
  a = a<<4;
  a -= 1;
  int b = a&1<<3;
  int c = a&1<<1;
  cout << b << endl;
  cout << c << endl;
  int d = b&c;
  cout << d << endl;
  if((a&1<<3) && (a&1<<1)) cout << a << endl;

  return 0;
}

#include<bits/stdc++.h>
using namespace std;

int main(){
  int N, A, B;
  cin >> N >> A >> B;

  if((abs(A-B)-1)%2==0) cout << "Borys" << endl;
  else cout << "Alice" << endl;

  return 0;
}

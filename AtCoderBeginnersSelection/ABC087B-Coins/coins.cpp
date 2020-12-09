#include <iostream>
using namespace std;

int main(){
  int A,B,C,X;
  cin >> A >> B >> C >> X;

  int count = 0;

  int Amax = min(A, X/500);
  int Bmax = min(B, X/100);
  
  for(int i=0;i<=Bmax;i++){
    for(int j=0;j<=Amax;j++){
      if(500*j + 100*i <= X && 50*C >= X-500*j-100*i) count++;
    }
  }

  cout << count << endl;

  return 0;
}

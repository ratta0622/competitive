#include <iostream>
using namespace std;

int main(void){
  int A,B,C,X,Y;
  cin >> A >> B >> C >> X >> Y;
  
  long long int min = 5000*1e10;  

  int ABmax = max(X,Y);
  long long int value;

  for(int i=0;i<=ABmax;i++){
    int x = i;
    int y = i;
    value = 2*i*C;
    
    if(X>x) value += A*(X-x);
    if(Y>y) value += B*(Y-y);

    if(value < min) min = value;
  }

  cout << min << endl;

  return 0;
}

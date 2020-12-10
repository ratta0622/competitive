#include <iostream>

using namespace std;

int main(void){
  long long int X, K, D;
  cin >> X >> K >> D;

  long long int x=X;
  for(int i=1;i<=K;i++){
    if(abs(x) > D*( (K-i+1)/2 ) && K-i+1>2){
      if(x>0){
        x -= D*( (K-i+1)/2 );
      }else{
        x += D*( (K-i+1)/2 );
      }
      i += (K-i+1)/2 -1;
    }else if(abs(x) > D){
      if(x>0){
        x -= D;
      }else{
        x += D;
      }
    }else if( (K-i)%2==0 ){
      cout << abs(D-abs( x )) << endl;
      return 0;
    }else{
      cout << abs(x) << endl;
      return 0;
    }
  }

  cout << abs( x ) << endl;

  return 0;
}

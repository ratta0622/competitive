#include <iostream>
using namespace std;

int main(){
  int N,Y;
  cin >> N >> Y;

  int max10k = Y/10000;
  int max5k  = Y/5000;
  int k;
  
  for(int i=0;i<=max10k;i++){
    for(int j=0;j<=max5k;j++){
      if(10000*i + 5000*j >Y) break;
      k = (Y-10000*i-5000*j)/1000;
      if(i+j+k == N){
        cout << i << " " << j << " " << k << endl;
        return 0;
      }
    }
  }

  cout << -1 << " " << -1 << " " << -1 << endl;

  return 0;
}

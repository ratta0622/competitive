#include <iostream>
using namespace std;

int main(){
  int N;
  cin >> N;

  int d[N];
  for(int i=0;i<N;i++){
    cin >> d[i];
  }

  int under_d = 101;
  int count = 0;

  while(true){
    int min=0;
    for(int i=0;i<N;i++){
      if(d[i] < under_d && d[i] > min){
        min = d[i];
      }
    }
    if(min == 0){
      break;
    }else{
      count++;
    }
    under_d = min;
  }

  cout << count << endl;

  return 0;
}

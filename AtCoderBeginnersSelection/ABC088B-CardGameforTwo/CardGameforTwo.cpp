#include <iostream>
using namespace std;

int main(){
  int N;
  cin >> N;

  int a[N];
  for(int i=0;i<N;i++){
    cin >> a[i];
  }
  
  int A = 0;
  int B = 0;
  
  bool turn = true;

  while(true){
    int idx=0;
    for(int i=1;i<N;i++){
      if(a[idx] < a[i]) idx=i;
    }
    if(a[idx]==0) break;
    if(turn){
      A += a[idx];
    }else{
      B += a[idx];
    }
    turn = !turn;   
    a[idx] = 0;
  }

  cout << abs(A-B) << endl;

  return 0;
}

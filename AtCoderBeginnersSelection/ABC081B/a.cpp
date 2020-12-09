#include <iostream>
using namespace std;

int main(){
  int count = 0;
  bool flag = false;
  int N;
  cin >> N;

  int A[N];
  for(int i = 0;i<N;i++){
    cin >> A[i];
  }

  while(true){
    for(int i = 0;i<N;i++){
      if(A[i]%2 == 1){
        flag = true;
        break;
      }
      A[i] /= 2;
    }
    if(flag) break;
    count++;
  }
  
  cout << count << endl;

  return 0;
}

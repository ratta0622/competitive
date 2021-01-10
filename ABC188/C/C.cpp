#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  int N_pow = pow(2,N);
  int A[N_pow];
  for(int i=0; i<N_pow; ++i){
    cin >> A[i];
  }
  for(int i=1; i<=N-1; ++i){
    for(int j=0; j<N_pow; j+=(int)pow(2,i)){
       int max_num = *max_element(A+j, A+j+(int)pow(2,i));
       for(int k=j; k<j+(int)pow(2,i); ++k){
         if(A[k]!=max_num) A[k] = 0;
       }
    }

  /* for(int i=0; i<N_pow; ++i){ */
  /*   cout << A[i] << " "; */
  /* } */
  /* cout << endl; */

  }

  int answer;
  int buffer=INT_MAX;
  for(int i=0; i<N_pow; ++i){
    if(A[i]!=0 && A[i]<buffer){
      answer = i+1;
      buffer = A[i];
    }
  }

  cout << answer << endl;
  

  return 0;
}

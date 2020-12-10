#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void){
  int N;
  cin >> N;
  int L[N];
  for(int i=0;i<N;i++){
    cin >> L[i];
  }
  
  int count=0;
  vector<int> length = {0, 0, 0};
  bool flag=true;
    
  for(int i=0;i<N;i++){
    for(int j=i+1;j<N;j++){
      for(int k=j+1;k<N;k++){
        flag = true;
        if(L[i]==L[j] || L[j]==L[k] || L[k] == L[i]) flag=false;
        
        if(flag){
          length[0] = L[i];
          length[1] = L[j];
          length[2] = L[k];

          sort(length.begin(), length.end());

          /* if( length[0]+length[1] > length[2]) count++; */
          if( length[0]+length[1] > length[2]){
            count++;
          } 
        }
      }
    }
  }

  cout << count << endl;

  return 0;
}

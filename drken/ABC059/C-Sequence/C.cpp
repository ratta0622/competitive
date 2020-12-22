#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >>n;
  int a[n];
  for(int i=0; i<n; ++i){
    cin >> a[i];
  }

  bool flag = true;
  int sum=0;
  int count_true = 0;
  for(int i=0; i<n; ++i){
    sum += a[i];
    if(flag){
      if(sum>=0){
        count_true += (sum+1);
        sum = -1;
      }
    }else{
      if(sum<=0){
        count_true += (1-sum);
        sum = 1;
      }
    }
    flag = !flag;
  }

  flag = false;
  sum=0;
  int count_false = 0;
  for(int i=0; i<n; ++i){
    sum += a[i];
    if(flag){
      if(sum>=0){
        count_false += (sum+1);
        sum = -1;
      }
    }else{
      if(sum<=0){
        count_false += (1-sum);
        sum = 1;
      }
    }
    flag = !flag;
  }
  cout << min(count_true, count_false) << endl;

  return 0;
}

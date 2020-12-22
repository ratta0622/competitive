#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
  int N;
  cin >> N;
  int x[N], y[N], h[N];
  for(int i=0; i<N; ++i){
    cin >> x[i] >> y[i] >> h[i];
  }
  int top[101][101]={};
  
  for(int i=0; i<N; ++i){
    if(h[i]==0){
      top[x[i]][y[i]] = -1;
      continue;
    }
    for(int j=0; j<=100; ++j){
      for(int k=0; k<=100; ++k){
        if(top[j][k] == -1) continue;
        int high = h[i] + abs(j-x[i]) + abs(k-y[i]);
        if(top[j][k]==0){
          top[j][k] = high;
        }else if(top[j][k]!=high){
          top[j][k] = -1;
        }
      }
    }
  }

  int CX, CY, H;
  for(int i=0; i<=100; ++i){
    for(int j=0; j<=100; ++j){
      if(top[i][j]>0){
        CX=i;
        CY=j;
        H=top[i][j];
      }
    }
  }


  /* for(int i=0; i<=100; ++i){ */
  /*   for(int j=0; j<=100; ++j){ */
  /*     cout << top[i][j]; */
  /*   } */
  /*   cout << endl; */
  /* } */


  cout << CX << ' ' << CY << ' ' << H << endl;

  return 0;
}

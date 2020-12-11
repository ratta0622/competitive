#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(void){
  /* input */
  int c[3][3];
  for(int i=0; i<3; ++i){
    for(int j=0; j<3; ++j){
      cin >> c[i][j];
    }
  }

  int C[3][3];
  bool flag = false;

  for(int i=0; i<=*max_element(c[0], c[0]+3); ++i){
    if(flag) break;
    for(int idx=0; idx<3; ++idx){
      C[0][idx] = c[0][idx]-i;
    }
    for(int j=0; j<=*max_element(c[1], c[1]+3); ++j){
      if(flag) break;
      for(int idx=0; idx<3; ++idx){
        C[1][idx] = c[1][idx]-j;
      }
      for(int k=0; k<=*max_element(c[2], c[2]+3); ++k){
      if(flag) break;
        for(int idx=0; idx<3; ++idx){
          C[2][idx] = c[2][idx]-k;
        }
        if(C[0][0]==C[1][0] && C[1][0]==C[2][0] && C[0][1]==C[1][1] && C[1][1]==C[2][1] && C[0][2]==C[1][2] && C[1][2]==C[2][2]) flag = true;
      }
    }
  }

  flag?(cout << "Yes" << endl):(cout << "No" << endl);

  return 0;
}

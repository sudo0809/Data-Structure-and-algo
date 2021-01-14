#include<iostream>
using namespace std;

int main(){

  int n;
  cin>>n;

  int a[100][100];
  int cont_sum[100][100] = {0}; //Prefix matrix
  int s_col=0;
  int s_row=0;
  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      cin>>a[i][j];
      if(i==0 and j==0){
        cont_sum[i][j] = a[i][j];
      }
      else if(j>0 and i==0){
        cont_sum[i][j] = cont_sum[i][j-1] + a[i][j];
      }
      else if(j==0 and i!=0){
        cont_sum[i][j] = cont_sum[i-1][j] + a[i][j];
      }
      else if(j>0 and i>0){
        cont_sum[i][j] = cont_sum[i-1][j] + cont_sum[i][j-1] + a[i][j] - cont_sum[i-1][j-1];
      }
    }
  }

  int q;
  cin>>q;
  int tli, tlj, bri, brj;
  for(int i=0; i<q; i++){
    cin>>tli>>tlj>>bri>>brj;
    int sum = cont_sum[bri][brj] - cont_sum[tli-1][brj] - cont_sum[bri][tlj-1] + cont_sum[tli-1][tlj-1];
    cout<<sum;
  }

  // int sum = cont_sum[bri][brj] - cont_sum[tli-1][brj] - cont_sum[bri][tlj-1] + cont_sum[tli-1][tlj-1];
  // cout<<sum;

  return 0;
}

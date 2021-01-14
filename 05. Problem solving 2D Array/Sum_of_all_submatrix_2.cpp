  #include<iostream>
  using namespace std;

  int main() {

    int n;
    cin>>n;

    int a[100][100];
    int cont_sum[100][100] = {0};
    //Prefix matrix
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

    //print continued sum array
    for(int i=0; i<n; i++){
      for(int j=0; j<n; j++){
        cout<<cont_sum[i][j]<<" ";
      }
      cout<<endl;
    }

    int sum=0;
    // li = lower row; lj = lower column
    // bi = back row; bj = back column
    for(int li=0; li<n; li++){
      for(int lj=0; lj<n; lj++){
        for(int bi=li; bi<n; bi++){
          for(int bj=lj; bj<n; bj++){
            //Boundary condition
            if(li==0 and lj==0){
              sum += cont_sum[bi][bj];
            }
            else if(li==0 and lj>0){
              sum += cont_sum[bi][bj] - cont_sum[bi][lj-1];
            }
            else if(lj==0 and li>0){
              sum += cont_sum[bi][bj] - cont_sum[li-1][bj];
            }
            //Inner condition
            else{
              sum += cont_sum[bi][bj] - cont_sum[li-1][bj] - cont_sum[bi][lj-1] + cont_sum[li-1][lj-1];
            }
          }
        }
      }
    }
    // int li = 1;
    // int lj = 1;
    // int bi = 2;
    // int bj = 2;
    // sum = cont_sum[bi][bj] - cont_sum[li-1][bj] - cont_sum[bi][lj-1] + cont_sum[li-1][lj-1];
    cout<<sum;

    return 0;
  }

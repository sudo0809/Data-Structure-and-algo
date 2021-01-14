#include<iostream>
using namespace std;

bool subsetSum(int arr[], int *temp, int temp_idx, int vidx, int e, int sum){
    if(vidx==e){
        if(sum == 0 and temp_idx!=-1){
            return true;
        }
        return false;
    }

    //keeping the vidx element in temp
    temp_idx++;
    temp[temp_idx] = arr[vidx];
    sum += temp[temp_idx];
    bool ans1 = subsetSum(arr, temp, temp_idx, vidx+1, e, sum);

    //not keeping the vidx element in output
    sum -= temp[temp_idx];
    temp_idx--;
    bool ans2 = subsetSum(arr, temp, temp_idx, vidx+1, e, sum);

    if(ans1 or ans2){
        return true;
    }
    return false;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++){
            cin>>arr[i];
        }

        int temp[n]={0};
        if(subsetSum(arr, temp, -1, 0, n, 0)){
            cout<<"Yes"<<endl;
        }
        else{
            cout<<"No"<<endl;
        }
    }
}

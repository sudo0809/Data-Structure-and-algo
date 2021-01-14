#include<iostream>
#include<algorithm>
using namespace std;

bool compare(int a, int b){
    char a_char = '0' + a;
    char b_char = '0' + b;

    return a_char < b_char;
}

void subset_sum(int arr[], int *out, int n, int target, int base_ptr, int out_ptr, int sum){
    //base case
    if(sum == target){
        sort(out, out+out_ptr, compare);
        for(int i=0; i<out_ptr; i++){
            cout<<out[i]<<" ";
        }
        cout<<endl;
        return;
    }

    if(base_ptr==n){
        return;
    }

    for(int i=base_ptr; i<n; i++){
        if(sum+arr[i] <= target){
            sum += arr[i];
            out[out_ptr] = arr[i];
            out_ptr++;
            subset_sum(arr, out, n, target, i+1, out_ptr, sum);

            //backtracking
            sum -= arr[i];
            out_ptr--;
        }
    }
}

int main(){
    int n;
    cin>>n;
    int arr[150];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    int target;
    cin>>target;

    int out[150];
    subset_sum(arr, out, n, target, 0, 0, 0);
}

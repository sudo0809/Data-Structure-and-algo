#include<iostream>
#include<climits>
using namespace std;

int main()
{
    int n;
    cin>> n;

    int max_sum = INT_MIN;

    int arr[1000];

    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int left = -1;
    int right = -1;
    //Giving the start
    for(int i=0;i<n;i++){
        //Giving or Iterating the start for every start
        for(int j=i;j<n;j++){
            int sum = 0;
            //Element of subarray between index i and j
            for(int k=i;k<=j;k++){
                //cout<<arr[k]<<",";
                sum = sum + arr[k];
            }
            //cout<<sum<<endl;
            if(sum > max_sum){
                max_sum = sum;
                left = i;
                right = j;
            }
        }
    }

    cout<<"Max sum of the subarray is "<<max_sum<<"."<<endl;
    for (int i=left;i<=right;i++){
        cout<<arr[i]<<",";
    }

    return 0;
}

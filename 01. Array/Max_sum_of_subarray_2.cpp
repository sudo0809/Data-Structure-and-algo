#include<iostream>
#include<climits>
using namespace std;

int main()
{
    int n;
    cin>> n;

    int max_sum = INT_MIN;

    int arr[1000];
    int cumSum[1000] = {0};

    cin>>arr[0];
    cumSum[0] = arr[0];

    for(int i=1;i<n;i++){
        cin>>arr[i];
        cumSum[i] = cumSum[i-1] + arr[i];
    }
    int left = -1;
    int right = -1;
    //Giving the start
    for(int i=0;i<n;i++){
        //Giving or Iterating the start for every start
        for(int j=i;j<n;j++){
            int sum = 0;
            //sum of sub-array between index i and j
            sum = cumSum[j] - cumSum[i-1];
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


#include<iostream>
using namespace std;

int maxpoint = 0;
void winnerPoints(int arr[], int s, int e, int p1_points, int turn){
    if(s>=e){
        // cout<<p1_points<<endl;
        maxpoint = max(maxpoint, p1_points);
        return;
    }
    //2 ways to choose the point
    if(turn%2==0){
        //choose from start
        p1_points+= arr[s];
        winnerPoints(arr, s+1, e, p1_points, turn+1);

        //choose from last
        p1_points+= arr[e] - arr[s];
        winnerPoints(arr, s, e-1, p1_points, turn+1);
    }
    else{
        if(arr[s] > arr[e]){
            winnerPoints(arr, s+1, e, p1_points, turn+1);
        }
        else{
            winnerPoints(arr, s, e-1, p1_points, turn+1);
        }
    }

    return;
}

int main(){

    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    winnerPoints(arr, 0, n-1, 0, 0);
    cout<<maxpoint<<endl;

    return 0;
}

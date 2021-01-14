#include<iostream>
#include<algorithm>
using namespace std;

int cowStays(long long int stalls[], int n, int cows, long long int key){

    int firstCow = stalls[0];
    int i=1;
    int prevCowIdx = firstCow;
    while(cows-1){
        if(i==n){
            return 0;
        }
        else if(stalls[i] - prevCowIdx >= key){
            prevCowIdx = stalls[i];
            i++;
            cows--;
        }
        else{
            i++;
        }
    }
    return 1;
}

int main() {

    int n, c;
    cin>>n>>c;
    long long int stalls[n];
    for(int i=0; i<n; i++){
        cin>>stalls[i];
    }
    sort(stalls, stalls+n);
    long long int end = stalls[n-1];
    long long int s = stalls[0];
    int threshold = 0;
    while(s<=end){
        long long int mid = (s+end)/2;
        if(cowStays(stalls, n, c, mid)){
            s = mid+1;
            threshold = mid;
        }
        else{
            end = mid -1;
        }
    }
    cout<<threshold<<endl;
    return 0;
}

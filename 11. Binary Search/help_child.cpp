#include<iostream>
using namespace std;

int find_key(int a[], int n, int key){
    int s = 0;
    int e = n-1;
    while(s<=e){
        int mid =(s+e)/2;
        if(a[mid] == key){
            return mid;
        }
        else if(a[s] <= a[mid]){
            //element lies on the left or the right side of the part 1
            if(key<=a[mid] and key>= a[s]){
                e = mid -1;
            }
            else{
                s = mid +1;
            }
        }
        else{
            if(key<=a[e] and key>= a[mid]){
                s = mid + 1;
            }
            else{
                e = mid - 1;
            }
        }
    }

    return -1;
}

int main() {

    int n;
    cin>>n;
    int a[n];
    for(int i=0; i<n; i++){
        cin>>a[i];
    }

    int key;
    cin>>key;

    cout<<find_key(a,n,key)<<endl;

    return 0;
}

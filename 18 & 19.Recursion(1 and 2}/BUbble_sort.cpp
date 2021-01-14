#include<iostream>
using namespace std;

//Bubble sort Recursively
void bubble_sort(int a[], int n){
    if (n==1){
        return;
    }

    //rec case
    for(int j=0; j<n-1; j++){
        if(a[j] > a[j+1]){
            swap(a[j], a[j+1]);
        }
    }
    bubble_sort(a, n-1);

    return;
}

void bubble_sort_recursive(int a[], int j, int n){
    if(n==1){
        return;
    }

    if(j==n-1){
        //single pass of the current array has done
        return bubble_sort_recursive(a, 0, n-1);
    }
    //rec case
    if(a[j] > a[j+1]){
        swap(a[j], a[j+1]);
    }
    bubble_sort_recursive(a, j+1, n);
    return;
}

int main(){
    int a[] = {5,4,3,2,1};
    int n = 5; 

    // bubble_sort(a, n);
    bubble_sort_recursive(a, 0, n);

    for(int i=0; i<n; i++){
        cout<<a[i]<<" ";
    }
}

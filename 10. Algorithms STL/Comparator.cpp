#include<iostream>
using namespace std;

bool compare(int a, int b){
    cout<<"Comparing "<<a<<" and "<<b<<endl;
    return a<b;
}

//Bubble sort
void bubble_sort(int a[], int n, bool (&comp)(int a, int b)){

    for(int itr=1; itr<n; itr++){

        for(int j=0; j<(n-itr); j++){
            if(comp(a[j], a[j+1])){
                swap(a[j], a[j+1]);
            }
        }
    }

}

int main(){

    int n;
    cin>>n;

    int a[1000];
    for(int i=0; i<n; i++){
        cin>>a[i];
    }

    bubble_sort(a, n, compare);
    for(int i=0; i<n; i++){
        cout<<a[i]<<" ";
    }
}

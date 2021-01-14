#include<iostream>
#include<list>
using namespace std;

// template<typename T> or
template<class T>
int search(T arr[], int n, T key){
    for(int p=0; p<n; p++){
        if(arr[p]==key){
            return p;
        }
    }
    return n;
}

template<class ForwardIterator, class T>
ForwardIterator search(ForwardIterator start, ForwardIterator end, T key){

    while(start!=end){
        if(*start==key){
            return start;
        }
        start++;
    }
    return end;
}


int main(){
/*
    int arr[] = {1,2,3,4,5,6};
    int n = sizeof(arr)/sizeof(int);
    int key = 5;
    // cout<<search(arr, n, key)<<endl;

    float b[] = {1.1, 1.2, 1.3};
    float k = 1.2;
    cout<<search(b, 3, k)<<endl;
    */
    list<int> l;
    l.push_back(1);
    l.push_back(2);
    l.push_back(5);
    l.push_back(3);

    auto it = search(l.begin(), l.end(), 5);
    if(it==l.end()){
        cout<<"element is not present";
    }
    else{
        cout<<*it<<endl;
    }

    return 0;
}

#include<iostream>
#include<vector>
using namespace std;

int main() {


    vector<int> d{1,2,3,5,9};
    //Push back O(1) for most of the time
    d.push_back(17);

    //Pop back/ Remove the last element O(1)
    d.pop_back();

    //INsert some element in the middle
    d.insert(d.begin()+3, 100);
    //How many time you wnt a element to occur and added
    //complexity is O(N) where is N is the no. of elemnts added + elements shifted
    d.insert(d.begin()+2, 4, 204);

    //erase some elemet in the middle
    d.erase(d.begin()+2);
    d.erase(d.begin()+2, d.begin()+5);

    //size
    cout<<d.size()<<endl;
    cout<<d.capacity()<<endl;

    //we avoid shrink
    d.resize(8); //if the size is incresing more memory is allocated
    cout<<d.capacity()<<endl;

    //Remove all the element but the memory ocuppied is same
    d.clear();

    //empty
    if(d.empty()){
        cout<<"The vector is empty"<<endl;
    }
    cout<<d.size()<<endl;

    for(int x:d){
        cout<<x<<" ";
    }
    d.push_back(10);
    d.push_back(11);
    d.push_back(12);

    cout<<d.front()<<endl;
    cout<<d.back()<<endl;

    //Reserve
    int n;
    cin>>n;
    vector<int> v;
    //To avoid doubling, we use reserve function
    //Doubling consumes more time
    v.reserve(1000);
    for(int i=0; i<n; i++){
        int no;
        cin>>no;
        v.push_back(no);
    }
    cout<<"Capacity "<<v.capacity()<<endl;
    for(int x:v){
        cout<<x<<" ";
    }



    return 0;
}

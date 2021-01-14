#include<iostream>
#include "vector.h"
using namespace std;

int main(){
    Vector<int> v;

    v.push_back(1);

    v.push_back(3);
    v.push_back(4);
    v.push_back(5);
    v.pop_back();
    v.push_back(6);
    v.push_back(22);

    cout<<v.at(2)<<endl;
    cout<<v.operator[](2)<<endl;

    cout<<v.capacity()<<endl;
    for(int i=0; i<v.size(); i++){
        cout<<v[i]<<" ";
    }

    return 0;
}

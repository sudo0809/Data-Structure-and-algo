#include<iostream>
#include<cstring>
using namespace std;

//Let us define a vector class
class Vector{
    //Data Members and some functions
    int *arr;
    int cs;
    int maxSize;

public:
    Vector(int defaultSize=4){
        maxSize = defaultSize;
        cs = 0;
        arr = new int[maxSize];
    }

    //overloading round bracktes will make it functional objects
    void operator()(string s){
        cout<<s<<" Yeah!!!"<<endl;
    }


    void push_back(int data){
        if(cs==maxSize){
            //doubling operation
            int *oldarr = arr;
            arr = new int[maxSize*2];
            maxSize *= 2;

            for(int i=0; i<cs; i++){
                arr[i] = oldarr[i];
            }
            //Delete the old array
            delete [] oldarr;
        }
        arr[cs] = data;
        cs++;
    }

    bool empty(){
        return cs==0;
    }
    void pop_back(int data){
        if(!empty()){
            cs--;
        }
    }

    void print(){
        for(int i=0; i<cs; i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }

    int at(int i){
        return arr[i];
    }

    int getSize(){
        return cs;
    }
    int getMaxSize(){
        return maxSize;
    }

    int& operator[](int i){
        return arr[i];
    }

};

ostream& operator << (ostream &os, Vector &v){
    cout<<"In << operator"<<endl;
    v.print();
    return os;
}
istream& operator >> (istream &is, Vector &v){
    //Input a vector

    return is;
}


int main(){

    Vector v(20);
    v("inside my round brackets");
    for(int i=0;i<=6; i++){
        v.push_back(i*i);
    }
    // cout<<v.getSize()<<endl;
    // cout<<v.getMaxSize()<<endl;

    Vector fun;
    fun = v; //copy assignment operator

    cout<<fun;

    v.print();
    // cout<<v[2]<<endl;

    v[2] = 5;
    v[2] += 5;
    cout<<"Final value "<<v[2]<<endl;

}

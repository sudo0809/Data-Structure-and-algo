#include<iostream>
#include<vector>

using namespace std;
int main(){

    //Ways to initialize the vector
    vector<int> a;
    vector<int> b(5,10);
    vector<int> c(b.begin(), b.end());
    vector<int> d{1,2,4,5,6};

    //Look at how we can iterate over the vector
    for(int i=0; i<c.size(); i++){
        cout<<c[i]<<" ";
    }
    cout<<endl;

    for(auto it=b.begin(); it!=b.end(); it++){
        cout<<(*it)<<" ";
    }
    cout<<endl;

    //For each loop
    for(int x:d){
        cout<<x<<" ";
    }
    cout<<endl;

    //Discussing more func
    vector<int> v;
    int n;
    cin>>n;
    for(int i=0; i<n; i++){
        int no;
        cin>>no;
        v.push_back(no);
    }

    for(int x:v){
        cout<<x<<" ";
    }
    cout<<endl;

    //UNderstand at memory level - what are difference in d and v
    cout<<v.size()<<endl;
    cout<<v.capacity()<<endl; //no. of elemets that can be scored
    cout<<v.max_size()<<endl; //max no. of elements that can be scored

    cout<<d.size()<<endl;
    cout<<d.capacity()<<endl; //no. of elemets that can be scored
    cout<<d.max_size()<<endl; //max no. of elements that can be scored




    return 0;
}

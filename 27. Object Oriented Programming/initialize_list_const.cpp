#include<iostream>
#include<cstring>
using namespace std;

class Car{
private:
    float price;

public:
    int model;
    char *name;
    const int msp;
    //static allocation
    Car():msp(99){  //initializing list
        name=NULL;
    }
    Car(float p, int m, char *n, int minprice=99):price(p),msp(minprice){
        // price = p;
        model = m;
        name = new char[strlen(n)+1];
        strcpy(name,n);
    }

    Car(Car &X):msp(X.msp){
        cout<<"Inside Copy Constructor"<<endl;
        price = X.price;
        model = X.model;
        //this is done for deep copy
        name = new char[strlen(X.name)+1];
        strcpy(name, X.name);
    }
    void operator=(Car &X){
        cout<<"Copy Assignment Constructor"<<endl;
        price = X.price;
        model = X.model;
        //this is done for deep copy
        name = new char[strlen(X.name)+1];
        strcpy(name, X.name);
    }

    void setPrice(int p){
        price = p;
    }

    void print() const{
        cout<<"Name "<<name<<endl;
        cout<<"Model no. "<<model<<endl;
        cout<<"Price "<<price<<endl;
    }

    //Destructor od the object
    ~Car(){
        cout<<"Inside Destructor of car "<<name<<endl;
        //removing dynamically alocated memory
        if(name!=NULL){
            delete [] name;
        }
    }

};

int main(){
    Car c(100, 222, "BMW"); // parametrized constructor
    cout<<c.msp<<endl;

    Car d; // constructor
    d = c; //copy assignment constructor


    d.name[0] = 'A';
    d.setPrice(400);

    c.print();

    d.print();
}

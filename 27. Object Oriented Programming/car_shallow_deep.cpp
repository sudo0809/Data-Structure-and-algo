#include<iostream>
#include<cstring>
using namespace std;

class Car{
private:
    float price;

public:
    int model;
    char *name;

    Car(){
        name=NULL;
    }
    Car(float p, int m, char *n){
        price = p;
        model = m;
        name = new char[strlen(n)+1];
        strcpy(name,n);
    }

    Car(Car &X){
        price = X.price;
        model = X.model;
        //this is done for deep copy
        name = new char[strlen(X.name)+1];
        strcpy(name, X.name);
    }

    void setPrice(int p){
        price = p;
    }

    void print(){
        cout<<"Name "<<name<<endl;
        cout<<"Model no. "<<model<<endl;
        cout<<"Price "<<price<<endl;
    }

};

int main(){
    Car c(100, 222, "BMW"); // parametrized constructor
    Car d(c); //copy constructor
    d.name[0] = 'A';
    d.setPrice(400);

    c.print();
    d.print();
}

#include<iostream>
#include<cstring>
using namespace std;

//access specifier - public and private

//defining a new Datatype
class Car{
private:
    float price;

public:
    int model_no;
    char name[20];

    //Construtor
    Car(){
        cout<<"Inside Car Constructor  "<<endl;
    }
    //parameterised constructor
    Car(float p, int m, char*n){
        price = p ;
        model_no = m;
        strcpy(name, n);
    }
    //Hidden copy Constructor
    Car(Car &x){
        cout<<"Copy Construtor ";
        price = x.price;
        model_no = x.model_no;
        strcpy(name, x.name);
    }

    void print(){
        cout<<"Name "<<name<<endl;
        cout<<"Model no. "<<model_no<<endl;
        cout<<"Price "<<price<<endl;
    }

    float get_discounted_price(float x){
        return (price*(1.0-x));
    }

    float apply_discount(float x){
        price = price*(1.0-x);
        return price;
    }
    //setter
    void set_price(float p){
        int msp = 111; //min set price
        if(p>msp){
            price = p;
        }
        else{
            price = msp;
        }
    }
    //getter
    float get_price(){
        return price;
    }
};

int main(){

    Car c;
    Car d(222,300,"Audi");

    cout<<"Car d"<<endl;
    d.print();

    Car e(d); //copyconstructor
    //anothr way of calling copy Constructor
    Car f = e; // Also a copy Construtor
    cout<<"Car E"<<endl;
    e.set_price(1000);
    e.print();

    c.model_no = 112;
    c.name[0] = 'B';
    c.name[1] = 'M';
    c.name[2] = 'W';
    c.name[3] = '\0';

    c.set_price(100);

    cout<<"Car C"<<endl;
    c.print();
}

#include<iostream>
using namespace std;

//access specifier - public and private

//defining a new Datatype
class Car{
private:
    float price;

public:
    int model_no;
    char name[20];

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
        if(p>0){
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
    //create an object
    Car c;

    // cout<<"size of object c "<<sizeof(c)<<endl;
    // cout<<"size of a class Car "<<sizeof(Car)<<endl;

    // c.price = 100; //cant intialize as price is private
    c.model_no = 112;
    c.name[0] = 'B';
    c.name[1] = 'M';
    c.name[2] = 'W';
    c.name[3] = '\0';

    c.set_price(-10);

    c.print();
}

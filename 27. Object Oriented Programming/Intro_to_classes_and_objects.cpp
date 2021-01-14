#include<iostream>
using namespace std;

//defining a new Datatype
class Car{
public:
    float price;
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
};

int main(){
    //create an object
    Car c;

    // cout<<"size of object c "<<sizeof(c)<<endl;
    // cout<<"size of a class Car "<<sizeof(Car)<<endl;

    c.price = 100;
    c.model_no = 112;
    c.name[0] = 'B';
    c.name[1] = 'M';
    c.name[2] = 'W';
    c.name[3] = '\0';

    // cout<<c.name<<" Model no "<<c.model_no<<" Price "<<c.price<<endl;
    c.print();

    cout<<"Enter the discount you want to give ";
    float discount;
    cin>>discount;
    cout<<"Discounted price is "<<c.apply_discount(discount)<<endl;

    c.print();
    //creating an array of Datatype Car
    Car arr[20];//store info about max 20 Cars


    return 0;
}

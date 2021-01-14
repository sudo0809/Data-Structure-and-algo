#include<iostream>
#include<stack>
using namespace std;

void stockSpan(int price[], int n, int span[]){

    stack<int> s; //indices of the days
    s.push(0);
    span[0] = 1;
    for(int i=1; i<n; i++){
        int currentPrice = price[i];
        //topmst element higher than the current price
        while(!s.empty() and price[s.top()]<=currentPrice){
            s.pop();
        }

        if(!s.empty()){
            int pre_highest = s.top();
            span[i] = i - pre_highest;
        }
        else{
            span[i] = i+1;
        }

        //push this element into the Stack
        s.push(i);
    }
}

int main(){

    int prices[] = {100,80,60,70,60,75,85};
    int n = sizeof(prices)/sizeof(int);
    int span[10000] = {0};

    stockSpan(prices, n, span);
    for(int i=0; i<n; i++){
        cout<<span[i]<<" ";
    }

}

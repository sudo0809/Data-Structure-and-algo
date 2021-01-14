#include<iostream>
#include<stack>
using namespace std;

int getMaxArea(int hist[], int n){
    stack<int> s;

    int max_area = 0;
    int tp; //store top of stack here
    int area_with_top;

    int i=0;
    while(i<n){
        if(s.empty() || hist[s.top()] <= hist[i]){
            s.push(i);
            i++;
        }
        else{
            tp = s.top();
            s.pop();

            if(s.empty()){
                area_with_top = hist[tp] * i;
            }
            else{
                area_with_top = hist[tp]*(i-s.top()-1);
            }

            max_area = max(max_area, area_with_top);
        }
    }

    while(s.empty() == false){
        tp = s.top();
        s.pop();

        if(s.empty()){
            area_with_top = hist[tp] * i;
        }
        else{
            area_with_top = hist[tp]*(i-s.top()-1);
        }

        max_area = max(max_area, area_with_top);
    }

    return max_area;
}

int main(){
    // int histogram[] = {6,1,5,6,5,7};
    // int histogram[] = {6,2,5,4,5,1,6};
    // int n = sizeof(histogram)/sizeof(int);
    int n;
	cin>>n;
	int histogram[106];
	for(int i=0; i<n; i++){
		cin>>histogram[i];
	}

    cout<<getMaxArea(histogram, n)<<endl;

    return 0;
}

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<string> a;

void DictOrder(string str, string temp, int ptr){
    if(str[ptr] == '\0'){

        if(str>temp){
            a.push_back(str);
        }
        return;
    }

    for(int i=ptr; str[i]!='\0'; i++){
        // temp[ptr] = str[i];
        swap(str[i], str[ptr]);
        DictOrder(str, temp, ptr+1);
        swap(str[i], str[ptr]);
    }

    return ;
}


int main(){
    string str;
    cin>>str;

    string temp;
    temp = str;
    DictOrder(str, temp, 0);

    sort(a.begin(), a.end());
    for(auto i:a){
        cout<<i<<endl;
    }


    return 0;
}

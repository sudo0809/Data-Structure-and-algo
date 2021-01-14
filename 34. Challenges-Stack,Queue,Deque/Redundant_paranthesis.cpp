#include<iostream>
#include<list>
using namespace std;

bool wasteParanthesis(char a[]){
    list<char> s;
    int count=0;
    for(int i=0; a[i]!='\0';i++){

        if(a[i]==')'){
            while(s.back()!='('){
                s.pop_back();
                count++;
            }
            //pop the opening paranthesis seperately '('
            s.pop_back();
            if(count==0){
                return false;
            }
            else{
                count=0;
            }
        }
        else{
            s.push_back(a[i]);
        }
    }

    return true;
}

int main(){
    int t;
    cin>>t;
    char a[100];

    while(t--){
        cin>>a;
        if(wasteParanthesis(a)){
            cout<<"Not Duplicates"<<endl;
        }
        else{
            cout<<"Duplicate"<<endl;
        }
    }

    return 0;
}

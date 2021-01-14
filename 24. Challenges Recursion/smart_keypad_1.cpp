#include<iostream>
#include<cstring>
using namespace std;

string table[] = { " ", ".+@$", "abc", "def", "ghi", "jkl" , "mno", "pqrs" , "tuv", "wxyz" };

void keypadArrange(char s[], char* temp, int idx, int n){
    if(idx==n){
        temp[idx] = '\0';
        cout<<temp<<endl;
        return;
    }

    int keypad_num = s[idx] - '0';
    // temp[idx] = table[keypad_num]
    int keypad_char_available = table[keypad_num].size();

    for(int i=0; i<keypad_char_available; i++){
        temp[idx] = table[keypad_num][i];
        keypadArrange(s, temp, idx+1, n);
    }

    return;
}

int main(){
    char s[10];
    cin>>s;

    char temp[10];
    // cout<<table[1].size()<<endl;
    keypadArrange(s, temp, 0, strlen(s));
}

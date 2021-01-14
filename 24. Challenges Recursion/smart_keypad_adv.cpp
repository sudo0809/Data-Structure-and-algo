#include<iostream>
#include<cstring>
using namespace std;

string searchIn [] = {
            "prateek", "sneha", "deepak", "arnav", "shikha", "palak",
            "utkarsh", "divyam", "vidhi", "sparsh", "akku"
    };

string table[] = { " ", ".+@$", "abc", "def", "ghi", "jkl" , "mno", "pqrs" , "tuv", "wxyz" };

string combos[1000];
int combo_idx=0;

// bool searchString(string *name, char temp[], int e, int s, int name_ptr, int name_len){
//     ///base case
//     if(s==e){
//         return true;
//     }
//     if(name_ptr == name_len){
//         return false;
//     }
//
//     //rec case
//     if(name[name_ptr] == temp[s]){
//         if(searchString(name, temp, e, s++, name_ptr++, name_len)){
//             return true;
//         }
//         //backtracking
//         s--;
//         name_ptr--;
//     }
//     if(searchString(name, temp, e, s, name_ptr++, name_len)){
//         return true;
//     }
//
//     return false;
// }

void checkInStr(char temp[], int n){

    for(int i=0; i<=10; i++){

        int found=searchIn[i].find(temp);
            if(found!=-1)
            {
                cout<<searchIn[i]<<endl;
            }

        // int searchStringLen = searchIn[i].size();
        // // cout<<searchStringLen<<endl;
        // if(searchString(&searchIn[i], temp, n, 0, 0, searchStringLen)){
        //     cout<<searchIn[i]<<endl;
        // }
    }
    return;
}


void keypadArrange(char s[], char* temp, int idx, int n){
    if(idx==n){
        temp[idx] = '\0';
        // cout<<temp<<endl;
        checkInStr(temp, idx);
        // combos[combo_idx] = temp;
        // combo_idx++;
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

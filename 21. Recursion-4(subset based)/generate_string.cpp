#include<iostream>
using namespace std;

char letter_to_number[27] = {'.','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};

void generate_strings(char *in, char *out, int i, int j){

    //base case
    if(in[i] == '\0'){
        out[j] = '\0';
        cout<<out<<endl;
        return;
    }

    //rec case
    //Taking one digit
    int firstDigit = in[i] - '0';
    out[j] = letter_to_number[firstDigit];
    generate_strings(in, out, i+1, j+1);

    //Taking 2 digits only if the number is less than 26
    if(in[i+1] != '\0'){
        int secondDigit = in[i+1] - '0';
        int secondNum = 10*firstDigit + secondDigit;

        if(secondNum<=26){
            out[j] = letter_to_number[secondNum];
            generate_strings(in, out, i+2, j+1);
        }
    }

    return ;
}

int main(){

    char in[100];
    cin>>in;

    char out[100];

    generate_strings(in, out, 0, 0);

}

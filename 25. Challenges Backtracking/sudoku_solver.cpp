#include<iostream>
#include<cmath>
using namespace std;

bool NumberPossible(int num, int sudoku[][9], int i, int j, int n){

    //checking horizontal and vertical directions
    for(int x=0; x<n; x++){
        if(sudoku[x][j] == num || sudoku[i][x] == num){
            return false;
        }
    }

    //checking subboxes
    int rn = sqrt(n);
    int subX = (i/rn)*rn;
    int subY = (j/rn)*rn;
    for(int a=subX; a<subX+rn; a++){
        for(int b=subY; b<subY+rn; b++){
            if(sudoku[a][b]==num){
                return false;
            }
        }
    }

    return true;
}

bool solver(int sudoku[][9], int i, int j, int n){

    if(i==n){
        //print the solved sudoku
        for(int a=0; a<n; a++){
            for(int b=0; b<n; b++){
                cout<<sudoku[a][b]<<" ";
            }
            cout<<endl;
        }
        return true;
    }

    if(j==n){
        return solver(sudoku, i+1, 0, n);
    }

    if(sudoku[i][j]!=0){
        return solver(sudoku, i, j+1, n);
    }

    for(int number=1; number<=n; number++){
        if(NumberPossible(number, sudoku, i, j, n)){
            sudoku[i][j] = number;

            if(solver(sudoku, i, j, n)){
                return true;
            }
        }
    }

    sudoku[i][j] = 0; // backtracking
    return false;
}

int main(){

    int n;
    cin>>n;

    int sudoku[9][9];

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>sudoku[i][j];
        }
    }

    bool isSudokuSolved = solver(sudoku, 0, 0, n);
    if (isSudokuSolved==false){
        cout<<"No solution of this sudoku"<<endl;
    }

    return 0;
}

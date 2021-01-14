#include<iostream>
using namespace std;

int cnt = 0;

bool isSafe(int board[][10], int i, int j, int n){
    //You can check col
    for(int row=0; row<i; row++){
        if(board[row][j] == 1){
            return false;
        }
    }

    //You can check for Right Diagonal
    int x = i;
    int y = j;

    while(x>=0 && y<n){
        if(board[x][y] == 1){
            return false;
        }
        x--;
        y++;
    }

    //Check for left diagonal too
    x = i;
    y = j;
    while(x>=0 && y>=0){
        if(board[x][y] == 1){
            return false;
        }
        x--;
        y--;
    }
    return true;
}

bool solveNQueen(int board[][10], int i, int n){
    //base case
    if(i==n){
        //You have successfully place queen in n rows(1...n-1)
        //Print the board
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<n;j++){
        //         if(board[i][j]==1){
        //             cout<<"Q ";
        //         }
        //         else{
        //             cout<<"_ ";
        //         }
        //     }
        //     cout<<endl;
        // }
        // cout<<endl<<endl;
        cnt++;
        return false;
    }

    //recursive case
    //Try to place the queen in the current row
    //and call on the remaining part of the board
    for(int j=0; j<n; j++){
        if(isSafe(board, i, j, n)){
            //Place the queen - Assuming i,j is the right position
            board[i][j] = 1;

            bool nextQueenRakhPaye = solveNQueen(board, i+1, n);
            if(nextQueenRakhPaye){
                return true;
            }
            //Means i,j is not the correct position as above is false
            //so Backtracking
            board[i][j] = 0; //Backtracking
        }
    }
    //You have tried for all position int the current row
    return false;
}


int main(){
    int n;
    cin>>n;

    int board[10][10] = {0};
    solveNQueen(board, 0, n);

    cout<<cnt<<endl;
    return 0;
}

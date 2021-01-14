#include<iostream>
#include<cstring>
using namespace std;

#define MOD 1000000007
int board[100][100];

int numWays(int row, int col){

    //base case
    if(board[0][0]==-1){
        return 0;
    }
    //otherwise
    //compute for first row
    for(int j=0; j<col; j++){
        if(board[0][j]==-1){
            break;
        }
        board[0][j]=1;
    }
    //compute for first col
    for(int i=0; i<row; i++){
        if(board[i][0]==-1){
            break;
        }
        board[i][0]=1;
    }
    //for rest of the board
    for(int i=1;i<row;i++){
        for(int j=1; j<col; j++){

            if(board[i][j]==-1){
                continue ;
            }
            board[i][j] = 0;

            if(board[i][j-1]!=-1){
                board[i][j] = board[i][j-1]%MOD;
            }
            if(board[i-1][j]!=-1){
                board[i][j] = (board[i][j]+board[i-1][j])%MOD;
            }
        }
    }
    //check for final cell
    if(board[row-1][col-1]==-1){
        return 0;
    }
    //Print the entire board
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }

    return board[row-1][col-1];
}

int main(){
    int row, col,num_of_blocked_cell;
    cin>>row>>col>>num_of_blocked_cell;
    memset(board, 0, sizeof(board));

    for(int i=0; i<num_of_blocked_cell; i++){
        int X,Y;
        cin>>X>>Y;
        //marking the blocked cell as -1;
        board[X-1][Y-1] = -1;
    }
    cout<<numWays(row,col)<<endl;

    return 0;
}

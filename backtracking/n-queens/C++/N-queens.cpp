/*
    author : @rishabhkumar112
    The only line of input consists of the dimension of chessboard(n).
    If the solution exits the program prints a nxn chessboard with 1 denoting that the queen is present in that cell.
    If the solution doesn't exist the program prints "NOt Possible" (without quotes).
*/

#include <bits/stdc++.h>
using namespace std ;
int n ; // dimension of chessboard.
int board[20][20] = {} ;

// checks whether a particular cell is safe or not //
int is_attacked(int r, int c) {
    int i, j ;
    //rows 
    for(j = 0; j<n; j++) {
        if(board[r][j] == 1)
        return true;
    }
    //columns 
    for(i = 0; i<n; i++) {
        if(board[i][c] == 1)
        return true ;
    }
    //diagonal 
    for(i = 0; i<n; i++) {
        for(j = 0; j<n; j++) {
            if(board[i][j] == 1 && i+j == r+c)
            return true ;
        }
    }
    for(i = 0; i<n; i++) {
        for(j = 0; j<n; j++) {
            if(board[i][j] == 1 && i-j == r-c)
            return true;
        }
    }
    
    return false ;
}

bool queens(int size) {
    int i, j ;
    if(size == 0) 
    return true;
    else {
        for(i = 0; i<n; i++) {
            for(j = 0; j<n; j++) {
                if(is_attacked(i, j) == 1) // cell is not safe. 
                continue ;
                
                board[i][j] = 1;  // place the queen on cell--(i, j).
                
                if(queens(size-1) == true) 
                return true ;
                
                board[i][j] = 0; // solution not found, so revert changes.
            }
        }
    }
    
    return false ;
}

int main () {
    int i, j;
    cin >> n;
    int size = n ;
    if(queens(size) == true) {
        for(i = 0; i<n; i++) {
            for(j = 0; j<n; j++) {
                cout << board[i][j] << ' ';
            }
            cout<<'\n';
        }
    }
    else
    cout<<"Not possible";
    
    return 0;
}

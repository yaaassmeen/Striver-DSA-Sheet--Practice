//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// UNASSIGNED is used for empty cells in sudoku grid 
#define UNASSIGNED 0  

// N is used for the size of Sudoku grid.  
// Size will be NxN  
#define N 9  


// } Driver Code Ends
class Solution 
{
    bool isValid(int board[N][N], int row, int col, int num) {
    // Check if num is already present in the same row or column
    for (int i = 0; i < N; i++) {
        if (board[row][i] == num) {
            return false;
        }
        if (board[i][col] == num) {
            return false;
        }
    }

    // Check if num is already present in the 3x3 subgrid
    int subgridStartRow = row - row % 3;
    int subgridStartCol = col - col % 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[subgridStartRow + i][subgridStartCol + j] == num) {
                return false;
            }
        }
    }

    return true;
}
    
    public:
    //Function to find a solved Sudoku. 
    bool SolveSudoku(int board[N][N])  
    { 
        // Your code here
        int row = -1, col = -1;
    bool isEmptyCell = false;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (board[i][j] == 0) {
                row = i;
                col = j;
                isEmptyCell = true;
                break;
            }
        }
        if (isEmptyCell) {
            break;
        }
    }

    // If no empty cell is found, the Sudoku is solved
    if (!isEmptyCell) {
        return true;
    }

    // Try different numbers from 1 to 9 in the empty cell
    for (int num = 1; num <= 9; num++) {
        if (isValid(board, row, col, num)) {
            // Place the number in the empty cell
            board[row][col] = num;

            // Recursively solve the Sudoku
            if (SolveSudoku(board)) {
                return true;
            }

            // If the current placement leads to no solution, undo it
            board[row][col] = 0;
        }
    }

    // If no number can be placed in the current empty cell, backtrack
    return false;
    }
    
    //Function to print grids of the Sudoku.
    void printGrid (int grid[N][N]) 
    {
        // Your code here 
        for(int i = 0;i< N;i++){
            for(int j=0;j<N;j++){
                cout<<grid[i][j]<<" ";
            }
        }
    }
};

//{ Driver Code Starts.

int main() {
	int t;
	cin>>t;
	while(t--)
	{
		int grid[N][N];
		
		for(int i=0;i<9;i++)
		    for(int j=0;j<9;j++)
		        cin>>grid[i][j];
		        
		Solution ob;
		
		if (ob.SolveSudoku(grid) == true)  
            ob.printGrid(grid);  
        else
            cout << "No solution exists";  
        
        cout<<endl;
	}
	
	return 0;
}
// } Driver Code Ends

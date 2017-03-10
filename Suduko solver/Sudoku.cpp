#include "Suduko.h"

void Sudoku::FillGrid()
{
	//Filling the grid using user input from .txt file.
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> m_Grid[i][j];
		}
	}
}


bool Sudoku::inRow(int row, int val)
{
	for (int i = 0; i < 9; i++) {    //iterating through all columns.
		if (m_Grid[row][i] == val)  //constant row.
			return true;    //returns true if found.
	}
	return false;  //false if not found.
}


bool Sudoku::inCol(int col, int val)
{
	for (int i = 0; i < 9; i++) {   //iterating through rows.
		if (m_Grid[i][col] == val)  // constant column.
			return true;       //returns true if found.
	}
	return false;   //false if not found.
}


bool Sudoku::inSubGrid(int intRow, int intCol, int val)
{
	/*introw: used to alter the search area to search in desired row.
	//intcol: used to alter the search area to search in desired col.
	Their values are calculated in the function isValid.*/

	//search in the current subgrid for the value val.
	for (int i = 0; i < 3; i++) { 
		for (int j = 0; j < 3; j++) {
			if (m_Grid[i + intRow][j + intCol] == val)
				return true;   //returns true if found.
		}
	}
	return false;    //returns false if not found.
}


bool Sudoku::isValid(int row, int col, int val)
{
	int rR = row - (row % 3);   //used in the function check subgrid
	int rC = col - (col % 3);   //used in the function check subgrid

	/*if not in row, not col, not in subgrid, then it's valid*/
	return !inRow(row, val) && !inCol(col, val) && !inSubGrid(rR, rC, val);
}


bool Sudoku::Done(int &row, int& col)
{
	for (row = 0; row < 9; row++) {
		for (col = 0; col < 9; col++) {
			if (m_Grid[row][col] == 0) //if a cell is still empty.
				return false;  //then we aren't done yet.
		}
	}
	return true;  //if all cells are filled, then we are done solving.
}


bool Sudoku::Play()
{
	/*the function Done, changes the values i and j to point exactly
	at the empty cell, so we can try putting numbers in there to fill it*/
	int i, j;

	if (Done(i, j))   //if done solving, return true.
		return true;

	//trying all possible values for an empty cell.
	for (int val = 1; val <= 9; val++) {
		if (isValid(i, j, val)) {  //if valid move.
			m_Grid[i][j] = val;  //try the current val.
			if (Play())  //if the current value fits in.
				return true;  //we found a match.

			/*if not true, then the current value doesn't fit, so we 
			unmark it, and try another value. */
			m_Grid[i][j] = 0;  //unmark.
		}
	}
	return false;  //backtrack to find the perfect fit.
}


void Sudoku::Solve()
{
	if (Play())   //if it's solvable, solve it and print solution.
		Print();
	else
		cout << "NO SOLUTION";  //Wrong configuration.
}


void Sudoku::Print()
{
	//Printing the solved grid.
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cout <<" "<< m_Grid[i][j] << " ";
		}
		cout << endl;
	}
}
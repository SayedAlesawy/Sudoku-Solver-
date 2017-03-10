#include "Solution.h"

class Sudoku
{
private:
	int m_Grid[9][9];  //Square grid.

	/*A function to check if a value is present in the current row*/
	bool inRow(int row, int val);

	/*A function to check if a value is present in the current column*/
	bool inCol(int col, int val);

	/*A function to check if a value is present in the current 3x3 subgrid*/
	bool inSubGrid(int intRow, int intCol,int val);

	/*A function to verify that a value is not present in neither the current
	cell nor the current coloumn, nor the current subgrid, thus a valid move*/
	bool isValid(int row, int col, int val);

	/*A function to check whether the whole game has been solved or not*/
	bool Done(int &row, int& col);

	/*A fcuntion to solve the grid using backtracking*/
	bool Play();

	/*A function to print the grid after being solved*/
	void Print();

public:
	/*A function to read user input from a file that contains the grid description*/
	void FillGrid();

	/*A function to orchestrate the solving process*/
	void Solve();
};
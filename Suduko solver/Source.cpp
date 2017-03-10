#include "Suduko.h"

int main()
{
	//changes the buffer input to .txt files.
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	//---------------------------------------

	Sudoku Sd;   //creating a object of type Sudoku.

	Sd.FillGrid();  //fill the grid.

	Sd.Solve();  //solve it.

	return 0;    //Done.
}
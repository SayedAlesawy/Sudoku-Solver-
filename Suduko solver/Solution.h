#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;


/*
Approach:

I am using a simple backtracking algorithm to brute force the solution of 
the grid, the main steps are:

1- Check if the grid has an empty cell.

2- If there is an empty cell then we are not done yet, so try every 
   possible number that can fill that cell starting from 1 all the way to 9 
   in each iteration, I put the value in the empty cell I have identified, 
   earlier, then I recursively call the function with the new gird 
   i.e."the old grid+ the recently added value", the function continues 
   and ends up with one of either possibilities:
     A) The added value fits in and a solution is found
     B) The value doesn't fit, i.e. makes it not feasible to complete 
	    solving the gird, so I unmark "undo" or "remove" the added value, 
		and try another one.

3- Continue to do step 2 until I either don't find a solution or 
   no solution at all.

   Notes:
   1- I think a no solution would be a result of an invalid configuration 
      or maybe some other mathematical reason that I haven't gone deep 
	  into :V

   2- The time complexity of this algorithm is exponential, but I have tried
      multiple problems, and my lenovo z51 takes fractions of a second to 
	  solve a normal 9X9 grid even for the most evil configurations, so I
	  didn't feel the need to add any optimizations.
*/
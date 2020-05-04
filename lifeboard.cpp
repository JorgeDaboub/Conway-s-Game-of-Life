// Lifeboard implementation
// By: Jorge Daboub
//
#include<iostream>
#include<cstdlib>
#include<unistd.h>
#include"lifeboard.h"
using namespace std;

// Constructor
Board::Board() {
	for(auto i = 0; i < len; i++)
		for(auto j = 0; j < len; j++)  
			current[i][j] = false;
}
// Deconstroctor
Board::~Board() {}

// Option to turn delays off
void Board::noDelay() {delay = false;}

// Displaying the board
void Board::Display() {

	if(delay)	
		usleep(100000);

	system("clear");

	// For loop to print the output
	for (int i = 0; i < (len + 2); i ++) {

		// Prints the boundary
		if((i == 0) || (i == (len + 1))) {
			for(int i = 0; i < (len+2); i++)
				cout << "-";
			cout << endl;
		}
		else {
			cout << "|";
			// Printing the cells
			for(int j = 0; j < len; j++) {
				if(current[i-1][j] == true)
					cout << "X";
				else
					cout << " ";
			}
			cout << "|" << endl;
		}
	}
}

// Updating individual cells
void Board::UpdateCell(int a, int b, bool t) {current[a][b] = t;}

void Board::Next() {
	int nearby;
	// Chekcing all the cells
	for(int r = 0; r < len; r++)
		for(int c = 0; c < len; c++){
			//Checking all adjecent cells and adding them up
			nearby = 0;
			if((c-1) >= 0)
				if(current[r][c-1])
					nearby++; 
			if((c+1) < len)
				if(current[r][c+1])
					nearby++; 
			if((r-1) >= 0)
				if(current[r-1][c])
					nearby++; 
			if(((r-1) >= 0) && ((c-1) >= 0))
				if(current[r-1][c-1])
					nearby++; 
			if(((r-1) >= 0) && ((c+1) < len))
				if(current[r-1][c+1])
					nearby++; 
			if(((r+1) < len) && ((c-1) >= 0))
				if(current[r+1][c-1])
					nearby++; 
			if((r+1) < len)
				if(current[r+1][c])
					nearby++; 
			if(((r+1) < len) && ((c+1) < len))
				if(current[r+1][c+1])
					nearby++; 

			if(current[r][c])
				if((nearby == 2) || (nearby == 3))
					temp[r][c] = true;
				else
					temp[r][c] = false;
			else
				if(nearby == 3)
					temp[r][c] = true;
				else
					temp[r][c] = false;
		}
	// copying temp to current
	for(auto i = 0; i < len; i++)
		for(auto j = 0; j < len; j++)  
			current[i][j] = temp[i][j];
	Display();
}

void Board::play() {
	int nearby;

	while(true){
		Next();
	}
}

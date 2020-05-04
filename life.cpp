// Life Main Driver
// By: Jorge Daboub

#include<iostream>
#include<fstream>
#include<string>
#include"lifeboard.h"
using namespace std;


int main(int argc, char *argv[]) {
	Board game;

	// if ther is a file
	if (argc > 1) {
		// added the option to run without delays 
		if (argc > 2)
			game.noDelay();

		ifstream ifs;
		string fileName = argv[1];
		string a;
		int b, c;

		ifs.open(fileName);
		if (!ifs) {
			cout << "Bad file name: " << fileName << endl;
			exit(10);
		}

		ifs >> a >> b >> c;
		bool val;
		// loading the data from the file
		while(ifs) {

			if (a == "a") {
				val = true;
				game.UpdateCell(b,c,val);
			}
			else if (a == "r") {
				val = false;
				game.UpdateCell(b,c,val);
			}	
			ifs >> a >> b >> c;
		}
		// plays the game looping in
		game.play();
	}
	// 
	else {
		char choice;
		int a,b;
		bool val;

		while(true){
			// displayign the board
			game.Display();

			cin >> choice;

			if(choice == 'q')
				exit(1);
			if(choice == 'n'){
				game.Next();
				continue;
			}
			else if(choice == 'p'){
				game.play();
				continue;
			}

			cin >> a >> b;
			// if the coordinate is out of range tell the user
			if((a > (len-1)) || (b > (len-1))){
				cout << "Out of range." << endl;
				continue;
			}
			// adding a cell
			if(choice == 'a'){
				val = true;
				game.UpdateCell(a,b,val);
				game.Display();
			}
			// removing a cell
			else if(choice == 'r'){
				val = false;
				game.UpdateCell(a,b,val);
				game.Display();
			}	

		}


	}
	return 0;
}

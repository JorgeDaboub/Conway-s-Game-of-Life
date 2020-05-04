// Lifeboard.h 
// By: Jorge Daboub

using namespace std;
const int len = 40;

class Board {

	public:
		Board();
		~Board();
		void Display();
		void UpdateCell(int,int,bool);
		void play();
		void Next();
		void noDelay();

	private:
		bool current[len][len];
		bool temp[len][len];
		bool delay;
};

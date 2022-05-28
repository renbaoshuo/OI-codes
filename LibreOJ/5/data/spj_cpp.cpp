#include <iostream>
#include <fstream>
using namespace std;
int main() {
	ifstream score_in("input");
	ifstream std("answer");
	ifstream usr("user_out");

	long long score, answer, user_answer;
	score_in >> score;
	std >> answer;
	usr >> user_answer;

	if (!usr) {
		cerr << "Failed to read any number from user output. Exiting." << endl;
		cout << 0;
	} else if (user_answer == 0) {
		cerr << "Commiserations. Score is " << score << "." << endl;
		cout << score;
	} else if (user_answer == answer) { 
		cerr << "Correct!" << endl;
		cout << 100;
	} else {
		cerr << "Sorry, incorrect date." << endl;
		cout << 0;
	}
}

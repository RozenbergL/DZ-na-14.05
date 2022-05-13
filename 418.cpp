#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct text {
	vector <string> strs;
	int ip = 0;
	void ad_string() {
		strs.push_back("");
	}
	void up() {
		if (ip > 0) {
			ip--;
		}
	}
	void down() {
		if (ip < 99) {
			ip++;
		}
	}
	void push(char x) {
		strs[this->ip] = strs[ip] + x;
	}
	void arase() {
		if (strs[this->ip].length() == 0) {
			strs[ip - 1] = strs[ip - 1].substr(0, strs[ip - 1].length() - 1);
		}
		else {
			strs[ip] = strs[ip].substr(0, strs[ip].length() - 1);
		}
	}
	void enter() {
		ip++;
		strs.push_back("");
	}
};
int main()
{
	text s;
	s.ad_string();
	string input;
	getline(cin, input);
	int maxi = 0;
	for (int i = 0; i < input.length(); i++) {
		if (input[i] == '<') {
			s.arase();
		}
		if (input[i] == '/') {
			s.enter();
		}
		if (input[i] == '^') {
			s.up();
		}
		if (input[i] == '|') {
			s.down();
		}
		if ((input[i] != '<') && (input[i] != '/') && (input[i] != '^') && (input[i] != '|')) {
			s.push(input[i]);
		}
		for (auto now : s.strs) {
			if (now.length() > maxi) {
				maxi = now.length();
			}
		}
	}
	for (auto now : s.strs) {
			cout << now << endl;
		}
	cout << maxi;
	return 0;
}
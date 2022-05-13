#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

int main()
{
	ifstream fin;
	ofstream fout;
	fin.open("input.txt");
	fout.open("output.txt");
	int n;
	fin >> n;
	int answer = 1;
	for (int i = 1; i <= n; i++){
	    if ((answer * i) % 10 != 0){
	        answer = (answer * i) % 10;
	    }else{
	        answer = ((answer * i) / 10) % 10;
	    }
	}
	fout << answer;
    return 0;
}
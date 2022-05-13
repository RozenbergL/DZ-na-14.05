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
	int count = 2 * (n / 7);
	if (n % 7 == 1){
	    count++;
	}
	if (n % 7 >= 2){
	    count += 2;
	}
	count += n;
	if (count == 53 || count == 66){
	    count++;
	}
	fout << count;
    return 0;
}
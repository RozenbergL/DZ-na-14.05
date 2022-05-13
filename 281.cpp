#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

int factorial(int i)
{
  if (i==0){
    return 1;
  }
  else{
    return i*factorial(i-1);
  }
}

int main()
{
	ifstream fin;
	ofstream fout;
	fin.open("input.txt");
	fout.open("output.txt");
	int n, m;
	fin >> n >> m;
	int answer = 0;
	for (int i = m; i <= n; i++){
	    answer += factorial(n) / (factorial(i) * factorial(n - i));
	}
	fout << answer;
    return 0;
}
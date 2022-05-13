#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

bool prime(long long n){ 
	for(long long i = 2; i <= sqrt(n); i++)
		if (n % i == 0)
			return false;
	return true;
}

int main()
{
	ifstream fin;
	ofstream fout;
	fin.open("input.txt");
	fout.open("output.txt");
	int k;
	fin >> k;
	int count = 0;
	int num = 2;
	vector <int> prost;
	while (count < 3571){
	    if (prime(num) == true){
	        count++;
	       prost.push_back(num); 
	    }
	    num++;
	}
	fout << prost[prost[k - 1] - 1];
    return 0;
}
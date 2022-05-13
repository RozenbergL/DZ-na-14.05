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
	vector <pair <int, int>> sp;
	int maxi = 0;
	for (int i = 0; i < n; i++){
	    int x, y, x1, y1;
	    fin >> x >> y >> x1 >> y1;
	    int t1 = 60 * x + y;
	    int t2 = 60 * x1 + y1;
	    if (t1 == t2){
	        t1 = 0;
	        t2 = 1440;
	    }
	    if (t1 > t2){
	        t2 += 1440;
	    }
	    if (t1 > maxi){
	        maxi = t1;
	    }
	    if (t2 > maxi){
	        maxi = t2;
	    }
	    pair <int, int> p;
	    p.first = t1;
	    p.second = t2;
	    sp.push_back(p);
	}
	int answer = 0;
	for (int i = 0; i <= maxi; i++){
	    int flag = 0;
	    for (int j = 0; j < n; j++){
	        if ((i < sp[j].first || i >= sp[j].second) && (i < sp[j].first + 1440 || i >= sp[j].second + 1440)){
	            flag = 1;
	            break;
	        }
	    }
	    if (flag == 0){
	       answer++;
	    }
	}
	fout << answer;
    return 0;
}
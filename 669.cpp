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
    int divi = 2;
    vector <int> d;
    while (n > 1){
        while (n % divi == 0){
            d.push_back(divi);
            n = n / divi;
        }
        if (divi == 2){ 
            divi++;
        }
        else{ 
            divi += 2;
        }
    }
    sort(d.begin(), d.end());
    if (d.size() < 2){
        fout << -1 << " " << -1;
    }else{
        int ans = 1;
        fout << d[0];
        for (int i = 1; i < d.size(); i++){
            if (ans * d[i] < 10){
                ans = ans * d[i];
            }else{
                fout << ans;
                ans = 1;
            }
        }
        fout << ans;
        fout << " ";
        for (int i = d.size() - 1; i >= 0; i--){
            fout << d[i];
        }
    }
    return 0;
}
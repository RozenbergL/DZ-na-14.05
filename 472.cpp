#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>
#include <string>
#include <cmath>
#include <map>

using namespace std;

int main()
{
	ifstream fin;
	ofstream fout;
	fin.open("input.txt");
	fout.open("output.txt");
    int n, m;
    fin >> n >> m;
    vector <int> pod;
    map <int, int> dir;
    for (int i = 0; i < n; i++){
        int x;
        fin >> x;
        pod.push_back(x);
        dir[x] = 0;
    }
    for (int i = 0; i < n; i++){
        dir[pod[i]]++;
    }
    sort(pod.begin(), pod.end());
    int i = 0;
    int current = 0;
    while (i < n){
        current += dir[pod[i]];
        if (m < (pod[i + dir[pod[i]]] - pod[i]) * current){
            fout << pod[i] + m / (pod[i + dir[pod[i]]] - pod[i]);
        }else{
            if (i < n - 1){
                m = m - ((pod[i + dir[pod[i]]] - pod[i]) * current);
            }
            i += dir[pod[i]];
        }
    }
    if (m > 0){
        fout << pod[n - 1] + m / n;
    }
    return 0;
}
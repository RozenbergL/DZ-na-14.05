#include <vector>
#include <algorithm>
#include <fstream>
#include <string>

using namespace std;

int main() {
    long long MAXI = 100000000000000;
    ifstream in("input.txt");
    ofstream out("output.txt");
    int n;
    in >> n;
    vector <vector <int>> sp(n + 1, vector <int>(n + 1, 0));
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            in >> sp[i][j]; 
        }
    }
    vector <vector<int>> max_prov(1 + n, vector<int>(1 + n, -MAXI));
    max_prov[0][0] = 0;
    for (int i = 1; i <= n; i++) { 
        for (int k = 0; k <= n; k++) {
            max_prov[i][k] = max_prov[i - 1][k]; 
            for (int z = 1; z <= k; z++) { 
                if (max_prov[i][k] < sp[z][i] + max_prov[i - 1][k - z]){
                    max_prov[i][k] = sp[z][i] + max_prov[i - 1][k - z];
                }
            }
        }
    }
    out << max_prov[n][n];
    return 0;
}
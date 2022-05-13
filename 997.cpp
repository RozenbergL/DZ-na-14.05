#include <fstream>
#include <map>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

bool prov(char c) {
    const string spaces(".,:;-'\"!?\n \t");
    return spaces.find(c) != string::npos;
}
string input(istream& ist) {
    string str;
    while (true) {
        if (ist.eof() || ist.bad())
            break;
        auto symbol = ist.peek();
        if (false == prov(symbol))
            break;
        ist.get();
    }
    while (true) {
        if (ist.eof() || ist.bad())
            break;
        auto symbol = ist.peek();
        if (prov(symbol))
            break;
        str.push_back(ist.get());
    }
    return str;
}
int main() {
    ifstream in("input.txt");
    ofstream out("output.txt");
    int n, m;
    in >> n >> m;
    map <string, int> d;
    for (int i = 0; i < n; ++i) {
        d.insert(make_pair(input(in), 0));
    }
    while (true) {
        string str = input(in);
        if (str.empty())
            break;
        auto xxx = d.find(str);
        if (xxx == d.end()) {
            out << "Some words from the text are unknown.";
            return 0;
        }
        d[str]++;
    }
    for (auto pair : d) {
        if (pair.second == 0) {
            out << "The usage of the vocabulary is not perfect.";
            return 0;
        }
    }
    out << "Everything is going to be OK.";
}
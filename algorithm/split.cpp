#include <iostream>
#include <vector>
#include <string>
#include <sstream>
 
using namespace std;

vector<string> split(string str, char delimiter) {
    vector<string> internal;
    stringstream ss(str);
    string temp;
 
    while (getline(ss, temp, delimiter)) {
        internal.push_back(temp);
    }
 
    return internal;
}
 
int main(int argc, char **argv) {
    string line = "Thank you for visiting my Blog.";
    vector<string> line_vector = split(line, ' ');
 
    for (int i = 0; i < line_vector.size(); ++i)
        cout << line_vector[i] << endl;
}

#include<bits/stdc++.h>
using namespace std;

int main(){
    string names, instructions;
    getline(cin, names);
    cin.ignore();
    getline(cin, instructions);

    vector <string> n_v, i_v;
    stringstream ss_n(names), ss_i(instructions);
    string name, in;
    while (getline(ss_n, name, ',')){n_v.push_back(name);}
    while (getline(ss_i, in, ',')){i_v.push_back(in);}

    int curr = 0, n = n_v.size();
    for (string &in : i_v)
    {
        char dir = in[0]; int dist = stoi(in.substr(1));
        if (dir == 'R') curr = min(curr + dist, n - 1);
        else curr = max(curr - dist, 0);
    }
    cout << n_v[curr] << endl;
    return (0);
}
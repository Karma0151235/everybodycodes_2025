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
        char dir = in[0]; int k = stoi(in.substr(1));
        if (dir == 'R') curr = (curr + k) % n;
        else curr = ((curr - k) % n + n) % n;
        swap(n_v[curr], n_v[0]);
        curr = 0;
    }
    cout << n_v[0] << endl;
    return (0);
}
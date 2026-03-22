/*
    some basics of map
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    // let's create a map of string to int
    map<string, int> m;
    // let's insert some key-value pairs into the map
    m["apple"] = 1;
    m["banana"] = 2;
    m["orange"] = 3;

    // let's print the map
    cout << "Map contents:" << endl;
    for (const auto &pair : m) {
        cout << pair.first << ": " << pair.second << endl;
    }
    


    return 0;
}
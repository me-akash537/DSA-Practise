/*
    some basic operations on vectors
*/

#include <bits/stdc++.h>
using namespace std;

void printVector(const std::vector<int> &v) {
    cout << "Vector: ";
    for (const auto &elem : v) {
        cout << elem << " ";
    }
    cout << endl;
}

void findElement(int element, const vector<int> &v) {
    auto it = find(v.begin(), v.end(), element);
    if (it != v.end()) {
        cout << "Element " << element << " found at index: " << distance(v.begin(), it) << endl;
    } else {
        cout << "Element " << element << " not found in the vector." << endl;
    }


}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    // let's begin with a simple vector
    vector<int> v = {1, 8, 3, 5, 2, 7, 4, 6};
    printVector(v);

    // let's add and remove some elements
    v.push_back(9);
    printVector(v);
    v.pop_back();
    printVector(v);

    // some more basic functions: size(), empty(), clear(), back(), front()
    cout << "Size: " << v.size() << endl;
    cout << "Is empty: " << v.empty() << endl;
    cout << "Front element: " << v.front() << endl;
    cout << "Back element: " << v.back() << endl;
    cout << "Max element: " << *max_element(v.begin(), v.end()) << endl;
    cout << "Min element: " << *min_element(v.begin(), v.end()) << endl;

    // what else can we do with vector? we can sort it, reverse it, find the max element, min element and more.
    sort(v.begin(), v.end());
    printVector(v);

    reverse(v.begin(), v.end());
    printVector(v);

    // now let's try to find the index of a specific element, say 5
    findElement(5, v);
    findElement(10, v);

    // binary search for an element, say 3
    bool found = binary_search(v.begin(), v.end(), 3);
    cout << "Element 3 " << (found ? "found" : "not found") << " using binary search, need to sort." << endl;

    // remember that binary search only works on sorted vectors, so sort it first
    sort(v.begin(), v.end());
    found = binary_search(v.begin(), v.end(), 3);
    cout << "Element 3 " << (found ? "found" : "not found") << " using binary search." << endl;



    return 0;
}



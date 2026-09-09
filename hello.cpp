#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    auto start = high_resolution_clock::now();

    cout << "Hello World\n";

    auto end = high_resolution_clock::now();

    auto duration = duration_cast<microseconds>(end - start);

    cout << "Execution time: " << duration.count() << " microseconds\n";

    return 0;
}

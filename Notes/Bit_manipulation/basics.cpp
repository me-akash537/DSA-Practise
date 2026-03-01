#include <bits/stdc++.h>
using namespace std;

string toBinary(int n, int bits) {
    bool negative = false;
    if (n < 0) {
        negative = true;
        n = -n;
    }

    string bin;
    while (n > 0) {
        bin += (n % 2 ? '1' : '0');
        n /= 2;
    }

    // pad to required bits
    while (bin.size() < bits) {
        bin += '0';
    }
    reverse(bin.begin(), bin.end());

    if (negative) {
        // 1's complement
        for (int i = 0; i < bits; i++)
            bin[i] = (bin[i] == '0') ? '1' : '0';
        // add 1
        for (int i = bits - 1; i >= 0; i--) {
            if (bin[i] == '0') {
                bin[i] = '1';
                break;
            }
            bin[i] = '0';
        }
    }
    return bin;
}

int binary_to_decimal(int B) {
    int decimal = 0;
    int base = 1;
    while (B > 0) {
        int last_digit = B % 10;
        decimal += last_digit * base;
        base *= 2;
        B /= 10;
    }
    return decimal;
}

void swap_using_temp(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

void swap_using_xor(int &a, int &b) {
    a = a ^ b;
    b = a ^ b; // or say b = (a ^ b) ^ b = a
    a = a ^ b; // or say a = (a ^ b) ^ a = b
}

bool isIthBitSet(int n, int i) {
    return (n & (1 << i)) != 0;
}

int setKthBit(int n, int k) {
    return n | (1 << k);
}

bool isPowerOfTwo(int n) {
    return n > 0 && ( (n & (n - 1)) == 0 );
}

int toggleIthBit(int n, int i) {
    return n ^ (1 << i);
}

int clearLastSetBit(int n) {
    return n & (n - 1);
}

int countSetBits(int n) {
    int count = 0;
    while (n != 0) {
        n = n & (n-1);
        count++;
    }
    return count;
}

int main () {
    int bits = 8;
    int n = -13;
    cout << toBinary(n, bits) << endl;
    cout << bitset<8>(n) << endl;

    int binary = 10011;
    cout << binary_to_decimal(binary) << endl;
    cout << bitset<8>(binary_to_decimal(binary)) << endl;

    // now let's see a bit on basic bit manipulation operations
    int a = 5; // 0101
    int b = 3; // 0011
    cout << (a & b) << endl; // 0001 -> 1
    cout << (a | b) << endl; // 0111 -> 7
    cout << (a ^ b) << endl; // 0110 -> 6
    cout << (a << 1) << endl; // 1010 -> 10
    cout << (~a) << endl; // 1010 -> -6 (in 2's complement)


    // now let's see how swapping is easier with bit manipulation
    // first method: using a temporary variable
    int x = 11, y = 13;
    swap_using_temp(x, y);
    cout << "x = " << x << ", y = " << y << endl;

    // second method: using XOR
    x = 11, y = 13;
    swap_using_xor(x, y);
    cout << "x = " << x << ", y = " << y << endl;

    // now let's check if ith bit is set or not
    int num = 11; // 1011
    int i = 2;
    if (isIthBitSet(num, i)) {
        cout << "Bit is set" << endl;
    } else {
        cout << "Bit is not set" << endl;
    }

    // now let's set the kth bit
    i = 2;
    num = 10; // 1010
    cout << setKthBit(num, i) << endl; // 1110 -> 14

    // lets check if a number is power of two
    num = 16;
    if (isPowerOfTwo(num)) {
        cout << num << " is a power of two" << endl;
    } else {
        cout << num << " is not a power of two" << endl;
    }
    num = 18;
    if (isPowerOfTwo(num)) {
        cout << num << " is a power of two" << endl;
    } else {
        cout << num << " is not a power of two" << endl;
    }
    
    // toggle the i-th bit
    num = 10; // 1010
    i = 1;
    cout << "Toggling bit " << i << " in " << num << " gives " << toggleIthBit(num, i) << endl;

    // clearing last set bit
    num = 10; // 1010
    cout << "Clearing last set bit in " << num << " gives " << clearLastSetBit(num) << endl;

    // count set bits in a number
    num = 115; // 1110011
    cout << "Number of set bits in " << num << " is " << countSetBits(num) << endl;

    return 0;
}
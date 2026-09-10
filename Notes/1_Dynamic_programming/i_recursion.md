# Find n-th Fibonacci number using recursion

```cpp
int fibo(int n){
    if (n < 0) {
        return -1;
    }
    if (n == 0){
        return 0;
    }
    if (n == 1){
        return 1;
    }
    return fibo(n - 1) + fibo(n - 2);
}
```

## Time and space Complexity

* Time complexity - O(2^n)
* Space Complexity - O(n)
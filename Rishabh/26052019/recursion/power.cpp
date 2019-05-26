#include "power.h"

long long power1WayRecursion(long a, long n) {  //  O(n)
    return (n == 0) ? 1 : (power1WayRecursion(a, n - 1) * a) % (1000000007);
}

long long power2WayRecursion(long a, long n) {    // O(logn)
    if(!n) return 1;
    long long halfPower = power2WayRecursion(a, n / 2);

    return (halfPower * halfPower * (n & 1) ? a : 1);
}
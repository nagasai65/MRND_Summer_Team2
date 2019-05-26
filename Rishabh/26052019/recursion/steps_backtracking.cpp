#include "steps_backtracking.h"

unsigned long numberOfWaysOfClimbingStairs(unsigned int n, unsigned int k) {
    // n stairs left
    // 1..k number of ways of climbing stairs
    unsigned int numberOfStepsToJump;
    unsigned long ways = 0;
    unsigned small = (n > k) ? k : n;
    if(n == 0) return 1;
    if (n < 0) return 0;
    for(numberOfStepsToJump = 1; numberOfStepsToJump <= small; ++numberOfStepsToJump)
        ways += numberOfWaysOfClimbingStairs(n - numberOfStepsToJump, k);

    return ways;
}
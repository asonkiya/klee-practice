#include <stdio.h>
#include <klee/klee.h>

int main() {
    int x, y;
    int i, j, count = 0;
    
    // Mark both x and y as symbolic inputs.
    klee_make_symbolic(&x, sizeof(x), "x");
    klee_make_symbolic(&y, sizeof(y), "y");

    // Outer branch: decide which section to run based on x.
    if (x < 10) {
        for (i = 0; i < 2; i++) {
            for (j = 0; j < 2; j++) {
                // Branch inside the loop: use y to decide how to update count.
                if (y > 100) {
                    count += 1;  // For larger values of y, increment count.
                } else {
                    count -= 1;  // Otherwise, decrement count.
                }
            }
        }
        // Final branch based on the value of count.
        if (count > 0) {
            printf("Nested loop branch: count is positive (count=%d)\\n", count);
        } else if (count == 0) {
            printf("Nested loop branch: count is zero (count=%d)\\n", count);
        } else {
            printf("Nested loop branch: count is negative (count=%d)\\n", count);
        }
    } else {
        // If x is 10 or greater, check if it equals the special value 42.
        if (x == 42) {
            printf("x is the answer!\\n");
        } else {
            printf("x is 10 or higher, but not the answer\\n");
        }
    }
    
    return 0;
}

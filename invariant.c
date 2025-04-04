// Loop invariant verification
//This one is just practice
#include <klee/klee.h>
#include <assert.h>

int main() {
    int n;
    klee_make_symbolic(&n, sizeof(n), "n");
    klee_assume(n >= 1);
    klee_assume(n <= 10);

    int prod = 1;
    for (int i = 1; i <= n; i++) {
        prod *= i;
        // Invariant: product should always be divisible by i
        klee_assert(prod % i == 0);
    }

    return 0;
}

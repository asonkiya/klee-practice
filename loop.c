// Loop behaivior exploration Practice
#include <klee/klee.h>
#include <assert.h>

int main() {
    int x;
    klee_make_symbolic(&x, sizeof(x), "x");
    klee_assume(x >= 0);
    klee_assume(x <= 5); // bounded loop

    int count = 0;
    for (int i = 0; i < x; i++) {
        count++;
    }

    // Trigger exploration of loop-unroll variants
    if (count == 3) {
        klee_assert(1); // reachable for x == 3
    }

    return 0;
}

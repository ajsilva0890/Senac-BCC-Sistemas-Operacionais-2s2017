#include "single_process.h"
#include "helpers.h"

void estimate_pi_with_single_process() {
    point p;
    int darts;
    double hit = 0.0;

    srand((unsigned)time(NULL));

    printf("Enter with number of darts to be played (minimum value: 10000):\n");
    scanf("%d", &darts);
    if (darts < 10000) {
        darts = 10000;
    }

    for (int i = 0; i < darts; i++) {
        p = randPoint();
        if (inside(p)) {
            hit++;
        }
    }

    double pi = 4*hit/darts;

    printf("PI: %f\n", pi);
}

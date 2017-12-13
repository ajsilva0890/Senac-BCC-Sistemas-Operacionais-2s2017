#include "helpers.h"

point randPoint() {
    point p = {(double)rand() / (double)((unsigned)RAND_MAX + 1), (double)rand() / (double)((unsigned)RAND_MAX + 1)};
    return p;
}

double distance(point p1, point p2) {
    return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}

bool inside(point p) {
    point c = {0 , 0};
    if (distance(c, p) <= 1) {
        return true;
    }
    return false;
}

// (ex. 6.1.1 - calculate euclids distance between two points)

#include <stdio.h>
#include <math.h>

struct crd{
    int x;
    int y;
};

float euclid_dist(const struct crd *p1, const struct crd *p2);

int main(){

    struct crd p1 = {2,2};
    struct crd p2 = {3,3};
    
    printf("%.1f\n", euclid_dist(&p1, &p2));

    return 0;
}

float euclid_dist(const struct crd *p1, const struct crd *p2){
    return sqrt(pow((p1->x - p2->x),2) + pow((p1->y - p2->y),2));
}

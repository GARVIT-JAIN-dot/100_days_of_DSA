/* Problem: Given a target distance and cars’ positions & speeds, compute the number of car fleets reaching the destination.
Sort cars by position in descending order and calculate time to reach target. */
#include <stdio.h>
#include <stdlib.h>

struct Car {
    int position;
    int speed;
};

int compare(const void *a, const void *b) {

    struct Car *c1 = (struct Car *)a;
    struct Car *c2 = (struct Car *)b;

    return c2->position - c1->position;
}

int main() {

    int target, n;

    printf("Enter target distance: ");
    scanf("%d", &target);

    printf("Enter number of cars: ");
    scanf("%d", &n);

    struct Car cars[n];

    printf("Enter positions of cars:\n");

    for (int i = 0; i < n; i++) {
        scanf("%d", &cars[i].position);
    }

    printf("Enter speeds of cars:\n");

    for (int i = 0; i < n; i++) {
        scanf("%d", &cars[i].speed);
    }

    qsort(cars, n, sizeof(struct Car), compare);

    int fleets = 0;

    double lastTime = 0.0;

    for (int i = 0; i < n; i++) {

        double time =
            (double)(target - cars[i].position)
            / cars[i].speed;

        if (time > lastTime) {

            fleets++;

            lastTime = time;
        }
    }

    printf("Number of car fleets: %d\n", fleets);

    return 0;
}
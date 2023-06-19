#include <stdio.h>

typedef struct {
    int x;
    int y;
} Point;

typedef struct {
    Point topLeft;
    Point bottomRight;
} Rectangle;

void printRectangle(Rectangle r) {
    printf("Top left: (%d, %d)\n", r.topLeft.x, r.topLeft.y);
    printf("Bottom right: (%d, %d)\n", r.bottomRight.x, r.bottomRight.y);
}

int main() {
    Rectangle r1 = {{0, 0}, {4, 3}};
    Rectangle r2;

    printf("Enter the top left and bottom right points of a rectangle:\n");
    scanf("%d %d %d %d", &r2.topLeft.x, &r2.topLeft.y, &r2.bottomRight.x, &r2.bottomRight.y);

    printf("Rectangle 1:\n");
    printRectangle(r1);
    printf("Rectangle 2:\n");
    printRectangle(r2);

    return 0;
}

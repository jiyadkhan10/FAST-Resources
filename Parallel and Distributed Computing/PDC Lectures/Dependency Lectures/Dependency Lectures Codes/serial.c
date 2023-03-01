#include <stdio.h>

int TaskX() {
  sleep(15);
  return 15;}
int TaskY() {
  sleep(5);
  return 5; }
int TaskZ() {
  sleep(5);
  return 5; }

int main(int argc, char** argv) {
    int x,y;
    int z=10;
    x=TaskX();
    y=TaskY()+z;
    y=x-5;
    z=TaskZ();

    printf("x: %d y: %d z: %d\n", x, y, z);
    return 0;
}

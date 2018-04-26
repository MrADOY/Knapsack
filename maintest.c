#include "display.h"
#include "glouglou.h"
#include "utils.h"
#include "data.h"

int main(int argc, char const *argv[]) {

  Object *t;
  t = generate_object_randomly(10, 100, 20);

  glouglou(t, 20);

  return 0;
}

#ifndef __GLOUGLOU_H__
#define __GLOUGLOU_H__

#include "data.h"

typedef struct {

  int index;
  double rapport;

}glou;

int *glouglou(Object *t, int size, double max_bag, int *borne_plus, int *borne_moins);

#endif

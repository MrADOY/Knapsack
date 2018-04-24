#ifndef __DATA_H__
#define __DATA_H__

#define ALPHA 0.50

/*
 * Object that will be put in the bag
 */

typedef struct {
  int size;
  int cost;
}Object;

/*
 * This function create tab which contains object
 * an object is an item which is characterized by size and cost
 */

Object* generate_object_randomly(int a, int b, int size_);

/*
 * This function returns the bag capacity which depends
 * of the interval values
 */

double generate_bag_capacity(Object* t, int size_);

/*
 * Useful to know bag capacity
 */

int find_best_sum(int** tab, Object* t, int size, int max_size);
#endif

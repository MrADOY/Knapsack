#ifndef __DATA_H__
#define __DATA_H__

#define SIZE 10000

/*
 * This function create tab which contains object
 * an object is an item which is characterized by size and cost
 */

Object* generate_object_randomly(int a, int b);

/*
 * This function returns the bag capacity which depends
 * of the interval values
 */

double generate_bag_capacity(Object* t, int ALPHA)

/*
 * Object that will be put in the bag
 */

typedef struct {
  int size;
  int cost;
}Object;

/*
 * Useful to know bag capacity
 */

const double ALPHA = 0.50;

#endif

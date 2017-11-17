#include <vector>
#include <stdint.h>
#include <cmath>
#include <iostream>
#include "murmur.h"

#define SALT_CONSTANT 0x97c29b3a

class Bloom{

    std::vector<bool> *filter;
    int k; //Number of associated Hash Functions
    int m; //Number of bits
    int n; //Number of elements
    float p; //False positive probability
    uint32_t *hash_vals;

public:
    Bloom(int Capacity, float p);
    void add(void* element, int len);
    bool contains(void* element, int len);
    void hash_funcs(void * element, int len);
    ~Bloom();
};

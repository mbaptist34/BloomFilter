
#include "Bloom.h"
#include "murmur.h"

Bloom::Bloom(int Capacity, float p) {
    this->n = Capacity;
    this->m = floor((-this->n) * log(p) / pow(log(2),2));
    this->k = floor(this->m / this->n / (pow(log(2),2)));
    this->p = p;

    filter = new std::vector<bool>(this->m);

    this->hash_vals = new uint32_t[this->k];
}

void Bloom::add(void * element, int len) {
    this->hash_funcs(element, len);

    for (int i = 0; i < this->k; i++) {
        (*this->filter)[this->hash_vals[i]] = 1;
    }
}

bool Bloom::contains(void * element, int len) {
    this->hash_funcs(element, len);

    for (int i = 0; i < this->k; i++) {
        if(!(*this->filter)[hash_vals[i]]) {
            return false;
        }    
    } 

    return true;
}

Bloom::~Bloom() {
    delete this->filter;
    delete this->hash_vals;
}

void Bloom::hash_funcs(void * element, int len) {
    uint32_t hashes[4];
    
    MurmurHash3_x64_128(element, len, SALT_CONSTANT, hashes);

    uint32_t h1 = hashes[0];
    uint32_t h2 = hashes[1];

    for (int i = 0; i < this->k; i++) {
        this->hash_vals[i] = (h1 + i * h2) % this->m;
    }
}


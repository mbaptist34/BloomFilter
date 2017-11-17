/*
 murmur.c and murmur.h were written by Austin Appleby
 who placed them in the public domain. I did not modify his code
 outside of omitting sections that were unused by my program.
 https://github.com/aappleby/smhasher
 */

#ifndef _MURMURHASH3_H_
#define _MURMURHASH3_H_

#include <stdint.h>

void MurmurHash3_x64_128 ( const void * key, int len, uint32_t seed, void * out );

#endif // _MURMURHASH3_H_

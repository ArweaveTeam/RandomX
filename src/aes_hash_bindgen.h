#ifndef AES_HASH_BINDGEN_H
#define AES_HASH_BINDGEN_H
#endif

#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

void hashAes1Rx4_soft(const void *input, size_t inputSize, void *hash);
void hashAes1Rx4_hard(const void *input, size_t inputSize, void *hash);

void fillAes1Rx4_soft(void *state, size_t outputSize, void *buffer);
void fillAes1Rx4_hard(void *state, size_t outputSize, void *buffer);

void fillAes4Rx4_soft(void *state, size_t outputSize, void *buffer);
void fillAes4Rx4_hard(void *state, size_t outputSize, void *buffer);

void hashAndFillAes1Rx4_soft(void *scratchpad, size_t scratchpadSize, void *hash, void* fill_state);
void hashAndFillAes1Rx4_hard(void *scratchpad, size_t scratchpadSize, void *hash, void* fill_state);

#ifdef __cplusplus
}
#endif

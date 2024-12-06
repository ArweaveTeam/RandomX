#include "aes_hash.hpp"

extern "C" {
    void hashAes1Rx4_soft(const void *input, size_t inputSize, void *hash) {
        hashAes1Rx4<true>(input, inputSize, hash);
    }

    void hashAes1Rx4_hard(const void *input, size_t inputSize, void *hash) {
        hashAes1Rx4<false>(input, inputSize, hash);
    }

    void fillAes1Rx4_soft(void *state, size_t outputSize, void *buffer) {
        fillAes1Rx4<true>(state, outputSize, buffer);
    }

    void fillAes1Rx4_hard(void *state, size_t outputSize, void *buffer) {
        fillAes1Rx4<false>(state, outputSize, buffer);
    }

    void fillAes4Rx4_soft(void *state, size_t outputSize, void *buffer) {
        fillAes4Rx4<true>(state, outputSize, buffer);
    }

    void fillAes4Rx4_hard(void *state, size_t outputSize, void *buffer) {
        fillAes4Rx4<false>(state, outputSize, buffer);
    }

    void hashAndFillAes1Rx4_soft(void *scratchpad, size_t scratchpadSize, void *hash, void* fill_state) {
        hashAndFillAes1Rx4<true>(scratchpad, scratchpadSize, hash, fill_state);
    }

    void hashAndFillAes1Rx4_hard(void *scratchpad, size_t scratchpadSize, void *hash, void* fill_state) {
        hashAndFillAes1Rx4<false>(scratchpad, scratchpadSize, hash, fill_state);
    }
}

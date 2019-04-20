#include "../randomx.h"
#include <stdio.h>

int main() {
	const char mySeed[] = "RandomX example seed";
	const char myInput[] = "RandomX example input";
	char hash[RANDOMX_HASH_SIZE];

	randomx_cache *myCache = randomx_alloc_cache(RANDOMX_FLAG_DEFAULT);
	randomx_init_cache(myCache, mySeed, sizeof mySeed);
	randomx_vm *myMachine = randomx_create_vm(RANDOMX_FLAG_DEFAULT);
	randomx_vm_set_cache(myMachine, myCache);

	randomx_calculate_hash(myMachine, &myInput, sizeof myInput, hash);

	randomx_destroy_vm(myMachine);
	randomx_release_cache(myCache);

	for (unsigned i = 0; i < RANDOMX_HASH_SIZE; ++i)
		printf("%02x", hash[i] & 0xff);

	printf("\n");

	return 0;
}
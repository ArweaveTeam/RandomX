/*
Copyright (c) 2018-2019, tevador <tevador@gmail.com>

All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:
	* Redistributions of source code must retain the above copyright
	  notice, this list of conditions and the following disclaimer.
	* Redistributions in binary form must reproduce the above copyright
	  notice, this list of conditions and the following disclaimer in the
	  documentation and/or other materials provided with the distribution.
	* Neither the name of the copyright holder nor the
	  names of its contributors may be used to endorse or promote products
	  derived from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#pragma once

//Cache size in KiB. Must be a power of 2.
#ifndef RANDOMX_ARGON_MEMORY
#define RANDOMX_ARGON_MEMORY       262144
#endif

//Number of Argon2d iterations for Cache initialization.
#define RANDOMX_ARGON_ITERATIONS   3

//Number of parallel lanes for Cache initialization.
#define RANDOMX_ARGON_LANES        1

//Argon2d salt
#define RANDOMX_ARGON_SALT         "RandomX-Arweave\x01"

//Number of random Cache accesses per Dataset item. Minimum is 2.
#define RANDOMX_CACHE_ACCESSES     8

//Target latency for SuperscalarHash (in cycles of the reference CPU).
#define RANDOMX_SUPERSCALAR_LATENCY   170

//Dataset base size in bytes. Must be a power of 2.
#ifndef RANDOMX_DATASET_BASE_SIZE
#define RANDOMX_DATASET_BASE_SIZE  536870912 // 2^29 = 512 Mi (bytes), tweaked for Arweave
#endif

//Dataset extra size. Must be divisible by 64.
#define RANDOMX_DATASET_EXTRA_SIZE 31563008 // 493172 (just an arbitrary number) * 64, tweaked for Arweave

//Number of instructions in a RandomX program. Must be divisible by 8.
#ifndef RANDOMX_PROGRAM_SIZE
#define RANDOMX_PROGRAM_SIZE       256
#endif

//Number of iterations during VM execution.
#ifndef RANDOMX_PROGRAM_ITERATIONS
#define RANDOMX_PROGRAM_ITERATIONS 2048
#endif

//Number of chained VM executions per hash.
#ifndef RANDOMX_PROGRAM_COUNT
#define RANDOMX_PROGRAM_COUNT      8
#endif

//Scratchpad L3 size in bytes. Must be a power of 2.
#ifndef RANDOMX_SCRATCHPAD_L3
#define RANDOMX_SCRATCHPAD_L3      2097152
#endif

//Scratchpad L2 size in bytes. Must be a power of two and less than or equal to RANDOMX_SCRATCHPAD_L3.
#define RANDOMX_SCRATCHPAD_L2      262144

//Scratchpad L1 size in bytes. Must be a power of two (minimum 64) and less than or equal to RANDOMX_SCRATCHPAD_L2.
#define RANDOMX_SCRATCHPAD_L1      16384

//Jump condition mask size in bits.
#define RANDOMX_JUMP_BITS          8

//Jump condition mask offset in bits. The sum of RANDOMX_JUMP_BITS and RANDOMX_JUMP_OFFSET must not exceed 16.
#define RANDOMX_JUMP_OFFSET        8

/*
Instruction frequencies (per 256 opcodes)
Total sum of frequencies must be 256
*/

//Integer instructions
#ifndef RANDOMX_FREQ_IADD_RS
#define RANDOMX_FREQ_IADD_RS       25
#endif

#ifndef RANDOMX_FREQ_IADD_M
#define RANDOMX_FREQ_IADD_M         7
#endif

#ifndef RANDOMX_FREQ_ISUB_R
#define RANDOMX_FREQ_ISUB_R        16
#endif

#ifndef RANDOMX_FREQ_ISUB_M
#define RANDOMX_FREQ_ISUB_M         7
#endif

#ifndef RANDOMX_FREQ_IMUL_R
#define RANDOMX_FREQ_IMUL_R        16
#endif

#ifndef RANDOMX_FREQ_IMUL_M
#define RANDOMX_FREQ_IMUL_M         4
#endif

#ifndef RANDOMX_FREQ_IMULH_R
#define RANDOMX_FREQ_IMULH_R        4
#endif

#ifndef RANDOMX_FREQ_IMULH_M
#define RANDOMX_FREQ_IMULH_M        1
#endif

#ifndef RANDOMX_FREQ_ISMULH_R
#define RANDOMX_FREQ_ISMULH_R       4
#endif

#ifndef RANDOMX_FREQ_ISMULH_M
#define RANDOMX_FREQ_ISMULH_M       1
#endif

#ifndef RANDOMX_FREQ_IMUL_RCP
#define RANDOMX_FREQ_IMUL_RCP       8
#endif

#ifndef RANDOMX_FREQ_INEG_R
#define RANDOMX_FREQ_INEG_R         2
#endif

#ifndef RANDOMX_FREQ_IXOR_R
#define RANDOMX_FREQ_IXOR_R        15
#endif

#ifndef RANDOMX_FREQ_IXOR_M
#define RANDOMX_FREQ_IXOR_M         5
#endif

#ifndef RANDOMX_FREQ_IROR_R
#define RANDOMX_FREQ_IROR_R        10
#endif

#ifndef RANDOMX_FREQ_IROL_R
#define RANDOMX_FREQ_IROL_R         0
#endif

#ifndef RANDOMX_FREQ_ISWAP_R
#define RANDOMX_FREQ_ISWAP_R        4
#endif

//Floating point instructions
#ifndef RANDOMX_FREQ_FSWAP_R
#define RANDOMX_FREQ_FSWAP_R        8
#endif

#ifndef RANDOMX_FREQ_FADD_R
#define RANDOMX_FREQ_FADD_R        20
#endif

#ifndef RANDOMX_FREQ_FADD_M
#define RANDOMX_FREQ_FADD_M         5
#endif

#ifndef RANDOMX_FREQ_FSUB_R
#define RANDOMX_FREQ_FSUB_R        20
#endif

#ifndef RANDOMX_FREQ_FSUB_M
#define RANDOMX_FREQ_FSUB_M         5
#endif

#ifndef RANDOMX_FREQ_FSCAL_R
#define RANDOMX_FREQ_FSCAL_R        6
#endif

#ifndef RANDOMX_FREQ_FMUL_R
#define RANDOMX_FREQ_FMUL_R        20
#endif

#ifndef RANDOMX_FREQ_FDIV_M
#define RANDOMX_FREQ_FDIV_M         4
#endif

#ifndef RANDOMX_FREQ_FSQRT_R
#define RANDOMX_FREQ_FSQRT_R        6
#endif

//Control instructions
#ifndef RANDOMX_FREQ_CBRANCH
#define RANDOMX_FREQ_CBRANCH       16
#endif

#ifndef RANDOMX_FREQ_CFROUND
#define RANDOMX_FREQ_CFROUND        1
#endif

//Store instruction
#ifndef RANDOMX_FREQ_ISTORE
#define RANDOMX_FREQ_ISTORE        16
#endif

//No-op instruction
#ifndef RANDOMX_FREQ_NOP
#define RANDOMX_FREQ_NOP            0
#endif
/*                               ------
                                  256
*/
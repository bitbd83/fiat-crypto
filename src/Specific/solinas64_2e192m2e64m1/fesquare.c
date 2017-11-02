#include <stdint.h>
#include <stdbool.h>
#include <x86intrin.h>
#include "liblow.h"

#include "fesquare.h"

typedef unsigned int uint128_t __attribute__((mode(TI)));

#if (defined(__GNUC__) || defined(__GNUG__)) && !(defined(__clang__)||defined(__INTEL_COMPILER))
// https://gcc.gnu.org/bugzilla/show_bug.cgi?id=81294
#define _subborrow_u32 __builtin_ia32_sbb_u32
#define _subborrow_u64 __builtin_ia32_sbb_u64
#endif

#undef force_inline
#define force_inline __attribute__((always_inline))

void force_inline fesquare(uint64_t* out, uint64_t x5, uint64_t x6, uint64_t x4, uint64_t x2)
{  uint128_t x7 = ((((uint128_t)x2 * x5) + (((uint128_t)x4 * x6) + (((uint128_t)x6 * x4) + ((uint128_t)x5 * x2)))) + (0x10000 * ((uint128_t)x5 * x5)));
{  uint128_t x8 = ((((uint128_t)x2 * x6) + (((uint128_t)x4 * x4) + ((uint128_t)x6 * x2))) + (((uint128_t)x5 * x5) + (0x10000 * (((uint128_t)x6 * x5) + ((uint128_t)x5 * x6)))));
{  uint128_t x9 = ((((uint128_t)x2 * x4) + ((uint128_t)x4 * x2)) + ((((uint128_t)x6 * x5) + ((uint128_t)x5 * x6)) + (0x10000 * (((uint128_t)x4 * x5) + (((uint128_t)x6 * x6) + ((uint128_t)x5 * x4))))));
{  uint128_t x10 = (((uint128_t)x2 * x2) + (((uint128_t)x4 * x5) + (((uint128_t)x6 * x6) + ((uint128_t)x5 * x4))));
{  uint64_t x11 = (uint64_t) (x10 >> 0x30);
{  uint64_t x12 = ((uint64_t)x10 & 0xffffffffffff);
{  uint128_t x13 = (x7 >> 0x30);
{  uint64_t x14 = ((uint64_t)x7 & 0xffffffffffff);
{  uint128_t x15 = ((0x1000000000000 * x13) + x14);
{  uint128_t x16 = (x15 >> 0x30);
{  uint64_t x17 = ((uint64_t)x15 & 0xffffffffffff);
{  uint128_t x18 = ((x11 + x9) + (0x10000 * x16));
{  uint128_t x19 = (x18 >> 0x30);
{  uint64_t x20 = ((uint64_t)x18 & 0xffffffffffff);
{  uint128_t x21 = (x12 + x16);
{  uint64_t x22 = (uint64_t) (x21 >> 0x30);
{  uint64_t x23 = ((uint64_t)x21 & 0xffffffffffff);
{  uint128_t x24 = (x19 + x8);
{  uint128_t x25 = (x24 >> 0x30);
{  uint64_t x26 = ((uint64_t)x24 & 0xffffffffffff);
{  uint128_t x27 = (x25 + x17);
{  uint64_t x28 = (uint64_t) (x27 >> 0x30);
{  uint64_t x29 = ((uint64_t)x27 & 0xffffffffffff);
{  uint128_t x30 = (((uint128_t)0x1000000000000 * x28) + x29);
{  uint64_t x31 = (uint64_t) (x30 >> 0x30);
{  uint64_t x32 = ((uint64_t)x30 & 0xffffffffffff);
{  uint64_t x33 = ((x22 + x20) + (0x10000 * x31));
{  uint64_t x34 = (x33 >> 0x30);
{  uint64_t x35 = (x33 & 0xffffffffffff);
{  uint64_t x36 = (x23 + x31);
{  uint64_t x37 = (x36 >> 0x30);
{  uint64_t x38 = (x36 & 0xffffffffffff);
out[0] = x32;
out[1] = x34 + x26;
out[2] = x37 + x35;
out[3] = x38;
}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}
// caller: uint64_t out[4];
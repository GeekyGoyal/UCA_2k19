/**  Bits and Bytes
*
*   @Aparna Goyal, 1911981092, 02/08/2021  */

#include <stdio.h>

/*  bitAnd - x & y using only ~ and |
*    Example bitAnd(6, 5) = 4
*    Legal ops:  ~ |  
*    Max ops: 8 */
int bitAnd(int x, int y) { 
    return ~(~x | ~y);
}

/*  bitXor - x ^ y using only ~ and &
* Example bitXor(4, 5) = 1
*  Legal ops:  ~ &  
*  Max ops: 14 */ 
int bitXor(int x, int y) {
    return ((~x) & y);
}

/* sign - return 1 if positive, 0 if zero, and -1 if negative
* Examples: sign(130) = 1, sign(-23) = -1
* Legal ops: ! ~ & ^ | + << >>
* Max ops : 10 */
int sign(int x) {
    return ((!!x) | (x >> 31));
}

/* getByte - extract byte n from word x
* Examples: getByte(0x12345678, 1)  = 0x56
*Legal ops: ! ~ & ^| + << >>
Max ops: 6 */
int getByte(int x, int n) {
    return 0xff & (x >> (n << 3));
}

/* logicalShift - shift x to the right by n, using a logical shift
* can assume that 0 <=n<=31
* examples: logicalShift(0x87654321, 4) = 0x8765432
* Legal ops:  ~ & ^ | + << >>
* Max ops: 20 */
int logicalShift(int x, int n) {
    return (x >> n) & (~(((1 << 31) >> n) << 1));
}

/* conditional - same as x ? y : z
* example conditional (2, 4, 5) = 4
* ! ~ & ^ | + << >>
* Max ops: 16 */
int conditional(int x, int y, int z) {
    return z ^ ((y ^ z) & ((!x) + ~0));
}

/* bang - Compute !x without using !
*  Examples: bang(3)=0, bang(0)=1
*  Legal ops: ~ & ^ | + << >>
*  Max ops: 12 */ 
int bang(int x) {
     return (((~x + 1) | x) >> 31) + 1;
}

 
/* Return x with the n bits that begin at position p inverted (i.e. turn 0 /* into 1 and vice versa)
* and the rest left unchanged. Consider the indices of x to begin with the /* lower -order bit   numbered
* Legal ops: ~ & ^ | << >>
* as zero */
int invert (int x, int p, int n) {
    return   x ^ (~(~0 << n) << (p + 1 - n));
}

int main() {
    int x, y, z;
    printf("Enter three numbers: ");
    scanf("%d %d %d", &x, &y, &z);
    printf("BitAnd: %d\n", bitAnd(x, y));
    printf("BitXor: %d\n", bitXor(x, y));
    printf("Sign: %d\n", sign(x));
    printf("getByte: %d\n", getByte(x, y));
    printf("logicalShift: %d\n", logicalShift(x, y));
    printf("conditional: %d\n", conditional(x, y, z));
    printf("bang: %d\n", bang(x));
    printf("invert: %d\n", invert(x, y, z));
    return 0;
}
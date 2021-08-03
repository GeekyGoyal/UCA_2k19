
/**  Bits and Bytes
*
*   @Aparna Goyal, 1911981092, 02/08/2021  */

#include <stdio.h>

/**  bitAnd - x & y using only ~ and |
*    Example bitAnd(6, 5) = 4
*    Legal ops:  ~ |  
*    Max ops: 8 */
int bitAnd(int x, int y) { 
    return ~(~x | ~y);
}

/**  bitXor - x ^ y using only ~ and |
/* Example bitXor(4, 5) = 1
*  Legal ops:  ~ &  
*  Max ops: 14 */
int bitXor(int x, int y) {
    return ~(x | (~y));
}

/* sign - return 1 if positive, 0 if zero, and -1 if negative
* Examples: sign(130) = 1, sign(-23) = -1
* Legal ops: ! ~ & ^ | + << >>
* Max ops : 10 */
int sign(int x) {
    if(x & (~x) == 0) {
        return 0;
    }

}

int main() {
    int x, y;
    printf("Enter two numbers: ");
    scanf("%d %d", &x, &y);
    printf("BitAnd: %d\n", bitAnd(x, y));
    printf("BitXor: %d\n", bitXor(x, y));
    printf("Sign: %d\n", sign(x));
    return 0;
}
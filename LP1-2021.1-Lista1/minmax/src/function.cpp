#include <cstdio>
#include "function.h"

/*! 
 * Finds and returns a pair with the first instance of the smallest element
 * and the last instance of the largest element in an array.
 *
 * @param V This is the array-to-pointer decay representing an array.
 * @param n The array's size.
 *
 * @return A pair of indexes to the first smallest and last largest values.
 */

std::pair<int,int> min_max( int V[], size_t n )
{
    if (n == 1){
        return {0,0};
    } else if (n == 0){
        return {-1,-1};
    }
    int posmaior = 0,posmenor = 0;
    for (int i = 0; i < n; ++i) {
        if (V[i] >= V[posmaior] && i > posmaior){
            posmaior = i;
        }else if(V[i] < V[posmenor] ){
            posmenor = i;
        }
    }
    return { posmenor, posmaior };
}

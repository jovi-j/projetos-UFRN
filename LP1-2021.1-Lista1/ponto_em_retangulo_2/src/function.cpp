#include "function.h"

/*! 
 * Verifica se um ponto está dentro de um retângulo.
 */

location_t pt_in_rect( const Ponto &IE, const Ponto &SD, const Ponto &P )
{
    if((P.x >= IE.x and P.x <= SD.x) and (P.y >= IE.y and P.y <= SD.y)){
        if (P.x == IE.x or P.x == SD.x or P.y == IE.y or P.y == SD.y) {
            return location_t::BORDER;
        } else{
            return location_t::INSIDE;
        }
    }
    return location_t::OUTSIDE;
}

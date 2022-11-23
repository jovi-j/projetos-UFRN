/*!
 * @brief Implementação do Ponto em Retângulo V2.
 * @author selan
 * @data June, 6th 2021
 */

#include <iostream>
using std::cout;
using std::cin;
using std::endl;
#include <algorithm>
using std::min;
using std::max;

#include "function.h"

//=== Funções

// Coloque aqui qualquer função auxiliar que desejar.


int main(){
    int x1, x2, x3, y1, y2, y3;
    while(cin >> std::ws >> x1 >> y1 >> x2 >> y2 >> x3 >> y3){
       Ponto IE = {x1,y1};
       Ponto SD = {x2,y2};
       Ponto P = {x3,y3};
        switch (pt_in_rect(IE,SD,P)) {
            case INSIDE:
                cout << "inside\n";
                break;
            case BORDER:
                cout << "border\n";
                break;
            case OUTSIDE:
                cout << "outside\n";
                break;
        }
    }
}

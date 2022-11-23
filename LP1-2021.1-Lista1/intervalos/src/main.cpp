/*!
 * @brief This code implements the Intervalos programming problem
 * @author selan
 * @data June, 6th 2021
 */

#include <iostream>
using std::cout;
using std::cin;
using std::endl;
#include <iomanip>
using std::setprecision;

int main(){
    int x, total = 0;
    int percent_val[5] = {0,0,0,0,0};
    while (cin >> std::ws >> x) {
        total++;
        if(x < 0 or x >= 100) {
            percent_val[4]++;
        }
        else if (x >= 0 && x < 25){
            percent_val[0]++;
        }
        else if (x >= 25 && x < 50) {
            percent_val[1]++;
        }
        else if (x >= 50 && x < 75) {
            percent_val[2]++;
        }
        else if(x >= 75 && x < 100) {
            percent_val[3]++;
        }
    }
    for (int i : percent_val) {
        float value = (float) i / (float) total * 100.0;
        cout << std::setprecision(4) << value << endl;
    }
}

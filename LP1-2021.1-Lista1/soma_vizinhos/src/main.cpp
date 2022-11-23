/*!
 * @brief This code implements the "Soma Vizinhos" programming problem
 * @author selan
 * @data June, 6th 2021
 */
#include <iostream>
using std::cout;
using std::cin;
using std::endl;
using namespace std;

int main(){
    int m,n,sum = 0;
    while (cin >> ws >> m >> n) {
        sum = m;
        if(n >= 0){
            for (int i = 1; i < n; ++i) {
                sum += m + i;
            }
        }
        else{
            for (int i = 1; i < abs(n); ++i) {
                sum += m - i;
            }
        }
        cout << sum << endl;
    }
}

#include <iostream>
using namespace std;

const int SIZE = 5; // input size.

int main(void)
{
    // TODO: Adicione aqui seu código.
    int numbers[SIZE] = {0,0,0,0,0};
    int negatives = 0;
    for (int i = 0; i < SIZE; ++i) {
        cin >> numbers[i];
        if (numbers[i] < 0)
            negatives++;
    }
    cout << negatives;
    return 0;
}

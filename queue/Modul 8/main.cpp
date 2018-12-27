#include <iostream>
#include "queue.h"

using namespace std;

int main()
{
    int n;
    cout << "Masukkan Durasi Simulasi: ";cin >> n;
    cout << "Simulasi " << n << " menit" << endl;
    cout << endl;
    simulasi(n);
    return 0;
}

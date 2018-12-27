#include <iostream>
#include "HEADER.h"
#include <string.h>
using namespace std;
#include<time.h>
#include<windows.h>
int main()
{
    list_buku c;
    system("COLOR 37");
    createlistbuku(c);
    list_pembeli p;
    createlistpembeli(p);
    menu(c,p);
    return 0;
}

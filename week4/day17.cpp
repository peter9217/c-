#include <iostream> // ǥ�� ���̺귯��
#include "text.h"
#define customN 33333
#define custom(x) ((x)*(x))
#define DEBUG

using namespace std;

int main() {
    #ifdef DEBUG
        cout << "DEBUG ���� �Դϴ�."<<endl;
    #else
        cout << "DEBUG ���°� �ƴմϴ�" <<endl;
    #endif
    cout << "#define custom = " << customN<< endl;
    cout << "#define custom(x (x*x)) = " << custom(2)<< endl;
    //#define custom = 33333
    //#define custom(x (x*x)) = 4
    cout <<"headerNumber = "<< headerNumber<<endl;
    #undef DEBUG

    #ifdef DEBUG
        cout << "DEBUG ���� �Դϴ�."<<endl;
    #else
        cout << "DEBUG ���°� �ƴմϴ�" <<endl;
    #endif
    return 0;
}
#include <iostream>

using namespace std;

void increment(int &num) {
    cout <<"-------- intcrement �Լ� ȣ��(b+1)"<<"\n" ; 
    num += 1; // num�� ���� ������ �����ϹǷ� ȣ���� ������ ���� ������
}

void justPrintValue(const int &num) {
    cout <<"-------- justPrintValue �Լ� ȣ��" << endl ; 
    // num += 1; //read-only
}

int main(){
    int a=0;
    int &aal=a;

    cout <<"-------- b=5"<<"\n" ; 
    int b = 5;
    increment(b); 
    cout <<"b = "<< b << endl; 
    justPrintValue(b); 
    cout <<"b = "<< b << endl; 

    int c=a;
    c++;
    cout <<"-------- c=a , c++"<<"\n" ; 
    cout <<"a = "<< a<< endl;
    cout <<"c = "<< c<< endl;
    return 0;
}
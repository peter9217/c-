#include <iostream> 

using namespace std; 

int Function(int a){
    cout << "Function �Լ�\n";
    return 2+a;
};
int main() { 
    cout <<"-------- cout"<<"\n" ; 
    cout <<"Hello, World!\n"<<"\n" ; 
    cout <<"-------- �¿� ���� ����"<<"\n" ; 
    cout <<"��\t"<<"��\n" ; 
    cout <<"������\t"<<"����\n" ; 
    cout <<"����\t" <<"���"<<endl; 
    cout <<"-------- ���� Ÿ�� ���� �� cout"<<"\n" ; 
    cout <<(double)7000*700 << endl ;
    int  ab = 0;
    cout <<"-------- �Լ� ȣ��"<<"\n" ; 
    ab=Function(3);
    cout << ab;   
    cout << "end";
    
    return 0;
}

#include <iostream>


using namespace std;
typedef signed short Sshort;
int i = 10;
int a = 111;
Sshort pluss(Sshort, Sshort y=50);
inline int pluss(int, int y=50);
int main(){
    Sshort p = pluss(static_cast<Sshort>(1), static_cast<Sshort>(2));
    int d = pluss(1, 2);
    // cout << i <<"\n";
    // cout << a;
    // p = pluss(30, 30);
    // cout << p<<"---------\n";
    return 0;
}

Sshort pluss(Sshort x, Sshort y){
    cout <<"-------- pluss(Sshort, Sshort) ȣ��"<<"\n" ; 
    Sshort i = x+y;
    a = 222;
    cout <<"ȣ�Ⱚ(x+y) = "<< i<<endl ; 
    return i;
}
int pluss(int x, int y){
    cout <<"-------- pluss(int, int) ȣ��"<<"\n" ; 
    int i = x-y;
    cout <<"ȣ�Ⱚ(x-y) = "<< i<<endl ; 
    return i;
}
#include <iostream>


using namespace std;

int main(){
    cout <<"-------- �߰�ȣ �ܺ�"<<"\n" ; 
    int a=0;
        cout <<"a = "<<a<<endl;
    {
        int a=2;
        cout <<"-------- �߰�ȣ ����"<<"\n" ; 
        cout <<"a = "<<a<<endl;
    }
        cout <<"-------- �߰�ȣ �ܺ�"<<"\n" ; 
        cout <<"a = "<<a<<endl;
    int b =1;
    cout <<"-------- ++�� ���� �� ����"<<"\n" ; 
    a++;
    cout <<"a++ = "<< a<<endl;
    int c =2;
    b++;
    cout <<"-------- --�� ���� �� ����"<<"\n" ; 
    cout <<"b = "<< b<<"\n";
    cout <<"b-- = "<< b--<<"\n";
    cout <<"--b = "<< --b<<"\n";
    cout <<"a+ ++b+c = "<< a+ ++b+c<<"\n";
    if(b>2||b==0){
        cout << "big"<<b;
    }else {
        cout << "b=="<<b;
    }
    return 0;
}
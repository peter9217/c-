#include <iostream>

using namespace std;

int main(){
    cout <<"-------- Ÿ�Ժ� ũ��"<<"\n" ; 
    cout << "int\t\t"<<sizeof(int)<<endl;
    cout << "short\t\t"<<sizeof(short)<<endl;
    cout << "long\t\t"<<sizeof(long)<<endl;
    cout << "long long\t"<<sizeof(long long)<<endl;
    cout << "char\t\t"<<sizeof(char)<<endl;
    cout << "double\t\t"<<sizeof(double)<<endl;
    typedef signed short ss;  //���� �ڷ��� ��Ī
    ss width=10, height=10, area=width*height;
    cout <<"-------- ��Ī�� �ڷ��� "<<endl; 
    cout<<"width = "<<width<<"\n";
    cout <<"area = "<< area<<"\n";
    cout <<"char(125) = "; 
    cout << (char)125<<"\n";
    width=5;
    cout <<"-------- ������ �ȿ� �ִ� ��"<<endl; 
    enum days {aaa=0, bbb=1, ccc=2, sunday=3};
    cout <<"days(4) = "<< days(4)<<"\n";
    cout <<"days::b = "<< days::bbb;
    cout <<"days::c = "<< days::ccc<<"\n";
    cout <<"days::sunday = "<< days::sunday<<"\n";
    // days daysOff;
    // int x;
    // cin >> x;
    // daysOff= days(x);
    // if(daysOff==aaa)
    //     cout << daysOff <<"-------------------\n";
    // else cout << "asd";
    return 0;

}
#include <iostream>
#include <string>
using namespace std;
typedef string st;
int main(){
    int counter = 0;
    cout <<"-------- loop����"<<"\n" ; 
    loop: counter++;
    cout << "counter = "<<counter<<endl ;
    if (counter<5)
    goto loop;
    cout <<"-------- loopŻ��"<<"\n" ; 
    counter=0;
    cout <<"-------- while����"<<"\n" ; 
    while(counter<5 && counter>-1)
    {counter++;
    cout << "counter = "<< counter<<endl ;
    }
    cout <<"-------- whileŻ��"<<"\n" ; 
    cout <<"-------- do����"<<"\n" ; 
    do{
        cout << "������ ����Ǵ� do(counter) = "<< "do!("<<counter<<")"<<endl;
        counter--;
    } while(counter>0);
        cout << "counter(while) = "<< counter<<endl;
    cout <<"-------- doŻ��"<<"\n" ; 

    cout <<"-------- for ����"<<"\n" ; 
    for(int i=0; i<5; i++){
        cout << "i = "<< i<<"\n";
    }
    cout <<"-------- forŻ��"<<"\n" ; 
    int a= 1;
    int b= 1;
    int c= 2;
    int n = 5;
    cout <<"-------- for ����"<<"\n" ; 
    for (n -= 3; n; n--) {
        a = b;
        b = c;
        c = a + b;
        cout <<"c(n) = "<< c<<"("<<n<<")"<<endl;
    }
    cout <<"-------- forŻ��"<<"\n" ; 
    n = 5;
    cout <<"-------- switch����"<<"\n" ; 
    switch(n){ 
        case 1: cout <<"n = "<< 1<<endl;
            break;
        case 5: cout <<"n = "<< 5<<endl;
            break;
        case 10: cout <<"n = "<< 10<<endl;
            break;
        default: cout <<"nothing"<<endl;
    }
    cout <<"-------- switchŻ��"<<"\n" ; 

    
    return 0;
}
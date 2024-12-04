#include <iostream>
#include <typeinfo>


using namespace std;

template <typename T>
T add(T a, T b){
    return a+b;
}

template <typename T>
class Calculator{
    public :
    T add2(T a, T b){
        return a + b;
    }
    T subtract(T a, T b){
        return a - b;
    }
};

template <typename T1, typename T2>
class Pair {
private:
    T1 first;
    T2 second;

public:
    Pair(T1 a, T2 b) : first(a), second(b) {}

    void display() {
        cout << "ù��° : " << first<<" (Ÿ�� : "<<typeid(first).name() << ") �ι�° : " << second<<" (Ÿ�� : "<<typeid(second).name() <<")"<< endl;
        cout << "ù��° + �ι�° :    " << first+second << endl;
    }
};

template <>
class Pair<char, char> {
private:
    char first;
    char second;
public:
    Pair(char a, char b) : first(a), second(b) {}

    void display() {
        cout << "char �ڷ����� ���� Ư��ȭ�Դϴ�. �� = " << first << second << endl;
    }
};


int main(){
    cout << "-------�Լ� ���ø�" << endl;
    cout <<"add(3, 5) = "<< add(3, 5)<< endl;
    cout <<"add(string([](){return \"a\";}()), string([](){return \"b\";}())) = "<< add(string([](){return "a";}()), string([](){return "b";}()))<< endl;
    cout << "-------Ŭ���� ���ø�" <<endl;
    Calculator<int> intCalc;
    cout <<"intCalc.add2(3, 5) = "<< intCalc.add2(3, 5)<< endl;
    // cout <<"intCalc.subtract(string([](){return \"a\";}()), string([](){return \"b\";}())) = "<< intCalc.subtract(string([](){return "a";}()), string([](){return "b";}()))<< endl;
    cout << "-------���� ���ø�" <<endl;
    Pair<int, double> p1(1, 2.5);
    p1.display();

    Pair<string, char> p2("Hello", 'A');
    p2.display();
    cout << "-------���ø� Ư��ȭ" <<endl;
    Pair<string, char> p3("H", 'A');
    p3.display();
    Pair<char, char> p4('H', 'A');
    p4.display();
    
    
    return 0;
}
#include <iostream>
using namespace std;

class MyClass {
private:
    int value;
    int value2;

public:
    explicit MyClass(int v) : value(v) {}  // ����� ������

    void printValue() const {
        cout << "Value: " << value << endl;
    }
    void printValue2() const {
        cout << "Value2: " << value2 << endl;
    }
};

int main() {
    MyClass obj1(10);  // ��������� ��ü ����
    obj1.printValue(); 

    // ������ ���� �Ͻ��� �� ��ȯ�� �Ұ���
    // MyClass obj2 = 20; 
    
    // obj2.printValue();  
    // obj2.printValue2();  //�Ͻ��� �� ��ȯ���� ���� value�� ������
    return 0;
}
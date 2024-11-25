#include <iostream>
using namespace std;

class MyClass {
private:
    int* data;
public:
    // �⺻ ������
    MyClass(int value) {
        data = new int(value);
        cout << "Constructor\n";
    }

    // �̵� ������
    MyClass(MyClass&& other) noexcept {
        data = other.data;   // �ڿ� �̵�
        other.data = nullptr; // ���� ��ü�� �ڿ� �����͸� null�� ����
    }

    // �Ҹ���
    ~MyClass() {
        delete data;
        cout << "Destructor\n";
    }

    void printData() {
        cout << "Data: " << *data << endl;
    }
};
class MyClass2 {
private:
    int value;
public:
    explicit MyClass2(int v) : value(v) {}
    MyClass2 operator+(const MyClass2& other) {
        return MyClass2(value + other.value);
    }
};
class MyClass3 {
private:
    int data;
    static int count;  // ���� ��� ����
public:
        // ������
    MyClass3(int value) : data(value) {
        count++;  // ��ü�� ������ ������ count ����
    }

    // ���� ��� �Լ�
    static void printCount() {
        cout << "Number of objects: " << count << endl;
    }
    // ������ �Լ� ����
    friend void FprintData(const MyClass3& obj);
    // �Ϲ� ��� �Լ�
    void printData() const {
        cout << "Data: " << data << endl;
    }
};
void FprintData(const MyClass3& obj) {
    cout << "Data: " << obj.data << endl;  // private ����� ���� ����
}
int MyClass3::count = 0;
int main() {
    MyClass obj1(10);          // �⺻ ������ ȣ��
    MyClass obj2 = move(obj1);  // �̵� ������ ȣ��

    obj2.printData();           // Data: 10

    MyClass3 obj3(10);
    MyClass3 obj4(20);

     MyClass3::printCount();  // ���: Number of objects: 2

    obj3.printData();  
    obj4.printData(); 
    cout<<"------------------"<<endl;
    cout<<"������� ����";
    FprintData(obj3);
    return 0;
}
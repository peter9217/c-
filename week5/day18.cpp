#include <iostream>
#include <thread>
#include <string>
#include <mutex>

using namespace std;
mutex mtx;

void printMessage(const string& message);
int counter = 0;
void increment() {
    for (int i = 0; i < 100000; ++i) {
        lock_guard<mutex> lock(mtx);
        ++counter; // ������ ���� �߻� ����
    }
    cout << "increment�Լ� ȣ��, ����� �������� ID : " <<this_thread::get_id()<<endl;
}

int main() {
    cout << "---------������ ����"<<endl;
    thread t1(printMessage, "������ ȣ��");
    t1.join();
    
    cout << "---------���� ǥ���İ� ������"<<endl;
    thread t2([](){
        cout<<"���� ǥ������ ������ ������ ȣ��" << endl;
    });
    t2.join();
    
    thread t3(increment);
    thread t4(increment);
    t3.join();
    t4.join();
    cout << "Counter : " << counter << endl;


    cout << "Counter: " << counter << endl; // ����ġ ���� ���. ��, mutex�� ���� �������� ���

    cout << "Number of threads supported: "
              << thread::hardware_concurrency() << endl;


    return 0;
}

void printMessage(const string& message){
    cout << message << endl;
    cout << "�Լ� ȣ��" << endl;
};
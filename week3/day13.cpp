#include <iostream>
#include <string>

using namespace std;
class say {
    int someNumber;
    public:
    say(int i) : someNumber(i){};
    void printa(int i){
        cout <<"-------- printa(int) ȣ��" << endl ; 
        cout<< "int��"<<i << endl;
    }
    void printa(string i){
        cout <<"-------- printa(string) ȣ��" << endl ; 
        cout << "string��" << i <<endl;
    }
    void printa(double i){
        cout <<"-------- printa(double) ȣ��" << endl ; 
        cout << "double��" << i << endl;
    }
    int getNumber(){
        return someNumber;
    }
};

class Int{
    int x, y;
    public :
    Int(int x= 0, int y=0):x(x),y(y){}
    Int operator+(const Int& other){
        return Int(x+other.x,y+other.y);
    }
    void display(){
        cout <<"-------- Int.display() ȣ��" << endl ; 
        cout<<x<<","<<y<<endl;
    }
};

// class Shape {
// public:
//     virtual void draw() = 0; // ���� ���� �Լ�
// };

class Shape {
public:
    virtual void draw() {  // ���� �Լ�
        cout <<"-------- Shape.draw() ȣ��" << endl ; 
        cout << "Drawing a generic shape." << endl;
    }
};

class Circle : public Shape {
public:
    void draw() override {  // ���� �Լ� ������
        cout <<"-------- Circle.draw() ȣ��" << endl ; 
        cout << "Drawing a circle." << endl;
    }
};

class Rectangle : public Shape {
public:
    void draw() override {
        cout << "Drawing a rectangle." << endl;
    }
};
int main() {
    say say(4);
    say.printa("s");
    say.printa(3);
    say.printa(3.5);
    cout<<"say.getNumber() = "<< say.getNumber() <<"\n"<< endl;
    Int a(1,3), b(2,4);
    Int c = a+b;
    c.display();

    Shape* shape1 = new Circle();
    Shape* shape2 = new Rectangle();

    shape1->draw();  // Circle�� draw() ȣ��
    shape2->draw();  // Rectangle�� draw() ȣ��

    delete shape1;
    delete shape2;
    return 0;
}
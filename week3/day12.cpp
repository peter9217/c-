#include <iostream>
#include <string>

using namespace std;

class cat {
    protected:
        string name;
        int age;
    public:
        cat(const string& objName, int myAge) : name(objName), age(myAge) {
            cout << "cat ��ü ����"<<endl;
        }
        virtual void meow() const {
        cout << "moew : " << name << endl;
    
        }
};
class family {
    public:
    void say() {
        cout <<"-------- family.say" << endl ; 
        cout << "�ȳ��ϼ��� �����Դϴ�." << endl; 
    }
};
class kitty : public cat, public family{
    public:
        kitty(const string& objName, int myAge) : cat(objName, myAge) {
            cout << "kitty ��ü ����"<<endl;
        }
        void meow() const override {
            cout << "moewwwwww : " << name <<endl;
        } 
};


int main(){
    cout <<"-------- rommy ����" << endl ; 
    kitty rommy("rommy", 10);
    rommy.meow();
    cout <<"-------- sammy ����" << endl ; 
    kitty sammy("sammy", 10);
    sammy.meow();
    rommy.say();

    return 0;
}
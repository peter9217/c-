#include <iostream>
#include <string>

using namespace std;

inline string meow();
class cat {
    string name;
    unsigned int age;
public:
    cat() {
        name = "�����";
        age = 0;
    }
    cat(string initialName, unsigned int initialAge) {
        name = initialName;
        age = initialAge;
    }
    ~cat(){};
    void setName(const string newName){
        name=newName; 
    }
    string getName() const {
        return name;
    }
    string meow() const {
        return "�߿�";
    }
};

int main(){
    cat rommy=cat();
    rommy.setName("�ι�");
    cout <<"-------- �ι� ����"<<"\n" ; 
    cout <<"rommy.getName() = "<< rommy.getName()<<endl;
    cat semmy("����",2);
    cout <<"-------- ���� ����"<<"\n" ; 
    cout <<"semmy.getName() = "<< semmy.getName()<<endl;
    // cout << cat.meow();
}
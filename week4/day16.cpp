#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

int main() {
    // int number;
    // cout << "----����� ��Ʈ��"<<endl;
    // cout << "���� �Է�";
    // cin >> number;
    // cout << "�Է��� ����" <<number;
    cout << "----���� ��Ʈ��"<<endl;
    cout << "----���� ����"<<endl;
    ofstream outFile("learn/week4/text.txt");
    if (outFile.is_open()){
        outFile << "inin" << endl;
        outFile << "gogo" << endl;
        outFile.close();
    }else {
        cerr<<endl;
    }
    cout << "----���� ���� �Ϸ�"<<endl;


    cout << "----���� �б�"<<endl;
    ifstream inFile("learn/week4/text.txt");
    if(inFile.is_open()){
        string line;
        while (getline(inFile, line)){
            cout << line << endl;
        }
        inFile.close();
    };
    cout << "----���� �б� �Ϸ�"<<endl;

    cout << "----��Ʈ�� ����."<<endl;
    cout <<"�ܼ��� �ٹٲٴ� ����"<< "\n"; 
    cout <<"��Ʈ���� ���� endl"<< endl; 
    cout << "----��Ʈ�� ����. ������"<<endl;
    cout <<fixed<< setprecision(2); 
    cout <<"3.444444="<<3.444444<<"\n" ; 
    cout <<"3.444444="<<3.444444<<endl; ; 
    cout << setw(50)<< right << "����";
    cout << setw(10)<< left << "������";
    cout << "----��Ʈ�� Ư¡ ."<<endl;
    cout << "��Ʈ��"<<"\n";
    cout << "Ȯ��";
    cout << eof();

    return 0;
}
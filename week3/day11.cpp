#include <iostream>
#include <vector>

using namespace std;

int main(){
    int arr[5];
    int arrC[] = {1,2,3,4,5};
    string arrS[]= {"asdfg", "asdd"};
    cout <<"-------- arr[5], arrC[] = {1,2,3,4,5}" << endl ; 
    cout <<"arr[0] = "<< arr[0]<<endl;
    cout <<"arrC[0] = "<< arrC[0]<<endl;
    cout <<"arrS[0] = "<< arrS[0]<<endl;
    cout <<"-------- for�� ����" << endl ; 
    for(int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++){
        cout <<"i = "<< i <<endl;
        cout <<"arr[i] = "<< arr[i] << endl;
    }
    cout <<"-------- for�� Ż��" << endl ; 

    int matrix[3][4] = {{2,3,4,5},{7,8,9,10},{11,12,13,14}};
    cout <<"matrix[2][0] = "<< matrix[2][0]<<endl;

    vector<int> vec;  // �� ����
    vector<int> vec2(5);  // 0���� �ʱ�ȭ�� 5�� ũ�⸦ ���� ����
    vector<int> vec3(5, 10); // 10���� �ʱ�ȭ�� 5�� ũ�� ����
    vector<int> vec4 = {1,2,3};  // �ʱⰪ�� �־� ����

    cout <<"-------- for�� ����" << endl ; 
    for (int i = 0; i < vec3.size(); i++) {
        cout <<"vec[i] = "<< vec3[i] << endl;
    }
    cout <<"-------- for�� Ż��" << endl ; 
    cout<<"vec2[1] = "<<vec2[1]<<endl;
    cout<<"vec3[1] = "<<vec3[1]<<endl;
    cout<<"vec4[1] = "<<vec4[1]<<endl;
    vec2.push_back(6);
    cout<<"vec2[4] = "<<vec2[4]<<endl;
    cout<<"----------------------"<<endl;
    try
    {
        cout<<vec2.at(8)<<endl;
    }
    catch(const exception& e)
    {
        cerr << e.what() << '\n';
    }
    
    cout<<"----------------------"<<endl;

    return 0;
}
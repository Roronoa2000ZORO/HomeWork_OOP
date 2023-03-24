#ifndef DYNAMICMEMORY
#define DYNAMICMEMORY

#include<iostream>
#include<random>

using namespace std;


class DinamicArray {
private:
    int size;
    int* data;
public:
    int get_size()const;
    int* get_data()const;


    //����������� ������
    DinamicArray(int size = int());
    //���������� ������
    ~DinamicArray();



                            /*������*/
    //���������� �������
    void fillArray();

    //������ ����� �������
    void swapAdress(int* buffer);

    //��������� �������� � ����� �������
    void push_back(int value);
    //������� ��������� ������� �������
    void pop_back();

    //��������� �������� � ������ �������
    void push_front(int value);
    //������� ������� ������� �������
    void pop_front();

    //��������� �������� � ������ �� ���������� �������
    void insert(int value, int pos);
    //������� ������� �� ������� �� ��������� �������
    void erase(int pos);

   /*�������� �������������� ����:*/
    operator int* ();


};

class DinamicArray2x : public DinamicArray
{
private:
    int rows;
    int cols;
    int** data;
public:
    int get_size()const;
    int** get_data()const;

    //����������� ������
    DinamicArray2x(int rows, int cols);
    //���������� ������
    ~DinamicArray2x();

                                    /*������*/

    //��������� ������ ������ � ����� ���
    void push_row_back();



};

//������� �������
int MyRandom(int a, int b);

//�������� ������� � �����
ostream& operator<<(ostream& ost, const DinamicArray& obj);

/*
//�������� ������ ��� ��������� ������������ ������
int* Alocate(? ? ? );
//����������� ������, ���������� ���
int* Clear(? ? ? );

//��������� ������ ������ � ����� ���
int* push_row_back(? ? ? );
//��������� ������ ������ � ������ ���
int* push_row_front(? ? ? );
//��������� ������ ������ � ��� �� ��������� �������
int* insert_row(? ? ? );

//������� ��������� ������ �� ���
int* pop_row_back(? ? ? );
//������� ������� ������ �� ���
int* pop_row_front(? ? ? );
//������� ������ �� ��� �� ��������� �������
int* erase_row(? ? ? );

//��������� ������ ������� � ����� ���
int* push_col_back(? ? ? );
//��������� ������ ������� � ������ ���
int* push_col_front(? ? ? );
//��������� ������ ������� � ��� �� ��������� �������
int* insert_col(? ? ? );

//������� ��������� ������� �� ���
int* pop_col_back(? ? ? );
//������� ������� ������� �� ���
int* pop_col_front(? ? ? );
//������� ������� �� ��� �� ��������� �������
int* erase_col(? ? ? );
*/
#endif // !DYNAMICMEMORY

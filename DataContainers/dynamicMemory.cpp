#include"dynamicMemory.hpp"

int DinamicArray::get_size() const
{
	return size;
}

int* DinamicArray::get_data() const
{
	return data;
}

//����������� ������
DinamicArray::DinamicArray(int size) :size(size), data(new int[size] {})
{
}
//���������� ������
DinamicArray::~DinamicArray()
{
	size = int();
	delete[] data;
	data = nullptr;
}



										/*������*/

void DinamicArray::fillArray()
{
	for (size_t i = 0; i < size; i++)
	{
		data[i] = MyRandom(1, 100);
	}
}

//������ ����� �������
void DinamicArray::swapAdress(int* buffer) {
	int* holder = buffer;
	buffer = data;
	data = holder;
	delete[] buffer;
	buffer = nullptr;
}


//��������� �������� � ����� �������
void DinamicArray::push_back(int value)
{
	size++;
	int* buffer = new int[size]{};

	for (size_t i = 0; i < size; i++)
	{
		if (i == size - 1) {
			buffer[i] = value;
		}
		else {
			buffer[i] = data[i];
		}
	}
	swapAdress(buffer);
}
//������� ��������� ������� �������
void DinamicArray::pop_back()
{
	size--;
	int* buffer = new int[size]{};

	for (size_t i = 0; i < size; i++)
	{
		buffer[i] = data[i];
	}
	swapAdress(buffer);
}


//��������� �������� � ������ �������
void DinamicArray::push_front(int value)
{
	size++;
	int* buffer = new int[size] {};
	for (size_t i = 0; i < size; i++)
	{
		if (i == 0) {
			buffer[i] = value;
		}
		else {
			buffer[i] = data[i - 1];
		}
	}
	swapAdress(buffer);
}
//������� ������� ������� �������
void DinamicArray::pop_front()
{
	size--;
	int* buffer = new int[size] {};
	for (size_t i = 0; i < size; i++)
	{
		buffer[i] = data[i + 1];
	}
	swapAdress(buffer);
}



//��������� �������� � ������ �� ���������� �������
void DinamicArray::insert(int value, int pos)
{
	size++;
	int* buffer = new int[size] {};
	int j = 0;
	for (size_t i = 0; i < size; i++)
	{
		if (i == pos) {
			buffer[i] = value;
			j++;
		}
		else {
			buffer[i] = data[i - j];
		}
	}
	swapAdress(buffer);
}

//������� ������� �� ������� �� ��������� �������
void DinamicArray::erase(int pos)
{
	size--;
	int* buffer = new int[size] {};
	int j = 0;
	for (size_t i = 0; i < size; i++)
	{
		if (i == pos) {
			j++;
		}
		buffer[i] = data[i + j];
	}
	swapAdress(buffer);
}
/*�������� �������������� ����:*/
DinamicArray::operator int* ()
{
	return data;
}


//������� �������
int MyRandom(int a, int b) {

	static mt19937 gen(random_device{}());
	uniform_real_distribution<> dis(a, b);
	return int(dis(gen));
}

//�������� ������� � �����
ostream& operator<<(ostream& ost, const DinamicArray& obj)
{
	for (size_t i = 0; i < obj.get_size(); i++)
	{
		ost << obj.get_data()[i] << "\t";
	}
	return ost;
}



/*__________________________________class DinamicArray2x__________________________*/



int DinamicArray2x::get_size() const
{
	return rows;
}

int** DinamicArray2x::get_data() const
{
	return data;
}

//����������� ������

DinamicArray2x::DinamicArray2x(int rows, int cols)
	: rows(rows), cols(cols), data(new int* [rows] {})
{
	for (size_t i = 0; i < rows; i++)
	{
		data[i] = DinamicArray(cols);
	}
}

//���������� ������
DinamicArray2x::~DinamicArray2x()
{
	DinamicArray::~DinamicArray();
	rows = int();
	delete[] data;
	data = nullptr;
}

void DinamicArray2x::push_row_back()
{

}





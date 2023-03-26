#include"dynamicArray.hpp"


/*----------------------------start-class-DinamicArray---------------------------*/

int DinamicArray::get_size() const
{
	return size;
}

int* DinamicArray::get_data() const
{
	return data;
}

void DinamicArray::set_size(int size)
{
	if (size < 2) size = 2;
	this->size = size;
}




//Конструктор класса
DinamicArray::DinamicArray(int size)
{
	set_size(size);
	data = new int[this->size] {};
}
//Конструктор копирования
DinamicArray::DinamicArray(const DinamicArray& other)
	: DinamicArray(other.size)
{
	for (size_t i = 0; i < size; i++)
	{
		data[i] = other.data[i];
	}
}
//Конструктор переноса
DinamicArray::DinamicArray(DinamicArray&& other) noexcept
	: size(other.size), data(other.data)
{
	other.data = nullptr;
}
//Деструктор класса
DinamicArray::~DinamicArray()
{
	size = int();
	delete[] data;
	data = nullptr;
}



										/*Методы*/

//Заполнение массива
void DinamicArray::fillArray()
{
	for (size_t i = 0; i < size; i++)
	{
		data[i] = MyRandom(1, 100);
	}
}

//меняет адрес местами
void DinamicArray::assignAdress(int* buffer) {
	delete[] data;
	data = buffer;
	buffer = nullptr;
}


//добавляет значение в конец массива
void DinamicArray::push_back(int value)
{
	size++;
	int* buffer = new int[size]{};

	for (size_t i = 0; i < size; i++)
	{
		if (i == size - 1) buffer[i] = value;
		else buffer[i] = data[i];
	}
	assignAdress(buffer);
}
//удаляет последний элемент массива
void DinamicArray::pop_back()
{
	size--;
	int* buffer = new int[size]{};

	for (size_t i = 0; i < size; i++)
	{
		buffer[i] = data[i];
	}
	assignAdress(buffer);
}


//добавляет значение в начало массива
void DinamicArray::push_front(int value)
{
	size++;
	int* buffer = new int[size] {};
	buffer[0] = value;

	for (size_t i = 1; i < size; i++)
	{
		buffer[i] = data[i - 1];
	}
	assignAdress(buffer);
}
//удаляет нулевой элемент массива
void DinamicArray::pop_front()
{
	size--;
	int* buffer = new int[size] {};
	for (size_t i = 0; i < size; i++)
	{
		buffer[i] = data[i + 1];
	}
	assignAdress(buffer);
}



//добавляет значение в массив по указанному индексу
void DinamicArray::insert(int pos, int value)
{
	size++;
	int* buffer = new int[size] {};
	int j = 0;
	for (size_t i = 0; i < size; i++)
	{
		if (i == pos) 
		{
			buffer[i] = value;
			j++;
		}
		else buffer[i] = data[i - j];
	}
	assignAdress(buffer);
}

//удаляет элемент из массива по заданному индексу
void DinamicArray::erase(int pos)
{
	size--;
	int* buffer = new int[size] {};
	int j = 0;
	for (size_t i = 0; i < size; i++)
	{
		if (i == pos) j++;

		buffer[i] = data[i + j];
	}
	assignAdress(buffer);
}



									/*Перегрузка операторов*/

//Оператор присваивания
DinamicArray& DinamicArray::operator=(const DinamicArray& other)
{
	if (this == &other) return *this;
	delete[] data;

	size = other.size;
	data = new int[size] {};
	for (size_t i = 0; i < size; i++)
	{
		data[i] = other.data[i];
	}
	return *this;
}
//Оператор переноса
DinamicArray& DinamicArray::operator=(DinamicArray&& other) noexcept
{
	if (this == &other) return *this;
	delete[] data;

	size = other.size;
	data = other.data;
	other.data = nullptr;

	return *this;
}



/*------------------------------end-class-DinamicArray---------------------------*/

//функция рандома
int MyRandom(int a, int b) {

	static mt19937 gen(random_device{}());
	uniform_real_distribution<> dis(a, b);
	return int(dis(gen));
}

//Оператор вставки в поток
ostream& operator<<(ostream& ost, const DinamicArray& obj)
{
	for (size_t i = 0; i < obj.get_size(); i++)
	{
		ost << obj.get_data()[i] << "\t";
	}
	return ost;
}

/*----------------------------start-class-DinamicArray2D-------------------------*/



int DinamicArray2D::get_rows() const
{
	return rows;
}

int DinamicArray2D::get_cols() const
{
	return cols;
}

int** DinamicArray2D::get_data() const
{
	return data;
}

void DinamicArray2D::set_rows(int rows)
{
	if (rows < 2)rows = 2;
	this->rows = rows;
}

void DinamicArray2D::set_cols(int cols)
{
	if (cols < 2)cols = 2;
	this->cols = cols;
}


//Конструктор класса
DinamicArray2D::DinamicArray2D(int rows, int cols)
{
	set_rows(rows);
	set_cols(cols);
	data = new int* [this->rows] {};
	for (size_t i = 0; i < this->rows; i++)
	{
		data[i] = new int [this->cols] {};
	}
}

//Конструктор копирования
DinamicArray2D::DinamicArray2D(const DinamicArray2D& other)
	:DinamicArray2D(other.rows, other.cols)
{
	for (size_t i = 0; i < rows; i++)
	{
		for (size_t j = 0; j < rows; j++)
		{
			data[i][j] = other.data[i][j];
		}
	}
}

//Конструктор переноса
DinamicArray2D::DinamicArray2D(DinamicArray2D&& other) noexcept
	:rows(other.rows), cols(other.cols), data(other.data)
{
	for (size_t i = 0; i < rows; i++)
	{
		other.data[i] = nullptr;
	}
	other.data = nullptr;
}

//Деструктор класса
DinamicArray2D::~DinamicArray2D()
{
	
	for (size_t i = 0; i < rows; i++)
	{
		delete[] data[i];
		data[i] = nullptr;
	}
	rows = int();
	cols = int();
	delete[] data;
	data = nullptr;
}

//Заполнение массива
void DinamicArray2D::fillArray()
{
	for (size_t i = 0; i < rows; i++)
	{
		for (size_t j = 0; j < cols; j++)
		{
			data[i][j] = MyRandom(1, 100);
		}
	}
}

//добавляет пустую строку в конец ДДМ
void DinamicArray2D::push_row_back()
{
	rows++;
	int** buffer = new int*[rows] {};

	for (size_t i = 0; i < rows; i++)
	{
		if (i == rows - 1) buffer[i] = new int[cols] {};
		else buffer[i] = data[i];
	}
	delete[] data;
	data = buffer;
	buffer = nullptr;
}
//удаляет последнюю строку из ДДМ
void DinamicArray2D::pop_row_back()
{
	rows--;
	int** buffer = new int* [rows] {};

	for (size_t i = 0; i < rows; i++)
	{
		buffer[i] = data[i];
	}
	delete[] data[rows];
	delete[] data;
	data = buffer;
	buffer = nullptr;
}


//добавляет пустую строку в начало ДДМ
void DinamicArray2D::push_row_front()
{
	rows++;
	int** buffer = new int* [rows] {};
	buffer[0] = new int[cols] {};
	for (size_t i = 1; i < rows; i++)
	{
		buffer[i] = data[i - 1];
	}
	delete[] data;
	data = buffer;
	buffer = nullptr;
}
//удаляет нулевую строку из ДДМ
void DinamicArray2D::pop_row_front()
{
	rows--;
	int** buffer = new int* [rows] {};

	for (size_t i = 0; i < rows; i++)
	{
		buffer[i] = data[i + 1];
	}
	delete[] data[0];
	delete[] data;
	data = buffer;
	buffer = nullptr;
}


//вставляет пустую строку в ДДМ по заданному индексу
void DinamicArray2D::insert_row(int pos)
{
	rows++;
	int** buffer = new int* [rows] {};
	int j = 0;
	for (size_t i = 0; i < rows; i++)
	{
		if (i == pos)
		{
			buffer[i] = new int[cols] {}; 
			j++;
		}
		else buffer[i] = data[i - j];
	}
	delete[] data;
	data = buffer;
	buffer = nullptr;
}
//удаляет строку из ДДМ по заданному индексу
void DinamicArray2D::erase_row(int pos)
{
	rows--;
	int** buffer = new int* [rows] {};
	int j = 0;
	for (size_t i = 0; i < rows; i++)
	{
		if (i == pos) j++;

		buffer[i] = data[i + j];
	}
	delete[] data[pos];
	delete[] data;
	data = buffer;
	buffer = nullptr;
}



//добавляет пустой столбец в конец ДДМ
void DinamicArray2D::push_col_back()
{
	cols++;

	for (size_t i = 0; i < rows; i++)
	{
		int* buffer = new int[cols] {};
		for (size_t j = 0; j < cols - 1; j++) buffer[j] = data[i][j];

		delete[] data[i];
		data[i] = buffer;
		buffer = nullptr;
	}
}
//удаляет последний столбец из ДДМ
void DinamicArray2D::pop_col_back()
{
	cols--;

	for (size_t i = 0; i < rows; i++)
	{
		int* buffer = new int[cols] {};
		for (size_t j = 0; j < cols; j++) buffer[j] = data[i][j];

		delete[] data[i];
		data[i] = buffer;
		buffer = nullptr;
	}
}


//добавляет пустой столбец в начало ДДМ
void DinamicArray2D::push_col_front()
{
	cols++;

	for (size_t i = 0; i < rows; i++)
	{
		int* buffer = new int[cols] {};
		for (size_t j = 1; j < cols; j++) buffer[j] = data[i][j - 1];

		delete[] data[i];
		data[i] = buffer;
		buffer = nullptr;
	}
}
//удаляет нулевой столбец из ДДМ
void DinamicArray2D::pop_col_front()
{
	cols--;

	for (size_t i = 0; i < rows; i++)
	{
		int* buffer = new int[cols] {};
		for (size_t j = 0; j < cols; j++) buffer[j] = data[i][j + 1];

		delete[] data[i];
		data[i] = buffer;
		buffer = nullptr;
	}
}

//вставляет пустой столбец в ДДМ по заданному индексу
void DinamicArray2D::insert_col(int pos)
{
	cols++;

	for (size_t i = 0; i < rows; i++)
	{
		int* buffer = new int[cols] {};
		int n = 0;
		for (size_t j = 0; j < cols; j++) 
		{
			if (j == pos) n++; 
			else buffer[j] = data[i][j - n];
		}

		delete[] data[i];
		data[i] = buffer;
		buffer = nullptr;
	}
}
//удаляет столбец из ДДМ по заданному индексу
void DinamicArray2D::erase_col(int pos)
{
	cols--;

	for (size_t i = 0; i < rows; i++)
	{
		int* buffer = new int[cols] {};
		int n = 0;
		for (size_t j = 0; j < cols; j++)
		{
			if (j == pos) n++;
			buffer[j] = data[i][j + n];
		}

		delete[] data[i];
		data[i] = buffer;
		buffer = nullptr;
	}
}
								/*Перегрузка операторов*/

//Оператор присваивания
DinamicArray2D& DinamicArray2D::operator=(const DinamicArray2D& other)
{
	if (this == &other) return *this;
	for (size_t i = 0; i < rows; i++)
	{
		delete[] data[i];
	}
	delete[] data;

	rows = other.rows;
	cols = other.cols;
	data = new int*[rows] {};

	for (size_t i = 0; i < rows; i++)
	{
		data[i] = new int[cols] {};
		for (size_t j = 0; j < cols; j++)
		{
			data[i][j] = other.data[i][j];
		}
	}
	
	return *this;
}
//Оператор переноса
DinamicArray2D& DinamicArray2D::operator=(DinamicArray2D&& other) noexcept
{
	if (this == &other) return *this;
	for (size_t i = 0; i < rows; i++)
	{
		delete[] data[i];
	}
	delete[] data;

	rows = other.rows;
	cols = other.cols;
	data = other.data;

	for (size_t i = 0; i < rows; i++)
	{
		other.data[i] = nullptr;
	}
	other.data = nullptr;
	return *this;
}


/*------------------------------end-class-DinamicArray2D-------------------------*/

//Оператор вставки в поток для двумерного массива
ostream& operator<<(ostream& ost, const DinamicArray2D& obj)
{
	for (size_t i = 0; i < obj.get_rows(); i++)
	{
		for (size_t j = 0; j < obj.get_cols(); j++)
		{
			ost << obj.get_data()[i][j] << "\t";
		}
		ost << endl;
	}
	return ost;
}
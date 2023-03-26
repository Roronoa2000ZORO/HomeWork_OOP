#include"dynamicArray.hpp"


/*----------------------------start-class-DinamicArray---------------------------*/

Type int DinamicArray<T>::get_size() const
{
	return size;
}

Type T* DinamicArray<T>::get_data() const
{
	return data;
}

Type void DinamicArray<T>::set_size(int size)
{
	if (size < 2) size = 2;
	this->size = size;
}




//Конструктор класса
template<typename T>DinamicArray<T>::DinamicArray(int size)
{
	set_size(size);
	data = new T[this->size] {};
}
//Конструктор копирования
template<typename T>DinamicArray<T>::DinamicArray(const DinamicArray& other)
	: DinamicArray(other.size)
{
	for (size_t i = 0; i < size; i++)
	{
		data[i] = other.data[i];
	}
}
//Конструктор переноса
template<typename T>DinamicArray<T>::DinamicArray(DinamicArray&& other) noexcept
	: size(other.size), data(other.data)
{
	other.data = nullptr;
}
//Деструктор класса
template<typename T>DinamicArray<T>::~DinamicArray()
{
	size = T();
	delete[] data;
	data = nullptr;
}



										/*Методы*/

//Заполнение массива
Type void DinamicArray<T>::fillArray()
{
	for (size_t i = 0; i < size; i++)
	{
		data[i] = MyRandom(1, 100);
	}
}

//меняет адрес местами
Type void DinamicArray<T>::assignAdress(T* buffer) {
	delete[] data;
	data = buffer;
	buffer = nullptr;
}


//добавляет значение в конец массива
Type void DinamicArray<T>::push_back(T value)
{
	size++;
	int* buffer = new T[size]{};

	for (size_t i = 0; i < size; i++)
	{
		if (i == size - 1) buffer[i] = value;
		else buffer[i] = data[i];
	}
	assignAdress(buffer);
}
//удаляет последний элемент массива
Type void DinamicArray<T>::pop_back()
{
	size--;
	int* buffer = new T[size]{};

	for (size_t i = 0; i < size; i++)
	{
		buffer[i] = data[i];
	}
	assignAdress(buffer);
}


//добавляет значение в начало массива
Type void DinamicArray<T>::push_front(T value)
{
	size++;
	int* buffer = new T[size] {};
	buffer[0] = value;

	for (size_t i = 1; i < size; i++)
	{
		buffer[i] = data[i - 1];
	}
	assignAdress(buffer);
}
//удаляет нулевой элемент массива
Type void DinamicArray<T>::pop_front()
{
	size--;
	int* buffer = new T[size] {};
	for (size_t i = 0; i < size; i++)
	{
		buffer[i] = data[i + 1];
	}
	assignAdress(buffer);
}



//добавляет значение в массив по указанному индексу
Type void DinamicArray<T>::insert(int pos, T value)
{
	size++;
	int* buffer = new T[size] {};
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
Type void DinamicArray<T>::erase(int pos)
{
	size--;
	int* buffer = new T[size] {};
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
Type DinamicArray<T>& DinamicArray<T>::operator=(const DinamicArray& other)
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
Type DinamicArray<T>& DinamicArray<T>::operator=(DinamicArray&& other) noexcept
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
Type T MyRandom(T a, T b) {

	static mt19937 gen(random_device{}());
	uniform_real_distribution<> dis(a, b);
	return T(dis(gen));
}

//Оператор вставки в поток
Type ostream& operator<<(ostream& ost, const DinamicArray<T>& obj)
{
	for (size_t i = 0; i < obj.get_size(); i++)
	{
		ost << obj.get_data()[i] << "\t";
	}
	return ost;
}

/*----------------------------start-class-DinamicArray2D-------------------------*/



Type int DinamicArray2D<T>::get_rows() const
{
	return rows;
}

Type int DinamicArray2D<T>::get_cols() const
{
	return cols;
}

Type T** DinamicArray2D<T>::get_data() const
{
	return data;
}

Type void DinamicArray2D<T>::set_rows(int rows)
{
	if (rows < 2)rows = 2;
	this->rows = rows;
}

Type void DinamicArray2D<T>::set_cols(int cols)
{
	if (cols < 2)cols = 2;
	this->cols = cols;
}


//Конструктор класса
template<typename T>DinamicArray2D<T>::DinamicArray2D(int rows, int cols)
{
	set_rows(rows);
	set_cols(cols);
	data = new int* [this->rows] {};
	for (size_t i = 0; i < this->rows; i++)
	{
		data[i] = new T[this->cols] {};
	}
}

//Конструктор копирования
template<typename T>DinamicArray2D<T>::DinamicArray2D(const DinamicArray2D& other)
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
template<typename T>DinamicArray2D<T>::DinamicArray2D(DinamicArray2D&& other) noexcept
	:rows(other.rows), cols(other.cols), data(other.data)
{
	for (size_t i = 0; i < rows; i++)
	{
		other.data[i] = nullptr;
	}
	other.data = nullptr;
}

//Деструктор класса
template<typename T>DinamicArray2D<T>::~DinamicArray2D()
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
Type void DinamicArray2D<T>::fillArray()
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
Type void DinamicArray2D<T>::push_row_back()
{
	rows++;
	T** buffer = new T*[rows] {};

	for (size_t i = 0; i < rows; i++)
	{
		if (i == rows - 1) buffer[i] = new T[cols] {};
		else buffer[i] = data[i];
	}
	delete[] data;
	data = buffer;
	buffer = nullptr;
}
//удаляет последнюю строку из ДДМ
Type void DinamicArray2D<T>::pop_row_back()
{
	rows--;
	T** buffer = new T* [rows] {};

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
Type void DinamicArray2D<T>::push_row_front()
{
	rows++;
	T** buffer = new T* [rows] {};
	buffer[0] = new T[cols] {};
	for (size_t i = 1; i < rows; i++)
	{
		buffer[i] = data[i - 1];
	}
	delete[] data;
	data = buffer;
	buffer = nullptr;
}
//удаляет нулевую строку из ДДМ
Type void DinamicArray2D<T>::pop_row_front()
{
	rows--;
	T** buffer = new T* [rows] {};

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
Type void DinamicArray2D<T>::insert_row(int pos)
{
	rows++;
	T** buffer = new T* [rows] {};
	int j = 0;
	for (size_t i = 0; i < rows; i++)
	{
		if (i == pos)
		{
			buffer[i] = new T[cols] {}; 
			j++;
		}
		else buffer[i] = data[i - j];
	}
	delete[] data;
	data = buffer;
	buffer = nullptr;
}
//удаляет строку из ДДМ по заданному индексу
Type void DinamicArray2D<T>::erase_row(int pos)
{
	rows--;
	T** buffer = new T* [rows] {};
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
Type void DinamicArray2D<T>::push_col_back()
{
	cols++;

	for (size_t i = 0; i < rows; i++)
	{
		T* buffer = new T[cols] {};
		for (size_t j = 0; j < cols - 1; j++) buffer[j] = data[i][j];

		delete[] data[i];
		data[i] = buffer;
		buffer = nullptr;
	}
}
//удаляет последний столбец из ДДМ
Type void DinamicArray2D<T>::pop_col_back()
{
	cols--;

	for (size_t i = 0; i < rows; i++)
	{
		T* buffer = new T[cols] {};
		for (size_t j = 0; j < cols; j++) buffer[j] = data[i][j];

		delete[] data[i];
		data[i] = buffer;
		buffer = nullptr;
	}
}


//добавляет пустой столбец в начало ДДМ
Type void DinamicArray2D<T>::push_col_front()
{
	cols++;

	for (size_t i = 0; i < rows; i++)
	{
		T* buffer = new T[cols] {};
		for (size_t j = 1; j < cols; j++) buffer[j] = data[i][j - 1];

		delete[] data[i];
		data[i] = buffer;
		buffer = nullptr;
	}
}
//удаляет нулевой столбец из ДДМ
Type void DinamicArray2D<T>::pop_col_front()
{
	cols--;

	for (size_t i = 0; i < rows; i++)
	{
		T* buffer = new T[cols] {};
		for (size_t j = 0; j < cols; j++) buffer[j] = data[i][j + 1];

		delete[] data[i];
		data[i] = buffer;
		buffer = nullptr;
	}
}

//вставляет пустой столбец в ДДМ по заданному индексу
Type void DinamicArray2D<T>::insert_col(int pos)
{
	cols++;

	for (size_t i = 0; i < rows; i++)
	{
		T* buffer = new T[cols] {};
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
Type void DinamicArray2D<T>::erase_col(int pos)
{
	cols--;

	for (size_t i = 0; i < rows; i++)
	{
		T* buffer = new T[cols] {};
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
Type DinamicArray2D<T>& DinamicArray2D<T>::operator=(const DinamicArray2D& other)
{
	if (this == &other) return *this;
	for (size_t i = 0; i < rows; i++)
	{
		delete[] data[i];
	}
	delete[] data;

	rows = other.rows;
	cols = other.cols;
	data = new T*[rows] {};

	for (size_t i = 0; i < rows; i++)
	{
		data[i] = new T[cols] {};
		for (size_t j = 0; j < cols; j++)
		{
			data[i][j] = other.data[i][j];
		}
	}
	
	return *this;
}
//Оператор переноса
Type DinamicArray2D<T>& DinamicArray2D<T>::operator=(DinamicArray2D&& other)
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
Type ostream& operator<<(ostream& ost, const DinamicArray2D<T>& obj)
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
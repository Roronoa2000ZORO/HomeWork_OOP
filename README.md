# HomeWork_OOP
TOREAD:


https://en.cppreference.com/w

https://drive.google.com/drive/folders/1mIhAKMp5-Jpy6s5X8u924tRCXFEdHE_z?usp=sharing


TODO:
Проверочный код в секции OPERATOR_PLUS должен заработать:
	https://github.com/okovtun/PV_211/blob/075a52ff5354e97614ef1ac78c6b4c2190bfe1c7/DataContainers/ForwardList/main.cpp#L173
	

DONE: (14)
В класс ForwardList добавить следующие методы:
	??? push_back(???);
	??? pop_front(???);
	??? pop_back(???);
	??? insert(???);	//вставляет значение в список по указанному индексу
	??? erase(???);		//удаляет значение из списка по указанному индексу

DONE: (13)
1. Добить все эти функции:
В проект DataContainers добавить следующте функции:
	??? push_front(???);	//добавляет значение в начало массива
	??? insert(???);		//добавляет значение в массив по указанному индексу
	??? pop_back(???);		//удаляет последний элемент массива
	??? pop_front(???);		//удаляет нулевой элемент массива
	??? erase(???);			//удаляет элемент из массива по заданному индексу
	??? Alocate(???);		//Выделяет память под двумерный динамический массив
	??? Clear(???);			//Освобождает память, занимаемую ДДМ
	??? push_row_back(???);	//добавляет пустую строку в конец ДДМ
	??? push_row_front(???);//добавляет пустую строку в начало ДДМ
	??? insert_row(???);	//вставляет пустую строку в ДДМ по заданному индексу
	??? pop_row_back(???);	//удаляет последнюю строку из ДДМ
	??? pop_row_front(???);	//удаляет нулевую строку из ДДМ
	??? erase_row(???);		//удаляет строку из ДДМ по заданному индексу
	??? push_col_back(???);	//добавляет пустой столбец в конец ДДМ
	??? push_col_front(???);//добавляет пустой столбец в начало ДДМ
	??? insert_col(???);	//вставляет пустой столбец в ДДМ по заданному индексу
	??? pop_col_back(???);	//удаляет последний столбец из ДДМ
	??? pop_col_front(???);	//удаляет нулевой столбец из ДДМ
	??? erase_col(???);		//удаляет столбец из ДДМ по заданному индексу

2. От веткти 'master' создать ветку 'DynamicMemoryTemplated', и в ней шаблонизировать 
   все функции для работы с массивами, кроме FillRand();

3. *** От ветки 'DynamicMemoryTemplated' создать ветку 'DynamicOptimisation', и в ней 
   оптимизировать все функции для работы с двумерными динамическими массивами.

TODO: (12)
1. В иерархию геометрицеских фигур добавить иерархию Треугольников;
2. ***В отдельной ветке вынести код рисования фигуры (hdc, hPen, hBrush...) в базовый класс, а в конкретном классе
	должны лишь вызываться функция рисования ::Rectangle(), ::Ellipse().....

TODO: (11)
1. Реализовать классы Circle и Triangle. Для рисования этих фигур используются следующие функции:
	https://learn.microsoft.com/en-us/windows/win32/gdi/about-filled-shapes
2. Для каждой фигуры добавить атрибут "Цвет";

DONE: (10)
Реализовать иерархию геометрических фигур: круг, треугольник, квадрат, прямоугольник ...
Для каждой фигуры вывести на экран ее первичные свойства, такие как длина стороны квадрата,
радиус круга...., и вторичные свойства: площадь и периметр. Так же каждую фигуру нужно нарисовать.


DONE: (9)
1. В проекте Files, разел WRITE_TO_FILE имя файла должно вводиться с клавиатуры;
2. Если при вводе имени пользователь не написал расширение имени файла, то программа сама должна добавить "*.txt";
3. Из файла "201 RAW.txt" создать новый файл "201 ready.txt", в котором столбцы с IP-адресом и MAC-адресом должны быть поменяны местами;
4. Из файла "201 RAW.txt" создать новый файл "201.dhcpd", который должен иметь следующий формат:
	https://github.com/okovtun/PV_211/blob/master/Inheritance/Task/201.dhcpd
5. Сохранить группу в файл;
6. Загрузить группу из файла;

DONE: (8)
Реализовать проект Academy;

DONE: (7)
Добавить в класс String Move-методы:
https://legacy.cplusplus.com/doc/tutorial/classes2/


DONE: (6)
1. Пять проектов на выбор залить на GitHub;
2. 
   Проверочный код в проекте IntroductionToOOP\String:
	https://github.com/okovtun/PV_211/blob/3f251e284849ad3896fd7e019ca2d3d8571497b9/IntroductionToOOP/String/main.cpp#L48
должен заработать.


DONE:(5)

1. Проверочный код в секции HOME_WORK_1 должен заработать:
	https://github.com/okovtun/PV_211/blob/5afd5711a7935f874783ff64f552bcc10ae46edd/IntroductionToOOP/Fraction/main.cpp#L415
2. Проверочный код в секции HOME_WORK_2 должен заработать:
	https://github.com/okovtun/PV_211/blob/5afd5711a7935f874783ff64f552bcc10ae46edd/IntroductionToOOP/Fraction/main.cpp#L422
	
	
	
	
DONE:(4)

Проверочный код должен заработать:
	Fraction A;
	cout << "Введите простю дробь: "; cin >> A;
	cout << A << endl;

	Необходимо предусмотреть следующие варианты ввода:
		5
		1/2
		2 3/4
		2(3/4)

DONE:(3)

Для класса Fraction перегрузить следующие операторы:
1. Арифметические операторы:+, -, *, /;
2. Составные присваивания:	+=, -=, *=, /=;
3. Операторы сравнения:		==, !=, >, <, >=, <=;
4. Написать метод ??? reduce(???), который сокращает дробь;
		https://www.webmath.ru/poleznoe/formules_12_7.php

DONE:(2)

0. Выучить теорию!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
1. В Solution 'IntroductionToOOP' добавить проект 'Fraction', и в нем реализовать класс 'Fraction',
   описывающий простую дробь. В классе должны быть все необходимые методы и операторы;

DONE:(1)

0. Выучить теорию!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
1. Написать метод ??? distance(???), который возвращает расстояние до указанной точки;		
2. Написать функцию ??? distance(???), которая возвращает расстояние между двумя точками;	

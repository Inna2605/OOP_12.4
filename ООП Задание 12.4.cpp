//Создать и инициализировать массив из 4-х объектов типа Дробь (Fraction) и записать этот массив в файл в бинарном режиме.
//Затем создать объект типа Дробь и считать из этого файла в этот объект данные предпоследнего объекта массива.Использовать позиционирование по файлу

#include <iostream>
#include <fstream>
#include"Fraction.h"
using namespace std;
int main()
{
	setlocale(LC_ALL, "ru");

	Fraction fraction1(4, 5);
	Fraction fraction2(3, 8);
	Fraction fraction3(1, 2);
	Fraction fraction4(14, 5);

	const int number = 4;
	Fraction array1[number];
	array1[0] = fraction1;
	array1[1] = fraction2;
	array1[2] = fraction3;
	array1[3] = fraction4;

	for (int i = 0; i < number; i++) {
		cout << array1[i] << endl;
	}

	//Записываем первый массив с объектами-дробями в файл Fraction 
	ofstream osFract("Fraction.txt", ios::binary);
	osFract.write((char*)array1, number * sizeof(Fraction));
	osFract.close();
	for (int i = 0; i < number; i++) {
		array1[i] = 0;
	}
	//Определяем розмер файла в байтах
	ifstream isFract("Fraction.txt", ios::binary | ios::ate);
	int fileSize = isFract.tellg();

	//Определяем количество объектов в файле
	int numObj = fileSize / sizeof(Fraction);

	//Перемещаем указатель на предпоследний объект
	isFract.seekg((numObj - 2) * sizeof(Fraction), ios::beg);

	//Считываем предпоследний объект в новый объект fraction4
	Fraction fraction5;
	isFract.read((char*)&fraction5, sizeof(Fraction));

	//Выводим на екран новый объект в который считали предпоследний объект
	cout << fraction5 << endl;
	
}

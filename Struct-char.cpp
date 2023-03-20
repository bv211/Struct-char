#include <iostream>
#include <Windows.h>

using namespace std;

struct Student
{
	char name[50]{};
	char group[50]{};
	int age{};
};

Student create_student();

void fill_students(Student* students, int size);

void print_students(Student* students, int size);

void print_student(const Student& student);

bool is_exist(const char* originalString, const char* findStr);

void find_students(Student* students, int size);

int main()
{
	setlocale(0, "");
	SetConsoleCP(1251);

#pragma region Пример реализации

	cout << "Область примера" << endl;
	cout << "--------------------------------------" << endl << endl;
	int number = 10; // целочисленное значение
	int* number_pointer = &number; // указатель на number

	cout << number << endl;
	cout << *number_pointer << endl;

	Student student{ "Name", "Group221", 30 }; // структура с тремя полями
	Student* student_pointer = &student; // указатель на структуру
	//auto student_pointer = &student; // или можно так

	cout << student.name << endl; // доступ напрямую
	cout << student_pointer->name << endl; // доступ через указатель
	cout << "\n--------------------------------------" << endl;

#pragma endregion

	int size{};

	cout << "Введите кол-во студентов:" << endl;
	cin >> size;
	cin.ignore();
	system("cls");

	auto students = new Student[size];
	fill_students(students, size);
	print_students(students, size);
	find_students(students, size);

	return 0;
}

Student create_student()
{
	const int buffer_size = 50;
	char name_buffer[buffer_size]{};
	char group_buffer[buffer_size]{};
	int age;

	cout << "Введите имя:" << endl;
	gets_s(name_buffer, buffer_size);

	cout << "Введите группу:" << endl;
	gets_s(group_buffer, buffer_size);

	cout << "Введите возраст:" << endl;
	cin >> age;
	cin.ignore();

	Student student{};
	strcpy_s(student.name, name_buffer);
	strcpy_s(student.group, group_buffer);
	student.age = age;

	return student;
}

void fill_students(Student* students, int size)
{
	for (int i = 0; i < size; i++)
		students[i] = create_student();
}

void print_students(Student* students, int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << i + 1 << ':' << endl;
		print_student(students[i]);
		cout << endl;
	}
}

void print_student(const Student& student)
{
	cout << "Имя: " << student.name << endl;
	cout << "Группа: " << student.group << endl;
	cout << "Возраст: " << student.age << endl;
}

bool is_exist(const char* originalString, const char* findStr)
{
	auto length = strlen(findStr);
	auto found = _strnicmp(originalString, findStr, length); // возращается -1, если нет совпадений, 0 - найдено

	return found == 0; // переводим в булеву
}

void find_students(Student* students, int size)
{
	const int buffer_size = 50;
	char found_name[buffer_size]{};

	cout << "Введите часть имени для поиска:" << endl;
	gets_s(found_name, buffer_size);

	for (int i = 0; i < size; i++)
	{
		Student& student = students[i];

		if (!is_exist(student.name, found_name))
			continue;

		print_student(student);
		cout << endl;
	}
}
#include <stdlib.h> //для очистки экрана
#include <iostream> //для работы с клавиатурой
#include <fstream>
#include <windows.h> 
#include <conio.h> 
#include <string.h>
#include<stdlib.h>
#include <iomanip> 
#include <io.h> //для файлов

using namespace std;

int p(0);

struct baza
{
	int number_of_contract; // номер контракта
	char name_of_product[10]; // имя товара
	char country_of_import[9]; // страна импорта
	char firma_of_import[20]; // фирма импорта
	int ful_volume_of_deposit; // общий объём поставок
	int size_of_product_now; // количество товара поставленного на данный момент

	unsigned int day_state_of_contract;	    //
	unsigned int monf_state_of_contract;	// дата заключения контралта
	unsigned int year_state_of_contract;	//

	unsigned int day_of_the_end_contract;	//
	unsigned int monf_of_the_end_contract;	// дата исполнения контракта в полном объёме
	unsigned int year_of_the_end_contract;	//
} B[1];


void menu()
{
	cout << "\n\tВыбирете действие:\n" << endl;
	cout << "1 - Ввести (Добавить) данные\n" << endl;   // +++++++ //
	cout << "2 - Определение общего объёма товара данного именования, необходимого для выполнения всех контрактов\n" << endl;	// +++++++++++ //
	cout << "3 - Наименования и объём товара, который необходимо допоставить по конкретному контракту, и времени, которое осталось до срока его исполнения\n" << endl;	  // !!!
	cout << "4 - Печать списка наименования товаров, поставляемых в указанную страну\n" << endl; // +++++++++ //
	cout << "5 - Корректеровка информации\n\n";	  // +++++++++ //
	cout << "6 - Просмотр базы данных\n\n";		// ++++++++++ //
	cout << "7 - Выход\n\n" << endl;	// ++++++++ //
	cin >> p;
	system("cls");
}


kontract()
{
	cout << "Ввкдите номер договора: ";
	unsigned int r(0);
	cin >> r;
	
	FILE *d;
	if ((d = fopen("file.txt", "rb+")) == 0)
	{
		cout << "Ошибка при чтении БД";
		return 0;
	}
	int m = filelength(fileno(d)) / sizeof(baza); // количество записей в БД 
	baza *n = new baza[m];
	fread(n, sizeof(B[0]), m, d);
	
	for (int k(0); k<m; k++)
	{
		if (r == n[k].number_of_contract)
		{
			system("cls");
			cout << "Наименование товара: " << n[k].name_of_product << endl;
			cout << "\nОбъём продукта, который необходимо допоставить: " << (n[k].ful_volume_of_deposit - n[k].size_of_product_now) << endl;
		}
	}
	fclose (d);
	
		cout << "\n\n\n\n\n\n\n\tДля выходв в меню нажмите любую клавишу";
	system("pause");
	system("cls");
	
}


ful_volume()
{
	cout << "Введите наименование товарв для вычесления объёма: " << endl;
	char boof[10];
	for (int k(0); k<11; k++)
	{ boof[k] = 0; }
	fflush(stdin);
	gets(boof);
	unsigned int unswer(0);
	
	FILE *d;
	if ((d = fopen("file.txt", "rb+")) == 0)
	{
		cout << "Ошибка при чтении БД";
		return 0;
	}
	int m = filelength(fileno(d)) / sizeof(baza); // количество записей в БД 
	baza *n = new baza[m];
	fread(n, sizeof(B[0]), m, d);
	
	for (int k(0); k<m; k++)
	{
		if (strcmp(boof,n[k].name_of_product) == 0)
		{
			unswer += (n[k].ful_volume_of_deposit - n[k].size_of_product_now);
		}
	}
	fclose(d);
	system("cls");
	cout << "\n\n\tДля выполнения всех контрактов в общей сложности необходимо поставить: " << unswer << " " << boof; 
	
	cout << "\n\n\n\n\n\n\n\tДля выходв в меню нажмите любую клавишу";
	system("pause");
	system("cls");
	
}


correct()
{
	cout << "Введите номер договора для корректировки: " << endl;
	int r(0);
	cin >> r;
	
	FILE *d;
	if ((d = fopen("file.txt", "rb+")) == 0)
	{
		cout << "Ошибка при чтении БД";
		return 0;
	}
	int m = filelength(fileno(d)) / sizeof(baza); // количество записей в БД 
	baza *n = new baza[m];
	fread(n, sizeof(B[0]), m, d);
	
			for (int k(0); k<m; k++)
			{ if (r == n[k].number_of_contract)
				{
					cout << "\tВыбирете что вы хотите изменить: " << endl;
					cout << "1- Номер контракта\n" ;
					cout << "2- Наименование товара\n" ;
					cout << "3- Страна импорта\n" ;
					cout << "4- Фирма импорта\n" ;
					cout << "5- Общий объём поставок\n" ;
					cout << "6- Количество товара поставленного на данный момент\n" ;
					cout << "7- Дата заключения контракта\n" ;
					cout << "8- Дата исполнения контракта в полном объёме\n" ;
					cout << "9- Отменить\n" ;
					unsigned int a(0);
					cin >> a;
					
					if (a == 1)
					{
						cout << "\n\n Введите новый номер контракта: " << endl;
						fflush(stdin);
						cin >> n[k].number_of_contract;
					}
					
					if (a == 2)
					{
						cout << "\n\n Введите новое наименование товара: " << endl;
						fflush(stdin);
						gets(n[k].name_of_product);
					}
					
					if (a == 3) 
					{
						cout << "\n\n Введите новую страгу импорта: " << endl;
						fflush(stdin);
						gets(n[k].country_of_import);
					}
					
					if (a == 4)
					{
						cout << "\n\n Введите новую фирму импорта: " << endl;
						fflush(stdin);
						gets(n[k].firma_of_import);
					}
					
					if (a == 5)
					{
						cout << "\n\n Введите новый объём поставок: " << endl;	
						fflush(stdin);
						cin >> n[k].ful_volume_of_deposit;
					}
					
					if (a == 6)
					{
						cout << "\n\n Введите новое количество товара поставленного на данный момент: " << endl;
						fflush(stdin);
						cin >> n[k].size_of_product_now;
					}
					
					if (a == 7)
					{
						cout << "\n\n Введите новый день заключения контракта: " << endl;
						fflush(stdin);
						cin >> n[k].day_state_of_contract;
						cout << "\n\n Введите новый месяц заключения контракта: " << endl;
						fflush(stdin);
						cin >> n[k].monf_state_of_contract;
						cout << "\n\n Введите новый год заключения контракта: " << endl;
						fflush(stdin);
						cin >> n[k].year_state_of_contract;
					}
					
					if (a == 8)
					{
						cout << "\n\n Введите новый день исполнения контракта в полном объёме: " << endl;
						fflush(stdin);
						cin >> n[k].day_of_the_end_contract;
						cout << "\n\n Введите новый месяц исполнения контракта в полном объёме: " << endl;
						fflush(stdin);
						cin >> n[k].monf_of_the_end_contract;
						cout << "\n\n Введите новый год исполнения контракта в полном объёме: " << endl;
						fflush(stdin);
						cin >> n[k].year_of_the_end_contract;
					}
					
					fclose(d);
					FILE *d;
					if ((d = fopen("file.txt", "w")) == 0)
						{
							cout << "Ошибка при чтении БД";
							return 0;
						}
						fwrite(n, sizeof(B[0]), m, d);	
				}
				fclose(d);
			}
	
	
		cout << "\n\n\n\n\n\n\n\tДля выходв в меню нажмите любую клавишу";
	system("pause");
	system("cls");
	
}


int spisok()
{
	cout << "Введите наименование страны, для просмотра списка товаров" << endl;
	char boof[9];
	for (int k(0); k<10; k++)
	{ boof[k]=0; }
	fflush(stdin);
	gets (boof);
	
	FILE *d;
	if ((d = fopen("file.txt", "rb+")) == 0)
	{
		cout << "Ошибка при чтении БД";
		return 0;
	}
	int m = filelength(fileno(d)) / sizeof(baza); // количество записей в БД 
	baza *n = new baza[m];
	fread(n, sizeof(B[0]), m, d);
	
	cout << "\tВ эту страну импортируют:\n" << endl;
		for (int k(0); k<m; k++)
		{		if (strcmp(boof,n[k].country_of_import) == 0)
		        { cout << "\n" << n[k].name_of_product << endl; }
	    }
		


	cout << "\n\n\n\n\n\n\n\tДля выходв в меню нажмите любую клавишу";
	system("pause");
	system("cls");
		
}


int entr()	// Ввести (Добавить) данные
{
	FILE *d;
	if ((d = fopen("file.txt", "a")) == 0)
	{
		cout << "Ошибка при чтении БД";
		return 0;
	}
	cout.width(20);
	fflush(stdin);

	fflush(stdin);
	cout << "\nВведите номер контракта" << endl;
	cin >> B[0].number_of_contract;

	fflush(stdin);
	cout << "\nВведите имя товара (услуги)" << endl;
	gets(B[0].name_of_product);

	fflush(stdin);
	cout << "\nВведите Страну импорта" << endl;
	gets(B[0].country_of_import);

	fflush(stdin);
	cout << "\nВведите фирму импорта" << endl;
	gets(B[0].firma_of_import);

	fflush(stdin);
	cout << "\nВведите общий объём поставок" << endl;
	cin >> B[0].ful_volume_of_deposit;

	fflush(stdin);
	cout << "\nВведите день закл.чения контракта" << endl;
	cin >> B[0].day_state_of_contract;

	fflush(stdin);
	cout << "\nВведите месяц заключения контракта" << endl;
	cin >> B[0].monf_state_of_contract;

	fflush(stdin);
	cout << "\nВведите год заключения контракта" << endl;
	cin >> B[0].year_state_of_contract;

	fflush(stdin);
	cout << "\nВведите день исполнения контракта в полном объёме" << endl;
	cin >> B[0].day_of_the_end_contract;

	fflush(stdin);
	cout << "\nВведите месяц исполнения контракта в полном объёме" << endl;
	cin >> B[0].monf_of_the_end_contract;

	fflush(stdin);
	cout << "\nВведите год исполнения контракта в полном объёме" << endl;
	cin >> B[0].year_of_the_end_contract;

	fflush(stdin);
	cout << "\nВведите количество товара, поставленного на данный момент" << endl;
	cin >> B[0].size_of_product_now;

	fflush(stdin);
	_getch();

	fwrite(B, sizeof(B[0]), 1, d);
	fclose(d);

	cout << "\n\n\n\n\n\n\n\tДля выходв в меню нажмите любую клавишу";
	system("pause");
	system("cls");
}


int seebaza()
{
	FILE *d;
	if ((d = fopen("file.txt", "rb+")) == 0)
	{
		cout << "Ошибка при чтении БД";
		return 0;
	}
	int m = filelength(fileno(d)) / sizeof(baza); // количество записей в БД 
	baza *n = new baza[m];
	fread(n, sizeof(B[0]), m, d);
	printf("_______________________________________________________________________________________________________________________________________________________________________________\n");
	printf("| № Контракта |   Имя товара  | Страна импорта | Фирта импорта | Общий объём постаков | Дата заключения контралта | Дата исполнения контракта |  К-во товара на данный момент |\n");
	for (int k(0); k<m; k++) {
		printf("|-------------|---------------|----------------|---------------|----------------------|---------------------------|---------------------------|-------------------------------|\n");
		printf("| %-11d | %-13s | %-14s | %-13s | %-20d | %7-d %7-d %9-d | %7-d %7-d %9-d | %22-d        |\n", n[k].number_of_contract, n[k].name_of_product, n[k].country_of_import, n[k].firma_of_import, n[k].ful_volume_of_deposit, n[k].day_state_of_contract, n[k].monf_state_of_contract, n[k].year_state_of_contract, n[k].day_of_the_end_contract, n[k].monf_of_the_end_contract, n[k].year_of_the_end_contract, n[k].size_of_product_now);
		if (k != m - 1)
			printf("|-------------|---------------|----------------|---------------|----------------------|---------------------------|---------------------------|-------------------------------|\n");
	}
	printf("|_____________|_______________|________________|_______________|______________________|___________________________|___________________________|_______________________________|\n");
	fclose(d);

	cout << "\n\n\n\n\n\n\n\tДля выходв в меню нажмите любую клавишу";
	system("pause");
	system("cls");

}


int main()
{
	setlocale(LC_ALL, "Russian");
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	
	do
	{
		menu();

		if (p == 1) { entr(); p = 0; }
		if (p == 2) { ful_volume(); p = 0; }
		if (p == 3) { kontract(); p = 0; }
		if (p == 4) { spisok(); p = 0; }
		if (p == 5) { correct(); p = 0; }
		if (p == 6) { seebaza(); p = 0; }
		if (p == 7) { return 0; p = 0; }

	} while (p = 7);
	return 0;
}


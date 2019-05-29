#include <stdlib.h> //��� ������� ������
#include <iostream> //��� ������ � �����������
#include <fstream>
#include <windows.h> 
#include <conio.h> 
#include <string.h>
#include<stdlib.h>
#include <iomanip> 
#include <io.h> //��� ������

using namespace std;

int p(0);

struct baza
{
	int number_of_contract; // ����� ���������
	char name_of_product[10]; // ��� ������
	char country_of_import[9]; // ������ �������
	char firma_of_import[20]; // ����� �������
	int ful_volume_of_deposit; // ����� ����� ��������
	int size_of_product_now; // ���������� ������ ������������� �� ������ ������

	unsigned int day_state_of_contract;	    //
	unsigned int monf_state_of_contract;	// ���� ���������� ���������
	unsigned int year_state_of_contract;	//

	unsigned int day_of_the_end_contract;	//
	unsigned int monf_of_the_end_contract;	// ���� ���������� ��������� � ������ ������
	unsigned int year_of_the_end_contract;	//
} B[1];


void menu()
{
	cout << "\n\t�������� ��������:\n" << endl;
	cout << "1 - ������ (��������) ������\n" << endl;   // +++++++ //
	cout << "2 - ����������� ������ ������ ������ ������� ����������, ������������ ��� ���������� ���� ����������\n" << endl;	// +++++++++++ //
	cout << "3 - ������������ � ����� ������, ������� ���������� ����������� �� ����������� ���������, � �������, ������� �������� �� ����� ��� ����������\n" << endl;	  // !!!
	cout << "4 - ������ ������ ������������ �������, ������������ � ��������� ������\n" << endl; // +++++++++ //
	cout << "5 - ������������� ����������\n\n";	  // +++++++++ //
	cout << "6 - �������� ���� ������\n\n";		// ++++++++++ //
	cout << "7 - �����\n\n" << endl;	// ++++++++ //
	cin >> p;
	system("cls");
}


kontract()
{
	cout << "������� ����� ��������: ";
	unsigned int r(0);
	cin >> r;
	
	FILE *d;
	if ((d = fopen("file.txt", "rb+")) == 0)
	{
		cout << "������ ��� ������ ��";
		return 0;
	}
	int m = filelength(fileno(d)) / sizeof(baza); // ���������� ������� � �� 
	baza *n = new baza[m];
	fread(n, sizeof(B[0]), m, d);
	
	for (int k(0); k<m; k++)
	{
		if (r == n[k].number_of_contract)
		{
			system("cls");
			cout << "������������ ������: " << n[k].name_of_product << endl;
			cout << "\n����� ��������, ������� ���������� �����������: " << (n[k].ful_volume_of_deposit - n[k].size_of_product_now) << endl;
		}
	}
	fclose (d);
	
		cout << "\n\n\n\n\n\n\n\t��� ������ � ���� ������� ����� �������";
	system("pause");
	system("cls");
	
}


ful_volume()
{
	cout << "������� ������������ ������ ��� ���������� ������: " << endl;
	char boof[10];
	for (int k(0); k<11; k++)
	{ boof[k] = 0; }
	fflush(stdin);
	gets(boof);
	unsigned int unswer(0);
	
	FILE *d;
	if ((d = fopen("file.txt", "rb+")) == 0)
	{
		cout << "������ ��� ������ ��";
		return 0;
	}
	int m = filelength(fileno(d)) / sizeof(baza); // ���������� ������� � �� 
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
	cout << "\n\n\t��� ���������� ���� ���������� � ����� ��������� ���������� ���������: " << unswer << " " << boof; 
	
	cout << "\n\n\n\n\n\n\n\t��� ������ � ���� ������� ����� �������";
	system("pause");
	system("cls");
	
}


correct()
{
	cout << "������� ����� �������� ��� �������������: " << endl;
	int r(0);
	cin >> r;
	
	FILE *d;
	if ((d = fopen("file.txt", "rb+")) == 0)
	{
		cout << "������ ��� ������ ��";
		return 0;
	}
	int m = filelength(fileno(d)) / sizeof(baza); // ���������� ������� � �� 
	baza *n = new baza[m];
	fread(n, sizeof(B[0]), m, d);
	
			for (int k(0); k<m; k++)
			{ if (r == n[k].number_of_contract)
				{
					cout << "\t�������� ��� �� ������ ��������: " << endl;
					cout << "1- ����� ���������\n" ;
					cout << "2- ������������ ������\n" ;
					cout << "3- ������ �������\n" ;
					cout << "4- ����� �������\n" ;
					cout << "5- ����� ����� ��������\n" ;
					cout << "6- ���������� ������ ������������� �� ������ ������\n" ;
					cout << "7- ���� ���������� ���������\n" ;
					cout << "8- ���� ���������� ��������� � ������ ������\n" ;
					cout << "9- ��������\n" ;
					unsigned int a(0);
					cin >> a;
					
					if (a == 1)
					{
						cout << "\n\n ������� ����� ����� ���������: " << endl;
						fflush(stdin);
						cin >> n[k].number_of_contract;
					}
					
					if (a == 2)
					{
						cout << "\n\n ������� ����� ������������ ������: " << endl;
						fflush(stdin);
						gets(n[k].name_of_product);
					}
					
					if (a == 3) 
					{
						cout << "\n\n ������� ����� ������ �������: " << endl;
						fflush(stdin);
						gets(n[k].country_of_import);
					}
					
					if (a == 4)
					{
						cout << "\n\n ������� ����� ����� �������: " << endl;
						fflush(stdin);
						gets(n[k].firma_of_import);
					}
					
					if (a == 5)
					{
						cout << "\n\n ������� ����� ����� ��������: " << endl;	
						fflush(stdin);
						cin >> n[k].ful_volume_of_deposit;
					}
					
					if (a == 6)
					{
						cout << "\n\n ������� ����� ���������� ������ ������������� �� ������ ������: " << endl;
						fflush(stdin);
						cin >> n[k].size_of_product_now;
					}
					
					if (a == 7)
					{
						cout << "\n\n ������� ����� ���� ���������� ���������: " << endl;
						fflush(stdin);
						cin >> n[k].day_state_of_contract;
						cout << "\n\n ������� ����� ����� ���������� ���������: " << endl;
						fflush(stdin);
						cin >> n[k].monf_state_of_contract;
						cout << "\n\n ������� ����� ��� ���������� ���������: " << endl;
						fflush(stdin);
						cin >> n[k].year_state_of_contract;
					}
					
					if (a == 8)
					{
						cout << "\n\n ������� ����� ���� ���������� ��������� � ������ ������: " << endl;
						fflush(stdin);
						cin >> n[k].day_of_the_end_contract;
						cout << "\n\n ������� ����� ����� ���������� ��������� � ������ ������: " << endl;
						fflush(stdin);
						cin >> n[k].monf_of_the_end_contract;
						cout << "\n\n ������� ����� ��� ���������� ��������� � ������ ������: " << endl;
						fflush(stdin);
						cin >> n[k].year_of_the_end_contract;
					}
					
					fclose(d);
					FILE *d;
					if ((d = fopen("file.txt", "w")) == 0)
						{
							cout << "������ ��� ������ ��";
							return 0;
						}
						fwrite(n, sizeof(B[0]), m, d);	
				}
				fclose(d);
			}
	
	
		cout << "\n\n\n\n\n\n\n\t��� ������ � ���� ������� ����� �������";
	system("pause");
	system("cls");
	
}


int spisok()
{
	cout << "������� ������������ ������, ��� ��������� ������ �������" << endl;
	char boof[9];
	for (int k(0); k<10; k++)
	{ boof[k]=0; }
	fflush(stdin);
	gets (boof);
	
	FILE *d;
	if ((d = fopen("file.txt", "rb+")) == 0)
	{
		cout << "������ ��� ������ ��";
		return 0;
	}
	int m = filelength(fileno(d)) / sizeof(baza); // ���������� ������� � �� 
	baza *n = new baza[m];
	fread(n, sizeof(B[0]), m, d);
	
	cout << "\t� ��� ������ �����������:\n" << endl;
		for (int k(0); k<m; k++)
		{		if (strcmp(boof,n[k].country_of_import) == 0)
		        { cout << "\n" << n[k].name_of_product << endl; }
	    }
		


	cout << "\n\n\n\n\n\n\n\t��� ������ � ���� ������� ����� �������";
	system("pause");
	system("cls");
		
}


int entr()	// ������ (��������) ������
{
	FILE *d;
	if ((d = fopen("file.txt", "a")) == 0)
	{
		cout << "������ ��� ������ ��";
		return 0;
	}
	cout.width(20);
	fflush(stdin);

	fflush(stdin);
	cout << "\n������� ����� ���������" << endl;
	cin >> B[0].number_of_contract;

	fflush(stdin);
	cout << "\n������� ��� ������ (������)" << endl;
	gets(B[0].name_of_product);

	fflush(stdin);
	cout << "\n������� ������ �������" << endl;
	gets(B[0].country_of_import);

	fflush(stdin);
	cout << "\n������� ����� �������" << endl;
	gets(B[0].firma_of_import);

	fflush(stdin);
	cout << "\n������� ����� ����� ��������" << endl;
	cin >> B[0].ful_volume_of_deposit;

	fflush(stdin);
	cout << "\n������� ���� ����.����� ���������" << endl;
	cin >> B[0].day_state_of_contract;

	fflush(stdin);
	cout << "\n������� ����� ���������� ���������" << endl;
	cin >> B[0].monf_state_of_contract;

	fflush(stdin);
	cout << "\n������� ��� ���������� ���������" << endl;
	cin >> B[0].year_state_of_contract;

	fflush(stdin);
	cout << "\n������� ���� ���������� ��������� � ������ ������" << endl;
	cin >> B[0].day_of_the_end_contract;

	fflush(stdin);
	cout << "\n������� ����� ���������� ��������� � ������ ������" << endl;
	cin >> B[0].monf_of_the_end_contract;

	fflush(stdin);
	cout << "\n������� ��� ���������� ��������� � ������ ������" << endl;
	cin >> B[0].year_of_the_end_contract;

	fflush(stdin);
	cout << "\n������� ���������� ������, ������������� �� ������ ������" << endl;
	cin >> B[0].size_of_product_now;

	fflush(stdin);
	_getch();

	fwrite(B, sizeof(B[0]), 1, d);
	fclose(d);

	cout << "\n\n\n\n\n\n\n\t��� ������ � ���� ������� ����� �������";
	system("pause");
	system("cls");
}


int seebaza()
{
	FILE *d;
	if ((d = fopen("file.txt", "rb+")) == 0)
	{
		cout << "������ ��� ������ ��";
		return 0;
	}
	int m = filelength(fileno(d)) / sizeof(baza); // ���������� ������� � �� 
	baza *n = new baza[m];
	fread(n, sizeof(B[0]), m, d);
	printf("_______________________________________________________________________________________________________________________________________________________________________________\n");
	printf("| � ��������� |   ��� ������  | ������ ������� | ����� ������� | ����� ����� �������� | ���� ���������� ��������� | ���� ���������� ��������� |  �-�� ������ �� ������ ������ |\n");
	for (int k(0); k<m; k++) {
		printf("|-------------|---------------|----------------|---------------|----------------------|---------------------------|---------------------------|-------------------------------|\n");
		printf("| %-11d | %-13s | %-14s | %-13s | %-20d | %7-d %7-d %9-d | %7-d %7-d %9-d | %22-d        |\n", n[k].number_of_contract, n[k].name_of_product, n[k].country_of_import, n[k].firma_of_import, n[k].ful_volume_of_deposit, n[k].day_state_of_contract, n[k].monf_state_of_contract, n[k].year_state_of_contract, n[k].day_of_the_end_contract, n[k].monf_of_the_end_contract, n[k].year_of_the_end_contract, n[k].size_of_product_now);
		if (k != m - 1)
			printf("|-------------|---------------|----------------|---------------|----------------------|---------------------------|---------------------------|-------------------------------|\n");
	}
	printf("|_____________|_______________|________________|_______________|______________________|___________________________|___________________________|_______________________________|\n");
	fclose(d);

	cout << "\n\n\n\n\n\n\n\t��� ������ � ���� ������� ����� �������";
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


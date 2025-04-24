#include <iostream>
#include <cstring>
#include <string>
#include <fstream>
#include <istream>
#include <cstdlib>
fstream fp;
const string fname = "imoti.dat";
using namespace std;
const int N = 100;
struct imot
{
	char num[7];
	string name;
	string type;
	string region;
	string izgled;
	double cena;
	double plosht;
	int brStai;
	int etaj;
	string status;
};
void add_imot1(imot arr[]);
void add_imot2(imot arr[]);
void print_arr(imot arr[]);
void po_plosht(imot arr[], imot arr2[]);
void prodadeni(imot arr[], imot arr2[]);
void vuzhodqshta_cena(imot arr[]);
int zapisvane();
int chetene(imot arr[], int& size);
int main()
{
	imot imoti[N];
	imot b[N];
	imot c[N];
	int size = sizeof(imoti);
	int choice;
	do
	{
		cout << "1.Dobavete nov imot" << endl
			<< "2.Izvejdane na ekrana na vsichki imoti" << endl
			<< "3.Tursete imoti" << endl
			<< "4.Podrejdane na osnovniq masiv" << endl
			<< "5.Upravlenie na failove" << endl
			<< "6.Izlizane ot programata" << endl
			<< "Napravi svoq izbor: ";
		do
		{
			cin >> choice;
		} while ((choice < 1) || (choice > 6));
		switch (choice)
		{
		case 1:cout << endl << "1.1 Dobavqne na edin nov imot" << endl
			<< "1.2 Dobavqne na broi imoti izbran ot vas" << endl
			<< "1.3 Vrushtane nazad" << endl
			<< "Vuvedete svoq izbor 1/2: ";
			do
			{
				cin >> choice;
			} while ((choice < 1) || (choice > 3));
			switch (choice)
			{
			case 1: add_imot1(imoti); break;
			case 2: add_imot2(imoti); break;
			case 3: exit(0);
			default: cout << endl << "Opitaite otnovo!"; break;
			}
		case 2: print_arr(imoti); break;
		case 3: cout << endl << "3.1 Izvejdane na imoti s nai-golqma plosht" << endl
			<< "3.2 Izvejdane na ekrana na prodadenite imoti" << endl
			<< "3.3 Izlezte ot tova menu" << endl
			<< "Vuvedete svoq izbor: ";
			do
			{
				cin >> choice;
			} while ((choice < 1) || (choice > 3));
			switch (choice)
			{
			case 1:po_plosht(imoti, b); break;
			case 2:prodadeni(imoti, c); break;
			case 3:exit(0);
			default: cout << endl << "Opitaite otnovo!"; break;
			}
		case 4:vuzhodqshta_cena(imoti);
		case 5:cout << endl << "5.1 Izvejdane na masiva s imoti ot fail"
			<< endl << "5.2 Vuvejdane na masiva s imoti ot fail"
			<< endl << "5.3 Izlez ot menu" << endl
			<< "Vuvedi svoq izbor: ";
			do
			{
				cin >> choice;
			} while ((choice < 1) || (choice > 3));
			switch (choice)
			{
			case 1: zapisvane(); break;
			case 2: chetene(imoti, size); break;
			case 3: exit(0);
			}
		case 6:exit(1);
		default: cout << endl << "Opitaite otnovo!"; break;
		}
	} while (choice != 6);
}
//Funkciq za vuvejdane na edin elemnt v masiva
void add_imot1(imot arr[])
{
	int size = sizeof(arr);
	imot cur;
	cout << endl << "Vuvedete nomer na imota: ";
	cin >> cur.num;

	cout << endl << "Vuvedete ime na brokera: ";
	getline(cin, cur.name);

	cout << endl << "Vuvedete ot kakuv tip e imota: ";
	getline(cin, cur.type);

	cout << endl << "Vuv kakuv raion e imota: ";
	getline(cin, cur.region);

	cout << endl << "Kakvo e izlojenieto na imota: ";
	getline(cin, cur.izgled);

	cout << endl << "Cena na imota: ";
	cin >> cur.cena;

	cout << endl << "Plosht na imota v kv/m: ";
	cin >> cur.plosht;

	cout << endl << "Broi stai: ";
	cin >> cur.brStai;

	cout << endl << "Broi etaji: ";
	cin >> cur.etaj;

	cout << endl << "Prodaden/Svoboden/Kapariran: ";
	getline(cin, cur.status);

	arr[size] = cur;
}
void add_imot2(imot arr[])
{
	int n;
	cout << endl << "Kolko imota iskate da vuvedete: ";
	cin >> n;
	if ((n > 100) || (n < 0))
	{
		cout << endl << "Greshno vuveden broi imoti!!!";
	}
	else
	{
		for (size_t i = 0; i < n; i++)
		{

			cout << endl << "Vuvedete nomer na imota: ";
			cin >> arr[i].num;
			cout << endl << "Vuvedete ime na brokera: ";
			getline(cin, arr[i].name);
			cout << endl << "Vuvedete ot kakuv tip e imota: ";
			getline(cin, arr[i].type);
			cout << endl << "Vuv kakuv raion e imota: ";
			getline(cin, arr[i].region);
			cout << endl << "Kakvo e izlojenieto na imota: ";
			getline(cin, arr[i].izgled);
			cout << endl << "Cena na imota: ";
			cin >> arr[i].cena;
			cout << endl << "Plosht na imota v kv/m: ";
			cin >> arr[i].plosht;
			cout << endl << "Broi stai: ";
			cin >> arr[i].brStai;
			cout << endl << "Broi etaji: ";
			cin >> arr[i].etaj;
			cout << endl << "Prodaden/Svoboden/Kapariran: ";
			getline(cin, arr[i].status);

		}
	}
}
//Funkciq za printirane na masiva.
void print_arr(imot arr[])
{
	int size = sizeof(arr[N]);
	for (size_t i = 0; i < size; i++)
	{
		cout << endl << "Num: " << arr[i].num;
		cout << endl << "Broker: " << arr[i].name;
		cout << endl << "Tip: " << arr[i].type;
		cout << endl << "Raion: " << arr[i].region;
		cout << endl << "Izlojenie: " << arr[i].izgled;
		cout << endl << "Cena: " << arr[i].cena;
		cout << endl << "Plosht kv/m: " << arr[i].plosht;
		cout << endl << "Broi stai: " << arr[i].brStai;
		cout << endl << "Etaji: " << arr[i].etaj;
		cout << endl << "Prodaden/Svoboden/Kapariran: " << arr[i].status;
		cout << endl << "_______________________________________________";
	}
}
//Funkciq za zapisvane na imotite s nai-golqma plosh v nov masiv.
void po_plosht(imot arr[], imot arr2[])
{
	int br = 0;
	for (size_t i = 0; i < N; i++)
	{
		if (arr[i].plosht >= 75)
		{
			arr2[br] = arr[i];
			br++;
		}
	}
	print_arr(arr2);
}
//Funkciq za zapisvane na prodadenite imoti v nov masiv.
void prodadeni(imot arr[], imot arr2[])
{
	int br1 = 0;
	for (size_t i = 0; i < N; i++)
	{
		if (arr[i].status == "prodaden")
		{
			arr2[br1] = arr[i];
			br1++;
		}
	}
	print_arr(arr2);
}
//Funckiq za sortirane na masiva po vuzhodqsht red na cenata. Bez izvejdane na ekrana.
void vuzhodqshta_cena(imot arr[])
{
	int size = sizeof(arr[N]);
	int temp, i, j;
	for (size_t i = 0; i < size; i++)
	{
		for (size_t j = 0; j < size - 1; j++)
		{
			if (arr[j].cena > arr[i].cena)
			{
				temp = arr[i].cena;
				arr[i].cena = arr[j].cena;
				arr[j].cena = temp;
			}
		}
	}
}
//funciq za zapisvane na masiva vuv fail.
int zapisvane()
{
	imot temp;
	fp.open(fname, ios::binary);
	if (fp.fail())
	{
		cout << endl << "Nqma takuv fail"; exit(1);
	}
	for (size_t i = 0; i < N; i++)
	{
		cout << endl << "Vuvedete nomer na imota: ";
		cin >> temp.num;
		cout << endl << "Vuvedete ime na brokera: ";
		getline(cin, temp.name);
		cout << endl << "Vuvedete ot kakuv tip e imota: ";
		getline(cin, temp.type);
		cout << endl << "Vuv kakuv raion e imota: ";
		getline(cin, temp.region);
		cout << endl << "Kakvo e izlojenieto na imota: ";
		getline(cin, temp.izgled);
		cout << endl << "Cena na imota: ";
		cin >> temp.cena;
		cout << endl << "Plosht na imota v kv/m: ";
		cin >> temp.plosht;
		cout << endl << "Broi stai: ";
		cin >> temp.brStai;
		cout << endl << "Broi etaji: ";
		cin >> temp.etaj;
		cout << endl << "Prodaden/Svoboden/Kapariran: ";
		getline(cin, temp.status);
		fp.write((char*)&temp, sizeof(imot));
	}
	fp.close();
}
int chetene(imot arr[], int& size)
{
	fp.open(fname, ios::binary);
	if (fp.fail())
	{
		cout << endl << "Nqma takuv fail."; exit(1);
	}
	fp.seekg(ios::end);
	size = fp.tellg() / sizeof(imot);
	fp.seekg(0L, ios::beg);
	fp.read((char*)arr,size* sizeof(imot));
	fp.close();
}

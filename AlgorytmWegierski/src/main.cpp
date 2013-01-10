/*
 * main.cpp
 *
 *  Created on: 11-12-2012
 *      Author: Administrator
 */

//basic file operations
#include <iostream>
#include <fstream>
#include <boost/numeric/ublas/matrix.hpp>
#include <boost/numeric/ublas/io.hpp>

//using namespace std;

int main() {
/*	ofstream myfile;
	myfile.open("example.txt", ios::out | ios::app);
	if(myfile.is_open()==true) {
		cout << "Plik example.txt otwarty poprawnie\n";
		cout << myfile.tellp() << "\n";
		myfile << "Writing this to a file.\n";
		cout << myfile.tellp() << "\n";
		myfile << "A to jest kolejna linijka\n";
		cout << myfile.tellp() << "\n";
		myfile.close();
	}
	else cout << "Nie uda³o siê otworzyc pliku\n";*/

/*	string linia;
	ifstream myfile("example.txt", ios::in);
	if(myfile.is_open()) {
		while(myfile.good()) {
			cout << "telg(): " << myfile.tellg() << "\t";
			getline(myfile,linia);
			cout << linia << endl;
		}
		myfile.close();
	}
	else cout << "Nie uda³o siê otworzyc pliku\n";*/

/*	long poczatek, koniec;
	ifstream myfile("example.txt");
	poczatek = myfile.tellg();
	myfile.seekg(0,ios::end);
	koniec = myfile.tellg();
	myfile.close();
	cout << "Rozmiar pliku wynosi: " <<
			(koniec-poczatek) <<
			"bajtów.\n";*/

/*	ifstream::pos_type size;
	char * memblock;

	ifstream file("example.bin", ios::in|ios::binary|ios::ate);
	if(file.is_open()) {
		size = file.tellg();
		memblock = new char [size];
		file.seekg(0,ios::beg);
		file.read(memblock, size);
		file.close();

		cout << "ca³y plik jest wczytany do pamiêci\n";

		ofstream myfile("example_kopia.bin", ios::out|ios::binary);
		if(myfile.is_open()){
			myfile.write(memblock, size);
			myfile.close();
			cout << "Plik zosta³ skopiowany\n";
		}
		else cout << "Nie uda³o siê zapisac kopi pliku\n";

		delete[] memblock;
	}
	else cout << "Nie uda³o siê otworzyc pliku\n";*/


	std::cout << "Metoda Wegierska\n\n";
	std::cout << "Menu:\n";
	std::cout << "c - Wczytaj macierz z konsoli\n";
	std::cout << "p - Wczytaj macierz z pliku\n";
	std::cout << "l - Wygeneruj macierz losowo\n";

	boost::numeric::ublas::matrix<double> macierz;

	char c;
	std::cin.get(c);
	switch (c) {
		case 'c':
			std::cout << ">> z konsoli\n";
			std::cout << "Podaja macierz jak w przykladowym formacie:\n";
			std::cout << "[3,3]((1,2,3),(4,5,6),(7,8,9))\n";

			std::cin >> macierz;
			break;

		case 'p':
			std::cout << ">> z pliku\n";
			std::cout << "Przykotuj plik o nazwie dane.txt\n";
			std::cout << "z danymi w postaci: [3,3]((1,2,3),(4,5,6),(7,8,9))";
			break;
		case 'l':
			std::cout << ">> losowo\n";
			break;
		default:
			std::cout << "wybierz c, p lub l\n";
			break;
	}


	boost::numeric::ublas::matrix<double> M;
	std::ifstream plik("dane.txt", std::ios::in);

	if(plik.is_open()) {
		if(plik >> M) {
			std::cout << "Wypisuje macierz: ";
			std::cout << M;
		}
		else {
			std::cout << "Nie udal sie zapis do macierzy\n";
			return 1;
		}

	}
	else {
		std::cout << "Nie udalo sie otworzyc pliku\n";
		return 1;
	}

	return 0;
}




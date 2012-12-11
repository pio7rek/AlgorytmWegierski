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

using namespace std;

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

	boost::numeric::ublas::matrix<double> M;
	ifstream plik("dane.txt", ios::in);

	if(plik.is_open()) {
		if(plik >> M) {
			cout << "Wypisuje macierz: ";
			cout << M;
		}
		else {
			cout << "Nie udal sie zapis do macierzy\n";
			return 1;
		}

	}
	else {
		cout << "Nie udalo sie otworzyc pliku\n";
		return 1;
	}

	return 0;
}




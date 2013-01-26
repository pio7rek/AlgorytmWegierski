/*
 * main.cpp
 *
 *  Created on: 11-12-2012
 *      Author: Administrator
 */

//basic file operations
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <time.h>
#include <boost/numeric/ublas/matrix.hpp>
#include <boost/numeric/ublas/io.hpp>

using namespace boost::numeric::ublas;

template <typename T> void wypisz(boost::numeric::ublas::matrix<T>);
template <typename T> void min_wiersz(boost::numeric::ublas::matrix<T> &m, int wiersz);

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
	std::cout << "p - Wczytaj macierz z pliku dane.txt\n";
	std::cout << "l - Wygeneruj macierz losowo\n";
	std::cout << "k - koniec\n";
	std::cout << "\nMacierz podawaj jak w przykladowym formacie:\n";
	std::cout << "[3,3]((1,2,3),(4,5,6),(7,8,9))" << std::endl;

	boost::numeric::ublas::matrix<double> M;
	std::ifstream plik("dane.txt", std::ios::in);

	char c;
	std::cin.get(c);
	switch (c) {
		//macierz z konsoli
		case 'c':
			std::cout << ">> z konsoli\n";
			std::cin >> M;

			std::cout << "Wypisuje macierz: ";
			std::cout << M;
			break;
		//macierz z pliku
		case 'p':
			std::cout << ">> z pliku dame.txt\n";

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

			break;
		//macierz w sposob losowy
		case 'l':{
			std::cout << ">> losowo\n";
			std::cout << "ile losowych macierzy chcesz utworzyc ?\n";
			int ile;
			std::cin >> ile;

			srand((unsigned int) time(NULL));
			//glowna macierz
			boost::numeric::ublas::matrix<double> m2(5,5);
			//maciesz pomocnicza - zakreskowania
			boost::numeric::ublas::matrix<int> tmp(5,5);
			const int NORMALNE = 0;
			const int RAZKRESKA = 1;
			const int DWAKRESKA = 2;

			while(ile-- > 0) {
				//losowanie elementow macierzy
				for (unsigned wiersz = 0; wiersz < m2.size1 (); ++wiersz)
					for (unsigned kolumna = 0; kolumna < m2.size2 (); ++kolumna)
						m2(wiersz, kolumna) = (double)(rand() % 30 + 1);
				std::cout << m2 << std::endl;

				wypisz(m2);
				std::cout <<"---- odejmuje minimum w wierszach\n";
				//odjecie minimalnegoe elementu w wierszach
				for(unsigned int wiersz=0; wiersz<m2.size1(); ++wiersz) {
					int min = m2(wiersz,0);
						for(unsigned int i=0; i<m2.size1(); ++i)
							if(m2(wiersz, i) < min)
								min = m2(wiersz,i);
						for(unsigned int i=0; i<m2.size1(); ++i)
							m2(wiersz,i)-=min;
				}

				wypisz(m2);
				std::cout <<"---- odejmuje minimum w kolumnach\n";

				//odjecie minimalnego elementu w kolumnie
				for(unsigned int kolumna=0; kolumna<m2.size1(); ++kolumna) {
					int min = m2(0,kolumna);
					for(unsigned int i=0; i<m2.size1(); ++i)
						if(m2(i, kolumna) < min)
							min = m2(i, kolumna);
					for(unsigned int i=0; i<m2.size1(); ++i)
						m2(i,kolumna)-=min;
				}

				wypisz(m2);

				//minimalne kreskowanie
			}
		}
			break;
		default:
			std::cout << "wybierz c, p, l lub k\n";
			break;
	}

//	matrix_row<MAT> vr(m, index);
//	matrix_column<MAT> vc(m, index);


//	boost::numeric::ublas::matrix<double> M;




	return 0;
}

template <typename T> void wypisz(boost::numeric::ublas::matrix<T> m) {
	for(unsigned int wiersz=0; wiersz<m.size1(); ++wiersz) {
		for(unsigned int kolumna=0; kolumna<m.size2(); ++kolumna) {
			std::cout.width(2);
			std::cout << m(wiersz,kolumna) << ",";
		}
		std::cout << std::endl;
	}
}

template <typename T> void min_wiersz(boost::numeric::ublas::matrix<T> &m, int wiersz) {
	int min = m(wiersz,0);
	for(unsigned int i=0; i<m.size1(); ++i)
		if(m(wiersz,i)<min)
			min = m(wiersz,i);
	for(unsigned int i=0; i<m.size1(); ++i)
		m(wiersz,i)-=min;
}

#include<stdio.h>
#include<iostream>
#include<string>
#include<fstream>
#include<vector>
#include<istream>
#include <algorithm>

using namespace std;

void  readfromFile(int& n, string fileName, int a[100]) {
	fstream readFile;
	n = 0;
	readFile.open(fileName, ios::in);
	if (!readFile) {
		cerr << "Unable to open file in.txt";
		exit(1);   // call system to stop
	}
	readFile >> n;
	for (int i = 0; i < n; i++) {
		readFile >> a[i];
	}
	readFile.close();
}

void  readfromFileMatrice(int& n, int& m, string fileName, int a[100][100]) {
	fstream readFile;
	n = 0;
	readFile.open(fileName, ios::in);
	if (!readFile) {
		cerr << "Unable to open file in.txt";
		exit(1);   // call system to stop
	}
	readFile >> n >> m;
	for (int i = 0; i < n; i++) 
		for(int j = 0; j < m; j++)
			readFile >> a[i][j];

	readFile.close();
}

int problema5(int n, int a[100]) {
	int viz[100] = { 0 };

	for (int i = 0; i < n; i++) {
		viz[a[i]] ++;
		if (viz[a[i]] == 2)
			return a[i];
	}

}

int problema6(int n, int a[100]) {
	int viz[100] = { 0 };

	for (int i = 0; i < n; i++) {
		viz[a[i]] ++;
		if (viz[a[i]] > n/2)
			return a[i];
	}

}

int problema10(int n,int m, int a[100][100]) {
	int max = 0, jj,poz;
	for (int i = 0; i < n; i++){
		jj = 0;
		for (int j = 0; j < m; j++) 
			if(a[i][j] == 1)
				jj++;

		if (jj > max) {
			max = jj;
			poz = i;
		}
	}
	return poz;
}

double problema2(int x1,  int x2, int y1, int y2)
{
	double x = x1 - x2; 
	double y = y1 - y2;
	double dist;

	dist = pow(x, 2) + pow(y, 2);
	dist = sqrt(dist);

	return dist;
}

void problema8(int n) {
	int nr = 1,lungime = 1;
	int stringNr[100] = { 0 };
	stringNr[0] = 1;
	cout << "Numerele sunt: 1"  << endl;
	while (nr != n) {
		nr++;
		int plus = 1;
		for (int i = 0; i <= lungime; i++) {
			stringNr[i] = stringNr[i] + plus;
			if (stringNr[i] == 2) {
				stringNr[i] = 0;
				plus = 1;
				if (lungime == i + 1)
					lungime++;
			}
			else plus = 0;
		}
		for (int i = lungime-1; i >= 0; i--)
			cout << stringNr[i];
		cout << endl;
	}
}

void problema7(int n,int a[100],int nr) {

	sort(a, a + n);
	cout << "Numarul cautat este  " << a[n - nr] << endl;

}

void problema4(string  a) {
	string cuvinte[100];
	int cuv = 0;
	bool validare = true;
	std::size_t found;
	while (validare) {
		found = a.find(" ");
		if (found > a.length()) {
			cuvinte[cuv] = a.substr(0, a.length());
			a = "";
		}
		else {
			cuvinte[cuv] = a.substr(0, found);
			a = a.substr(found + 1, a.length());
		}
		cuv++;

		if (a.length()==0)
			validare = false;
	}
	sort(cuvinte, cuvinte + cuv);

	cout << "Cuvintele care apar o singura data sunt:" << endl;
	for (int i = 1; i < cuv; i++)
		if (cuvinte[i] == cuvinte[i + 1] || cuvinte[i] == cuvinte[i - 1])
			i = i;
		else
			cout << cuvinte[i] << endl;
}

string problema1(string a) {
	string cuvinte[100];
	int cuv = 0;
	bool validare = true;
	std::size_t found;
	while (validare) {
		found = a.find(" ");
		if (found > a.length()) {
			cuvinte[cuv] = a.substr(0, a.length());
			a = "";
		}
		else {
			cuvinte[cuv] = a.substr(0, found);
			a = a.substr(found + 1, a.length());
		}
		cuv++;

		if (a.length() == 0)
			validare = false;
	}
	sort(cuvinte, cuvinte + cuv);
	return cuvinte[cuv-1];
}

int problema3(int a, int a1[100], int b, int b1[100]) {
	int toReturn = 0;
	for (int i = 0; i < a; i++) {
		toReturn = toReturn + a1[i] * b1[i];
	}
	return toReturn;
}

void interschimb(int& nr1, int& nr2) {
	int aux;
	aux = nr1;
	nr1 = nr2;
	nr2 = aux;
}

int problema9(int n, int m, int matriceM1[100][100],int r1, int r2, int s1, int s2) {
	int sum = 0;

	if (s1 < r1)
		interschimb(s1, r1);
	if (s2 < r2)
		interschimb(s2, r2);

	for (int i = r1-1; i < s1; i++)
		for (int j = r2-1; j < s2; j++)
			sum = sum + matriceM1[i][j];
	return sum;
}

int main(int argc, char* argv[]) {
	int pb5, pb6,pb10, n1, n2, n,m;
	int numere[100] = { 0 }, numere2[100] = { 0 }, numere7[100] = { 0 };
	int matriceM[100][100] = { 0 }, v1[100] = {0}, v2[100] = { 0 }, matriceM1[100][100] = { 0 };
	string vaai = "Ana are mere rosii si galbene";
	string boooooov = "ana are ana are ana  mere rosii si galbene si kk";

	readfromFile(n, "problema5.txt", numere);

	pb5 = problema5(n, numere);
	cout << "numarul " << pb5 << " apare de 2 ori" << endl;

	readfromFile(n, "problema6.txt", numere2);
	pb6 = problema6(n, numere2);
	cout << "numarul " << pb6 << " apare majoritar" << endl;

	readfromFileMatrice(n, m, "problema10.txt", matriceM);
	pb10 = problema10(n,m, matriceM);
	cout << "linia " << pb10 + 1 << " contine cele mai multe cifre de 1" << endl;
	
	cout <<"distanta este: "<< problema2(1, 5, 4, 1) << endl;

	problema8(5);

	readfromFile(n, "problema7.txt", numere7);
	problema7(n,numere7,2);
	
	cout << "Cuvantul cautat este:" << problema1(vaai) << endl;

	problema4(boooooov);
	readfromFile(n1, "problema3V1.txt", v1);
	readfromFile(n2, "problema3V2.txt", v2);
	cout<<"Produslu scalar este:" << problema3(n1, v1, n2, v2)<<endl;

	readfromFileMatrice(n, m, "problema9.txt", matriceM1);
	cout<<"suma este:"<<problema9(n, m, matriceM1, 4,4,2,2)<<endl;

	return 0;
}

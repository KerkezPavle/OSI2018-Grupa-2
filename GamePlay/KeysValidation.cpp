#define _CRT_SECURE_NO_DEPRECATE
#include "KeysValidation.h"
#include <fstream>
#include <string>
#include <time.h>
#define SEDAM 604800
#define SAT 3600
#define DAN 86400
using namespace std;


std::string currentDateTime()
{
	time_t     now = time(0);
	tm  tstruct;
	char       buf[80];
	tstruct = *localtime(&now);
	strftime(buf, sizeof(buf), "%Y %m %d %X", &tstruct);
	return buf;
}

void deaktivirajIgru(int igra)
{
	int i = 0;
	string s;
	string* niz = nullptr;
	niz = new string[4];
	int indeks_niza;
	ifstream datoteka("assets/data/igra.txt");
	if (datoteka.is_open())
	{
		while (getline(datoteka, s))
		{
			niz[i++] = s;
		}
		datoteka.close();
	}
	for (int j = 0; j < i; j++)
	{
		if (niz[j][0] - '0' == igra)niz[j][2] = 50;
	}
	ofstream datoteka2;
	datoteka2.open("assets/data/igra.txt", fstream::out);
	for (int j = 0; j < i; j++)datoteka2 << niz[j] << "\n";
	datoteka2.close();
}



bool provjeraPonavljanjaKoda(string kod)
{
	ifstream datoteka("assets/data/used_codes.txt");
	if (datoteka.is_open())
	{
		string t;
		while (getline(datoteka, t))
		{
			if (t == kod)
				return false;
		}
		datoteka.close();
	}
	return true;
}

bool otkljucaj_igru(std::string datoteka, std::string igra, std::string kod, int broj_igre)
{
	if (broj_igre < 0 || broj_igre>4)return false;
	if (!provjeraPonavljanjaKoda(kod))return false;
	bool radi = true;
	bool pronadjen = false;
	string temp, t;
	ifstream myfile(datoteka);
	ofstream file;
	ifstream provjera(igra);
	if (provjera.is_open())
	{
		string temp1;
		while (getline(provjera, temp1))
		{
			int i = (temp1[0] - '0');
			if ((i - broj_igre) == 0)
			{
				radi = false;
				break;
			}
		}
		provjera.close();
	}
	if (radi)
	{
		if (myfile.is_open())
		{
			while (getline(myfile, temp))
			{
				if (temp == kod)
				{
					pronadjen = true;
					ofstream datoteka;
					datoteka.open

					("assets/data/used_codes.txt", fstream::app);
					datoteka << temp << "\n";
					datoteka.close();
					break;
				}
			}
			if (pronadjen)
			{
				(file.open(igra, fstream::app));
				{
					t = currentDateTime();
					file << broj_igre << " " <<1 << " " << t << "\n";
				}
				file.close();
			}
			else
			{
				return false;
			}
			myfile.close();
		}
		return true;
	}
	return false;
}

bool vratiRazliku(string vrijeme, int razlika)
{
	int godina = (vrijeme[4] - '0') * 1000 + (vrijeme[5] - '0')

		* 100 + (vrijeme[6] - '0') * 10 + vrijeme[7] - '0';
	int mjesec = (vrijeme[9] - '0') * 10 + vrijeme[10] - '0';
	int dan = (vrijeme[12] - '0') * 10 + vrijeme[13] - '0';
	int sat = (vrijeme[15] - '0') * 10 + vrijeme[16] - '0';
	int minut = (vrijeme[18] - '0') * 10 + vrijeme[19] - '0';
	int sekund = (vrijeme[21] - '0') * 10 + vrijeme[22] - '0';
	time_t timer;
	struct tm y2k = { 0 };
	double seconds;
	int godina_razlika = godina - 1900;
	y2k.tm_hour = sat;   y2k.tm_min = minut; y2k.tm_sec =

		sekund;
	y2k.tm_year = godina_razlika; y2k.tm_mon = mjesec - 1;

	y2k.tm_mday = dan;
	time(&timer);
	seconds = difftime(timer, mktime(&y2k));
	if (seconds > razlika)return false;
	else return true;
}

bool isActive(std::string datoteka, int igra)
{
	int pronadjen = 0;
	string pomocni_niz;
	string temp;
	ifstream myfile(datoteka);
	if (myfile.is_open())
	{
		while (getline(myfile, pomocni_niz))
		{
			if ((pomocni_niz[0] - '0') == igra)
			{
				temp = pomocni_niz;
				pronadjen = 1;
			}
		}
		myfile.close();
	}
	if (pronadjen == 0)return false;
	if ((temp[2] - '0') == 2)return false;
	if (igra == 4)
	{
		if ((temp[0] - '0') == 4)return true;
	}
	if (igra == 1)
	{
		if (vratiRazliku(temp, SAT))return true;
	}
	if (igra == 2)
	{

		if (vratiRazliku(temp, DAN))return true;
	}
	if (igra == 3)
	{
		if (vratiRazliku(temp, SEDAM))return true;
	}
	return false;
}

bool isDeactivated(int igra)
{
	ifstream datoteka("assets/data/igra.txt");
	string* niz = nullptr;
	niz = new string[4];
	string s;
	int i = 0;
	if (datoteka.is_open())
	{
		while (getline(datoteka, s))
		{
			niz[i++] = s;
		}
		datoteka.close();
	}
	for (int j = 0; j < i; j++)
	{
		if (i == 0)return false;
		if (niz[j][0] - '0' == igra)
		{
			if (niz[j][2] - '0' == 2)
			{
				datoteka.close();
				delete[]niz;
				 return true;
			}
		}
	}
	datoteka.close();
	delete[]niz;
	return false;
}


bool isExpired(int igra)
{
	bool pronadjen = false;
	string pomocni_niz;
	string temp;
	ifstream myfile("assets/data/igra.txt");
	if (myfile.is_open())
	{
		while (getline(myfile, pomocni_niz))
		{
			if ((pomocni_niz[0] - '0') == igra)
				temp = pomocni_niz;
			pronadjen = true;
		}
		myfile.close();
	}
	if (!pronadjen)return false;
	if (igra == 4)
	{
		return false;
	}
	if (igra == 1)
	{
		if (vratiRazliku(temp, SAT))return false;
		else return true;
	}
	if (igra == 2)
	{

		if (vratiRazliku(temp, DAN))return false;
		else return true;
	}
	if (igra == 3)
	{
		if (vratiRazliku(temp, SEDAM))return false;
		else return true;
	}
	return false;
}
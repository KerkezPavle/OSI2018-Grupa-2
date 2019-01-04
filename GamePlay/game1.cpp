#include"Game1.h"
#include <iostream>
#include <ctime>
//a-veci br, b-manji br
int ucitaj_br(int a, int b)
{
	int n;
	std::cout << "Unesite broj iz opsega" << a << "-" << b << ":" << std::endl;
	do
	{
		std::cin >> n;
		if (n > a || n < b)
			std::cout << "Taj broj nije iz dozvoljenog opsega, unesite ponovo broj." << std::endl;
	} while (n > a || n < b);
	return n;
}

//a i b su interval od a do b
int slucajan_br(int a, int b)
{
	srand(time(NULL));
	rand();
	return rand() % (a - b) + b;
}

//prima broj bodova
int izlaz_iz_igre(int brb)
{
	std::cout << "Trenutno imate: " << brb << " bodova." << std::endl << std::endl;
	std::cout << "Zelite li nastaviti igrati?" << std::endl;
	std::cout << "DA-1, NE-2" << std::endl;
	//omogucava izlazak iz igre
	int tmp;
	do {
		std::cin >> tmp;
	} while (tmp != 1 && tmp != 2);
	return tmp;
}



int game1(int brb, int br_igranja)
{

	/*
	nez hoces li funkciju game1 pozivati ovako ili nekako drugacije
	ugl ako je drugacije ovde samo stavi
	brb=f();
	br_igranja=g();
	gdje je f-funkcija koja vraca trenutni br bodova
	a g- funkcija koja vraca koliko puta je do sada korisnik igrao igru 1 (da znam da li je namjesteno ono da stalno dobija ili ne)
	funkcija game1 vraca ukupan br bodova.
	*/

	int n, a, b;
	int prag = brb;

	std::cout << "Pravila igre: " << std::endl;
	std::cout << "Aplikacija ce prvo na slucajan nacin izabrati odredjeni broj."<<std::endl;
	std::cout << "Korisnik ima 5 pokusaja da ga pogodi tako sto unosi broj"<<std::endl;
	std::cout << "Aplikacija nakon svakog pokusaja prikazuje poruku:" << std::endl <<"\"Broj koji trazite je[veci | manji] od unesenog broja\""<<std::endl;
	std::cout << "Ako korisnik pogodi trazeni broj dobija"<<std::endl<< "100 / broj_pokusaja bodova za svoj profil. " << std::endl << std::endl << std::endl;

	while (true)
	{
		a = 100;
		b = 0;
		//NAMJESTENO, GUBI
		if ((br_igranja > 3) && (prag < 20))
		{
			int br_pokusaja = 0;
			while (true)
			{
				if (br_pokusaja <= 4)
				{
					n = ucitaj_br(a, b);
					br_pokusaja++;
					if (n >= ((a + b) / 2))
					{
						std::cout << std::endl << "Broj koji trazite je manji od navedenog broja." << std::endl;
						a = n - 1;
					}
					if (n < (a + b) / 2)
					{
						std::cout << std::endl << "Broj koji trazite je veci od navedenog broja." << std::endl;
						b = n + 1;
					}
				}
				else
				{
					std::cout << std::endl << "Niste pogodili, trazeni broj je bio " << slucajan_br(a, b) << "." << std::endl;
					if (izlaz_iz_igre(brb) == 2) //ako zeli napustiti igru vraca broj bodova i prekida while petlju
					{
						return brb;//vracam ukupan broj bodova iz funkcije
					}
					else //inace vraca se br pokusaja na 0
					{
						br_pokusaja = 0;
						a = 100;
						b = 0;
						break;
					}
				}
			}
			for (int i = 0; i < 5; i++)
				std::cout << std::endl;
			continue;
		}

		//NORMALNI, POSTENI DIO IGRE
		if ((br_igranja > 3) && (prag >= 100))
		{
			int trazeni_br = slucajan_br(100, 0);
			int br_pokusaja = 0;

			while (true)
			{

				if (br_pokusaja == 5)
				{
					std::cout << std::endl << "Niste pogodili, trazeni broj je bio " << trazeni_br << "." << std::endl;

					if (izlaz_iz_igre(brb) == 2) //ako zeli napustiti igru vraca broj bodova i prekida while petlju
					{
						return brb;//vracam ukupan broj bodova iz funkcije
					}
					else //inace vraca se br pokusaja na 0
					{
						br_pokusaja = 0;
						a = 100;
						b = 0;
						break;
					}

					trazeni_br = slucajan_br(100, 0);
				}
				n = ucitaj_br(a, b);
				br_pokusaja++;
				if (n == trazeni_br)
				{
					brb = brb + 100 / br_pokusaja;
					std::cout << std::endl << "Pogodili ste trazeni broj i dobili " << (100 / br_pokusaja) << " bodova" << std::endl;
					prag = prag - (100 / br_pokusaja);

					if (izlaz_iz_igre(brb) == 2) //ako zeli napustiti igru vraca broj bodova i prekida while petlju
					{
						return brb;//vracam ukupan broj bodova iz funkcije
					}
					else //inace vraca se br pokusaja na 0
					{
						br_pokusaja = 0;
						a = 100;
						b = 0;
						break;
					}
				}
				else
				{
					if (n > trazeni_br)
					{
						std::cout << std::endl << "Broj koji trazite je manji od navedenog broja." << std::endl;
						a = n - 1;
					}
					if (n < trazeni_br)
					{
						std::cout << std::endl << "Broj koji trazite je veci od navedenog broja." << std::endl;
						b = n + 1;
					}
				}

			}
			for (int i = 0; i < 5; i++)
				std::cout << std::endl;
			continue;
		}


		//Namjesteni dio igre, dobija
		if ((br_igranja <= 3) || ((br_igranja > 3) && (prag >= 20) && (prag < 100)))
		{
			int br_pokusaja = 0;
			int pogodak;

			if (br_igranja <= 3)
				pogodak = slucajan_br(5, 1); // slucajnim izborom odredim kad korisnik treba da dobije u prva tri puta
			else
			{
				pogodak = 100 / prag;//ako je prag spao na manje od 100 onda odredim kad treba da dobije i da mu onemogucim dalje dobijanje
				prag = 0;
			}

			while (true)
			{
				n = ucitaj_br(a, b);//ucita se broj koji korisnik misli da je odgovarajuci
				br_pokusaja++;
				if (br_pokusaja == pogodak) //ako je broj pokusaja jednak onom broju koji sam slucajnim izborom izvukao
				{							//onda je "pogodio" broj
					brb = brb + 100 / br_pokusaja; //povecava se br bodova
					br_igranja++;//povecava se i broj igranja (kad dostigne 3, prestaje onaj rezim kad stalno dobija)...

					std::cout << std::endl << "Pogodili ste trazeni broj i dobili " << (100 / br_pokusaja) << " bodova" << std::endl;

					if (izlaz_iz_igre(brb) == 2) //ako zeli napustiti igru vraca broj bodova i prekida while petlju
					{
						return brb; //vracam ukupan broj bodova iz funkcije
					}
					else //inace vraca se br pokusaja na 0, i odredjuje se ponovo iz kog puta treba da pogodi
					{
						br_pokusaja = 0;
						pogodak = slucajan_br(5, 1);
						a = 100;
						b = 0;
						break; //Izlazak iz ove while petlje, da bi provjerio da li je i dalje u rezimu za dobijanje ili prelazi u normalni rezim
					}
				}
				if (br_pokusaja < pogodak) //...
				{
					if (n >= ((a + b) / 2))
					{
						std::cout << std::endl << "Broj koji trazite je manji od navedenog broja." << std::endl;
						a = n - 1;
					}
					if (n < (a + b) / 2)
					{
						std::cout << std::endl << "Broj koji trazite je veci od navedenog broja." << std::endl;
						b = n + 1;
					}
				}
			}
			if (br_igranja == 4) prag = brb;

			for (int i = 0; i < 5; i++)
				std::cout << std::endl;
		}

	}
}

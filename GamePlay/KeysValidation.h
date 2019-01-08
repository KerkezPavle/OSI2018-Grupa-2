#pragma once
#include <iostream>
#define _CRT_SECURE_NO_DEPRECATE

bool otkljucaj_igru(std::string, std::string, std::string igra, int);

bool isActive(std::string, int); // za string staviti "assets/data/igra.txt"

bool isDeactivated(int);

std::string currentDateTime();

bool provjeraPonavljanjaKoda(std::string);

bool vratiRazliku(std::string, int);

void deaktivirajIgru(int);

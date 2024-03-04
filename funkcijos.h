#ifndef FUNKCIJOS_H
#define FUNKCIJOS_H
#include "mokinys.h"

bool Patikrinimas(string kint);
void Vidurkis(vector<Mokinys> &A);
void Isvedimas(const vector<Mokinys> &A, int MOK_kiekis);
bool PagalVidurki(const Mokinys &a, const Mokinys &b);
bool PagalMediana(const Mokinys &a, const Mokinys &b);
bool PagalVarda(const Mokinys &a, const Mokinys &b);
bool PagalPavarde(const Mokinys &a, const Mokinys &b);
void FailuGeneravimas();

#endif

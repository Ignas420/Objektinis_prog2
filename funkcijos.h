#ifndef FUNKCIJOS_H
#define FUNKCIJOS_H
#include "mokinys.h"
//
bool Patikrinimas(string kint);
void Vidurkis(vector<Mokinys> &A);
void Isvedimas(const vector<Mokinys> &A, int MOK_kiekis, string isvedimas);
void Isvedimas2(const vector<Mokinys> &A, int MOK_kiekis, string isvedimas);
bool PagalVidurki(const Mokinys &a, const Mokinys &b);
bool PagalMediana(const Mokinys &a, const Mokinys &b);
bool PagalVarda(const Mokinys &a, const Mokinys &b);
bool PagalPavarde(const Mokinys &a, const Mokinys &b);
void Rikiavimas(vector<Mokinys>& Mokslinciai, vector<Mokinys>& Nuskriaustieji, vector<int>& IrasuSk);
void GeneruotiFailus(vector<Mokinys>& Nuskriaustieji, vector<Mokinys>& Mokslinciai, vector<int>& IrasuSk, vector<Mokinys>& A);
void Skaitymas(vector<Mokinys>& Nuskriaustieji, vector<Mokinys>& Mokslinciai, vector<int>& IrasuSk, string failas, vector<Mokinys>& A, int& temp);
void StudentuRusiavimas(vector<Mokinys>& Nuskriaustieji, vector<Mokinys>& Mokslinciai, vector<Mokinys>& A, vector<int>& IrasuSk, string failas, int& temp);

#endif

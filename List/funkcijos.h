#ifndef FUNKCIJOS_H
#define FUNKCIJOS_H

#include "mokinys.h"

bool Patikrinimas (string kint);
void Vidurkis (list<Mokinys>& A);
void Isvedimas(const list<Mokinys>& A, int MOK_kiekis, string isvedimas);
void Isvedimas2(const list<Mokinys>& A, int MOK_kiekis, string isvedimas);
bool PagalVidurki(const Mokinys& a, const Mokinys& b);
bool PagalMediana(const Mokinys& a, const Mokinys& b);
bool PagalVarda(const Mokinys& a, const Mokinys& b);
bool PagalPavarde(const Mokinys& a, const Mokinys& b);
void Rikiavimas (list<Mokinys>& Mokslinciai, list<Mokinys>& Nuskriaustieji, list<int>& IrasuSk);
void GeneruotiFailus (list<Mokinys>& Nuskriaustieji, list<Mokinys>& Mokslinciai, list<int>& IrasuSk, list<Mokinys>& A);
void Skaitymas (list<Mokinys>& Nuskriaustieji, list<Mokinys>& Mokslinciai, list<int>& IrasuSk, string failas, list<Mokinys>& A, int& temp);
void StudentuRusiavimas (list<Mokinys>& Nuskriaustieji, list<Mokinys>& Mokslinciai, list<Mokinys>& A, list<int>& IrasuSk, string failas, int& temp);

#endif

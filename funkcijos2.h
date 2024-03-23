#ifndef FUNKCIJOS_H
#define FUNKCIJOS_H

#include "mokinys2.h"

bool Patikrinimas(string kint);
void Vidurkis(deque<Mokinys> &A);
void Isvedimas(const deque<Mokinys> &A, int MOK_kiekis, string isvedimas);
void Isvedimas2(const deque<Mokinys> &A, int MOK_kiekis, string isvedimas);
bool PagalVidurki(const Mokinys &a, const Mokinys &b);
bool PagalMediana(const Mokinys &a, const Mokinys &b);
bool PagalVarda(const Mokinys &a, const Mokinys &b);
bool PagalPavarde(const Mokinys &a, const Mokinys &b);
void Rikiavimas(deque<Mokinys>& Mokslinciai, deque<Mokinys>& Nuskriaustieji, deque<int>& IrasuSk);
void GeneruotiFailus(deque<Mokinys>& Nuskriaustieji, deque<Mokinys>& Mokslinciai, deque<int>& IrasuSk, deque<Mokinys>& A);
void Skaitymas(deque<Mokinys>& Nuskriaustieji, deque<Mokinys>& Mokslinciai, deque<int>& IrasuSk, string failas, deque<Mokinys>& A, int& temp);
void StudentuRusiavimas(deque<Mokinys>& Nuskriaustieji, deque<Mokinys>& Mokslinciai, deque<Mokinys>& A, deque<int>& IrasuSk, string failas, int& temp);
void StudentuRusiavimas2(deque<Mokinys> &Nuskriaustieji, deque<Mokinys> &Mokslinciai, deque<Mokinys> &A, deque<int> &IrasuSk, string failas, int &temp);

#endif

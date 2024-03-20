#ifndef FUNKCIJOS_H
#define FUNKCIJOS_H

#include "mokinys2.h"

bool Patikrinimas(string kint);
void Vidurkis(std::deque<Mokinys> &A);
void Isvedimas(const std::deque<Mokinys> &A, int MOK_kiekis, string isvedimas);
void Isvedimas2(const std::deque<Mokinys> &A, int MOK_kiekis, string isvedimas);
bool PagalVidurki(const Mokinys &a, const Mokinys &b);
bool PagalMediana(const Mokinys &a, const Mokinys &b);
bool PagalVarda(const Mokinys &a, const Mokinys &b);
bool PagalPavarde(const Mokinys &a, const Mokinys &b);
void Rikiavimas(std::deque<Mokinys>& Mokslinciai, std::deque<Mokinys>& Nuskriaustieji, std::deque<int>& IrasuSk);
void GeneruotiFailus(std::deque<Mokinys>& Nuskriaustieji, std::deque<Mokinys>& Mokslinciai, std::deque<int>& IrasuSk, std::deque<Mokinys>& A);
void Skaitymas(std::deque<Mokinys>& Nuskriaustieji, std::deque<Mokinys>& Mokslinciai, std::deque<int>& IrasuSk, string failas, std::deque<Mokinys>& A, int& temp);
void StudentuRusiavimas(std::deque<Mokinys>& Nuskriaustieji, std::deque<Mokinys>& Mokslinciai, std::deque<Mokinys>& A, std::deque<int>& IrasuSk, string failas, int& temp);

#endif

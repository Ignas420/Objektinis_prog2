#ifndef MOKINYS_H
#define MOKINYS_H

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <list>
#include <random>
#include <sstream>
#include <algorithm>
#include <chrono>
#include <stdexcept>
#include <deque>
#include <cstring>

using namespace std;

const char CRfv[] = "rezultatai.txt";
const char CRfv3[] = "mokslinciai.txt";
const char CRfv4[] = "nuskriaustieji.txt";

struct Mokinys
{
    string vardas;
    string pavarde;
    list<int> ND;
    int egzaminas;
    double VID;
    double MED;
};

#endif

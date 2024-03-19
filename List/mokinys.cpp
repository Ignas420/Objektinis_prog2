#include "mokinys.h"
#include "funkcijos.h"

bool Patikrinimas(string kint)
{
    const int ilgis = kint.length();
    char *temp_array = new char[ilgis + 1];
    strcpy(temp_array, kint.c_str());
    for (int i = 0; i < ilgis; i++)
    {
        if (!isalpha(temp_array[i]))
            return false;
    }
    delete[] temp_array;
    return true;
}

void Vidurkis(list<Mokinys> &A)
{
    for (auto &mok : A)
    {
        double suma = 0;
        for (int pazymys : mok.ND)
        {
            suma += pazymys;
        }
        suma += mok.egzaminas;
        double vidurkis = suma / (mok.ND.size() + 1);
        mok.VID = vidurkis;
    }
}

bool PagalVidurki(const Mokinys &a, const Mokinys &b)
{
    return a.VID > b.VID;
}

bool PagalMediana(const Mokinys &a, const Mokinys &b)
{
    return a.MED > b.MED;
}

bool PagalVarda(const Mokinys &a, const Mokinys &b)
{
    return a.vardas > b.vardas;
}

bool PagalPavarde(const Mokinys &a, const Mokinys &b)
{
    return a.pavarde > b.pavarde;
}

double visasLaikas;

void GeneruotiFailus(list<Mokinys> &Nuskriaustieji, list<Mokinys> &Mokslinciai, list<int> &IrasuSk, list<Mokinys> &A)
{
    srand(time(NULL));
    visasLaikas = 0.0;

    int temp_index = 0;
    for (auto irasai : IrasuSk)
    {
        auto start = std::chrono::high_resolution_clock::now();
        auto st = start;
        cout << "~FAILAS " + to_string(temp_index) + "~" << endl;
        string filename = "failas" + to_string(temp_index) + ".txt";
        ofstream fr(filename);

        if (!fr)
            throw runtime_error("Failas nurodytoje vietoje neegzistuoja!");

        int temp = rand() % 10 + 1;

        fr << setw(20) << left << "Vardas" << setw(20) << left << "Pavarde";
        for (int i = 0; i < temp; i++)
            fr << setw(10) << left << "ND";
        fr << setw(10) << left << "Egz." << endl;

        for (int j = 0; j < irasai; j++)
        {
            fr << setw(20) << left << ("Vardas" + to_string(j)) << setw(20) << left << ("Pavarde" + to_string(j));
            for (int k = 0; k < temp; k++)
                fr << setw(10) << left << rand() % 10 + 1;
            fr << setw(10) << left << rand() % 10 + 1 << endl;
        }

        fr.close();
        std::chrono::duration<double> diff = std::chrono::high_resolution_clock::now() - start;
        cout << "Failo " + to_string(temp_index) + " kurimo laikas: " << diff.count() << "s\n";

        visasLaikas += diff.count();

        Skaitymas(Nuskriaustieji, Mokslinciai, IrasuSk, filename, A, temp_index);
        temp_index++;
    }
}

void Skaitymas(list<Mokinys> &Nuskriaustieji, list<Mokinys> &Mokslinciai, list<int> &IrasuSk, string failas, list<Mokinys> &A, int &temp)
{
    auto start1 = std::chrono::high_resolution_clock::now();
    auto st1 = start1;

    string eil;
    ifstream fd(failas);
    if (!fd)
        throw runtime_error("Failas nurodytoje vietoje neegzistuoja!");
    getline(fd, eil);
    auto start = std::chrono::high_resolution_clock::now();
    auto st = start;
    while (getline(fd, eil))
    {
        istringstream iss(eil);
        Mokinys temp;
        iss >> temp.vardas >> temp.pavarde;
        int pazymiai;
        while (iss >> pazymiai)
            temp.ND.push_back(pazymiai);

        if (!temp.ND.empty())
        {
            temp.egzaminas = temp.ND.back();
            temp.ND.pop_back();
        }

        temp.ND.sort(); // Sort the list of grades
        double mediana;

        if (!temp.ND.empty())
        {
            auto it = temp.ND.begin();
            advance(it, temp.ND.size() / 2);
            mediana = *it;
            if (temp.ND.size() % 2 == 0)
            {
                it--;
                mediana = (*it + mediana) / 2.0;
            }
        }
        temp.MED = mediana;
        A.push_back(temp);
    }
    fd.close();
    std::chrono::duration<double> diff = std::chrono::high_resolution_clock::now() - start;
    cout << "Nuskaitymo laikas: " << diff.count() << "s\n";
    Vidurkis(A);
    StudentuRusiavimas(Nuskriaustieji, Mokslinciai, A, IrasuSk, failas, temp);

    std::chrono::duration<double> diff1 = std::chrono::high_resolution_clock::now() - start1;
    cout << "Visa programa " + to_string(temp) + " uztruko: " << diff1.count() << "s\n";

    visasLaikas += diff1.count();

    cout << endl;
}

void StudentuRusiavimas(list<Mokinys> &Nuskriaustieji, list<Mokinys> &Mokslinciai, list<Mokinys> &A, list<int> &IrasuSk, string failas, int &temp)
{
    string filename = "nuskriaustieji" + to_string(temp) + ".txt";
    string filename1 = "mokslinciai." + to_string(temp) + ".txt";
    int kint;
    auto start = std::chrono::high_resolution_clock::now();
    auto st = start;

    for (auto &mok : A)
    {
        if (mok.VID > 5.0)
            Nuskriaustieji.push_back(mok);
        else
            Mokslinciai.push_back(mok);
    }

    std::chrono::duration<double> diff = std::chrono::high_resolution_clock::now() - start;
    cout << "Studentu rusiavimas uztruko: " << diff.count() << "s\n";

    Mokslinciai.sort(PagalVidurki);
    Nuskriaustieji.sort(PagalVidurki);

    cout << "~Mokslinciai~" << endl;
    Isvedimas2(Mokslinciai, Mokslinciai.size(), filename);
    cout << "~Nuskriaustieji~" << endl;
    Isvedimas2(Nuskriaustieji, Nuskriaustieji.size(), filename1);
}

void Isvedimas(const list<Mokinys> &A, int MOK_kiekis, string isvedimas)
{
    char kint;
    cout << "Rezultatus matyti norite ekrane ar faile?(e/f): ";
    cin >> kint;
    if (kint == 'e')
    {
        auto start = std::chrono::high_resolution_clock::now();
        auto st = start;
        cout << setw(20) << left << "Vardas" << setw(20) << left << "Pavarde" << setw(20) << right << "Galutinis (Vid.) / Galutinis(Med.)" << endl;
        cout << setfill('-') << setw(80) << " " << endl;
        cout << setfill(' ');

        for (const auto &mok : A)
        {
            cout << setw(20) << left << mok.vardas << setw(20) << left << mok.pavarde << right << fixed << setprecision(2) << mok.VID << setw(18) << right << mok.MED;
            cout << endl;
        }
        std::chrono::duration<double> diff = std::chrono::high_resolution_clock::now() - start;
        cout << "Studentu isvedimas ekrane uztruko: " << diff.count() << "s\n";
    }
    else if (kint == 'f')
    {
        auto start = std::chrono::high_resolution_clock::now();
        auto st = start;
        ofstream fr(isvedimas);
        fr << setw(20) << left << "Vardas" << setw(20) << left << "Pavarde" << setw(20) << right << "Galutinis (Vid.) / Galutinis(Med.)" << endl;
        fr << setfill('-') << setw(80) << " " << endl;
        fr << setfill(' ');

        for (const auto &mok : A)
        {
            fr << setw(20) << left << mok.vardas << setw(20) << left << mok.pavarde << right << fixed << setprecision(2) << mok.VID << setw(18) << right << mok.MED;
            fr << endl;
        }
        fr.close();
        std::chrono::duration<double> diff = std::chrono::high_resolution_clock::now() - start;
        cout << "Studentu isvedimas i failus uztruko: " << diff.count() << "s\n";
    }
    else
        throw runtime_error("Netinkama ivestis!");
}

void Isvedimas2(const list<Mokinys> &A, int MOK_kiekis, string isvedimas)
{
    auto start = std::chrono::high_resolution_clock::now();
    auto st = start;
    ofstream fr(isvedimas);
    fr << setw(20) << left << "Vardas" << setw(20) << left << "Pavarde" << setw(20) << right << "Galutinis (Vid.) / Galutinis(Med.)" << endl;
    fr << setfill('-') << setw(80) << " " << endl;
    fr << setfill(' ');

    for (const auto &mok : A)
    {
        fr << setw(20) << left << mok.vardas << setw(20) << left << mok.pavarde << right << fixed << setprecision(2) << mok.VID << setw(18) << right << mok.MED;
        fr << endl;
    }
    fr.close();
    std::chrono::duration<double> diff = std::chrono::high_resolution_clock::now() - start;
    cout << "Studentu isvedimas i failus uztruko: " << diff.count() << "s\n";
}

void Rikiavimas(list<Mokinys> &Mokslinciai, list<Mokinys> &Nuskriaustieji, list<int> &IrasuSk)
{
    char kint;
    cout << "Pagal ka rikiuoti: varda, pavarde, vidurki, mediana?(v, p, V, m)" << endl;
    cin >> kint;
    if (kint == 'V')
    {
        Mokslinciai.sort(PagalVidurki);
        Nuskriaustieji.sort(PagalVidurki);
    }
    else if (kint == 'm')
    {
        Mokslinciai.sort(PagalMediana);
        Nuskriaustieji.sort(PagalMediana);
    }
    else if (kint == 'v')
    {
        Mokslinciai.sort(PagalVarda);
        Nuskriaustieji.sort(PagalVarda);
    }
    else if (kint == 'p')
    {
        Mokslinciai.sort(PagalPavarde);
        Nuskriaustieji.sort(PagalPavarde);
    }
    else
        throw runtime_error("Netinkama ivestis!");
}

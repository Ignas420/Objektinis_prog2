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

void Vidurkis(vector<Mokinys> &A)
{
    for (int i = 0; i < A.size(); i++)
    {
        Mokinys &mok = A[i];
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
/* void FailuGeneravimas(){
    cout << "~Naujo failo parametrai~" << endl;
    ofstream fr(CRfv2);

    if(!fr.is_open())
        throw runtime_error("Failas nurodytoje vietoje neegzistuoja!");

    int nd;
    cout << "Iveskite namu darbu kieki: " << endl;
    cin >> nd;
    if(cin.fail())
        throw runtime_error("Namu darbai turi buti skaicius!");

    fr << setw(20) << left << "Vardas" << setw(20) << left << "Pavarde";
    for(int i=0; i<nd; i++)
        fr << setw(10) << left << "ND";
    fr << setw(10) << left << "Egz." << endl;

    int irasai;
    cout << "Iveskite irasu skaiciu: " << endl;
    cin >> irasai;

    auto start = std::chrono::high_resolution_clock::now();
    auto st = start;

    for(int j=1; j<=irasai; j++){
        fr << setw(20) << left << ("Vardas"+to_string(j)) << setw(20) << left << ("Pavarde"+to_string(j));
        for(int i=0; i<nd; i++)
            fr << setw(10) << left << rand()%10+1;
        fr << setw(10) << left << rand()%10+1 << endl;
    }
    fr.close();
    std::chrono::duration<double> diff = std::chrono::high_resolution_clock::now() - start;
    cout << "Failo is "+ to_string(irasai) + " sukurimo laikas: " << diff.count() << "s\n";
} */

void GeneruotiFailus(vector<Mokinys>& Nuskriaustieji, vector<Mokinys>& Mokslinciai, vector<int>& IrasuSk, vector<Mokinys>& A)
{
    srand(time(NULL));

    for (int i = 0; i < IrasuSk.size(); i++)
    {
        auto start1 = std::chrono::high_resolution_clock::now();
        auto st1 = start1;

        auto start = std::chrono::high_resolution_clock::now();
        auto st = start;
        cout << "~FAILAS " + to_string(i) + "~" << endl;
        string filename = "failas" + to_string(i) + ".txt";
        ofstream fr(filename);

        if (!fr)
            throw runtime_error("Failas nurodytoje vietoje neegzistuoja!");

        int temp = rand() % 10 + 1;

        fr << setw(20) << left << "Vardas" << setw(20) << left << "Pavarde";
        for (int i = 0; i < temp; i++)
            fr << setw(10) << left << "ND";
        fr << setw(10) << left << "Egz." << endl;

        for (int j = 0; j < IrasuSk[i]; j++)
        {
            fr << setw(20) << left << ("Vardas" + to_string(j)) << setw(20) << left << ("Pavarde" + to_string(j));
            for (int k = 0; k < temp; k++)
                fr << setw(10) << left << rand() % 10 + 1;
            fr << setw(10) << left << rand() % 10 + 1 << endl;
        }

        fr.close();
        std::chrono::duration<double> diff = std::chrono::high_resolution_clock::now() - start;
        cout << "Failo " + to_string(i) + " kurimo laikas: " << diff.count() << "s\n";

        Skaitymas(Nuskriaustieji, Mokslinciai, IrasuSk, filename, A, i);

        std::chrono::duration<double> diff1 = std::chrono::high_resolution_clock::now() - start1;
        cout << "Visa programa " + to_string(i) + " uztruko: " << diff.count() << "s\n";
    }
}
void Skaitymas(vector<Mokinys>& Nuskriaustieji, vector<Mokinys>& Mokslinciai, vector<int>& IrasuSk, string failas, vector<Mokinys>& A, int& temp)
{
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

        sort(temp.ND.begin(), temp.ND.end());
        double mediana;

        if (!temp.ND.empty())
        {
            mediana = temp.ND[temp.ND.size() / 2];
            if (temp.ND.size() % 2 == 0)
            {
                mediana = (temp.ND[temp.ND.size() / 2 - 1] + temp.ND[temp.ND.size() / 2]) / 2.0;
            }
        }
        temp.MED = mediana;
        A.push_back(temp);
    }
    std::chrono::duration<double> diff = std::chrono::high_resolution_clock::now() - start;
    cout << "Nuskaitymo laikas: " << diff.count() << "s\n";
    fd.close();
    Vidurkis(A);
    StudentuRusiavimas(Nuskriaustieji, Mokslinciai, A, IrasuSk, failas, temp);
}
void StudentuRusiavimas(vector<Mokinys>& Nuskriaustieji, vector<Mokinys>& Mokslinciai, vector<Mokinys>& A, vector<int>& IrasuSk, string failas, int& temp)
{
    string filename = "nuskriaustieji" + to_string(temp) + ".txt";
    string filename1 = "mokslinciai." + to_string(temp) + ".txt";
    int kint;
    char input4;
    cout << "Isrinkti mokinius pagal vidurki ar mediana?(V, M) " << endl;
    cin >> input4;
    auto start = std::chrono::high_resolution_clock::now();
    auto st = start;
    if (input4 == 'V')
    {
        for (int i = 0; i < A.size(); i++)
        {
            if (A[i].VID > 5.0)
                Nuskriaustieji.push_back(A[i]);
            else
                Mokslinciai.push_back(A[i]);
        }
    }
    else if (input4 == 'M')
    {
        for (int i = 0; i < A.size(); i++)
        {
            if (A[i].MED > 5.0)
                Nuskriaustieji.push_back(A[i]);
            else
                Mokslinciai.push_back(A[i]);
        }
    }
    else
        throw runtime_error("Netinkama ivestis!");

    std::chrono::duration<double> diff = std::chrono::high_resolution_clock::now() - start;
    cout << "Studentu rusiavimas uztruko: " << diff.count() << "s\n";
    
    Rikiavimas(Mokslinciai, Nuskriaustieji, IrasuSk);

    cout << "~Mokslinciai~" << endl;
    Isvedimas(Mokslinciai, Mokslinciai.size(), filename);
    cout << "~Nuskriaustieji~" << endl;
    Isvedimas(Nuskriaustieji, Nuskriaustieji.size(), filename1);
}
void Isvedimas(const vector<Mokinys> &A, int MOK_kiekis, string isvedimas)
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

        for (int i = 0; i < MOK_kiekis; i++)
        {
            cout << setw(20) << left << A[i].vardas << setw(20) << left << A[i].pavarde << right << fixed << setprecision(2) << A[i].VID << setw(18) << right << A[i].MED;
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

        for (int i = 0; i < MOK_kiekis; i++)
        {
            fr << setw(20) << left << A[i].vardas << setw(20) << left << A[i].pavarde << right << fixed << setprecision(2) << A[i].VID << setw(18) << right << A[i].MED;
            fr << endl;
        }
        fr.close();
        std::chrono::duration<double> diff = std::chrono::high_resolution_clock::now() - start;
        cout << "Studentu isvedimas i failus uztruko: " << diff.count() << "s\n";
    }
    else
        throw runtime_error("Netinkama ivestis!");
}
void Rikiavimas(vector<Mokinys>& Mokslinciai, vector<Mokinys>& Nuskriaustieji, vector<int>& IrasuSk){
    char kint;
    cout << "Pagal ka rikiuoti: varda, pavarde, vidurki, mediana?(v, p, V, m)" << endl;
            cin >> kint;
                if (kint == 'V')
                {
                    sort(Mokslinciai.begin(), Mokslinciai.end(), PagalVidurki);
                    sort(Nuskriaustieji.begin(), Nuskriaustieji.end(), PagalVidurki);
                }
                else if (kint == 'm')
                {
                    sort(Mokslinciai.begin(), Mokslinciai.end(), PagalMediana);
                    sort(Nuskriaustieji.begin(), Nuskriaustieji.end(), PagalMediana);
                }
                else if (kint == 'v')
                {
                    sort(Mokslinciai.begin(), Mokslinciai.end(), PagalVarda);
                    sort(Nuskriaustieji.begin(), Nuskriaustieji.end(), PagalVarda);
                }
                else if (kint == 'p')
                {
                    sort(Mokslinciai.begin(), Mokslinciai.end(), PagalPavarde);
                    sort(Nuskriaustieji.begin(), Nuskriaustieji.end(), PagalPavarde);
                }
                else
                    throw runtime_error("Netinkama ivestis!");
}
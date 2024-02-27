#include "mokinys.h"

int main()
{
    try
    {
        int n, m, kint;
        vector<Mokinys> A;
        string eil;
        char input;

        cout << "Norite ivesti ar skaityti is failo?(i/s) ";
        cin >> input;
        if (input == 'i')
        {
            cout << "Norite ivesti ranka ar generuoti skaicius?(i/g) " << endl;
            cin >> input;
            cout << "Irasykite kiek yra mokiniu: ";
            cin >> m;
            if (cin.fail())
            {
                throw runtime_error("Namu darbai turi buti skaicius!");
                return 1;
            }
            if (input == 'i')
            {
                cout << "Iveskite vardus ir pavardes: " << endl;
                kint = m;
                Mokinys temp;
                while (m != 0)
                {
                    cin >> temp.vardas >> temp.pavarde;
                    if (!Patikrinimas(temp.vardas) || !Patikrinimas(temp.pavarde))
                    {
                        throw runtime_error("Ivestas netinkamas vardas arba pavarde!");
                        return 1;
                    }
                    A.push_back(temp);
                    m--;
                }
                cout << "Irasykite namu darbu kieki: " << endl;
                cin >> n;
                kint = n;

                for (int i = 0; i < A.size(); i++)
                {
                    cout << "Irasykite namu darbu pazymius: " << endl;
                    for (int j = 0; j < n; j++)
                    {
                        int pazymys;
                        cin >> pazymys;
                        A[i].ND.push_back(pazymys);
                        if (cin.fail())
                        {
                            throw runtime_error("Namu darbai turi buti skaicius!");
                            return 1;
                        }
                        if (pazymys < 1 || pazymys > 10)
                        {
                            throw runtime_error("Pazymys turi buti desimtbaleje sistemoje!");
                            return 1;
                        }
                    }
                    cout << "Irasykite egzamino rezultata: " << endl;
                    cin >> A[i].egzaminas;
                    if (cin.fail())
                    {
                        throw runtime_error("Pazymys turi buti skaicius!");
                        return 1;
                    }
                    if (A[i].egzaminas < 1 || A[i].egzaminas > 10)
                    {
                        throw runtime_error("Pazymys turi buti desimtbaleje sistemoje!");
                        return 1;
                    }
                    Vidurkis(A);

                    sort(A[i].ND.begin(), A[i].ND.end());

                    vector<int> temp = A[i].ND;
                    temp.push_back(A[i].egzaminas);
                    sort(temp.begin(), temp.end());
                    double median = temp[temp.size() / 2];
                    if (temp.size() % 2 == 0)
                        median = (temp[temp.size() / 2 - 1] + temp[temp.size() / 2]) / 2.0;
                    A[i].MED = median;
                }
            }
            else if (input == 'g')
            {
                cout << "Iveskite vardus ir pavardes: " << endl;
                kint = m;
                Mokinys temp;
                while (m != 0)
                {
                    cin >> temp.vardas >> temp.pavarde;
                    if (!Patikrinimas(temp.vardas) || !Patikrinimas(temp.pavarde))
                    {
                        throw runtime_error("Ivestas netinkamas vardas arba pavarde!");
                        return 1;
                    }
                    A.push_back(temp);
                    m--;
                }
                cout << "Irasykite namu darbu kieki: " << endl;
                cin >> n;
                kint = n;
                cout << "Generuojami pazymiai..." << endl;
                for (int i = 0; i < A.size(); i++)
                {
                    for (int j = 0; j < n; j++)
                    {
                        int pazymys;
                        pazymys = (rand() % 10) + 1;
                        A[i].ND.push_back(pazymys);
                        if (cin.fail())
                        {
                            throw runtime_error("Namu darbai turi buti skaicius!");
                            return 1;
                        }
                        if (pazymys < 1 || pazymys > 10)
                        {
                            throw runtime_error("Pazymys turi buti desimtbaleje sistemoje!");
                            return 1;
                        }
                    }
                    A[i].egzaminas = (rand() % 10) + 1;
                    ;
                    if (cin.fail())
                    {
                        throw runtime_error("Pazymys turi buti skaicius!");
                        return 1;
                    }
                    if (A[i].egzaminas < 1 || A[i].egzaminas > 10)
                    {
                        throw runtime_error("Pazymys turi buti desimtbaleje sistemoje!");
                        return 1;
                    }
                    Vidurkis(A);

                    sort(A[i].ND.begin(), A[i].ND.end());

                    vector<int> temp = A[i].ND;
                    temp.push_back(A[i].egzaminas);
                    sort(temp.begin(), temp.end());
                    double median = temp[temp.size() / 2];
                    if (temp.size() % 2 == 0)
                        median = (temp[temp.size() / 2 - 1] + temp[temp.size() / 2]) / 2.0;
                    A[i].MED = median;
                }
            }
        }
        else if (input == 's')
        {
            ifstream fd(CDfv);
            auto start = std::chrono::high_resolution_clock::now();
            auto st = start;
            if (!fd)
                throw runtime_error("Failas nurodytoje vietoje neegzistuoja!");
            getline(fd, eil);
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
            char kint;
            cout << "Pagal ka rikiuoti: varda, pavarde, vidurki, mediana?(v, p, V, m)" << endl;
            cin >> kint;
            if (kint == 'V')
            {
                sort(A.begin(), A.end(), PagalVidurki);
            }
            else if (kint == 'm')
            {
                sort(A.begin(), A.end(), PagalMediana);
            }
            else if (kint == 'v')
            {
                sort(A.begin(), A.end(), PagalVarda);
            }
            else if (kint == 'p')
            {
                sort(A.begin(), A.end(), PagalPavarde);
            }
            else
            {
                throw runtime_error("Netinkama ivestis!");
                return 1;
            }
        }
        else
        {
            throw runtime_error("Netinkama ivestis!");
            return 1;
        }
        Isvedimas(A, A.size());
        return 0;
    }
    catch (exception &e)
    {
        cout << "Klaida: " << e.what() << endl;
        return 0;
    }
}
#include "mokinys.h"
#include "funkcijos.h"

int main()
{
    try
    {
        int n, m, kint;
        vector<int> IrasuSk = {1000, 10000, 100000, 1000000, 10000000};
        vector<Mokinys> A;
        vector<Mokinys> Mokslinciai;
        vector<Mokinys> Nuskriaustieji;
        string eil;
        char input, input2, input3;
        cout << "Norite ivesti ar skaityti is failo?(i/s) " << endl;
        cin >> input;
        if (input == 'i')
        {
            cout << "Norite ivesti ranka ar generuoti skaicius?(i/g) " << endl;
            cin >> input2;
            if (input2 == 'i')
            {
                cout << "Irasykite kiek yra mokiniu: ";
                cin >> m;
                if (cin.fail())
                {
                    throw runtime_error("Kiekis turi buti skaicius!");
                    return 1;
                }
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
            else if (input2 == 'g')
            {
                cout << "Irasykite kiek yra mokiniu: ";
                cin >> m;
                if (cin.fail())
                {
                    throw runtime_error("Kiekis turi buti skaicius!");
                    return 1;
                }
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
            else
            {
                throw runtime_error("Netinkama ivestis!");
                return 1;
            }
        }
        //SKAITYMAS
        else if (input == 's')
        {
            auto start1 = std::chrono::high_resolution_clock::now();
            auto st1 = start1;
            string failas;
            cout << "Ar norite generuoti naujus failus?(t/n) " << endl;
            cin >> input3;
            if (input3 == 't')
                GeneruotiFailus(IrasuSk, A);
            else if (input3 == 'n')
                failas = CDfv;
            else
                throw runtime_error("Netinkama ivestis!");
            //
            Vidurkis(A);
            if (input3 == 't')
            {
                char input4;
                cout << "Isrinkti mokinius pagal vidurki ar mediana?(V, M) " << endl;
                cin >> input4;
                auto start = std::chrono::high_resolution_clock::now();
                auto st = start;
                if (input4 == 'V')
                {
                    for (int i = 0; i < A.size(); i++)
                    {
                        if (A[i].VID < 5.0)
                            Nuskriaustieji.push_back(A[i]);
                        else
                            Mokslinciai.push_back(A[i]);
                    }
                }
                else if (input4 == 'M')
                {
                    for (int i = 0; i < A.size(); i++)
                    {
                        if (A[i].MED < 5.0)
                            Nuskriaustieji.push_back(A[i]);
                        else
                            Mokslinciai.push_back(A[i]);
                    }
                }
                else
                    throw runtime_error("Netinkama ivestis!");
                std::chrono::duration<double> diff = std::chrono::high_resolution_clock::now() - start;
                cout << "Studentu rusiavimas uztruko: " << diff.count() << "s\n";

                cout << "~Mokslinciai~"<<endl;
                Isvedimas(Mokslinciai, Mokslinciai.size(), CRfv3);
                cout << "~Nuskriaustieji~"<<endl;
                Isvedimas(Nuskriaustieji, Nuskriaustieji.size(), CRfv4);
            }
            char kint;
            cout << "Pagal ka rikiuoti: varda, pavarde, vidurki, mediana?(v, p, V, m)" << endl;
            cin >> kint;
            if (input3 == 't')
            {
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
                {
                    throw runtime_error("Netinkama ivestis!");
                    return 1;
                }
            }
            else if (input3 == 'n')
            {
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
            std::chrono::duration<double> diff1 = std::chrono::high_resolution_clock::now() - start1;
            cout << "Programa uztruko: " << diff1.count() << "s\n";
        }
        else
        {
            throw runtime_error("Netinkama ivestis!");
            return 1;
        }
        if (input3 == 't')
            return 0;
        else
            Isvedimas(A, A.size(), CRfv);
        return 0;
    }
    catch (exception &e)
    {
        cout << "Klaida: " << e.what() << endl;
        return 0;
    }
}
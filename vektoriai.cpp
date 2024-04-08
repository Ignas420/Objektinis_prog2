#include "mokinys.h"
#include "funkcijos.h"

auto start1 = std::chrono::high_resolution_clock::now();


int Mokinys :: main()
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
        // SKAITYMAS
        else if (input == 's')
        {
            auto start1 = std::chrono::high_resolution_clock::now();
            auto st1 = start1;
            string failas;
            int temp;
            cout << "Iveskite 't'(taip) jei norite generuoti failus: " << endl;
            cin >> input3;
            if (input3 == 't')
                GeneruotiFailus(Nuskriaustieji, Mokslinciai, IrasuSk, A);
            //else if (input3 == 'n')
            //{
                char kint6;
                int kint5;
                string filename;

                cout << "Norite skaityti naujus ar senus failus?(n/s): " << endl;
                cin >> kint6;
                if(kint6 != 'n' && kint6 != 's')
                    throw runtime_error("Netinkama ivestis!");

                cout << "Iveskite failu skaiciu: "<<endl;
                cin >> kint5;
                if(cin.fail())
                    throw runtime_error("Netinkama ivestis!");

                for(int i=0; i<kint5; i++){
                    if(kint6 == 'n')
                        filename = "new_file" + to_string(i) + ".txt";
                    else
                        filename = "file" + to_string(i) + ".txt";
                    Skaitymas(Nuskriaustieji, Mokslinciai, IrasuSk, filename, A, i);
                }
            //}
            //else
                //throw runtime_error("Netinkama ivestis!");
            Vidurkis(A);
        }
        else
        {
            throw runtime_error("Netinkama ivestis!");
            return 1;
        }
        return 0;
    }
    catch (exception &e)
    {
        cout << "Klaida: " << e.what() << endl;
        return 0;
    }
}
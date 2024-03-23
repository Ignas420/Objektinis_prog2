#include "mokinys1.h"
#include "funkcijos1.h"

int main() {
    try {
        int n, m;
        list<int> IrasuSk = {1000, 10000, 100000, 1000000, 10000000};
        list<Mokinys> A;
        list<Mokinys> Mokslinciai;
        list<Mokinys> Nuskriaustieji;
        char input, input2, input3;

        cout << "Norite ivesti ar skaityti is failo?(i/s) " << endl;
        cin >> input;

        if (input == 'i') {
            cout << "Norite ivesti ranka ar generuoti skaicius?(i/g) " << endl;
            cin >> input2;

            if (input2 == 'i') {
                cout << "Irasykite kiek yra mokiniu: ";
                cin >> m;

                if (cin.fail()) {
                    throw runtime_error("Kiekis turi buti skaicius!");
                }

                cout << "Iveskite vardus ir pavardes: " << endl;

                for (int i = 0; i < m; ++i) {
                    Mokinys temp;
                    cin >> temp.vardas >> temp.pavarde;

                    if (!Patikrinimas(temp.vardas) || !Patikrinimas(temp.pavarde)) {
                        throw runtime_error("Ivestas netinkamas vardas arba pavarde!");
                    }

                    A.push_back(temp);
                }

                cout << "Irasykite namu darbu kieki: " << endl;
                cin >> n;

                for (auto& it : A) {
                    cout << "Irasykite namu darbu pazymius: " << endl;

                    for (int j = 0; j < n; ++j) {
                        int pazymys;
                        cin >> pazymys;

                        it.ND.push_back(pazymys);

                        if (cin.fail() || pazymys < 1 || pazymys > 10) {
                            throw runtime_error("Namu darbai turi buti skaicius nuo 1 iki 10!");
                        }
                    }

                    cout << "Irasykite egzamino rezultata: " << endl;
                    cin >> it.egzaminas;

                    if (cin.fail() || it.egzaminas < 1 || it.egzaminas > 10) {
                        throw runtime_error("Egzamino rezultatas turi buti skaicius nuo 1 iki 10!");
                    }

                    Vidurkis(A);

                    list<int> temp = it.ND;
                    temp.push_back(it.egzaminas);
                    temp.sort();

                    double median = *next(temp.begin(), temp.size() / 2);

                    if (temp.size() % 2 == 0) {
                        median = (*next(temp.begin(), temp.size() / 2 - 1) + *next(temp.begin(), temp.size() / 2)) / 2.0;
                    }

                    it.MED = median;
                }
                Isvedimas(A, A.size(), CRfv);
            } else if (input2 == 'g') {
                cout << "Irasykite kiek yra mokiniu: ";
                cin >> m;
                if (cin.fail()) {
                    throw runtime_error("Kiekis turi buti skaicius!");
                }

                cout << "Iveskite vardus ir pavardes: " << endl;
                int kint = m;
                Mokinys temp;
                while (m != 0) {
                    cin >> temp.vardas >> temp.pavarde;
                    if (!Patikrinimas(temp.vardas) || !Patikrinimas(temp.pavarde)) {
                        throw runtime_error("Ivestas netinkamas vardas arba pavarde!");
                    }
                    A.push_back(temp);
                    m--;
                }

                cout << "Irasykite namu darbu kieki: " << endl;
                cin >> n;
                kint = n;
                cout << "Generuojami pazymiai..." << endl;

                for (auto& student : A) {
                    for (int j = 0; j < n; j++) {
                        int pazymys = (rand() % 10) + 1;
                        student.ND.push_back(pazymys);
                        if (cin.fail()) {
                            throw runtime_error("Namu darbai turi buti skaicius!");
                        }
                        if (pazymys < 1 || pazymys > 10) {
                            throw runtime_error("Pazymys turi buti desimtbaleje sistemoje!");
                        }
                    }

                    student.egzaminas = (rand() % 10) + 1;
                    if (cin.fail()) {
                        throw runtime_error("Pazymys turi buti skaicius!");
                    }
                    if (student.egzaminas < 1 || student.egzaminas > 10) {
                        throw runtime_error("Pazymys turi buti desimtbaleje sistemoje!");
                    }
                    Vidurkis(A);
                    student.ND.sort();
                    list<int> temp = student.ND;
                    temp.push_back(student.egzaminas);
                    temp.sort();
                    double median = 0.0;
                    auto it = next(temp.begin(), temp.size() / 2);
                    if (temp.size() % 2 == 0) {
                        auto it2 = prev(it);
                        median = (*it + *it2) / 2.0;
                    } else {
                        median = *it;
                    }
                    student.MED = median;
                }
                Isvedimas(A, A.size(), CRfv);
            }
        } else if (input == 's') {
            string failas;
            int temp;

            cout << "Iveskite 't'(taip) jei norite generuoti failus: " << endl;
            cin >> input3;

            if (input3 == 't') {
                GeneruotiFailus(Nuskriaustieji, Mokslinciai, IrasuSk, A);
            }
                int kint5;
                string filename;
                char kint6;

                cout << "Norite skaityti naujus ar senus failus?(n/s): " << endl;
                cin >> kint6;
                if(kint6 != 'n' && kint6 != 's')
                    throw runtime_error("Netinkama ivestis!");

                cout << "Iveskite failu skaiciu: "<<endl;
                cin >> kint5;
                if(cin.fail())
                    throw runtime_error("Netinkama ivestis!");

                for (int i = 0; i < kint5; ++i) {
                    if(kint6 == 'n')
                        filename = "new_file" + to_string(i) + ".txt";
                    else
                        filename = "file" + to_string(i) + ".txt";
                    Skaitymas(Nuskriaustieji, Mokslinciai, IrasuSk, filename, A, i);
                }
            

            Vidurkis(A);
        } else {
            throw runtime_error("Netinkama ivestis!");
        }

        return 0;
    } catch (exception &e) {
        cout << "Klaida: " << e.what() << endl;
        return 1;
    }
}

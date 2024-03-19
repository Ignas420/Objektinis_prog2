#include "mokinys.h"
#include "funkcijos.h"

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
            } else if (input2 == 'g') {
                // Code for generating data
            } else {
                throw runtime_error("Netinkama ivestis!");
            }
        } else if (input == 's') {
            string failas;
            int temp;

            cout << "Ar norite generuoti naujus failus?(t/n) " << endl;
            cin >> input3;

            if (input3 == 't') {
                GeneruotiFailus(Nuskriaustieji, Mokslinciai, IrasuSk, A);
            } else if (input3 == 'n') {
                int kint5;
                cout << "Iveskite failu skaiciu: " << endl;
                cin >> kint5;

                for (int i = 0; i < kint5; ++i) {
                    string filename = "failas" + to_string(i) + ".txt";
                    Skaitymas(Nuskriaustieji, Mokslinciai, IrasuSk, filename, A, i);
                }
            } else {
                throw runtime_error("Netinkama ivestis!");
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

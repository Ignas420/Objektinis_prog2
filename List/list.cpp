#include "mokinys.h"
#include "funkcijos.h"

int main() {
    try {
        int n, m;
        std::list<int> IrasuSk = {1000, 10000, 100000, 1000000, 10000000};
        std::list<Mokinys> A;
        std::list<Mokinys> Mokslinciai;
        std::list<Mokinys> Nuskriaustieji;
        char input, input2, input3;

        std::cout << "Norite ivesti ar skaityti is failo?(i/s) " << std::endl;
        std::cin >> input;

        if (input == 'i') {
            std::cout << "Norite ivesti ranka ar generuoti skaicius?(i/g) " << std::endl;
            std::cin >> input2;

            if (input2 == 'i') {
                std::cout << "Irasykite kiek yra mokiniu: ";
                std::cin >> m;

                if (std::cin.fail()) {
                    throw std::runtime_error("Kiekis turi buti skaicius!");
                }

                std::cout << "Iveskite vardus ir pavardes: " << std::endl;

                for (int i = 0; i < m; ++i) {
                    Mokinys temp;
                    std::cin >> temp.vardas >> temp.pavarde;

                    if (!Patikrinimas(temp.vardas) || !Patikrinimas(temp.pavarde)) {
                        throw std::runtime_error("Ivestas netinkamas vardas arba pavarde!");
                    }

                    A.push_back(temp);
                }

                std::cout << "Irasykite namu darbu kieki: " << std::endl;
                std::cin >> n;

                for (auto& it : A) {
                    std::cout << "Irasykite namu darbu pazymius: " << std::endl;

                    for (int j = 0; j < n; ++j) {
                        int pazymys;
                        std::cin >> pazymys;

                        it.ND.push_back(pazymys);

                        if (std::cin.fail() || pazymys < 1 || pazymys > 10) {
                            throw std::runtime_error("Namu darbai turi buti skaicius nuo 1 iki 10!");
                        }
                    }

                    std::cout << "Irasykite egzamino rezultata: " << std::endl;
                    std::cin >> it.egzaminas;

                    if (std::cin.fail() || it.egzaminas < 1 || it.egzaminas > 10) {
                        throw std::runtime_error("Egzamino rezultatas turi buti skaicius nuo 1 iki 10!");
                    }

                    Vidurkis(A);

                    std::list<int> temp = it.ND;
                    temp.push_back(it.egzaminas);
                    temp.sort();

                    double median = *std::next(temp.begin(), temp.size() / 2);

                    if (temp.size() % 2 == 0) {
                        median = (*std::next(temp.begin(), temp.size() / 2 - 1) + *std::next(temp.begin(), temp.size() / 2)) / 2.0;
                    }

                    it.MED = median;
                }
                Isvedimas(A, A.size(), CRfv);
            } else if (input2 == 'g') {
                std::cout << "Irasykite kiek yra mokiniu: ";
                std::cin >> m;
                if (std::cin.fail()) {
                    throw std::runtime_error("Kiekis turi buti skaicius!");
                }

                std::cout << "Iveskite vardus ir pavardes: " << std::endl;
                int kint = m;
                Mokinys temp;
                while (m != 0) {
                    std::cin >> temp.vardas >> temp.pavarde;
                    if (!Patikrinimas(temp.vardas) || !Patikrinimas(temp.pavarde)) {
                        throw std::runtime_error("Ivestas netinkamas vardas arba pavarde!");
                    }
                    A.push_back(temp);
                    m--;
                }

                std::cout << "Irasykite namu darbu kieki: " << std::endl;
                std::cin >> n;
                kint = n;
                std::cout << "Generuojami pazymiai..." << std::endl;

                for (auto& student : A) {
                    for (int j = 0; j < n; j++) {
                        int pazymys = (rand() % 10) + 1;
                        student.ND.push_back(pazymys);
                        if (std::cin.fail()) {
                            throw std::runtime_error("Namu darbai turi buti skaicius!");
                        }
                        if (pazymys < 1 || pazymys > 10) {
                            throw std::runtime_error("Pazymys turi buti desimtbaleje sistemoje!");
                        }
                    }

                    student.egzaminas = (rand() % 10) + 1;
                    if (std::cin.fail()) {
                        throw std::runtime_error("Pazymys turi buti skaicius!");
                    }
                    if (student.egzaminas < 1 || student.egzaminas > 10) {
                        throw std::runtime_error("Pazymys turi buti desimtbaleje sistemoje!");
                    }
                    Vidurkis(A);
                    student.ND.sort();
                    std::list<int> temp = student.ND;
                    temp.push_back(student.egzaminas);
                    temp.sort();
                    double median = 0.0;
                    auto it = std::next(temp.begin(), temp.size() / 2);
                    if (temp.size() % 2 == 0) {
                        auto it2 = std::prev(it);
                        median = (*it + *it2) / 2.0;
                    } else {
                        median = *it;
                    }
                    student.MED = median;
                }
                Isvedimas(A, A.size(), CRfv);
            }
        } else if (input == 's') {
            std::string failas;
            int temp;

            std::cout << "Ar norite generuoti naujus failus?(t/n) " << std::endl;
            std::cin >> input3;

            if (input3 == 't') {
                GeneruotiFailus(Nuskriaustieji, Mokslinciai, IrasuSk, A);
            } else if (input3 == 'n') {
                int kint5;
                std::cout << "Iveskite failu skaiciu: " << std::endl;
                std::cin >> kint5;

                for (int i = 0; i < kint5; ++i) {
                    std::string filename = "failas" + std::to_string(i) + ".txt";
                    Skaitymas(Nuskriaustieji, Mokslinciai, IrasuSk, filename, A, i);
                }
            } else {
                throw std::runtime_error("Netinkama ivestis!");
            }

            Vidurkis(A);
        } else {
            throw std::runtime_error("Netinkama ivestis!");
        }

        return 0;
    } catch (std::exception &e) {
        std::cout << "Klaida: " << e.what() << std::endl;
        return 1;
    }
}

Konteinerių testavimas v1.0

Programos naudojimas:

Paleidziama programa su komandomis: g++ -o programa vektoriai.cpp/list.cpp/deque.cpp mokinys.cpp/mokinys1.cpp/mokinys2.cpp ir ./programa

Vos paleidus programa atsiras pasirinkimas ar norime ivesti duomenis ar skaityti is failo

1. Jei bus pasirenkamas duomenu ivedimas, bus reikalaujama pasirinkti ar norima ivesti/generuoti duomenis
1.1 Ar vienu, ar kitu budu reikes ivesti studentu vardus ir pavardes, toliau reikes ivesti studentu namu darbu ir egzamino pazymius
1.2 Jei bus pasirinktas duomenu generavimas, po vardu ir pavardziu irasymo nieko daryti nebereikes
1.3 Galiausiai reikes pasirinkti kur norime matyti duomenis ekrane ar faile
2. Jei pacioje pradzioje bus pasirinktas skaitymas, jusu bus klausiama ar norite generuoti naujus failus, ar tik skaityti
(SVARBU! Jei pasirenkate tik skaityma - tai reiskia, kad failus jau turite ir reikes irasyti failu kieki!) 
2.1 Irasius failu kieki, jie bus nuskaitomi, isvedami apytiksliai testavimu laikai ekrane bei sukuriami nauji failai, kuriuose yra surusiuoti studentai pagal vidurki (nuskriaustieji/mokslinciai)
2.2 Jei buvo pasirinktas nauju failu generavimas, bus sukurti visiskai nauji failai, pagal jusu pateiktas reiksmes vector/list/deque "IrasuSk"
2.3 Galiausiai, kaip ir anksciau, bus isvedami apytiksliai testavimu laikai ekrane bei sukuriami nauji failai, kuriuose yra surusiuoti studentai pagal vidurki (nuskriaustieji/mokslinciai)

Sistemos parametrai:
![image](https://github.com/Ignas420/Objektinis_prog/assets/145566919/d13edf9e-5d6e-4c45-a3ac-88abff2b612c)
![image](https://github.com/Ignas420/Objektinis_prog/assets/145566919/2a6e6423-bb80-42e7-9fbe-671f7b0e0958)

Testavimo rezultatai:

Programos veikimas su:

Vector

![image](https://github.com/Ignas420/Objektinis_prog/assets/145566919/cee5cf10-24ea-44e1-b33b-6276ee954ec8)

std::vector yra sparciausiai veikiantis, remiantis testavimo rezultatais, jis yra prieinamas per konkretu prieigos mechanizma, be jokio papildomo strukturizavimo ar sudetingumo bei turi galimybe greitai prieiti prie visu arba tam tikru duomenu elementu, tiesiogiai ir efektyviai juos pasiekiant

List

![image](https://github.com/Ignas420/Objektinis_prog/assets/145566919/92726075-9cd0-472b-a562-1cae7c1f042a)

std::list, pagal testavimo rezultatus, veike leciau, tai galejo lemti tai, kad sis sarasas yra su rodyklemis, o tai reiskia, kad reikejo iteruoti per visa sarasa, norint pasiekti tam tikrus elementus

Deque

![image](https://github.com/Ignas420/Objektinis_prog/assets/145566919/9ec26d2b-8477-4729-aa87-8849ed6ef9ae)

std::deque, mano gautais rezultatais, uztruko ilgiausiai, nors sis sarasas ir suteikia mums greita prieeiga prie pradzios ir pabaigos, elementu prieiga nera tiesiogine - reikia keliauti per keliu masyvu sarasa


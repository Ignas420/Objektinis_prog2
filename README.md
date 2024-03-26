Konteinerių testavimas v1.0

Makefile set-up:
Makefile idiegimas naudojant Chocolatey (Windows)

Isitikinkite, kad turite Chocolatey idiegima: patikrinkite, ar jusu kompiuteryje yra idiegta Chocolatey. Jei ne, idiekite pagal instrukcijas.

Idiekite Makefile: atidarykite PowerShell kaip administratorius ir ivykdykite sia komanda:

choco install make

Patikrinkite idiegima: patikrinkite, ar Makefile sekmingai idiegtas, vykdydami komanda:

make --version

Jei viskas sekminga, turetumete pamatyti Make versijos informacija

Makefile idiegimas naudojant kitus metodus
MacOS: Makefile iprastai yra idiegtas standartinėje MacOS distribucijoje, todel papildomu veiksmu paprastai nereikia

Linux: Daugumoje Linux distribuciju Makefile taip pat yra idiegtas is anksto. Jei reikia, naudokite savo paketu tvarkykle, pvz., apt-get, yum, dnf, arba kita pagal distribucija

Windows (be Chocolatey): Noredami idiegti Makefile Windows sistemoje be Chocolatey, galite naudoti rankinius idiegimo failus, kuriuos galite rasti internete. Paprastai tie failai turi .exe pletini ir gali buti lengvai idiegti, sekdamie pridedamas instrukcijas



Programos naudojimas veikimo metu:

Paleidziama programa su komandomis: g++ -o programa vektoriai.cpp/list.cpp/deque.cpp mokinys.cpp/mokinys1.cpp/mokinys2.cpp ir ./programa

Vos paleidus programa atsiras pasirinkimas ar norime ivesti duomenis ar skaityti is failo

1. Jei bus pasirenkamas duomenu ivedimas, bus reikalaujama pasirinkti ar norima ivesti/generuoti duomenis
   
1.1 Ar vienu, ar kitu budu reikes ivesti studentu vardus ir pavardes, toliau reikes ivesti studentu namu darbu ir egzamino pazymius

1.2 Jei bus pasirinktas duomenu generavimas, po vardu ir pavardziu irasymo nieko daryti nebereikes

1.3 Galiausiai reikes pasirinkti kur norime matyti duomenis ekrane ar faile

2. Jei pacioje pradzioje bus pasirinktas skaitymas, jusu bus klausiama ar norite generuoti naujus failus, jei ivesite 't'(taip), bus generuojami nauji failai, jei ivesite bet koki kita simboli, programa veiks toliau

2.1 Toliau, jusu bus klausiama ar norite skaityti naujai sukurtus failus, ar jau turimus

2.2 Bus prasoma ivesti, pasirinktinai, turimu/nauju failu kieki, jie bus nuskaitomi, isvedami apytiksliai testavimu laikai ekrane bei sukuriami nauji failai, kuriuose yra surusiuoti studentai pagal vidurki (nuskriaustieji/mokslinciai)

2.3 Galiausiai, kaip ir anksciau, bus isvedami apytiksliai testavimu laikai ekrane bei sukuriami nauji failai, kuriuose yra surusiuoti studentai pagal vidurki (nuskriaustieji/mokslinciai)

Sistemos specifikacijos:




Testavimas su 1000, 10000, 100000, 1000000, 10000000 failais, naudojant 1-aja strategija:

Vektoriai:

![image](https://github.com/Ignas420/Objektinis_prog/assets/145566919/380a1e9f-6b7c-4dc9-8e7c-d06c4ad20110)

List:

![image](https://github.com/Ignas420/Objektinis_prog/assets/145566919/aae8a168-7f04-4a31-ae12-b957508036b1)

Deque:

![image](https://github.com/Ignas420/Objektinis_prog/assets/145566919/a1045c58-0f1e-4814-9e11-175733a95ecc)


Testavimas su 1000, 10000, 100000, 1000000, 10000000 failais, naudojant 2-aja strategija:

Vektoriai:

![image](https://github.com/Ignas420/Objektinis_prog/assets/145566919/f96801b5-d68c-4f77-a380-fac2e279b547)

List:

![image](https://github.com/Ignas420/Objektinis_prog/assets/145566919/763aabc1-f66a-4953-8381-8c08dda67b88)

Deque:

![image](https://github.com/Ignas420/Objektinis_prog/assets/145566919/b69b15d0-0d41-43f6-9b6e-31be419c385f)

Is rezultatu matoma, kad vektoriai gerokai pranoksta list ir deque konteinerius. List konteineriai 2 kartus pagreiteja kai yra naudojama 1-oji strategija, o deque taip pat 2 kartus pagreiteja kai yra naudojama 2-oji strategija. Nors funkcijos atliekamos su vector konteineriu yra greiciausios, taciau is rezultatu yra matoma, kad su sio tipo konteineriais efektyviau yra naudoti 2-aja strategija. 

Kalbant apie skaiciavimo efektyvuma, vektoriai pranoksta list<> ir deque<> konteinerius del savo gretimos atminties paskirstymo, suteikdami greitesne prieiga prie elementu. Sarasai, nors ir siek tiek letesni, taip siulo vidutiniskai greita prieiga naudojant 1-aja strategija, palyginus su deque<> tipo konteineriais, jie igyvendinami kaip kintancio dydzio masyvai. Deque<> konteineriai yra optimizuoti efektyviam iterpimui ir istrynimui abiejuose duomenu saraso galuose, gali sukelti pertekline apkrova atsitiktinei prieigai, todel jie gali būti letesni tam tikrose operacijose.

Testavimo laikai, naudojant modifikuota 2-aja strategija su naujais algoritmais, vector<> konteineriais:

![image](https://github.com/Ignas420/Objektinis_prog/assets/145566919/8c6ec94a-22d1-4a99-a014-63680a117220)

Vidutiniu laiku skaiciavimas:

| Struktūra | Nuskaitymo vidurkis (s) | Rusiavimo didejimo tvarka vidurkis (s) | Studentu skirstymo vidurkis (s) | Visu programu veikimo vidurkis (s) |
|-----------|--------------------------|----------------------------------------|----------------------------------|--------------------------------------|
| Vektoriai | 12.311508784             | 5.023293878                            | 0.153422888                      | 17.4743382                           |
| List      | 22.25321922              | 3.93077876                             | 33.29937836                      | 79.450743226                         |
| Deque     | 13.75983258              | 24.96002994                            | 70.9988333                       | 119.66582334                         |

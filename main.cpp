#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <list>
#include <cmath>

using namespace std;

    string temphelyezes, tempember, sporttag, verseny, vonal, ltsporttag, ltsverseny;
    ifstream helsinki;
    ofstream helsinki2;

    int osszitem, listhelyezes, helyezes, osszehlyezes, arany, ezüst, bronz, osszerem, pontok, ember, legtobbsportoló, ltshelyezes, ltsemberek, kajakkenu, vivas, torna, uszas, atletika, kosarlabda, vizilabda, gerenda, legtobbsport, sorpontok;


    list<int> helyezesek;
    list<int> emberek;

void negyedik()
{

           if (helyezesek.back() == 1) {
                arany++;
                pontok = pontok + 7;
                sorpontok = 7;
            }
            if (helyezesek.back() == 2) {
                ezüst++;
                pontok = pontok + 5;
                sorpontok = 5;
            }
            if (helyezesek.back() == 3) {
                bronz++;
                pontok = pontok + 4;
                sorpontok = 4;
            }
            if (helyezesek.back() == 4) {
                pontok = pontok + 3;
                sorpontok = 3;
            }
            if (helyezesek.back() == 5) {
                pontok = pontok + 2;
                sorpontok = 2;
            }
            if (helyezesek.back() == 6) {
                pontok = pontok + 1;
                sorpontok = 1;
            }
            if (helyezesek.back() < 4) {
                if (sporttag == "kajakkenu") {
                    kajakkenu++;
                }
                if (sporttag == "vivas") {
                    vivas++;
                }
                if (sporttag == "torna") {
                    torna++;
                }
                if (sporttag == "uszas") {
                    uszas++;
                }
                if (sporttag == "atletika") {
                    atletika++;
                }
                if (sporttag == "kosarlabda") {
                    kosarlabda++;
                }
                if (sporttag == "vizilabda") {
                    vizilabda++;
                }
                if (sporttag == "gerenda") {
                    gerenda++;
                }


            }
            osszerem = arany + ezüst + bronz;

}
void hatodik()
{
    if(helsinki2.is_open())
            {
                if(sporttag == "kajakkenu")
                {
                    sporttag = "kajak-kenu";
                }
                helsinki2 << "helyezes: " << helyezes << ", ember: " << ember << ", pontok: " << sorpontok << ", sportag: " << sporttag << ", verseny: " << verseny << endl;
            }
            else
            {
                cout << "Nem sikerült megyitni a helsinki2.txt-t" << endl;
            }

}

void hetedik()
{
    if (ember > legtobbsportoló)
            {
                legtobbsportoló = ember;
                ltshelyezes = helyezes;
                ltsporttag = sporttag;
                ltsverseny = verseny;
                ltsemberek = ember;
            }
}
int main() {
    helsinki.open("helsinki.txt");
    helsinki2.open(("helsinki2.txt"));
    if (helsinki.is_open()) {
        //masodik feladat
        while (getline(helsinki, vonal)) {
            stringstream ss(vonal);
            getline(ss, temphelyezes, ' ');
            helyezes = stoi(temphelyezes);
            helyezesek.push_back(helyezes);
            getline(ss, tempember, ' ');
            ember = stoi(tempember);
            emberek.push_back(ember);
            getline(ss, sporttag, ' ');
            getline(ss, verseny, ' ');

            //harmadik feladat
            //negyedik feladat
            negyedik();
            //hatodik feladat
            hatodik();
            //hetedik feladat
            hetedik();

        }
    }
    else
    {
        cout << "Nem sikerult megyitni a helsinki.txt-t" << endl;
    }

        //KIIRÁSOK
        //harmadik feladat ha jól ertelmezem akkor minden sportolónak szamít a helyezese
        cout << "3. feladat: " << endl;
        cout << "ennyi helyezest ertek el: " << helyezesek.size() << endl << endl;
        //negyedik feladat
        cout << "4. feladat: " << endl;
        cout << "ennyi arany ermet szereztek: " << arany << endl;
        cout << "ennyi ezust ermet szereztek: " << ezüst << endl;
        cout << "ennyi bronz ermet szereztek: " << bronz << endl;
        cout << "ennyi ossz ermet szereztek: " << osszerem << endl << endl;

        //otodik feladat
        cout << "5. feladat: " << endl;
        cout << "osszesen ennyi pontot szereztek: " << pontok << endl << endl;

        //hatodik feladat
        legtobbsport = max(kajakkenu,
                           max(vivas, max(torna, max(uszas, max(atletika, max(kosarlabda, max(vizilabda, gerenda)))))));
        cout << "6. feladat: " << endl;
        if (legtobbsport == kajakkenu) {
            cout << "A kajakkenu sporttagban szereztek a legtobb ermet." << endl;
        }
        if (legtobbsport == vivas) {
            cout << "A vivas sporttagban szereztek a legtobb ermet." << endl;
        }
        if (legtobbsport == torna) {
            cout << "A torna sporttagban szereztek a legtobb ermet." << endl;
        }
        if (legtobbsport == uszas) {
            cout << "A uszas sporttagban szereztek a legtobb ermet." << endl;
        }
        if (legtobbsport == atletika) {
            cout << "A atletika sporttagban szereztek a legtobb ermet." << endl;
        }
        if (legtobbsport == kosarlabda) {
            cout << "A kosarlabda sporttagban szereztek a legtobb ermet." << endl;
        }
        if (legtobbsport == vizilabda) {
            cout << "A vizilabda sporttagban szereztek a legtobb ermet." << endl;
        }
        if (legtobbsport == gerenda) {
            cout << "A gerenda sporttagban szereztek a legtobb ermet." << endl;
        }
        cout << endl;

        //nyolcadik feladat
        cout << "8. feladat:" << endl;
        cout << "Helyezes: " << ltshelyezes << endl;
        cout << "Sportag: " << ltsporttag << endl;
        cout << "Versenyszam: " << ltsverseny << endl;
        cout << "Sportolok szama: " << ltsemberek << endl;

        helsinki2.close();
        helsinki.close();

        return 0;
    }

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

    list<int> helyezeseklist;
    list<int> embereklist;
    list<string> sporttaglist;
    list<string> versenylist;



void negyedik()
{
    switch(helyezeseklist.back()) {
        case 1:
            arany++;
            pontok = pontok + 7;
            sorpontok = 7;
            break;
        case 2:
            ezüst++;

            break;
        case 3:
            bronz++;

            break;
    }
    if(helyezeseklist.back() < 4) {
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
                osszerem = arany + ezüst + bronz;
            }
}
void otodik()
{

    switch(helyezeseklist.back())
            {
                case 1:
                    pontok = pontok + 7;
                    sorpontok = 7;
                    break;
                case 2:
                    pontok = pontok + 5;
                    sorpontok = 5;
                    break;
                case 3:
                    pontok = pontok + 4;
                    sorpontok = 4;
                    break;
                case 4:
                    pontok = pontok + 3;
                    sorpontok = 3;
                    break;
                case 5:
                    pontok = pontok + 2;
                    sorpontok = 2;
                    break;
                case 6:
                    pontok = pontok + 1;
                    sorpontok = 1;
                    break;
            }
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
    if (embereklist.back() > legtobbsportoló)
            {
                legtobbsportoló = embereklist.back();
                ltshelyezes = helyezes;
                ltsporttag = sporttag;
                ltsverseny = verseny;
                ltsemberek = embereklist.back();
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
            helyezeseklist.push_back(helyezes);
            getline(ss, tempember, ' ');
            ember = stoi(tempember);
            embereklist.push_back(ember);
            getline(ss, sporttag, ' ');
            sporttaglist.push_back(sporttag);
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
        cout << "ennyi helyezest ertek el: " << helyezeseklist.size() << endl << endl;
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

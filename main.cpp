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

    struct{
    list<int> helyezeseklist;
    list<int> embereklist;
    list<string> sporttaglist;
    list<string> versenylist;
    }helsinkistruct;


void masodik()
{
    while (getline(helsinki, vonal))
    {
        stringstream ss(vonal);
        getline(ss, temphelyezes, ' ');
        helyezes = stoi(temphelyezes);
        helsinkistruct.helyezeseklist.push_back(helyezes);
        getline(ss, tempember, ' ');
        ember = stoi(tempember);
        helsinkistruct.embereklist.push_back(ember);
        getline(ss, sporttag, ' ');
        helsinkistruct.sporttaglist.push_back(sporttag);
        getline(ss, verseny, ' ');
    }
}
void harmadik()
{
    cout << "3. feladat: " << endl;
    cout << "ennyi helyezest ertek el: " << helsinkistruct.helyezeseklist.size() << endl << endl;
}
void negyedik()
{
    switch(helsinkistruct.helyezeseklist.back())
    {
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
    if(helsinkistruct.helyezeseklist.back() < 4) {
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
    cout << "4. feladat: " << endl;
    cout << "ennyi arany ermet szereztek: " << arany << endl;
    cout << "ennyi ezust ermet szereztek: " << ezüst << endl;
    cout << "ennyi bronz ermet szereztek: " << bronz << endl;
    cout << "ennyi ossz ermet szereztek: " << osszerem << endl << endl;
}
void otodik()
{
    switch(helsinkistruct.helyezeseklist.back())
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

            cout << "5. feladat: " << endl;
            cout << "osszesen ennyi pontot szereztek: " << pontok << endl << endl;
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

                    legtobbsport = max(kajakkenu,max(vivas, max(torna, max(uszas, max(atletika, max(kosarlabda, max(vizilabda, gerenda)))))));
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
}

void hetedik()
{
    if (helsinkistruct.embereklist.back() > legtobbsportoló)
            {
                legtobbsportoló = helsinkistruct.embereklist.back();
                ltshelyezes = helyezes;
                ltsporttag = sporttag;
                ltsverseny = verseny;
                ltsemberek = helsinkistruct.embereklist.back();
            }
}


void nyolcadik()
{

        cout << "8. feladat:" << endl;
        cout << "Helyezes: " << ltshelyezes << endl;
        cout << "Sportag: " << ltsporttag << endl;
        cout << "Versenyszam: " << ltsverseny << endl;
        cout << "Sportolok szama: " << ltsemberek << endl;

        helsinki2.close();
        helsinki.close();
}
int main() {
    helsinki.open("helsinki.txt");
    helsinki2.open(("helsinki2.txt"));


    harmadik();
    negyedik();
    otodik();
    hatodik();
    hetedik();
    nyolcadik();

    return 0;
}

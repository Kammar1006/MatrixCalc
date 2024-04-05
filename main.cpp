#include <iostream>
#include <cmath>
#include <fstream>
#include <ctime> //rand
#include <cstdlib> //rand & sys cls
#include <vector>
#include <conio.h> //getch
#include "my_matrix.h"
#include <list>
using namespace std;

void pressKey(){
    cout<<"Press any key to continue."<<endl;
    int a = getch();
}


vector<double> T_0(4, 0);
my_matrix matrixBase(2, 2, T_0);
int matrix_it = 0;
list <my_matrix> matrixDB;

list<my_matrix>::iterator ii, jj;

int n, r, c;
vector<double>T1;
vector<double>T2;
vector<double>T3;
int Td[6]={0};


//Settings:
int rand_a=0, rand_b=4;
int gsF_clearing  = 1;
//bool gsF_showMatrix = true;
int gsF_showCalc = 0;
int gsF_searchByName=0;

bool findByName(){
    string b;
    if(gsF_searchByName){
        cout<<"Enter Matrix Name: "; cin>>b;
        for(ii=matrixDB.begin(); ii!=matrixDB.end();ii++){
            if(ii->name==b) return true;
        }
        cout<<"Error bad name!"<<endl;
        return false;
    }
    return false;
}

void gsF_menu(){
    int n;
    cout<<"Global Settings"<<endl;
    cout<<"1. rng values: "<<rand_a<<" - "<<rand_b<<endl;
    cout<<"2. clearing console: "<<gsF_clearing<<endl;
    cout<<"3. show calc: "<<gsF_showCalc<<endl;
    cout<<"4. search by name (show & change & delete): "<<gsF_searchByName<<endl;
    cout<<">>"; cin>>n;
    switch(n){
        case 1:{
            cout<<"Enter min rng value: "; cin>>rand_a;
            cout<<"Enter max rng value: "; cin>>rand_b;
            if(rand_a>rand_b) swap(rand_a, rand_b);
        }break;
        case 2:{
            cout<<"Change 'clearing console' option (0/1): "; cin>>gsF_clearing;
        }break;
        case 3:{
            cout<<"Change 'show calc' option (0/1): "; cin>>gsF_showCalc;
        }break;
        case 4:{
            cout<<"Change 'search by name' option (0/1): "; cin>>gsF_searchByName;
        }
    }
}

int show_menu(){

    if(gsF_clearing) system("cls");
    //cout<<matrixDB.max_size()<<endl;
    cout << "Matrix Calc v2" << endl;
    cout<<" Menu "<<endl;
    cout<<"1. Add Matrix: "<<endl;
    cout<<"2. Show Matrix: "<<endl;
    cout<<"3. Show All Matrix: "<<endl;
    cout<<"4. A+B "<<endl;
    cout<<"5. A-B "<<endl;
    cout<<"6. s*A"<<endl;
    cout<<"7. A*B"<<endl;
    cout<<"8. det(A) [19.11]"<<endl;
    cout<<"9. A^T"<<endl;
    cout<<"10. A^-1 [1.12]"<<endl;
    cout<<"11. A^n [5.12]"<<endl;
    cout<<"12. Triangle A [Soon]"<<endl;
    cout<<"13. [Soon]"<<endl;
    cout<<"14. Save (file)[11.12]"<<endl;
    cout<<"15. Load (file)[11.12]"<<endl;
    cout<<"16. Change Matrix [11.12]"<<endl;
    cout<<"17. Delete Matrix [11.12]"<<endl;
    cout<<"18. Settings [11.12]"<<endl;
    cout<<"19. Exit()"<<endl;
    cout<<">>"; cin>>n;
    if(gsF_clearing) system("cls");
    switch(n){
        case 1:{
            cout<<"Add New Matrix"<<endl;
            cout<<"row>>"; cin>>r;
            cout<<"column>>"; cin>>c;
            cout<<"1. Generate Numbers (rng: "<<rand_a<<" - "<<rand_b<<")"<<endl;
            cout<<"2. Enter Numbers"<<endl;
            cout<<">>"; cin>>n;
            T1.clear();
            if(n==1){
                for(int i=0; i<r; i++){
                    for(int j=0; j<c; j++){
                        //int wsk = i*c+j;
                        T1.push_back(rand()%(rand_b-rand_a+1)+rand_a);
                        //cout<<T1.size()<<" "<<T1[wsk]<<endl;
                    }
                }
                matrixBase.create_matrix(r, c, T1, "1");
                matrixBase.chId(matrixDB.size()+1);
                matrixDB.push_back(matrixBase);
                cout<<"Create Matrix No "<<matrixDB.size()<<endl;
            }
            else if(n==2){
                double a;
                for(int i=0; i<r; i++){
                    for(int j=0; j<c; j++){
                        cout<<"Enter "<<i+1<<" "<<j+1<<" number: "; cin>>a;
                        T1.push_back(a);
                    }
                }
                matrixBase.create_matrix(r, c, T1, "1");
                matrixBase.chId(matrixDB.size()+1);
                matrixDB.push_back(matrixBase);
                cout<<"Create Matrix No "<<matrixDB.size()<<endl;
            }
        };  break;
        /*case 2:{
            cout<<"Show Matrix"<<endl;
            int a;
            cout<<"Enter Matrix ID/No: "; cin>>a;
            ii = matrixDB.begin();
            advance(ii, a-1);
            ii->chMatrix(0); //better show
        };  break;*/
        case 2:{
            cout<<"Show Matrix"<<endl;
            int a;
            if(findByName()) ii->chMatrix(0);
            else{
                cout<<"Enter Matrix ID/No: "; cin>>a;
                ii = matrixDB.begin();
                advance(ii, a-1);
                ii->chMatrix(0); //better show
            }
        };  break;
        case 3:{
            cout<<"Show Matrix"<<endl;

            for(list <my_matrix>::iterator i=matrixDB.begin();i!=matrixDB.end();++i){
                i->show();
            }

            cout<<endl;
        };  break;

        case 4:{
            int a, b;
            cout<<"A + B = C"<<endl;
            cout<<"Enter Matrix A ID/No: "; cin>>a;
            cout<<"Enter Matrix B ID/No: "; cin>>b;
            //my_math_sum_matrix(matrixDB[--a], matrixDB[--b], &matrixDB[--c]);
            ii = matrixDB.begin();
            jj = matrixDB.begin();
            advance(ii, a-1);
            advance(jj, b-1);
            if(my_math_sum_matrix(*ii, *jj, &matrixBase, gsF_showCalc)){
                matrixBase.chId(matrixDB.size()+1);
                matrixDB.push_back(matrixBase);
                cout<<"Create Matrix No "<<matrixDB.size()<<endl;
            }


        }; break;

        case 5:{
            int a, b;
            cout<<"A - B = C"<<endl;
            cout<<"Enter Matrix A ID/No: "; cin>>a;
            cout<<"Enter Matrix B ID/No: "; cin>>b;
            //my_math_difference_matrix(matrixDB[--a], matrixDB[--b], &matrixDB[--c]);
            ii = matrixDB.begin();
            jj = matrixDB.begin();
            advance(ii, a-1);
            advance(jj, b-1);
            if(my_math_difference_matrix(*ii, *jj, &matrixBase, gsF_showCalc)){
                matrixBase.chId(matrixDB.size()+1);
                matrixDB.push_back(matrixBase);
                cout<<"Create Matrix No "<<matrixDB.size()<<endl;
            }
        }; break;

        case 6:{
            int a;
            double s;
            cout<<"A * s = C"<<endl;
            cout<<"Enter Matrix A ID/No: "; cin>>a;
            cout<<"Enter scalar: "; cin>>s;
            //my_math_scalar_matrix(matrixDB[--a], s, &matrixDB[--c]);
            ii = matrixDB.begin();
            advance(ii, a-1);
            my_math_scalar_matrix(*ii, s, &matrixBase, gsF_showCalc);
            matrixBase.chId(matrixDB.size()+1);
            matrixDB.push_back(matrixBase);
            cout<<"Create Matrix No "<<matrixDB.size()<<endl;
        }; break;

        case 7:{
            int a, b;
            cout<<"A * B = C"<<endl;
            cout<<"Enter Matrix A ID/No: "; cin>>a;
            cout<<"Enter Matrix B ID/No: "; cin>>b;
            //my_math_product_matrix(matrixDB[--a], matrixDB[--b], &matrixDB[--c]);
            ii = matrixDB.begin();
            jj = matrixDB.begin();
            advance(ii, a-1);
            advance(jj, b-1);
            if(my_math_product_matrix(*ii, *jj, &matrixBase, gsF_showCalc)){
                matrixBase.chId(matrixDB.size()+1);
                matrixDB.push_back(matrixBase);
                cout<<"Create Matrix No "<<matrixDB.size()<<endl;
            }
        }; break;

        case 8:{
            int a;
            cout<<"det(A)"<<endl;
            cout<<"Enter Matrix A ID/No: "; cin>>a;
            ii = matrixDB.begin();
            advance(ii, a-1);
            cout<<"det(A) = "<<my_math_det_matrix(*ii, gsF_showCalc)<<endl;
        }; break;

        case 9:{
            int a;
            cout<<"A^T = B"<<endl;
            cout<<"Enter Matrix A ID/No: "; cin>>a;
            //my_math_transposition_matrix(matrixDB[--a], &matrixDB[--b]);
            ii = matrixDB.begin();
            advance(ii, a-1);
            my_math_transposition_matrix(*ii, &matrixBase);
            matrixBase.chId(matrixDB.size()+1);
            matrixDB.push_back(matrixBase);
            cout<<"Create Matrix No "<<matrixDB.size()<<endl;
        }; break;

        case 10:{
            int a;
            cout<<"A^-1 = B"<<endl;
            cout<<"Enter Matrix A ID/No: "; cin>>a;
            ii = matrixDB.begin();
            advance(ii, a-1);
            if(my_math_reverse_matrix(*ii, &matrixBase, gsF_showCalc)){
                matrixBase.chId(matrixDB.size()+1);
                matrixDB.push_back(matrixBase);
                cout<<"Create Matrix No "<<matrixDB.size()<<endl;
            }
            //if(c) my_math_reverse_matrix(matrixDB[--a], &matrixDB[--b], true);
            //else my_math_reverse_matrix(matrixDB[--a], &matrixDB[--b], false);

        }; break;

        case 11:{
            int a, c;
            cout<<"A^n = B"<<endl;
            cout<<"Enter Matrix A ID/No: "; cin>>a;
            cout<<"Enter n: "; cin>>c;
            ii = matrixDB.begin();
            advance(ii, a-1);
            if(my_math_power_matrix(*ii, &matrixBase, c, gsF_showCalc)){
                matrixBase.chId(matrixDB.size()+1);
                matrixDB.push_back(matrixBase);
                cout<<"Create Matrix No "<<matrixDB.size()<<endl;
            }
        }break;

      /*case 12:{
            int a, b, c;
            //cout<<"Sum Matrix"<<endl;
            cout<<"sqrt(A) = B"<<endl;
            cout<<"Enter Matrix A ID/No: "; cin>>a;
            cout<<"Enter Matrix B ID/No: "; cin>>b;
            //cout<<"Enter n: "; cin>>c;
            my_math_sqrt_matrix(matrixDB[--a], &matrixDB[--b], 2);
        }break;*/

        case 12:{
            int a;
            cout<<"Triangle"<<endl;
            cout<<"Enter Matrix A ID/No: "; cin>>a;
            ii = matrixDB.begin();
            advance(ii, a-1);
            my_math_triangle_matrix(*ii, &matrixBase, gsF_showCalc);
            matrixBase.chId(matrixDB.size()+1);
            matrixDB.push_back(matrixBase);
            cout<<"Create Matrix No "<<matrixDB.size()<<endl;
        }break;

        case 14:{
            //SAVE
            cout<<"SAVE"<<endl;
            ofstream saveF("matrixDB.txt");
            saveF<<6<<" "; //Ignore line - settings (no first line)
            saveF<<0<<" "; //rand_a
            saveF<<4<<" "; //rand_b
            saveF<<gsF_clearing<<" "; //clearing console
            saveF<<gsF_showCalc<<" "; //show calc
            saveF<<matrixDB.size()<<endl; //no records
            saveF.close();
            for(list <my_matrix>::iterator i=matrixDB.begin();i!=matrixDB.end();++i){
                i->save();
            }
        }break;

        case 15:{
            //LOAD
            int a, r, c, id;
            vector <double> T;
            string name;
            cout<<"LOAD"<<endl;
            cout<<"Are you sure? - You lose running DB? (0/1): ";
            cin>>a;
            if(!a) break;


            ifstream loadF("matrixDB.txt");
            if(loadF.good()){
                matrixDB.clear();
                loadF>>a;
                if(a!=6){
                    loadF.close();
                    break;
                }
                loadF>>rand_a>>rand_b>>gsF_clearing>>gsF_showCalc>>a;
                for(int i=0; i<a; i++){
                    T.clear();
                    loadF>>name;
                    loadF>>id;
                    loadF>>r;
                    loadF>>c;
                    for(int j=0; j<r*c; j++){
                        loadF>>id;
                        T.push_back(id);
                    }
                    matrixBase.create_matrix(r, c, T, name);
                    matrixBase.chId(matrixDB.size()+1);
                    matrixDB.push_back(matrixBase);
                    cout<<"Load Matrix No "<<matrixDB.size()<<endl;
                }
            }
            loadF.close();
        }break;

        case 16:{

            int a;
            cout<<"Change Matrix"<<endl;
            if(findByName()==false){
                cout<<"Enter Matrix ID/No: "; cin>>a;
                ii = matrixDB.begin();
                advance(ii, a-1);
            }
            ii->chMatrix(1);

        }break;

        case 17:{
            int a;
            cout<<"DELETE Matrix"<<endl;
            cout<<"Are you sure? - You lose record DB (0/1)? "; cin>>a;
            if(!a) break;
            if(findByName()==false){
                cout<<"Enter Matrix ID/No: "; cin>>a;
                ii = matrixDB.begin();
                advance(ii, a-1);
            }
            matrixDB.erase(ii);
            ii = matrixDB.begin();
            advance(ii, a-1);
            for(list<my_matrix>::iterator aa=ii; aa!=matrixDB.end();aa++){
                aa->chId(a);
                a++;
            }
            cout<<"Delete object; Other object change your's id instantly."<<endl;
        }break;

        case 18:{
            gsF_menu();
        }break;

        case 19:{
            return 0;
        };  break;
    }
    pressKey();
    return 1;
}

int main()
{
    srand(time(NULL));
    while(show_menu());

    return 0;
}

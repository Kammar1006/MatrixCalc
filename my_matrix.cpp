#include <iostream>
#include <cmath>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include "my_matrix.h"

using namespace std;

string toString(int &i) {
    stringstream ss;
    ss << i;

    return ss.str();
}


my_matrix::create_matrix(int r, int c, vector<double>tab, string n){
    name = n;
    row = r;
    column = c;
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            if(T.size()==(i*c+j)) T.push_back(tab[i*c+j]);
            else T[i*c+j] = tab[i*c+j];
            //cout<<"-> "<<T[i*c+j]<<endl;
        }
    }
}

my_matrix::my_matrix(){
    vector<double> T_0(4, 0);
    id = 0;
    create_matrix(2, 2, T_0, "1");
}

my_matrix::my_matrix(int r, int c,  vector<double> &tab, string n){
    id = 0;
    create_matrix(r, c, tab, n);
}

my_matrix::show(){
    cout<<endl;
    for(int i = 0; i<row; i++){
        for(int j=0; j<column; j++){
            cout<<round(1000*(T[i*column+j]))/1000<<"\t";
        }
        cout<<endl;
    }
    cout<<endl;
}

my_matrix::save(){
    ofstream saveF("matrixDB.txt", ios::app);
    saveF<<name<<" "<<id<<endl;
    saveF<<row<<" "<<column<<endl;
    for(int i=0; i<row*column; i++){
        if(i%column==0 && i!=0) saveF<<endl;
        saveF<<T[i]<<" ";
    }
    saveF<<endl;
    saveF.close();
}

my_matrix::chId(int idF){
    id = idF;
    if(name=="1") name = "Matrix" + toString(idF);
}

my_matrix::chMatrix(int op){
    cout<<"id: "<<id<<endl;
    cout<<"name: "<<name<<endl;
    cout<<"row: "<<row<<endl;
    cout<<"column: "<<column<<endl;
    show();
    if(op){
        int b;
        cout<<"New name: "; cin>>name;
        cout<<"Change size & values (0/1)? "; cin>>b;
        if(b){
            cout<<"New size"<<endl;
            cout<<"Row: "; cin>>row;
            cout<<"Column: "; cin>>column;
            cout<<"New table: "<<endl;
            T.clear();
            double a;
            for(int i=0; i<row; i++){
                for(int j=0; j<column; j++){
                    cout<<"Enter "<<i+1<<" "<<j+1<<" number: "; cin>>a;
                    T.push_back(a);
                }
            }
        }
    }
}

int my_math_sum_matrix(my_matrix a, my_matrix b, my_matrix *c, bool showCalc){
    if(a.row == b.row && a.column == b.column){
        c->row = a.row;
        c->column = a.column;
        c->name = "1";
        c->T.clear();
        for(int i=0; i<a.row*a.column; i++){
            c->T.push_back(a.T[i]+b.T[i]);
            if(showCalc) cout<<c->T[i]<<" = "<<a.T[i]<<" + "<<b.T[i]<<endl;
        }
        return 1;
    }
    else{
        cout<<"Impossible to sum"<<endl;
        cout<<a.row<<"x"<<a.column<<" != "<<b.row<<"x"<<b.column<<endl;
        return 0;
    }
    //cout<<c->row<<"x"<<c->column<<" => "<<c->T[3]<<endl;
}

int my_math_difference_matrix(my_matrix a, my_matrix b, my_matrix *c, bool showCalc){
    if(a.row == b.row && a.column == b.column){
        c->row = a.row;
        c->column = a.column;
        c->name = "1";
        c->T.clear();
        for(int i=0; i<a.row*a.column; i++){
            c->T.push_back(a.T[i]-b.T[i]);
            if(showCalc) cout<<c->T[i]<<" = "<<a.T[i]<<" - "<<b.T[i]<<endl;
        }
        return 1;
    }
    else{
        cout<<"Impossible to difference"<<endl;
        cout<<a.row<<"x"<<a.column<<" != "<<b.row<<"x"<<b.column<<endl;
        return 0;
    }
    //cout<<c->row<<"x"<<c->column<<" => "<<c->T[3]<<endl;
}

void my_math_scalar_matrix(my_matrix a, double s, my_matrix *c, bool showCalc){
        c->row = a.row;
        c->column = a.column;
        c->name = "1";
        c->T.clear();
        for(int i=0; i<a.row*a.column; i++){
            c->T.push_back(a.T[i]*s);
            if(showCalc) cout<<c->T[i]<<" = "<<s<<" * "<<a.T[i]<<endl;
        }
}

void my_math_transposition_matrix(my_matrix a, my_matrix *c){
        c->row = a.column;
        c->column = a.row;
        c->name = "1";
        c->T.clear();
        for(int i=0; i<a.row*a.column; i++){
            c->T.push_back(0);
        }
        for(int i=0; i<a.row; i++){
            for(int j=0; j<a.column; j++){
                c->T[j*a.row+i] = a.T[i*a.column+j];
            }
        }
}

int my_math_product_matrix(my_matrix a, my_matrix b, my_matrix *c, bool showCalc){
    if(a.column == b.row){
        c->row = a.row;
        c->column = b.column;
        c->name = "1";
        c->T.clear();
        for(int i=0; i<c->row; i++){
            for(int j=0; j<c->column; j++){
                double s=0;
                if(showCalc) cout<<i+1<<" "<<j+1<<": ";
                for(int k=0; k<a.column; k++){
                    if(showCalc && k<a.column-1) cout<<a.T[i*a.column+k]*b.T[k*c->column+j]<<"+";
                    else if(showCalc) cout<<a.T[i*a.column+k]*b.T[k*c->column+j]<<"=";
                    s+=a.T[i*a.column+k]*b.T[k*c->column+j];
                }
                if(showCalc) cout<<s<<endl;
                c->T.push_back(s);
            }
        }
        return 1;
    }
    else{
        cout<<"Impossible to product"<<endl;
        cout<<a.column<<" != "<<b.row<<endl;
        return 0;
    }
}
double my_math_det_matrix(my_matrix a, bool showCalc){
    //double det, wsk;
    //vector<double>Tp;
    if(a.column == a.row){
        vector<double>T0(pow(a.row-1, 2), 0);
        my_matrix b(a.row-1, a.row-1, T0);
        int i=0;

        if(a.row==1) return a.T[0];
        if(a.row==2) return a.T[0]*a.T[3]-a.T[1]*a.T[2];
        double s=0;
        if(a.row>2){
            for(int j=0; j<a.column; j++){
                b.T.clear();
                for(int m=0; m<a.row; m++){
                    for(int n=0; n<a.row; n++){
                        if(m!=i && n!=j) b.T.push_back(a.T[m*a.row+n]);
                    }
                }
                if(showCalc) b.show();
                s+=a.T[j]*pow((-1), (j))*my_math_det_matrix(b, showCalc);
            }
            return s;
        }
    }
    else{
        cout<<"Impossible to 'det'"<<endl;
        cout<<a.column<<" != "<<a.row<<endl;
    }
    return 1e100;
}

int my_math_reverse_matrix(my_matrix a, my_matrix *c, bool showCalc){
    //double det, wsk;
    //vector<double>Tp;
    if(a.column == a.row){
        double detA = my_math_det_matrix(a, showCalc);
        cout<<detA<<endl;
        if(detA==0){
            cout<<"Impossible to reverse"<<endl;
            cout<<detA<<"=0"<<endl;
            return 0;
        }
        if(a.row==1){
            c->row=1;
            c->column=1;
            c->name = "1";
            c->T.clear();
            c->T.push_back(1.0/detA);
            return 1;
        }
        if(a.row==2){
            c->row=2;
            c->column=2;
            c->name = "1";
            c->T.clear();
            c->T.push_back(a.T[3]/detA);
            //cout<<c->T[0]<<endl;
            c->T.push_back(a.T[1]/detA*(-1));
            c->T.push_back(a.T[2]/detA*(-1));
            c->T.push_back(a.T[0]/detA);
            return 1;
        }
        if(a.row>2){
            a.show();
            c->row = a.row;
            c->column = a.column;
            c->name = "1";
            c->T.clear();
            vector<double>T0(pow(a.row-1, 2), 0);
            my_matrix b(a.row-1, a.row-1, T0);
            for(int i=0; i<a.row; i++){
                for(int j=0; j<a.column; j++){
                    b.T.clear();
                    for(int m=0; m<a.row; m++){
                        for(int n=0; n<a.row; n++){
                            if(m!=i && n!=j) b.T.push_back(a.T[m*a.row+n]);
                        }
                    }
                    if(showCalc) b.show();
                    c->T.push_back(pow((-1), (j+i))*my_math_det_matrix(b, showCalc));
                }
            }
            if(showCalc) c->show();
            my_math_transposition_matrix(*c, c);
            cout<<"1/"<<detA<<"*"<<endl;
            c->show();
            my_math_scalar_matrix(*c, 1.0/detA, c);
            return 1;
        }
    }
    else{
        cout<<"Impossible to reverse"<<endl;
        cout<<a.column<<" != "<<a.row<<endl;
        return 0;
    }
}

int my_math_power_matrix(my_matrix a, my_matrix *c, int n, bool showCalc){
    if(a.column == a.row){
        if(n<1) goto gt_errorN;
        c->row = a.row;
        c->column = a.column;
        c->name = "1";
        c->T.clear();
        for(int i=0; i<a.column*a.row; i++){
            c->T.push_back(a.T[i]);
        }
        if(n>1){
            for(int j=0; j<n-1; j++) my_math_product_matrix(a, *c, c);
        }
        return 1;
    }
    else{
        cout<<"Impossible to product"<<endl;
        cout<<a.column<<" != "<<a.row<<endl;
        return 0;
    }
    if(false){
        gt_errorN:
        cout<<"Error n<1"<<endl;
        return 0;
    }
}

void my_math_sqrt_matrix(my_matrix a, my_matrix *c, int n, bool showCalc){
    if(a.column == a.row){
        if(n<2) goto gt_errorN;
        if(n>2) goto gt_errorS;
        c->row = a.row;
        c->column = a.column;
        c->name = "1";
        c->T.clear();
        for(int i=0; i<a.column*a.row; i++){
            c->T.push_back(a.T[i]);
        }
        if(n==2){
            vector<double>T0(pow(a.row, 2), 0);
            my_matrix b(a.row, a.row, T0);
            while(true){
                my_math_reverse_matrix(a, &b, false);
                a.show();
                b.show();
                bool flag = true;
                for(int i=0; i<a.column*a.row; i++){
                    c->T[i] = 0.5*(a.T[i] + b.T[i]);
                    swap(c->T[i], a.T[i]);
                    if(c->T[i]!=a.T[i]) flag = false;
                }
                c->show();
                cout<<endl<<endl;
                if(flag) return;
            }
        }

    }
    else{
        cout<<"Impossible to product"<<endl;
        cout<<a.column<<" != "<<a.row<<endl;
    }
    if(false){
        gt_errorN:
        cout<<"Error n<2"<<endl;
        return;
        gt_errorS:
        cout<<"Soon! n>2"<<endl;
    }
}

void my_math_triangle_matrix(my_matrix a, my_matrix *c, bool showCalc){
    int m;
    double q;
    c->row = a.row;
    c->column = a.column;
    c->T.clear();
    for(int i=0; i<a.row*a.column; i++){
        c->T.push_back(a.T[i]);
    }

    /*
    function for matrix without any zeros:

    for(int i=0; i<c->row; i++){
        for(int j=i+1; j<c->column; j++){
            q = 1.0 * c->T[j*c->column+i] / c->T[i*c->column+i];
            for(int k=0; k<c->column; k++){
                cout<<c->T[j*c->column+k]<<" -= 1.0 * "<<q<<" * "<<c->T[i*c->column+k]<<endl;
                c->T[j*c->column+k] -= 1.0 * q * c->T[i*c->column+k];
            }
        }
    }

    */

    for(int i=0; i<c->row; i++){
        for(int j=i+1; j<c->row; j++){
            m=0;
            while(c->T[i*c->column+i]==0 && m<c->row){
                if(m==i) m++;
                for(int k=0; k<c->column; k++){
                    c->T[i*c->column+k] += c->T[m*c->column+k];
                }
                m++;
            }
            if(c->T[i*c->column+i]){
                q = 1.0 * c->T[j*c->column+i] / c->T[i*c->column+i];
                for(int k=0; k<c->column; k++){
                    cout<<c->T[j*c->column+k]<<" -= 1.0 * "<<q<<" * "<<c->T[i*c->column+k]<<endl;
                    c->T[j*c->column+k] -= 1.0 * q * c->T[i*c->column+k];
                }
            }
        }
    }

}

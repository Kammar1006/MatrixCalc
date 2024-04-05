#include <iostream>
#include <vector>

using namespace std;

class my_matrix;
int my_math_sum_matrix(my_matrix a, my_matrix b, my_matrix *c, bool showCalc=false);
int my_math_difference_matrix(my_matrix a, my_matrix b, my_matrix *c, bool showCalc=false);
void my_math_scalar_matrix(my_matrix a, double s, my_matrix *c, bool showCalc=false);
void my_math_transposition_matrix(my_matrix a, my_matrix *c);
int my_math_product_matrix(my_matrix a, my_matrix b, my_matrix *c, bool showCalc=false);
double my_math_det_matrix(my_matrix a, bool showCalc = false);
int my_math_reverse_matrix(my_matrix a, my_matrix *c, bool showCalc);
int my_math_power_matrix(my_matrix a, my_matrix *c, int n=2, bool showCalc=false);
void my_math_sqrt_matrix(my_matrix a, my_matrix *c, int n=2, bool showCalc=false);
void my_math_triangle_matrix(my_matrix a, my_matrix *c, bool showCalc=false);



class my_matrix{
    public:
    string name;
    private:
    int id;
    int row;
    int column;
    vector<double> T;
    public:
    my_matrix();
    my_matrix(int r, int c, vector<double> &tab, string n="0");
    create_matrix(int r, int c, const vector<double>tab, string n);
    save();
    show();
    chId(int idF);
    chMatrix(int op);

    friend int my_math_sum_matrix(my_matrix a, my_matrix b, my_matrix *c, bool showCalc);
    friend int my_math_difference_matrix(my_matrix a, my_matrix b, my_matrix *c, bool showCalc);
    friend void my_math_scalar_matrix(my_matrix a, double s, my_matrix *c, bool showCalc);
    friend void my_math_transposition_matrix(my_matrix a, my_matrix *c);
    friend int my_math_product_matrix(my_matrix a, my_matrix b, my_matrix *c, bool showCalc);
    friend double my_math_det_matrix(my_matrix a, bool showCalc);
    friend int my_math_reverse_matrix(my_matrix a, my_matrix *c, bool showCalc);
    friend int my_math_power_matrix(my_matrix a, my_matrix *c, int n, bool showCalc);
    friend void my_math_sqrt_matrix(my_matrix a, my_matrix *c, int n, bool showCalc);
    friend void my_math_triangle_matrix(my_matrix a, my_matrix *c, bool showCalc);
};

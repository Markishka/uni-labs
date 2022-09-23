#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
#include <vector>


using namespace std;

const int n = 10000;
int c[10];


void reset(int* p) { //reseting array for histogram
    for (int i = 0; i < 10; i++) {
        *(p + i) = 0;
    }
}


int menu() {
    cout << "1 : Linear congruent method" << endl;
    cout << "2 : Quadr congruent method" << endl;
    cout << "3 : Fibonacci numbers" << endl;
    cout << "4 : Inverse congruent sequence" << endl;
    cout << "5 : Merge method" << endl;
    cout << "6 : \"3 sigma\" rule" << endl;
    cout << "7 : Polar coordinate method" << endl;
    cout << "8 : The method of relations" << endl;
    cout << "9 : Logarithm method for generating an indicative distribution" << endl;
    cout << "10: Ahrens method for generating a gamma distribution of order a > 1" << endl;
    cout << "hello there";
    int met;
    cin >> met;
    return met;
}


void method01() {
    int x;
    const int a = 29;
    int c_ = 31;
    const int m = 131;
    int x0 = 1;
    vector<int> x1_vls = {};
    for (int i = 0; i < n; i++) {
        x = (a * x0 + c_) % m;
        x1_vls.push_back(x);
        double u = (double)x / m;
        x0 = x;
        c[(int) (u * 10)]++;
    }
}


void method02() {
    int x;
    const int a = 34;
    int c_ = 190;
    const int d = 33;
    const int m = 121;
    int x0 = 1;
    vector<int> x2_vls = {};
    for (int i = 0; i < n; i++) {
        x = (d * x0 * x0 + a * x0 + c_) % m;
        x2_vls.push_back(x);
        double u = (double)x / m;
        x0 = x;
        c[(int)(u * 10)]++;
    }
}


void method03() {
    int x = 1;
    int x0 = 1;
    int x1;
    const int m = 150;
    for (int i = 0; i < n; i++) {
        x1 = (x + x0) % m;
        double u = (double)x1 / m;
        x0 = x;
        x = x1;
        c[(int)(u * 10)]++;
    }
}

int inversion(int x, int m) { //inversion for methods
    int inv = 0;
    for (int i = 0; i < m; i++) {
        if ((x * i) % m == 1) {
            inv = i;
        }
    }
    return inv;
}


void method04() {
    const int a = 29;
    int c_ = 18;
    const int m = 6543;
    int x0 = 1;
    int x;
    for (int i = 0; i < n; i++) {
        x = (a * inversion(x0, m) + c_) % m;
        double u = (double)x / m;
        x0 = x;
        c[(int)(u * 10)]++;
    }
}


void method05() {
        int x;
        int a = 29;
        int c_ = 31;
        int m = 131;
        int x0 = 1;
        vector<int> x1_vls = {};
        for (int i = 0; i < n; i++) {
            x = (a * x0 + c_) % m;
            x1_vls.push_back(x);
            double u = (double)x / m;
            x0 = x;
            c[(int)(u * 10)]++;
        }
        x;
        a = 34;
        c_ = 190;
        int d = 33;
        m = 121;
        x0 = 1;
        vector<int> x2_vls = {};
        for (int i = 0; i < n; i++) {
            x = (d * x0 * x0 + a * x0 + c_) % m;
            x2_vls.push_back(x);
            double u = (double)x / m;
            x0 = x;
            
            c[(int)(u * 10)]++;
        }
    reset(c);
    m = 24;
    int z;
    for (int i = 0; i < n; i++) {
        z = (x1_vls[i] + x2_vls[i]) % m;
        double u = (double)z / m;
        c[(int)(u * 10)]++;
    }
}


void for_method06_08(double x) {    
    if (-3 <= x && x < -2.4) {
        c[0]++;
    }
    if (-2.4 <= x && x < -1.8) {
        c[1]++;
    }
    if (-1.8 <= x && x < -1.2) {
        c[2]++;
    }
    if (-1.2 <= x && x < -0.6) {
        c[3]++;
    }
    if (-0.6 <= x && x < 0) {
        c[4]++;
    }
    if (0 <= x && x < 0.6) {
        c[5]++;
    }
    if (0.6 <= x && x < 1.2) {
        c[6]++;
    }
    if (1.2 <= x && x < 1.8) {
        c[7]++;
    }
    if (1.8 <= x && x < 2.4) {
        c[8]++;
    }
    if (2.4 <= x && x <= 3) {
        c[9]++;
    }
}


void method06() {
    int x;
    int a = 29;
    int c_ = 31;
    int m = 131;
    int x0 = 1;
    vector<double> x1_vls = {};
    for (int i = 0; i < n * 12; i++) {
        x = (a * x0 + c_) % m;
        double u = (double)x / m;
        x0 = x;
        x1_vls.push_back(u);
        c[(int)(u * 10)]++;
    }
    reset(c);
    m = 131;
    double sum = 0;
    for (int i = 0; i < 12 * n; i = i + 12)  {
        for (int s = 0; s < 12; s++) {
            double u = (double)x1_vls[i + s];
            sum = sum + u;
        }
        sum -= 6;
        for_method06_08(sum);
        sum = 0;
    }
}


void method07() {
    int x;
    int a = 29;
    int c_ = 31;
    int m = 131;
    int x0 = 1;
    vector<int> x1_vls = {};
    for (int i = 0; i < n; i++) {
        x = (a * x0 + c_) % m;
        x1_vls.push_back(x);
        double u = (double)x / m;
        x0 = x;
        c[(int)(u * 10)]++;
    }
    reset(c);
    double u1, u2, v1, v2, s, xf1, xf2;
    for (int i = 0; i < n-1; i++) {
        u1 = (double)x1_vls[i] / m;
        u2 = (double)x1_vls[1 + i] / m;
        v1 = 2 * u1 - 1;
        v2 = 2 * u2 - 1;
        s = v1 * v1 + v2 * v2;
        if (s < 1) {
            xf1 = v1 * sqrt((-2 * log(s)) / s);
            xf2 = v2 * sqrt((-2 * log(s)) / s);
            for_method06_08(xf1);
            for_method06_08(xf2);
        }
    }
}


void method08() {
    int x;
    const int a = 29;
    int c_ = 31;
    int m1 = 131;
    int x0 = 1;
    vector<int> x1_vls = {};
    for (int i = 0; i < n; i++) {
        x = (a * x0 + c_) % m1;
        x1_vls.push_back(x);
        double u = (double)x / m1;
        x0 = x;
        c[(int)(u * 10)]++;
    }
    x=0;
    c_ = 190;
    const int d = 33;
    int m2 = 121;
    x0 = 1;
    vector<int> x2_vls = {};
    for (int i = 0; i < n; i++) {
        x = (d * x0 * x0 + a * x0 + c_) % m2;
        x2_vls.push_back(x);
        double u = (double)x / m2;
        x0 = x;
        c[(int)(u * 10)]++;
    }
    reset(c);
    for (int i = 0; i < n; i++) {
        double u = (double)x1_vls[i] / m1;
        double v = (double)x2_vls[i] / m2;
        if (u != 0) {
            double xf = sqrt(8 / M_E) * (v - 0.5) / u;
            if (xf * xf <= -4 * log(u)) {
               for_method06_08(xf);
            }
        }
    }
}


void method09() {
    int x;
    const int a = 34;
    int c_ = 190;
    const int d = 33;
    const int m = 121;
    int x0 = 1;
    vector<int> x2_vls = {};
    for (int i = 0; i < n; i++) {
        x = (d * x0 * x0 + a * x0 + c_) % m;
        x2_vls.push_back(x);
        double u = (double)x / m;
        x0 = x;

        c[(int)(u * 10)]++;
    }
    reset(c);
    int mu = 74;
    double u, xf;
    for (int i = 0; i < n; i++) {
        u = (double)x2_vls[i] / m;
        xf = -mu * log(u);
        if (xf < 100) {
            c[(int)xf / 10]++;
        }
    }
}


void method10() {
    int x;
    int a = 29;
    int c_ = 31;
    int m = 131;
    int x0 = 1;
    vector<int> x1_vls = {};
    for (int i = 0; i < n; i++) {
        x = (a * x0 + c_) % m;
        x1_vls.push_back(x);
        double u = (double)x / m;
        x0 = x;
        c[(int)(u * 10)]++;
    }
    x = 0;
    a = 34;
    c_ = 190;
    const int d = 33;
    m = 121;
    x0 = 1;
    vector<int> x2_vls = {};
    for (int i = 0; i < n; i++) {
        x = (d * x0 * x0 + a * x0 + c_) % m;
        x2_vls.push_back(x);
        double u = (double)x / m;
        x0 = x;
        c[(int)(u * 10)]++;
    }
    reset(c);
    int m1 = 131, m2 = 121, a11 = 2;
    double y, xf, u, v;
    for (int i = 0; i < n; i++) {
        u = (double)x1_vls [i] / m1;
        y = tan(u * M_PI);
        xf = sqrt(2 * a11 - 1) * y + a11 - 1;
        if (xf > 0) {
            v = (double)x2_vls[i] / m2;
            if (v <= ((1 + y * y) * exp((a11 - 1) * log((xf) / (a11 - 1)) - sqrt(2 * a11 - 1) * y))) {
                c[(int)xf % 10]++;
            }
        }
    }
}


void histogram1_5() { //assessing histogram for methods 1-5
    cout << '\n' << "  Range       " << "Frequency" << endl;
    cout << "[0.0;1.0)" << "      " << (double)c[0] / 10000 << endl;
    for (int i = 1; i < 9; i++) {
        double current_range = (double)i / 10;
        cout << "[" << current_range << ";" << current_range + 0.1 << ")" << "      " << (double)c[i] / 10000 << endl;
    }
    cout << "[0.9;1.0]" << "      " << (double)c[9] / 10000 << '\n' << endl;
}


void histogram6_8() {                   //assessing histogram for methods 6-8
    double summ = 0;
    cout << '\n' << "  Range       " << "Frequency" << endl;
    cout << "[-3.0;-2.4)" << "      " << (double)c[0] / n << endl;
    cout << "[-2.4;-1.8)" << "      " << (double)c[1] / n << endl;
    cout << "[-1.8;-1.2)" << "      " << (double)c[2] / n << endl;
    cout << "[-1.2;-0.6)" << "      " << (double)c[3] / n << endl;
    cout << "[-0.6; 0.0)" << "      " << (double)c[4] / n << endl;
    cout << "[0.0 ; 0.6)" << "      " << (double)c[5] / n << endl;
    cout << "[0.6 ; 1.2)" << "      " << (double)c[6] / n << endl;
    cout << "[1.2 ; 1.8)" << "      " << (double)c[7] / n << endl;
    cout << "[1.8 ; 2.4)" << "      " << (double)c[8] / n << endl;
    cout << "[2.4 ; 3.0]" << "      " << (double)c[9] / n << '\n' << endl;
    for (int i = 0; i < 10; i++) {
        summ += (double)c[i] / n;
    }
    cout << summ;
}


void histogram9_10() { //assessing histogram for methods 9-10
    cout << '\n' << "  Range         " << "Frequency" << endl;
    cout << "[0  ; 10)" << "      " << (double)c[0] / 10000 << endl;
    for (int i = 1; i < 9; i++) {
        cout << "[" << i * 10 << " ; " << i * 10 + 10 << ")" << "      " << (double)c[i] / 10000 << endl;
    }
    cout << "[90 ;100]" << "      " << (double)c[9] / 10000 << '\n' << endl;
}


int main() {
    int met = -1;

    while (met) {
        met = menu();
        if (!met) {
            break;
        }

        switch (met) {
        case 1: method01();
            histogram1_5();
            break;
        case 2: method02();
            histogram1_5();
            break;
        case 3: method03();
            histogram1_5();
            break;
        case 4: method04();
            histogram1_5();
            break;
        case 5: method05();
            histogram1_5();
            break;
        case 6: method06();
            histogram6_8();
            break;
        case 7: method07();
            histogram6_8();
            break;
        case 8: method08();
            histogram6_8();
            break;
        case 9: method09();
            histogram9_10();
            break;
        case 10: method10();
            histogram9_10();
            break;
        default:
            break;
        }
        reset(c);
    }
    return 0;
}
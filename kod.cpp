#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

void gaussianElimination(vector<vector<double>>& a, int n) {
    for (int k = 0; k < n; k++) {
        if (a[k][k] == 0) {
            cerr << "Ошибка: деление на ноль. Проверьте коэффициенты." << endl;
            exit(1);
        }
        
        for (int i = k + 1; i < n; i++) {
            double coeff = a[i][k] / a[k][k];
            for (int j = k; j < n + 1; j++) {
                a[i][j] -= coeff * a[k][j];
            }
        }
    }
}

vector<double> backSubstitution(const vector<vector<double>>& a, int n) {
    vector<double> x(n);
    for (int i = n - 1; i >= 0; i--) {
        x[i] = a[i][n];
        for (int j = i + 1; j < n; j++) {
            x[i] -= a[i][j] * x[j];
        }
        x[i] /= a[i][i];
    }
    return x;
}

int main() {
    int n;
    cout << "Введите количество уравнений: ";
    cin >> n;

    vector<vector<double>> a(n, vector<double>(n + 1));
    cout << "Введите коэффициенты для уравнений (каждое уравнение в формате: a1 a2 ... an b):" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Уравнение " << i + 1 << ": ";
        for (int j = 0; j < n + 1; j++) {
            cin >> a[i][j];
        }
    }

    gaussianElimination(a, n);
    vector<double> solution = backSubstitution(a, n);

    cout << fixed << setprecision(6);
    for (int i = 0; i < n; i++) {
        cout << "x" << i + 1 << " = " << solution[i] << endl;
    }

    return 0;
}

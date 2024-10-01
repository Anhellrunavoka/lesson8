#include <iostream>
#include <cstdlib>
using namespace std;
//template<class T> void sered(T array[], size_t size) {
//    double sum = 0;
//    for (int i = 0; i < size; i++) {
//        sum += array[i];
//    }
//    cout <<"Seredne arifmetical: "<<sum / size;
//}
template<class T> 
class Matrix {
    T** ar;
    size_t row;
    size_t col;
public:
    Matrix(size_t row, size_t col) : row(row), col(col) {
        ar = new T * [row];
        for (size_t i = 0; i < row; i++) {
            ar[i] = new T[col];
        }
    }
    T* operator[](size_t index) {
        return ar[index];
    }
    const T* operator[](size_t index) const {
        return ar[index];
    }
    void add()  {
        for (size_t i = 0; i < row; i++) {
            for (size_t j = 0; j < col; j++) {
                ar[i][j]=1 + rand() % 50;
            }
        }
    }
    void addin() {
        cout << "Input massve(" << row * col << " numbers): " << endl;
        for (size_t i = 0; i < row; i++) {
            for (size_t j = 0; j < col; j++) {
                cin>>ar[i][j];
            }
        }
    }
    void print() const {
        cout << endl;
        for (size_t i = 0; i < row; i++) {
            for (size_t j = 0; j < col; j++) {
                cout<<ar[i][j]<<" ";
            }
            cout << endl;
        }
    }
    void MaxandMin() const {
        size_t max = ar[0][0],min = ar[0][0];
        for (size_t i = 0; i < row; i++) {
            for (size_t j = 0; j < col; j++) {
                if (ar[i][j] > max)  max = ar[i][j];
                if (ar[i][j] < min)  min = ar[i][j];
            }
        }
        cout <<endl<< "Max: " << max << "\nMin: " << min<<endl;
    }
    ~Matrix() {
        for (size_t i = 0; i < row; i++) {
            delete[] ar[i];
        }
        delete[] ar;
    }
    friend const Matrix operator+(const Matrix& m1, const Matrix& m2) {
        if (m1.col == m2.col && m1.row == m2.row) {
            Matrix<T> m3{ m1.row,m1.col };
            for (size_t i = 0; i < m1.row; i++) {
                for (size_t j = 0; j < m1.col; j++) {
                    m3[i][j] = m1[i][j] + m2[i][j];
                }
            }
            return m3;
        }
    }
    friend const Matrix operator-(const Matrix& m1, const Matrix& m2) {
        if (m1.col == m2.col && m1.row == m2.row) {
            Matrix<T> m3{ m1.row,m1.col };
            for (size_t i = 0; i < m1.row; i++) {
                for (size_t j = 0; j < m1.col; j++) {
                    m3[i][j] = m1[i][j] - m2[i][j];
                }
            }
            return m3;
        }
    }
    friend const Matrix operator*(const Matrix& m1, const Matrix& m2) {
        if (m1.col == m2.col && m1.row == m2.row) {
            Matrix<T> m3{ m1.row,m1.col };
            for (size_t i = 0; i < m1.row; i++) {
                for (size_t j = 0; j < m1.col; j++) {
                    m3[i][j] = m1[i][j] * m2[i][j];
                }
            }
            return m3;
        }
    }
    friend const Matrix<double> operator/(const Matrix& m1, const Matrix& m2) {
        if (m1.col == m2.col && m1.row == m2.row) {
            Matrix<double> m3{ m1.row,m1.col };
            for (size_t i = 0; i < m1.row; i++) {
                for (size_t j = 0; j < m1.col; j++) {
                    m3[i][j] = round((double(m1[i][j]) / double(m2[i][j]))*100)/100;
                }
            }
            return m3;
        }
    }
};
int main()
{
    srand(time(NULL));
    Matrix<int> ar{ 3, 3 };
    ar.add();
    ar.print();
    ar.MaxandMin();
    Matrix<int> ar2{ 3, 3 };
    ar2.addin();
    ar2.print();
    ar2.MaxandMin();
    Matrix<int> ar3= ar + ar2;
    cout<<endl << "Sum: " << endl;
    ar3.print();
    Matrix<int> ar4 = ar - ar2;
    cout << endl << "Minus: " << endl;
    ar4.print();
    Matrix<int> ar5 = ar * ar2;
    cout << endl << "Mnozhennyz: " << endl;
    ar5.print();
    Matrix<double> ar6 = ar / ar2;
    cout << endl << "Dilennya: " << endl;
    ar6.print();
    /*int intar[]{ 2,14,6,9 };
    int size = sizeof(intar) / sizeof(int);
    sered<int>(intar, size);*/
}


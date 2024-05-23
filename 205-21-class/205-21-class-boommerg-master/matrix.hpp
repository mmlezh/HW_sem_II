#ifndef MatrixVector_hpp
#define MatrixVector_hpp

#include <iostream>

using namespace std;
class matrix
{

  private:
    size_t size;
    double *data;

  public:
    //конструкторы [предполагается положительность size]

    matrix(); //работает

    matrix(const matrix &other); //работает

    matrix(size_t N); //работает

    static matrix creatE(size_t N); //работает

    //размер матрицы
    size_t Size() const; //работает

    //получение элемента для чтения[неотрицательность индексов и не превышение]
    double operator[](size_t indx) const; //работает

    //получение для записи[неотрицательность индексов и не превышение]
    double &operator()(size_t indx_r, size_t indx_c); //работает

    //оператор сравнения (равенство)
    bool operator==(const matrix &other) const; //работает

    //оператор сравнения (неравенство)
    bool operator!=(const matrix &other) const; //работает

    //оператор сравнения (строгое неравенство <)
    bool operator<(const matrix &other) const; //работает

    //оператор сравнения (строгое неравенство >)
    bool operator>(const matrix &other) const; //работает

    //оператор сравнения (нестрогое неравенство <=)
    bool operator<=(const matrix &other) const; //работает

    //оператор сравнения (нестрогое неравенство >=)
    bool operator>=(const matrix &other) const; //работает

    //присваивание
    matrix &operator=(const matrix &other); //работает

    //оператор суммирования
    matrix operator+(const matrix &right) const; //работает

    //оператор суммирования
    matrix &operator+=(const matrix &right); //работает

    //оператор разности
    matrix operator-(const matrix &right) const; //работает

    //оператор разности (унарный)
    matrix &operator-(); //работает

    //оператор разности (присваивающий)
    matrix &operator-=(const matrix &right); //работает

    //оператор умножения
    matrix operator*(const matrix &right) const; //работает

    //оператор умножения (присваивающий)
    matrix &operator*=(const matrix &right); //работает

    //метод перестановки строк
    void Swap(size_t i, size_t j); //работает

    //метод умножения строки на число
    void MulRow(size_t i, double cnst); //работает

    //метод суммы двух строк
    void AddRow(size_t i, size_t j); //работает

    //вывод и считывание матриц (работает)
    friend istream &operator>>(istream &input,
                               matrix &unit); //работает

    friend ostream &operator<<(ostream &output,
                               const matrix &unit); //работает

    //оператор транспонирования
    matrix Tran();

    //метод гаусса приведения к ступенчатому виду (было скопировано с прошлого
    //семестра)
    void Gauss();

    //ранг матрицы
    size_t Rank() const;

    //определитель
    double Det() const;

    //обратная
    matrix Inverse() const;

    //деструктор
    ~matrix(); //работает
};

class vector
{

  private:
    size_t size;
    double *data;

  public:
    //конструкторы [предполагается положительность size]
    vector(); //работает

    vector(const vector &other); //работает

    vector(size_t N); //работает

    //получение элементов

    //размер вектора
    size_t SizeV() const; //работает

    double operator[](size_t indx) const; //работает

    double &operator()(size_t indx); //работает

    //равенство
    bool operator!=(const vector &other) const; //работает

    vector &operator=(const vector &other); //работает

    //ввод и вывод
    friend istream &operator>>(istream &input, vector &unit); //работает

    friend ostream &operator<<(ostream &output, vector &unit); //работает

    //деструктор
    ~vector();
};

//действие матрицы на вектор
vector operator*(const matrix &mat, const vector &vec); //работает

vector operator*(const vector &vec, const matrix &mat); //работает

#endif
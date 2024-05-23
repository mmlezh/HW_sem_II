#include "matrix.hpp"
#include <cmath>
#define EPS 2e-12

using namespace std;

//конструкторы (работают) [предполагается положительность size]

matrix::matrix() : size(0), data(nullptr) {}

matrix::matrix(const matrix &other) : size(other.size), data(nullptr)
{
    data = new double[size * size];
    for (size_t i = 0; i < size * size; i++) {
        data[i] = other.data[i];
    }
}

matrix::matrix(size_t N) : size(N), data(nullptr)
{
    data = new double[size * size];
    for (size_t i = 0; i < size * size; i++) {
        data[i] = 0;
    }
}

matrix matrix::creatE(size_t N)
{
    matrix E(N);
    for (size_t i = 0; i < N; i++) {
        for (size_t j = 0; j < N; j++) {
            if (i == j) {
                E.data[i * N + j] = 1;
            }
        }
    }
    return E;
}

//размер матрицы
size_t matrix::Size() const
{
    return size;
}

//операторы

//получение элемента для чтения (работает) [предполагается data и indx <
// size*size]
double matrix::operator[](size_t indx) const
{
    return data[indx];
}

//получение для записи
double &matrix::operator()(size_t indx_r,
                           size_t indx_c) //добавить исключение [data и (indx_r
                                          //< size) && (indx_c < size)]
{
    return data[indx_r * size + indx_c];
}

//оператор сравнения (равенство) [data && other.data]
bool matrix::operator==(const matrix &other) const
{
    if (size == other.size) {
        for (size_t i = 0; i < size * size; i++) {
            if (!(fabs(data[i] - other.data[i]) < EPS)) {
                return false;
            }
        }
        return true;
    }
    return false;
}

//оператор сравнения (неравенство)
bool matrix::operator!=(const matrix &other) const
{
    if (size == other.size) {
        for (size_t i = 0; i < size * size; i++) {
            if (!(fabs(data[i] - other.data[i]) < EPS)) {
                return true;
            }
        }
        return false;
    }
    return true;
}

//оператор сравнения (строгое неравенство <)
bool matrix::operator<(const matrix &other) const
{
    for (size_t i = 0; i < size * size; i++) {
        if (!(data[i] < other.data[i])) {
            return false;
        }
    }
    return true;
}

//оператор сравнения (строгое неравенство >)
bool matrix::operator>(const matrix &other) const
{
    for (size_t i = 0; i < size * size; i++) {
        if (!(data[i] > other.data[i])) {
            return false;
        }
    }
    return true;
}

//оператор сравнения (нестрогое неравенство <=)
bool matrix::operator<=(const matrix &other) const
{
    for (size_t i = 0; i < size * size; i++) {
        if ((!(data[i] < other.data[i])) &&
            (!(fabs(data[i] - other.data[i]) < EPS))) {
            return false;
        }
    }
    return true;
}

//оператор сравнения (нестрогое неравенство >=)
bool matrix::operator>=(const matrix &other) const
{
    for (size_t i = 0; i < size * size; i++) {
        if ((!(data[i] > other.data[i])) &&
            (!(fabs(data[i] - other.data[i]) < EPS))) {
            return false;
        }
    }
    return true;
}

matrix &matrix::operator=(const matrix &other)
{
    if (this != &other) {

        delete[] data;

        data = nullptr;
        size = other.size;
        data = new double[other.size * other.size];
        for (size_t i = 0; i < size * size; i++) {
            data[i] = other.data[i];
        }
    }
    return *this;
}

//оператор суммирования
matrix matrix::operator+(const matrix &right) const
{
    matrix res(size);
    for (size_t i = 0; i < size * size; i++) {
        res.data[i] = data[i] + right.data[i];
    }
    return res;
}

//оператор суммирования
matrix &matrix::operator+=(const matrix &right)
{
    for (size_t i = 0; i < size * size; i++) {
        data[i] += right[i];
    }
    return *this;
}

//оператор разности
matrix matrix::operator-(const matrix &right) const
{
    matrix res(size);
    for (size_t i = 0; i < size * size; i++) {
        res.data[i] = data[i] - right.data[i];
    }
    return res;
}

//оператор разности (унарный)
matrix &matrix::operator-()
{
    for (size_t i = 0; i < size * size; i++) {
        data[i] = -data[i];
    }
    return *this;
}

//оператор разности (присваивающий)
matrix &matrix::operator-=(const matrix &right)
{
    for (size_t i = 0; i < size * size; i++) {
        data[i] -= right[i];
    }
    return *this;
}

//оператор умножения
matrix matrix::operator*(const matrix &right) const
{
    matrix res(size);
    for (size_t i = 0; i < size; i++) {
        for (size_t j = 0; j < size; j++) {
            double temp = 0;
            for (size_t k = 0; k < size; k++) {
                temp += data[i * size + k] * right.data[k * size + j];
            }
            res.data[i * size + j] = temp;
        }
    }
    return res;
}

//оператор умножения (присваивающий)
matrix &matrix::operator*=(const matrix &right)
{
    matrix res(size);
    for (size_t i = 0; i < size; i++) {
        for (size_t j = 0; j < size; j++) {
            double temp = 0;
            for (size_t k = 0; k < size; k++) {
                temp += data[i * size + k] * right.data[k * size + j];
            }
            res.data[i * size + j] = temp;
        }
    }
    *this = res;
    return *this;
}

//методы работы с строками матрицы
//метод перестановки строк
void matrix::Swap(size_t i, size_t j)
{
    double temp;
    for (size_t k = 0; k < size; k++) {
        temp = data[i * size + k];
        data[i * size + k] = data[j * size + k];
        data[j * size + k] = temp;
    }
}

//метод умножения строки на число
void matrix::MulRow(size_t i, double cnst)
{
    for (size_t j = 0; j < size; j++) {
        data[i * size + j] *= cnst;
    }
}

//метод суммы двух строк
void matrix::AddRow(size_t i, size_t j)
{
    for (size_t k = 0; k < size; k++) {
        data[i * size + k] += data[j * size + k];
    }
}

//вывод и считывание матриц (работает)

istream &operator>>(istream &input, matrix &unit)
{
    if (unit.size == 0) // добавить ошибку при попытке считать элемент
    {

        delete[] unit.data;
        //ошибка

        unit.data = nullptr;
        return input;
    }

    delete[] unit.data;

    unit.data = new double[unit.size * unit.size];
    for (size_t i = 0; i < unit.size; i++) {
        for (size_t j = 0; j < unit.size; j++) {
            input >> unit(i, j);
            //проверка на считываемость;
        }
    }
    return input;
}

ostream &operator<<(ostream &output, const matrix &unit)
{
    if (unit.size == 0) {

        delete[] unit.data;

        output << "Пустая матрица\n";
        return output;
    }
    for (size_t i = 0; i < unit.size; i++) {
        for (size_t j = 0; j < unit.size; j++) {
            if (fabs(unit[i * unit.size + j]) > EPS) {
                output << unit[i * unit.size + j] << "\t";
            } else {
                output << '0' << "\t";
            }
        }
        output << "\n";
    }
    return output;
}

//методы
//оператор транспонирования (работает)
matrix matrix::Tran()
{
    matrix temp(size);
    for (size_t i = 0; i < size; i++) {
        for (size_t j = 0; j < size; j++) {
            temp.data[j * size + i] = data[i * size + j];
        }
    }
    return temp;
}

//метод гаусса приведения к ступенчатому виду (работает)
void matrix::Gauss()
{
    size_t size = this->Size();
    for (size_t i = 0; i < size; i++) {
        //находим строку с максимальным первый ненулевым элементом
        size_t jmax = i;
        for (size_t j = i + 1; j < size; j++) {
            jmax =
                (fabs(data[j * size + i]) > fabs(data[jmax * size + i]) ? j
                                                                        : jmax);
        }
        if (fabs(data[jmax * size + i]) < EPS) {
            continue;
        }
        this->Swap(i, jmax);
        for (size_t j = i + 1; j < size; j++) {
            double *copy_temp = new double[size]; // memory leak
            for (size_t m = 0; m < size; m++) {
                copy_temp[m] = data[i * size + m];
            }
            double temp = data[j * size + i] / data[i * size + i];
            this->MulRow(i, -temp);
            this->AddRow(j, i);
            for (size_t m = 0; m < size; m++) {
                data[i * size + m] = copy_temp[m];
            }
            delete[] copy_temp;
        }
    }
}

//ранг матрицы(работает)
size_t matrix::Rank() const
{
    size_t rank = 0;
    matrix temp(*this);
    temp.Gauss();
    for (size_t i = 0; i < size; i++) {
        if (fabs(temp[i * size + i]) > EPS) {
            rank++;
        }
    }
    return rank;
}

//определитель (работает)
double matrix::Det() const
{
    matrix M(*this);
    size_t size = this->Size();
    double detM = 1;
    for (size_t i = 0; i < size; i++) {
        //находим строку с максимальным первый ненулевым элементом
        size_t jmax = i;
        for (size_t j = i + 1; j < size; j++) {
            jmax = (fabs(M.data[j * size + i]) > fabs(M.data[jmax * size + i])
                        ? j
                        : jmax);
        }
        if (fabs(M.data[jmax * size + i]) < EPS) {
            detM = 0;
            return detM;
        }
        M.Swap(i, jmax);
        detM = (i == jmax ? detM : -detM);
        for (size_t j = i + 1; j < size; j++) {
            double *copy_temp = new double[size];
            for (size_t m = 0; m < size; m++) {
                copy_temp[m] = M.data[i * size + m];
            }
            double temp = M.data[j * size + i] / M.data[i * size + i];
            M.MulRow(i, -temp);
            M.AddRow(j, i);
            for (size_t m = 0; m < size; m++) {
                M.data[i * size + m] = copy_temp[m];
            }
            delete[] copy_temp;
        }
        detM *= M.data[i * size + i];
    }
    return detM;
}

//обратная [НЕ РАБОТАЕТ]
matrix matrix::Inverse() const
{
    size_t size = this->Size();
    matrix Rez(*this);
    matrix I = matrix::creatE(size);
    for (size_t i = 0; i < size; i++) {
        //находим строку с максимальным первый ненулевым элементом
        size_t jmax = i;
        for (size_t j = i + 1; j < size; j++) {
            jmax =
                (fabs(Rez.data[j * size + i]) > fabs(Rez.data[jmax * size + i])
                     ? j
                     : jmax);
        }
        if (fabs(Rez.data[jmax * size + i]) < EPS) {
            continue;
        }
        Rez.Swap(i, jmax);
        I.Swap(i, jmax);
        for (size_t j = i + 1; j < size; j++) {
            double *copy_tmp1 = new double[size];
            double *copy_tmp2 = new double[size];
            for (size_t m = 0; m < size; m++) {
                copy_tmp1[m] = Rez.data[i * size + m];
                copy_tmp2[m] = I.data[i * size + m];
            }
            double temp = Rez.data[j * size + i] / Rez.data[i * size + i];
            Rez.MulRow(i, -temp);
            I.MulRow(i, -temp);
            Rez.AddRow(j, i);
            I.AddRow(j, i);
            for (size_t m = 0; m < size; m++) {
                Rez.data[i * size + m] = copy_tmp1[m];
                I.data[i * size + m] = copy_tmp2[m];
            }
            delete[] copy_tmp1;
            delete[] copy_tmp2;
        }
    }

    for (size_t i = 0; i < size; i++) {
        I.MulRow(i, 1 / Rez.data[i * size + i]);
        Rez.MulRow(i, 1 / Rez.data[i * size + i]);
        if (i > 0) {
            for (size_t j = i; j != 0; j--) {
                double *copy_tmp1 = new double[size];
                double *copy_tmp2 = new double[size];
                for (size_t m = 0; m < size; m++) {
                    copy_tmp1[m] = Rez.data[i * size + m];
                    copy_tmp2[m] = I.data[i * size + m];
                }
                double temp = Rez.data[(j - 1) * size + i];
                Rez.MulRow(i, -temp);
                I.MulRow(i, -temp);
                Rez.AddRow(j - 1, i);
                I.AddRow(j - 1, i);
                for (size_t m = 0; m < size; m++) {
                    Rez.data[i * size + m] = copy_tmp1[m];
                    I.data[i * size + m] = copy_tmp2[m];
                }
                delete[] copy_tmp1;
                delete[] copy_tmp2;
            }
        }
    }

    return I;
}

//деструктор
matrix::~matrix()
{

    delete[] data;
}

//конструкторы [предполагается положительность size]

vector::vector() : size(0), data(nullptr) {}

vector::vector(const vector &other) : size(other.size), data(nullptr)
{
    data = new double[size];
    for (size_t i = 0; i < size; i++) {
        data[i] = other.data[i];
    }
}

vector::vector(size_t N) : size(N), data(nullptr)
{
    data = new double[size];
    for (size_t i = 0; i < size; i++) {
        data[i] = 0;
    }
}

//размер вектора
size_t vector::SizeV() const
{
    return size;
}

//операторы

double vector::operator[](size_t indx) const
{
    return data[indx];
}

double &vector::operator()(size_t indx)
{
    return data[indx];
}
//равенство
bool vector::operator!=(const vector &other) const
{
    if (size == other.size) {
        if ((data != nullptr) && (other.data != nullptr)) {
            for (size_t i = 0; i < size; i++) {
                if (!(fabs(data[i] - other.data[i]) < EPS)) {
                    return true;
                }
            }
            return false;
        }
    }
    return true;
}

vector &vector::operator=(const vector &other)
{
    if (this != &other) {

        delete[] data;

        data = nullptr;
        size = other.size;
        if (other.data != nullptr) {
            data = new double[other.size];
            for (size_t i = 0; i < size; i++) {
                data[i] = other.data[i];
            }
        }
    }
    return *this;
}

//ввод и вывод
istream &operator>>(istream &input, vector &unit)
{
    if (unit.size == 0) {

        delete[] unit.data;
        //ошибка

        unit.data = nullptr;
        return input;
    }

    delete[] unit.data;

    unit.data = new double[unit.size];
    for (size_t i = 0; i < unit.size; i++) {
        input >> unit(i);
        //обработка считывания
    }
    return input;
}

ostream &operator<<(ostream &output, vector &unit)
{
    if (unit.size == 0) {

        delete[] unit.data;

        output << "Пустой вектор \n";
        return output;
    }
    for (size_t i = 0; i < unit.size; i++) {
        output << unit[i] << " ";
    }
    output << "\n";
    return output;
}

//деструктор
vector::~vector()
{

    delete[] data;
}

//действие матриц на векторы
//действие матрицы на вектор
vector operator*(const matrix &mat, const vector &vec)
{
    //проверка на согласованность размеров и невырожденность
    size_t len = vec.SizeV();
    vector rez(len);
    for (size_t j = 0; j < len; j++) {
        double temp = 0;
        for (size_t k = 0; k < len; k++) {
            temp += mat[j * len + k] * vec[k];
        }
        rez(j) = temp;
    }
    return rez;
}

vector operator*(const vector &vec, const matrix &mat)
{
    //проверка на согласованность размеров и невырожденность
    size_t len = vec.SizeV();
    vector rez(len);
    for (size_t j = 0; j < len; j++) {
        double temp = 0;
        for (size_t k = 0; k < len; k++) {
            temp += vec[k] * mat[k * len + j];
        }
        rez(j) = temp;
    }
    return rez;
}
#include "matrix.hpp"

// using namespace matrix;

int main()
{
    size_t size;
    size_t i;
    size_t j;
    double k;
    std::cin >> size;
    matrix A(size);
    matrix B(size);
    matrix C;
    vector V(size);
    vector G;

    std::cin >> A >> B;
    std::cin >> V;

    std::cin >> k;
    std::cin >> i >> j;

    //арифметика
    C = A + B;
    C += B;
    std::cout << ":\n" << C << "\n";

    C = A - B;
    C -= B;
    std::cout << ":\n" << C << "\n";

    C = -B;
    C += A;
    std::cout << ":\n" << C << "\n";

    C = A * B;
    C *= B;
    std::cout << ":\n" << C << "\n";

    G = A * V;
    G = V * A;
    std::cout << ":\n" << G << "\n";

    //сравнение
    if (A == B) {
        std::cout << "A == B \n";
    }
    if (A != B) {
        std::cout << "A != B \n";
    }
    if (A > B) {
        std::cout << "A > B \n";
    }
    if (A < B) {
        std::cout << "A < B \n";
    }
    if (A >= B) {
        std::cout << "A >= B \n";
    }
    if (A <= B) {
        std::cout << "A <= B \n";
    }

    //элементарные преобразования
    A.MulRow(i, k);
    A.Swap(i, j);
    A.AddRow(i, j);

    //сложности
    std::cout << "Транспонирование матрицы: \n" << A << "\n";
    C = A.Tran();
    std::cout << "результат: \n" << C << "\n";

    std::cout << "ранг матрицы: \n " << A << "\n";
    std::cout << "равен: " << A.Rank() << "\n";

    std::cout << "определитель матрицы: \n " << A << "\n";
    std::cout << "равен: " << A.Det() << "\n";

    A.Gauss();
    std::cout << "Ступенчатый вид: \n" << A << "\n";

    std::cout << "Обратная матрица: \n" << A.Inverse() << "\n";
    std::cout << "ПРОВЕРКА: \n" << A * A.Inverse() << "\n";
    return 0;
}
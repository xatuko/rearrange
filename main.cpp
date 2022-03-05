#include <iostream>
#include <vector>
#include <string>
#include <fstream>

/**
 * @brief Перегрузка оператора вывода для работы std::vector<int>.
 * @param out Ссылка на поток вывода.
 * @param arr Ссылка на массив, который необходимо напечатать.
 */
void operator << (std::ostream & out, const std::vector<int> arr)
{
    for (auto & el : arr)
        out << el << ' ';
    out << std::endl;
}

/**
 * @brief Факториал.
 */
int fact(const int & n)
{
    int res = 1;
    for (int i = 1; i <= n; i++)
        res *= i;
    return res;
}

/**
 * @brief Поменять местами элементы в std::vector<int>.
 * @param arr Массив.
 * @param p1 Индекс первого элемента.
 * @param p2 Индекс второго элемента.
 */
void swap(std::vector<int> & arr, int p1, int p2)
{
    if (p1 == p2)
        return;

    int buf = arr[p1];
    arr[p1] = arr[p2];
    arr[p2] = buf;
}

/**
 * @brief Функция, реализиющая алгоритм размещений без повторений.
 * @param arr Набор элементов.
 * @return std::vector<std::vector<int>> : набор возможных размещений.
 */
std::vector<std::vector<int>> perebor(const std::vector<int> & arr)
{
    std::vector<std::vector<int>> result;
    int count = fact(arr.size()),       // Количество всех вариантов.
        size  = arr.size(),             // Количество элементов.
        reps  = count / size;           // Повторения действий.

    result.resize(count, arr);

    for (size_t i = 0; i < arr.size()-1; i++)
    {
        size_t num = i;
        for (int variant = 0; variant < count;)
        {
            for (int j = 0; j < reps; j++)
            {
                swap(result[variant], i, num);
                variant++;
            }
            num = (num+1 == arr.size()) ? i : num+1;
        }
        size--;
        reps = reps / size;
    }
    return result;
}

int main(int, char**)
{
    // Пример работы

    std::vector<int> arr = {1, 2, 3};

    auto res = perebor(arr);
    for (auto & arr : res)
        std::cout << arr;

    return 0;
}
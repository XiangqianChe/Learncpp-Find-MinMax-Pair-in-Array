#include <iostream>
#include <vector>

template <typename T>
std::pair<std::size_t, std::size_t> findMinMax(const std::vector<T>& v)
{
    std::size_t minIndex{};
    std::size_t maxIndex{};
    for (std::size_t index{}; index < std::size(v); ++index)
    {
        if (v[index] < v[minIndex]) minIndex = index;
        if (v[index] > v[maxIndex]) maxIndex = index;
    }
    return { minIndex, maxIndex };
}

template <typename T>
void printArray(const std::vector<T>& v)
{
    std::cout << "With array ( ";
    for (const auto& e : v)
        std::cout << e << ", ";
    std::cout << "\b\b ):\n";
}

int main()
{
    std::vector<int> v1{};
    std::cout << "Enter numbers to add (use -1 to stop): ";
    while (true)
    {
        int i{};
        std::cin >> i;
        if (i == -1) break;

        if (!std::cin)
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        v1.emplace_back(i);
    }

    printArray(v1);
    auto m1{ findMinMax(v1) };
    std::cout << "The min element has index " << m1.first << " and value " << v1[m1.first] << '\n';
    std::cout << "The max element has index " << m1.second << " and value " << v1[m1.second] << '\n';

    return 0;
}
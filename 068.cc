#include <iostream>
#include <vector>
#include <ctime>
#include <random>

/**
 * 随机产生待排序数组
 * */
std::vector<int> random_data(const int &num_count)
{
    std::default_random_engine engine(time(NULL));
    std::uniform_int_distribution<int> distribution(0, 9);
    std::vector<int> vct(num_count);
    for (auto i = 0; i < num_count; i++)
        vct.at(i) = distribution(engine);
    return vct;
}

/**
 * 打印数组
 * */
void print(const std::vector<int> &vct)
{
    for (auto it = vct.begin(); it != vct.end(); it++)
        std::cout << *it << ' ';
    std::cout << std::endl;
}

/**
 * 归并排序递归核心
 * */
void merge_sort_core(std::vector<int> &data, std::vector<int> tmp, const int &start, const int &end)
{
    if (start < end)
    {
        auto mid = start + (end - start) / 2;
        merge_sort_core(data, tmp, start, mid);   // 递归前半部分
        merge_sort_core(data, tmp, mid + 1, end); // 递归后半部分
        // 开始：合并前后两部分
        auto i = start, k = start, j = mid + 1;
        // 开始：循环取较小的放入tmp数组
        while (i != mid + 1 && j != end + 1)
        {
            if (data.at(i) > data.at(j))
                tmp.at(k++) = data.at(j++);
            else
                tmp.at(k++) = data.at(i++);
        }
        // 结束：循环取较小的放入tmp数组
        while (i != mid + 1) // 前半部分还有剩余
            tmp.at(k++) = data.at(i++);
        while (j != end + 1) // 后半部分还有剩余
            tmp.at(k++) = data.at(j++);
        // 结束：合并前后两部分
        for (auto idx = start; idx <= end; idx++) // 将排序好的数组拷贝到指定空间
            data.at(idx) = tmp.at(idx);
    }
}

/**
 * 归并排序
 * */
std::vector<int> merge_sort(const std::vector<int> &data)
{
    auto ret = new std::vector<int>(data.begin(), data.end());
    if (data.size() > 0)
    {
        auto tmp = new std::vector<int>(data.size());
        merge_sort_core(*ret, *tmp, 0, data.size() - 1);
        delete tmp;
    }
    return *ret;
}

/**
 * 冒泡排序
 * */
std::vector<int> bubble_sort(const std::vector<int> &data)
{
    auto ret = new std::vector<int>(data.begin(), data.end());
    for (unsigned i = 0; i < ret->size(); i++)
        for (unsigned j = 0; j < ret->size() - i - 1; j++)
            if (ret->at(j) > ret->at(j + 1))
            {
                auto tmp = ret->at(j);
                ret->at(j) = ret->at(j + 1);
                ret->at(j + 1) = tmp;
            }
    return *ret;
}

int main(int argc, char const *argv[])
{
    const auto num_count = 15;
    auto data = random_data(num_count);
    std::cout << "Original input: ";
    print(data);
    std::cout << "Merge Sort: ";
    print(merge_sort(data));
    std::cout << "Bubble Sort: ";
    print(bubble_sort(data));
    std::cin.get();
    return 0;
}

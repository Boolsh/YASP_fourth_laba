#include "FLIST.h"

int FLIST::sum()
{
    int res{};
    std::for_each(list.begin(), list.end(), [&res](int n) {res += n; });
    return res;
}

float FLIST::average()
{
    float res{}; int count{};
    std::for_each(list.begin(), list.end(), [&res, &count](int n) {res += n; count++; });
    if (!count) return 0;
    return res/count;
}

void FLIST::print(std::ostream& stream)
{
	for (int a : list)
		stream << a << " ";
    std::cout << std::endl;
}



void FLIST::fill(std::fstream& file)
{
    if (!file.is_open()) {
        std::cerr << "Ошибка: файл не открыт!" << std::endl;
        return;
    }

    std::forward_list<int>::iterator ptr = list.before_begin();
    int x{};
    while (file >> x)
    {
        list.insert_after(ptr, x);
        ++ptr;
    }
}
std::forward_list<int> FLIST::modify_for(std::forward_list<int>::iterator start, std::forward_list<int>::iterator end)
{
    std::forward_list<int> res;
    std::forward_list<int>::iterator iter = res.before_begin();
    int first = (*start) * (*start);
    for (std::forward_list<int>::iterator ptr = start; start != end; ++ptr)
    {
        if (ptr == end) break;
        res.insert_after(iter, sqrt((*ptr) * (*ptr) + first));
        ++iter;
    }


    return res;
}


std::forward_list<int> FLIST::modify_transform(std::forward_list<int>::iterator start, std::forward_list<int>::iterator end)
{
    std::forward_list<int> res{start, end};//
    int first = (*start) * (*start);
    std::transform(start, end, res.begin(), [&first](int x) {return sqrt((x) * (x)+first);});
    return res;
}

std::forward_list<int> FLIST::modify_foreach(std::forward_list<int>::iterator start, std::forward_list<int>::iterator end)
{
    std::forward_list<int> res;
    std::forward_list<int>::iterator iter = res.before_begin();
    int first = (*start) * (*start);
    std::for_each(start, end, [&res, &iter, &first](int x) { res.insert_after(iter, sqrt((x) * (x)+first)); iter++; });
    return res;
}

//std::forward_list<int> FLIST::modify_foreach(std::forward_list<int>::iterator start, std::forward_list<int>::iterator end)
//{
//    std::forward_list<int> res{ list.begin(), list.end() };
//    int first = (*start) * (*start);
//    auto res_start = res.begin();
//    std::advance(res_start, std::distance(list.begin(), start));
//    std::for_each(res_start, std::next(res_start, std::distance(start, end)), [&first](int& x) {
//        x = std::sqrt(x * x + first); 
//        });
//
//    return res;
//}

//std::forward_list<int> FLIST::modify_transform(std::forward_list<int>::iterator start, std::forward_list<int>::iterator end)
//{
//    std::forward_list<int> res{ list.begin(), list.end() };
//    int first = (*start) * (*start);
//    std::forward_list<int>::iterator res_start = res.begin();
//    std::advance(res_start, std::distance(list.begin(), start));
//    std::forward_list<int>::iterator res_end = res_start;
//    std::advance(res_end, std::distance(start, end));
//    std::transform(res_start, res_end, res_start, [&first](int x) {
//        return std::sqrt(x * x + first);
//        });
//
//    return res;
//}

//std::forward_list<int> FLIST::modify_for(std::forward_list<int>::iterator start, std::forward_list<int>::iterator end)
//{
//    std::forward_list<int> res;
//    std::forward_list<int>::iterator iter = res.before_begin();
//    int first = (*start) * (*start);
//    if (start != list.begin())
//    {
//        for (std::forward_list<int>::iterator ptr = list.begin(); ptr != start; ++ptr)
//        {
//            if (ptr == start) break;
//            res.insert_after(iter, *ptr);
//            ++iter;
//        }
//    }
//
//    for (std::forward_list<int>::iterator ptr = start; start != end; ++ptr)
//    {
//        if (ptr == end) break;
//        res.insert_after(iter, sqrt((*ptr) * (*ptr) + first));
//        ++iter;
//    }
//
//    if (end != list.end())
//    {
//        for (std::forward_list<int>::iterator ptr = end; ptr != list.end(); ++ptr)
//        {
//            if (ptr == list.end()) break;
//            res.insert_after(iter, *ptr);
//            ++iter;
//        }
//    }
//
//    return res;
//}

#include "FLIST.h"

//? “ри версии метода modify, выполн€ющей преобразование контейнера.Ќа вход
//функции должны поступать итераторы начала и конца обрабатываемой части
//контейнера, в качестве результата функци€ должна возвращать
//модифицированный контейнер(не измен€€ исходный).–еализовать алгоритм
//через : for, std::transform, std::for_each;


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
        std::cerr << "ќшибка: файл не открыт!" << std::endl;
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
    std::forward_list<int> res{start, end};
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

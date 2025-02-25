#pragma once
#include <forward_list>
#include <Windows.h>
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>



// DONE
//? ћетод, получающий файловый поток на вход, котора€ осуществл€ет чтение чисел
//из файла в последовательный контейнер; 
// DONE
// 
//? “ри версии метода modify, выполн€ющей преобразование контейнера.Ќа вход
//функции должны поступать итераторы начала и конца обрабатываемой части
//контейнера, в качестве результата функци€ должна возвращать
//модифицированный контейнер(не измен€€ исходный).–еализовать алгоритм
//через : for, std::transform, std::for_each;
// 
// DONE
//? ћетоды, вычисл€ющие сумму и среднее арифметическое чисел, содержащихс€
//в контейнере(не вычисл€ть вручную через €вный вызов for / while / do - while);
// DONE
// 
// DONE
//? ћетод потокового вывода результата.ќсуществить вывод в файл и на экран с ее
//помощью.
//DONE

class FLIST
{
private:
	std::forward_list <int> list;
public:
	FLIST() {};
	~FLIST() {};

	void fill(std::fstream&);
	std::forward_list <int> modify_for(std::forward_list<int>::iterator start, std::forward_list<int>::iterator end);
	std::forward_list <int> modify_transform(std::forward_list<int>::iterator start, std::forward_list<int>::iterator end);
	std::forward_list <int> modify_foreach(std::forward_list<int>::iterator start, std::forward_list<int>::iterator end);
	std::forward_list<int>::iterator begin() { return list.begin(); };
	std::forward_list<int>::iterator end() { return list.end(); }
	std::forward_list<int>::iterator get_iterator(const size_t number)
	{
		std::forward_list<int>::iterator end = list.end();
		size_t i{ 1 };
		for (std::forward_list<int>::iterator ptr = list.begin(); ptr != end; ++ptr, ++i)
			if (i == number)
				return ptr;
		return end;
	}
	//{ 
	//	std::forward_list<int>::iterator res, prev_res;
	//	for (std::forward_list<int>::iterator iter = list.begin(); iter != list.end(); iter++)
	//	{
	//		prev_res = res;
	//		res = iter;
	//	}
	//	return prev_res; 
	//};
	int sum();
	float average();
	void print(std::ostream& = std::cout);

};


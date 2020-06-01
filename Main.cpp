#include <iostream>
#include <random>
#include <algorithm>
#include "Uniform.h"
#include <iterator>

/**

Для заданной размерности пространства N(параметр функции) 
заполнить последовательность N - мерных векторов(с которыми можно работать как с массивами размера N) 
псевдослучайными числами в диапазоне[–1, 1] таким образом, чтобы все они находились
внутри N - мерного 1 - шара(сумма квадратов координат меньше или равна единице).

Использовать generate и remove_if.

**/

using namespace std;

template<typename M>
M sqr(M m) {
	return m * m;
}


template<typename N>
vector<N> fun(size_t vecSize) {

	vector<N> vec(vecSize);

	Uniform<N> gen;

	auto pred = [=](vector<N> vector) {
		for (size_t i = 0; i < size(vector) - 1; i++) {
			if ((sqr(vector[i]) + sqr(vector[i + 1])) > 1) return false;
		}
		return true;
	};

	auto from = vec.begin();
	auto to = vec.end();

	generate(from, to, gen);

	to = remove_if(from, to, pred);

	vec.erase(to, vec.end());

	return vec;

}

int main() {

	for (auto& x : fun<float>(5))
	{
		cout << x << "\n";
	}
	return 0;
}


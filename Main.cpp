#include <iostream>
#include <random>
#include <algorithm>
#include "Uniform.h"
#include <iterator>
#include<vector>
#include <functional>

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

template <typename It>
It genpoints(size_t N, It from, It to) {
	// We assume that value_type of It is vector<NT>, thus NT is value_type of value_type of It:
	using NT = typename iterator_traits<It>::value_type::value_type;


	for (Uniform<NT> gen; from != to;) {

		generate(from, to, [&]() {

			vector<NT> point(N);
			// TODO: generate на point, используя ref(gen)
			generate(point.begin(), point.end(), ref(gen));
			return point;

			});

		float curSum = 0;

		from = remove_if(from, to, [&curSum](auto const& point){

			for (auto& y : point) {
			
				if (curSum <= 1) {
					curSum += sqr(y);
					cout << y << endl << curSum << " - is sum \n";
				}
				else if (curSum > 1) {
					cout << "Sum is more than one \n";
					curSum = 0;
					return false;
				}
				

			}

			});
	}

	cout << endl;

	return to;
}

int main() {

	vector<vector<float>> points(10);
	genpoints(5, begin(points), end(points));
	for (auto& point : points)
		copy(begin(point), end(point), ostream_iterator<float>(cout << endl, " "));
	return 0;
	
	

	
	return 0;
}


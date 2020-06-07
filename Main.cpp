#include <iostream>
#include "Uniform.h"
#include <iterator>
#include<vector>
#include <functional>
#include <numeric>

/**

��� �������� ����������� ������������ N(�������� �������) 
��������� ������������������ N - ������ ��������(� �������� ����� �������� ��� � ��������� ������� N) 
���������������� ������� � ���������[�1, 1] ����� �������, ����� ��� ��� ����������
������ N - ������� 1 - ����(����� ��������� ��������� ������ ��� ����� �������).

������������ generate � remove_if.

**/


template <typename It>
It genpoints(size_t N, It from, It to) {
	// We assume that value_type of It is vector<NT>, thus NT is value_type of value_type of It:
	using NT = typename iterator_traits<It>::value_type::value_type;


	for (Uniform<NT> gen; from != to;) {

		std::generate(from, to, [&]() {

			vector<NT> point(N);
			
			std::generate(point.begin(), point.end(), ref(gen));
			return point;

			});

		float curSum = 0;

		from = std::remove_if(from, to, [&curSum](auto const& point){

			if (inner_product(point.begin(), point.end(), point.begin(), 0.0) <= 1.0) return false;
			else return true;
		
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
	

}


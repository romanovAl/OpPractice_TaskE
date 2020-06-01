#include <iostream>
#include <random>
#include <algorithm>
#include "Uniform.h"
#include <iterator>
#include<vector>

/**

��� �������� ����������� ������������ N(�������� �������) 
��������� ������������������ N - ������ ��������(� �������� ����� �������� ��� � ��������� ������� N) 
���������������� ������� � ���������[�1, 1] ����� �������, ����� ��� ��� ����������
������ N - ������� 1 - ����(����� ��������� ��������� ������ ��� ����� �������).

������������ generate � remove_if.

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

	static N sum;

	auto pred = [=](N el) {
		if (sum + sqr(el) > 1) {
			//cout << "\nSum + sqr(el) = " << sum + sqr(el) << "	Cur sum is - " << sum << " no adding for element " << el;
			return true;

		}
		else {
			sum += sqr(el);
			//cout << "\nCur sum is (after) - " << sum << " adding element " << el;
			return false;
		}
		
	};

	

	auto from = vec.begin();
	auto to = vec.end();

	generate(from, to, gen);

	cout << "\n Vector before - \n";
	for (auto& x : vec) {
		cout << x << endl;
	}

	vec.erase(remove_if(from, to,pred), vec.end());

	cout << "\nvector after - \n";


	return vec;

}

int main() {
	
	vector<float> vector = fun<float>(30);

	float sum = 0;
	for (auto& x : vector)
	{
		cout << x << "\n";
		sum += sqr(x);
	}
	cout << "sum is - " << sum;

	
	return 0;
}


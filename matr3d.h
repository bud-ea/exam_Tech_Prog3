#pragma once
#include <iostream>
class Matr3Diag
{
private:
	int n;
	double* elem;
public:
	Matr3Diag();
	Matr3Diag(const Matr3Diag& temp);
	~Matr3Diag();//����������

	double get_elem(int i, int j) const;
	Matr3Diag sum(const Matr3Diag& temp);
	Matr3Diag multiplication(const Matr3Diag& temp);
	void print() const;
	void input(int size);

	/*���������� ����������
	*	- ��� ����� ������ 
	*			�������� ������ ������ +=, -+, ++, --
	*	- ��� ������������� �������
	*			��������� ������ � private ������ ������
	*	- ��� ������
	*/
	void operator+=(const Matr3Diag& temp);

	friend std::ostream& operator<<(std::ostream& out, const Matr3Diag& temp);
};


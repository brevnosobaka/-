//Myarr.h//
#pragma once
#include<fstream>
using namespace std;

template <class T>
class Myarr
{
private:
	T* arr;
	int n;
public:

	int size() const { 
		return n; }
	Myarr();
	Myarr(int n);
	Myarr(const Myarr& a);

	Myarr<T>& operator=(const Myarr<T>& a);

	T& operator[](int i);
	T& operator[](int i) const;

	friend ostream& operator<<(ostream& os, const Myarr<T> a) {
		for (int i = 0; i < a.n; i++)
			os << a[i] << "\n ";
		return os;
	}

	friend istream& operator>>(istream& os, Myarr<T>& a) {
		int n;
		os >> n;
		a.n = n;
		a.arr = new T[n];
		for (int i = 0; i < a.n; i++)
			os >> a[i];
		return os;
	}

	void writeBin(ofstream& os);
	void readBin(ifstream& os);
	~Myarr();
};

template<class T>
inline Myarr<T>::Myarr()
{
	n = 0;
	arr = nullptr;
}

template<class T>
inline Myarr<T>::Myarr(int n)
{
	this->n = n;
	arr = new T[this->n];
}

template<class T>
inline Myarr<T>::Myarr(const Myarr& a)
{
	this->n = a.n; 
	arr = new T[n];
	for (int i = 0; i < n; i++)
		arr[i] = a.arr[i];
}

template<class T>
inline Myarr<T>& Myarr<T>::operator=(const Myarr<T>& a)
{
	delete[]arr;
	this->n = a.n; 
	arr = new T[n];
	for (int i = 0; i < n; i++)
		arr[i] = a.arr[i];
	return*this;
}

template<class T>
inline T& Myarr<T>::operator[](int i)
{
	if (i >= n)throw "index error";
	return arr[i];
}

template<class T>
inline T& Myarr<T>::operator[](int i) const
{
	if (i < 0 || (i >= n))throw "index error";
	return arr[i];
}

template<class T>
inline void Myarr<T>::writeBin(ofstream& os)
{
	os.write((char*)arr, sizeof(T) * n);
	os.close();
}

template<class T>
inline void Myarr<T>::readBin(ifstream& os)
{
	os.seekg(0, os.end);
	int n = os.tellg() / sizeof(T);
	delete[]arr;
	arr = new T[n];
	this->n = n;
	os.seekg(0, os.beg);
	os.read((char*)arr, sizeof(T) * n);
	os.close();
}

template<class T>
inline Myarr<T>::~Myarr()
{
	delete[]arr;
	n = 0;
	arr = nullptr;
}

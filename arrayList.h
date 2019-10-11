#ifndef _arrayList_H
#define _arrayList_H
/*
	基于数组实现的线性表容器
	1.insert方法是否不应该插入引用，特别是在插入引用后在erase时不应调用其析构函数，防止该引用在其他地方也有使用
	2.在数组右移时注意不应使用copy而是copy_backward
	3.模板类与模板函数的声明与定义应当在同一头文件下，不支持模板类与模板函数分离编译
*/
#include"ADT.h"
#include<iostream>
template<class T>
class arrayList:LinearList<T>{
public:
	arrayList(int initSize = 10) {
		if (initSize < 1)
			throw "illegal initSize";
		array = new T[initSize];
		arrayLength = initSize;
		size = 0;
	}
	arrayList(const arrayList<T>& list) {
		arrayLength = list.arrayLength;
		size = list.size;
		array = new T[arrayLength];
		std::copy(list.array, list.array + arrayLength, array);
	}
	~arrayList() { delete[]array; }
	bool empty()const;
	int getSize()const;
	T& get(int index) const;
	int indexof(const T& element)const;
	void erase(int index);
	void insert(int index, T& element);
private:
	T* array;
	int arrayLength;
	int size;
	void checkIndex(int index)const;
};
template<class T>
bool arrayList<T>::empty()const {
	return size == 0;
}
template<class T>
int arrayList<T>::getSize()const {
	return size;
}
template<class T>
T& arrayList<T>::get(int index)const {
	checkIndex(index);
	return array[index];
}
template<class T>
int arrayList<T>::indexof(const T& element)const {
	for (int i = 0; i < size; i++) {
		if (array[i] == element)
			return i;
	}
	return -1;
}
template<class T>
void arrayList<T>::erase(int index) {
	checkIndex(index);
	std::copy(array + index + 1, array + arrayLength, array + index);
	--arrayLength;
}
template<class T>
void arrayList<T>::insert(int index, T& element) {
	if (index > size || index < 0)
		throw "illegal index";
	if (size == arrayLength) {
		T* temp = new T[arrayLength * 2];
		std::copy(array, array + arrayLength, temp);
		delete[]array;
		array = temp;
		arrayLength *= 2;
	}
	std::copy_backward(array + index, array + size, array + index + 1);
	array[index] = element;
	size++;
}
template<class T>
void arrayList<T>::checkIndex(int index)const {
	if (index < 0 || index >= size)
		throw "illegal index";
}
#endif
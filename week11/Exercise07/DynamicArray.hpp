#pragma once

template <class T>
class DynamicArray {
	void free();
	void copyFrom(const DynamicArray& other);

protected:
	T* elems;
	unsigned allocated;
	unsigned size;

public:
	DynamicArray();
	virtual ~DynamicArray();
	DynamicArray(const DynamicArray& other);
	DynamicArray& operator=(const DynamicArray& other);
	DynamicArray(DynamicArray&& other);
	DynamicArray& operator=(DynamicArray&& other);

	virtual T& operator[](int index) = 0;
	virtual const T& operator[](int index) const = 0;
	// Отговорът е не, не можем да използваме оператор += в полморфна йерархия
	// Понеже String и Numbers не са шаблонни, а използват конкретна "инстанция" на шаблонния клас
	// тогава полиморфно += би означавало += между разногласни типове, което няма как да стане (добре).
	virtual DynamicArray& operator+=(const DynamicArray& other) = 0;
};

template <class T>
void DynamicArray<T>::free() {
	delete[] elems;
}

template <class T>
void DynamicArray<T>::copyFrom(const DynamicArray& other) {
	this->size = other.size;
	this->allocated = other.allocated;
	elems = new T[allocated];
	for (int i = 0; i < size; i++) {
		elems[i] = other.elems[i];
	}
}

template <class T>
DynamicArray<T>::DynamicArray() {
	elems = nullptr;
	size = allocated = 0;
}

template <class T>
DynamicArray<T>::~DynamicArray() {
	free();
}

template <class T>
DynamicArray<T>::DynamicArray(const DynamicArray& other) {
	copyFrom(other);
}

template <class T>
DynamicArray<T>& DynamicArray<T>::operator=(const DynamicArray& other) {
	if (this != &other) {
		free();
		copyFrom(other);
	}
	return *this;
}

template <class T>
DynamicArray<T>::DynamicArray(DynamicArray&& other) {
	this->elems = other.elems;
	other.elems = nullptr;
	this->second = other.second;
	other.second = nullptr;
	this->allocated = other.allocated;
	this->size = other.size;
}

template <class T>
DynamicArray<T>& DynamicArray<T>::operator=(DynamicArray&& other) {
	if (this != &other) {
		free();

		this->elems = other.elems;
		other.elems = nullptr;
		this->allocated = other.allocated;
		this->size = other.size;
	}
	return *this;
}

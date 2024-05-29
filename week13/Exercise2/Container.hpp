#pragma once

template <class T>
class Container {
	void free();
	void copyFrom(const Container& other);

protected:
	T* arr;
	unsigned size;

public:
	Container();
	virtual ~Container();
	Container(const Container& other);
	Container& operator=(const Container& other);
	Container(Container&& other);
	Container& operator=(Container&& other);
};

template <class T>
void Container<T>::free() {
	delete[] arr;
}

template <class T>
void Container<T>::copyFrom(const Container& other) {
	this->size = other.size;
	this->arr = new T[size];
	for (int i = 0; i < size; i++) {
		this->arr[i] = other.arr[i];
	}
}

template <class T>
Container<T>::Container() {
	this->arr = nullptr;
	size = 0;
}

template <class T>
Container<T>::~Container() {
	free();
}

template <class T>
Container<T>::Container(const Container<T>& other) {
	copyFrom(other);
}

template <class T>
Container<T>& Container<T>::operator=(const Container<T>& other) {
	if (this != &other) {
		free();
		copyFrom(other);
	}
	return *this;
}

template <class T>
Container<T>::Container(Container<T>&& other) {
	this->arr = other.arr;
	other.arr = nullptr;
}

template <class T>
Container<T>& Container<T>::operator=(Container<T>&& other) {
	if (this != &other) {
		free();

		this->arr = other.arr;
		other.arr = nullptr;
	}
	return *this;
}

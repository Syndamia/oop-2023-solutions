#pragma once

template <class T, class U>
class MixedArray {
	void free();
	void copyFrom(const MixedArray& other);

protected:
	T* first;
	U* second;
	unsigned allocated;
	unsigned size;

public:
	MixedArray();
	virtual ~MixedArray();
	MixedArray(const MixedArray& other);
	MixedArray& operator=(const MixedArray& other);
	MixedArray(MixedArray&& other);
	MixedArray& operator=(MixedArray&& other);

	void At(int index, T*& valueFirst, U*& valueSecond);

	virtual MixedArray* operator+=(MixedArray* other) = 0;
};

template <class T, class U>
void MixedArray<T, U>::free() {
	delete[] first;
	delete[] second;
}

template <class T, class U>
void MixedArray<T, U>::copyFrom(const MixedArray& other) {
	this->size = other.size;
	this->allocated = other.allocated;
	first = new T[allocated];
	second = new U[allocated];
	for (int i = 0; i < size; i++) {
		first[i] = other.first[i];
		second[i] = other.second[i];
	}
}

template <class T, class U>
MixedArray<T, U>::MixedArray() {
	first = second = nullptr;
	size = allocated = 0;
}

template <class T, class U>
MixedArray<T, U>::~MixedArray() {
	free();
}

template <class T, class U>
MixedArray<T, U>::MixedArray(const MixedArray& other) {
	copyFrom(other);
}

template <class T, class U>
MixedArray<T, U>& MixedArray<T, U>::operator=(const MixedArray& other) {
	if (this != &other) {
		free();
		copyFrom(other);
	}
	return *this;
}

template <class T, class U>
MixedArray<T, U>::MixedArray(MixedArray&& other) {
	this->first = other.first;
	other.first = nullptr;
	this->second = other.second;
	other.second = nullptr;
	this->allocated = other.allocated;
	this->size = other.size;
}

template <class T, class U>
MixedArray<T, U>& MixedArray<T, U>::operator=(MixedArray&& other) {
	if (this != &other) {
		free();

		this->first = other.first;
		other.first = nullptr;
		this->second = other.second;
		other.second = nullptr;
		this->allocated = other.allocated;
		this->size = other.size;
	}
	return *this;
}

template <class T, class U>
void MixedArray<T, U>::At(int index, T*& valueFirst, U*& valueSecond) {
	if (index < 0) throw "Index out of bounds!";

	if (index % 2 == 0) {
		valueFirst = *first[index / 2];
		valueSecond = nullptr;
	}
	else {
		valueFirst = nullptr;
		valueSecond = *second[(index - 1) / 2];
	}
}

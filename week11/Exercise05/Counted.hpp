#pragma once

template <class T>
class Counted {
	T elem;
	unsigned count;

public:
	T& GetElem();
	unsigned GetCount();

	Counted& operator++();
	Counted operator++(int);
	Counted& operator--();
	Counted operator--(int);
	Counted& operator+=(int countChange);
	Counted& operator-=(int countChange);
};

template <class T>
T& Counted<T>::GetElem() {
	return elem;
}

template <class T>
unsigned Counted<T>::GetCount() {
	return count;
}

template <class T>
Counted<T>& Counted<T>::operator++() {
	++count;
	return *this;
}

template <class T>
Counted<T> Counted<T>::operator++(int) {
	count++;
	return *this;
}

template <class T>
Counted<T>& Counted<T>::operator--() {
	--count;
	return *this;
}

template <class T>
Counted<T> Counted<T>::operator--(int) {
	count--;
	return *this;
}

template <class T>
Counted<T>& Counted<T>::operator+=(int countChange) {
	count += countChange;
	return *this;
}

template <class T>
Counted<T>& Counted<T>::operator-=(int countChange) {
	count -= countChange;
	return *this;
}

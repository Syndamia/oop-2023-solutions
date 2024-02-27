#include <iostream>

struct DynamicIntArray {
	int* arrayPointer;
	int allocatedSize;
	int elementsCount;
};

void resize(DynamicIntArray& dynarr) {
	int* biggerArray = new int[dynarr.allocatedSize * 2];

	for (int i = 0; i < dynarr.elementsCount; i++) {
		biggerArray[i] = dynarr.arrayPointer[i];
	}

	delete[] dynarr.arrayPointer;
	dynarr.arrayPointer = biggerArray;
	dynarr.allocatedSize *= 2;
}

void addToEnd(DynamicIntArray& dynarr, int newElem) {
	if (dynarr.allocatedSize == dynarr.elementsCount) {
		resize(dynarr);
	}

	dynarr.arrayPointer[dynarr.elementsCount++] = newElem;
}

int main() {
	DynamicIntArray mydynarr = { new int[2], 2, 0 };
	addToEnd(mydynarr, 18);
	addToEnd(mydynarr, 6);
	addToEnd(mydynarr, 100);
	addToEnd(mydynarr, -773);
	addToEnd(mydynarr, 840);
	addToEnd(mydynarr, -1000);

	resize(mydynarr);

	std::cout << mydynarr.allocatedSize << " " << mydynarr.elementsCount << std::endl;
	for (int i = 0; i < mydynarr.elementsCount; i++) {
		std::cout << mydynarr.arrayPointer[i] << " ";
	}

	delete[] mydynarr.arrayPointer;
}

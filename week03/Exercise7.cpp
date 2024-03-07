#include <iostream>

int max(int a, int b) {
	return (a > b) ? a : b;
}

struct Interval {
private:
	int left;
	int right;
public:
	Interval(int left, int right) {
		if (left > right) throw "Left cannot be greater than right!";

		this->left  = left;
		this->right = right;
	}

	int getLeft() {
		return left;
	}
	int getRight() {
		return right;
	}

	bool TryMergeWith(Interval*& other) {
		if (this == nullptr || other == nullptr || other == this || right < other->left || other->right < left)
			return false;

		left  = max(left,  other->left);
		right = max(right, other->right);

		delete other;
		other = nullptr;

		return true;
	}
};

int main() {
	Interval* ivs[] = { new Interval(0, 3),   new Interval(3, 5),   new Interval(3, 8),
	                    new Interval(10, 15),
	                    new Interval(30, 80), };
	int size = 5;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			ivs[i]->TryMergeWith(ivs[j]);
		}
	}

	for (int i = 0; i < size; i++) {
		if (ivs[i] != nullptr) {
			std::cout << "[" << ivs[i]->getLeft() << ", " << ivs[i]->getRight() << "]";
			delete ivs[i];
		}
	}
	std::cout << std::endl;
}

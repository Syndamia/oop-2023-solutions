#include <cstring>

struct WoodPlank {
private:
	unsigned height;
	unsigned width;
	unsigned depth;
	float price;
	char type[1024];

	void copyFrom(const WoodPlank& other) {
		this->height = other.height;
		this->width = other.width;
		this->depth = other.depth;
		this->price = other.price;
		strcpy(this->type, other.type);
	}

public:
	unsigned GetHeight() {
		return height;
	}
	void SetHeight(unsigned newHeight) {
		height = newHeight;
	}

	unsigned GetWidth() {
		return width;
	}
	void SetWidth(unsigned newWidth) {
		width = newWidth;
	}

	unsigned GetDepth() {
		return depth;
	}
	void SetDepth(unsigned newDepth) {
		depth = newDepth;
	}

	float GetPrice() {
		return price;
	}
	void SetPrice(float newPrice) {
		price = newPrice;
	}

	const char* GetType() {
		return type;
	}
	void SetType(char newType[1024]) {
		strcpy(type, newType);
	}

	WoodPlank(const WoodPlank& other) {
		copyFrom(other);
	}
	WoodPlank& operator=(const WoodPlank& other) {
		if (this != &other) {
			copyFrom(other);
		}
		return *this;
	}
};

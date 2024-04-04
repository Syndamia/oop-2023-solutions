#include "Exercise1.h"
#include <cstring>

/* Private */

void Recipe::resize() {
	allocated *= 2;
	Ingredient* moreIngredients = new Ingredient[allocated];
	for (int i = 0; i < lastIndex; i++) {
		moreIngredients[i] = ingredients[i];
	}
	delete[] ingredients;
	ingredients = moreIngredients;
}

void Recipe::free() {
	delete[] ingredients;
}
void Recipe::copyFrom(const Recipe& other) {
	this->lastIndex = other.lastIndex;
	this->allocated = other.allocated;
	this->ingredients = new Ingredient[allocated];
	for (int i = 0; i < lastIndex; i++) {
		this->ingredients[i] = other.ingredients[i];
	}
}

/* Public */

Recipe::Recipe() {
	ingredients = nullptr;
	lastIndex = allocated = 0;
}
Recipe::~Recipe() {
	free();
}
Recipe::Recipe(const Recipe& other) {
	copyFrom(other);
}
Recipe& Recipe::operator=(const Recipe& other) {
	if (this != &other) {
		free();
		copyFrom(other);
	}
	return *this;
}
Recipe::Recipe(Recipe&& other) {
	this->ingredients = other.ingredients;
	this->lastIndex = other.lastIndex;
	this->allocated = other.allocated;

	other.ingredients = nullptr;
}
Recipe& Recipe::operator=(Recipe&& other) {
	if (this != &other) {
		free();

		this->ingredients = other.ingredients;
		this->lastIndex = other.lastIndex;
		this->allocated = other.allocated;

		other.ingredients = nullptr;
	}
	return *this;
}

void Recipe::AddIngredient(const Ingredient& newIng) {
	if (lastIndex == allocated) {
		resize();
	}
	ingredients[lastIndex++] = newIng;
}
void Recipe::RemoveIngredient(const char* name) {
	int index = 0;
	while (index < lastIndex && strcmp(ingredients[index].name, name) != 0) {
		index++;
	}
	if (index == lastIndex) {
		return;
	}

	while (index < lastIndex) {
		ingredients[index] = ingredients[index+1];
		index++;
	}
	lastIndex--;
}

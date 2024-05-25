#pragma once

class IndexArray {
	void free();
	void copyFrom(const IndexArray& other);

protected:
	int *indecies;
	unsigned size;

public:
	IndexArray();
	virtual ~IndexArray();
	IndexArray(const IndexArray& other);
	IndexArray& operator=(const IndexArray& other);
	IndexArray(IndexArray&& other);
	IndexArray& operator=(IndexArray&& other);
};

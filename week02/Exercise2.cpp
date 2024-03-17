#include <iostream>

struct Cell {
private:
	int value;
	char op;
	Cell* left;
	Cell* right;

public:
	Cell() {
		SetValue(0);
	}
	Cell(int value) {
		SetValue(value);
	}
	Cell(char op, Cell* left, Cell* right) {
		SetFormula(op, left, right);
	}

	int Evaluate() {
		switch (op) {
			case '+': value = left->GetValue() + right->GetValue(); break;
			case '-': value = left->GetValue() - right->GetValue(); break;
			case '*': value = left->GetValue() * right->GetValue(); break;
			case '/': value = left->GetValue() / right->GetValue(); break;
		}
		return 0;
	}

	int GetValue() {
		return value;
	}
	void SetValue(int value) {
		op = '\0';
		left = right = nullptr;
		this->value = value;
	}
	void SetFormula(char op, Cell* left, Cell* right) {
		this-> op = op;
		this->left = left;
		this->right = right;
		Evaluate();
	}
};

struct Table {
private:
	Cell** cells;
	int rows;
	int cols;

	void evaluateAllCells() {
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < cols; j++) {
				cells[i][j].Evaluate();
			}
		}
	}

public:
	Table(int rows, int cols) {
		this->rows = rows;
		this->cols = cols;
		cells = new Cell*[rows];
		for (int i = 0; i < rows; i++) {
			cells[i] = new Cell[cols];
		}
	}
	~Table() {
		for (int i = 0; i < rows; i++) {
			delete[] cells[i];
		}
		delete[] cells;
	}

	Cell* GetCell(int row, int col) {
		return &cells[row][col];
	}
	void SetCell(int row, int col, Cell cell) {
		cells[row][col] = cell;
	}

	void UpdateCell(int row, int col, int value) {
		cells[row][col].SetValue(value);
		evaluateAllCells();
	}
	void UpdateCell(int row, int col, char op, Cell* left, Cell* right) {
		cells[row][col].SetFormula(op, left, right);
		evaluateAllCells();
	}

	void Print() {
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < cols; j++) {
				std::cout << "|" << cells[i][j].GetValue();
			}
			std::cout << "|" << std::endl;
		}
	}
};

int main() {
	Table mytable(2, 2);
	mytable.SetCell(0, 0, Cell(5));
	mytable.SetCell(0, 1, Cell(7));
	mytable.SetCell(1, 0, Cell('*', mytable.GetCell(0, 0), mytable.GetCell(0, 1)));

	mytable.Print();

	return 0;
}

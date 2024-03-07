#include <iostream>

const int WHITE = 0;
const int BLACK = 1;

struct ChessPiece {
	int color;
	char figure;

	ChessPiece(int color, int figure) {
		this->color = color;
		this->figure = figure;
	}
};

struct ChessBoard {
private:
	ChessPiece*** board;
	int N;

	void setColumnPieces(int column, char pieceChar) {
		board[column][0]   = new ChessPiece(WHITE, pieceChar);
		board[column][1]   = new ChessPiece(WHITE, 'P');
		for (int i = 2; i < N-2; i++) {
			board[column][i] = nullptr;
		}
		board[column][N-2] = new ChessPiece(BLACK, 'P');
		board[column][N-1] = new ChessPiece(BLACK, pieceChar);
	}

	void fillBoardWithPieces() {
		for (int column = 0; column < N; column++) {
			switch (column % 8) {
				case 0: case 7:
					setColumnPieces(column, 'R'); break;
				case 1: case 6:
					setColumnPieces(column, 'K'); break;
				case 2: case 5:
					setColumnPieces(column, 'B'); break;
				case 3:
					setColumnPieces(column, 'I'); break;
				case 4:
					setColumnPieces(column, 'Q'); break;
			}
		}
	}

public:
	ChessBoard(int N) {
		if (N < 5) {
			throw "Board size cannot be less than 5!";
		}

		board = new ChessPiece**[N];
		for (int i = 0; i < N; i++) {
			board[i] = new ChessPiece*[N];
		}
		this->N = N;

		fillBoardWithPieces();
	}
	~ChessBoard() {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				delete board[i][j];
			}
			delete[] board[i];
		}
		delete[] board;
	}

	void Print() {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (board[j][i] == nullptr)
					std::cout << ' ';
				else
					std::cout << board[j][i]->figure;
			}
			std::cout << std::endl;
		}
	}
};

int main() {
	ChessBoard cb(10);
	cb.Print();
}

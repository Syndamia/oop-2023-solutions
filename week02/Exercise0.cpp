#include <iostream>

/*
 * а) подточка
 */

void boardCounts(char** board, int N, int& totalX, int& totalO, int& longestX, int& longestO) {
	totalX = totalO = longestX = longestO = 0;

	// Обща бройка Х и О
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (board[i][j] == 'X')
				totalX++;
			else
				totalO++;
		}
	}

	for (int i = 0; i < N; i++) {
		int rowXs = 0, rowOs = 0;
		for (int j = 0; j < N; j++) {
			// Когато редицата от Х е прекъсната, запазваме ако е най-дългата и връщаме
			if (board[i][j] == 'X')
				rowXs++;
			else {
				if (rowXs > longestX) {
					longestX = rowXs;
				}
				rowXs = 0;
			}

			// Когато редицата от О е прекъсната, запазваме ако е най-дългата и връщаме
			if (board[i][j] == 'O')
				rowOs++;
			else {
				if (rowOs > longestX) {
					longestX = rowOs;
				}
				rowOs = 0;
			}
		}
		if (rowXs > longestX) longestX = rowXs;
		if (rowOs > longestO) longestO = rowOs;
	}
}

void printResult(const char* nameX, const char* nameO, int totalX, int totalO, int longestX, int longestO) {
	std::cout << nameX << ": Total - " << totalX << ", Longest - " << longestX << std::endl;
	std::cout << nameO << ": Total - " << totalO << ", Longest - " << longestO << std::endl;
}

void mainA() {
	char nameX[1024];
	char nameO[1024];
	std::cin.getline(nameX, 1024);
	std::cin.getline(nameO, 1024);

	std::cin.clear();

	int N;
	std::cin >> N;

	char** board = new char*[N];
	for (int i = 0; i < N; i++) {
		board[i] = new char[N];
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			std::cin >> board[i][j];
		}
	}

	int totalX, totalO, longestX, longestO;
	boardCounts(board, N, totalX, totalO, longestX, longestO);
	printResult(nameX, nameO, totalX, totalO, longestX, longestO);

	for (int i = 0; i < N; i++) {
		delete[] board[i];
	}
	delete[] board;
}

/*
 * б) подточка
 * Почти същото е, намерете разликите
 */

struct GameBoard {
	char** board;
	int N;
};

void boardCounts(GameBoard gb, int& totalX, int& totalO, int& longestX, int& longestO) {
	totalX = totalO = longestX = longestO = 0;

	// Обща бройка Х и О
	for (int i = 0; i < gb.N; i++) {
		for (int j = 0; j < gb.N; j++) {
			if (gb.board[i][j] == 'X')
				totalX++;
			else
				totalO++;
		}
	}

	for (int i = 0; i < gb.N; i++) {
		int rowXs = 0, rowOs = 0;
		for (int j = 0; j < gb.N; j++) {
			// Когато редицата от Х е прекъсната, запазваме ако е най-дългата и връщаме
			if (gb.board[i][j] == 'X')
				rowXs++;
			else {
				if (rowXs > longestX) {
					longestX = rowXs;
				}
				rowXs = 0;
			}

			// Когато редицата от О е прекъсната, запазваме ако е най-дългата и връщаме
			if (gb.board[i][j] == 'O')
				rowOs++;
			else {
				if (rowOs > longestX) {
					longestX = rowOs;
				}
				rowOs = 0;
			}
		}
		if (rowXs > longestX) longestX = rowXs;
		if (rowOs > longestO) longestO = rowOs;
	}
}

void mainB() {
	char nameX[1024];
	char nameO[1024];
	std::cin.getline(nameX, 1024);
	std::cin.getline(nameO, 1024);

	std::cin.clear();

	GameBoard gb;
	std::cin >> gb.N;

	gb.board = new char*[gb.N];
	for (int i = 0; i < gb.N; i++) {
		gb.board[i] = new char[gb.N];
	}

	for (int i = 0; i < gb.N; i++) {
		for (int j = 0; j < gb.N; j++) {
			std::cin >> gb.board[i][j];
		}
	}

	int totalX, totalO, longestX, longestO;
	boardCounts(gb, totalX, totalO, longestX, longestO);
	printResult(nameX, nameO, totalX, totalO, longestX, longestO);

	for (int i = 0; i < gb.N; i++) {
		delete[] gb.board[i];
	}
	delete[] gb.board;
}

/*
 * в) подточка
 */

struct BoardCounts {
	int totalX;
	int totalO;
	int longestX;
	int longestO;
};

BoardCounts boardCounts(GameBoard gb) {
	BoardCounts bc = { 0, 0, 0, 0 };

	// Обща бройка Х и О
	for (int i = 0; i < gb.N; i++) {
		for (int j = 0; j < gb.N; j++) {
			if (gb.board[i][j] == 'X')
				bc.totalX++;
			else
				bc.totalO++;
		}
	}

	for (int i = 0; i < gb.N; i++) {
		int rowXs = 0, rowOs = 0;
		for (int j = 0; j < gb.N; j++) {
			// Когато редицата от Х е прекъсната, запазваме ако е най-дългата и връщаме
			if (gb.board[i][j] == 'X')
				rowXs++;
			else {
				if (rowXs > bc.longestX) {
					bc.longestX = rowXs;
				}
				rowXs = 0;
			}

			// Когато редицата от О е прекъсната, запазваме ако е най-дългата и връщаме
			if (gb.board[i][j] == 'O')
				rowOs++;
			else {
				if (rowOs > bc.longestX) {
					bc.longestX = rowOs;
				}
				rowOs = 0;
			}
		}
		if (rowXs > bc.longestX) bc.longestX = rowXs;
		if (rowOs > bc.longestO) bc.longestO = rowOs;
	}
	return bc;
}

void printResult(const char* nameX, const char* nameO, const BoardCounts& bc) {
	std::cout << nameX << ": Total - " << bc.totalX << ", Longest - " << bc.longestX << std::endl;
	std::cout << nameO << ": Total - " << bc.totalO << ", Longest - " << bc.longestO << std::endl;
}

void mainC() {
	char nameX[1024];
	char nameO[1024];
	std::cin.getline(nameX, 1024);
	std::cin.getline(nameO, 1024);

	std::cin.clear();

	GameBoard gb;
	std::cin >> gb.N;

	gb.board = new char*[gb.N];
	for (int i = 0; i < gb.N; i++) {
		gb.board[i] = new char[gb.N];
	}

	for (int i = 0; i < gb.N; i++) {
		for (int j = 0; j < gb.N; j++) {
			std::cin >> gb.board[i][j];
		}
	}

	BoardCounts bc = boardCounts(gb);
	printResult(nameX, nameO, bc);

	for (int i = 0; i < gb.N; i++) {
		delete[] gb.board[i];
	}
	delete[] gb.board;
}

/*
 * г)
 */

struct Game {
	char nameX[1024];
	char nameO[1024];
	GameBoard gb;
	BoardCounts bc;
};

void printResult(const Game& game) {
	std::cout << game.nameX << ": Total - " << game.bc.totalX << ", Longest - " << game.bc.longestX << std::endl;
	std::cout << game.nameO << ": Total - " << game.bc.totalO << ", Longest - " << game.bc.longestO << std::endl;
}

void mainD() {
	Game game;
	std::cin.getline(game.nameX, 1024);
	std::cin.getline(game.nameO, 1024);

	std::cin.clear();

	std::cin >> game.gb.N;

	game.gb.board = new char*[game.gb.N];
	for (int i = 0; i < game.gb.N; i++) {
		game.gb.board[i] = new char[game.gb.N];
	}

	for (int i = 0; i < game.gb.N; i++) {
		for (int j = 0; j < game.gb.N; j++) {
			std::cin >> game.gb.board[i][j];
		}
	}

	game.bc = boardCounts(game.gb);
	printResult(game);

	for (int i = 0; i < game.gb.N; i++) {
		delete[] game.gb.board[i];
	}
	delete[] game.gb.board;
}

int main() {
	mainA();
	mainB();
	mainC();
	mainD();
}

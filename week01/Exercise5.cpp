#include <iostream>
#include <cstring>

struct User {
	char name[1024];
	User** friends;
	int friendsSize;
};

User* findUserByName(User* users, int N, char name[1024]) {
	for (int i = 0; i < N; i++) {
		if (&users[i] == nullptr) continue;
		if (strcmp(users[i].name, name) == 0) {
			return &users[i];
		}
	}
	return nullptr;
}

struct VisitedUsers {
	User** visited;
	int size;
};
VisitedUsers newVisitedUsers(int size) {
	return { new User*[size], size };
}
void freeVisitedUsers(VisitedUsers& vu) {
	delete[] vu.visited;
}
bool visited(VisitedUsers& vu, User* user) {
	for (int i = 0; i < vu.size; i++) {
		if (vu.visited[i] == user) return true;
	}
	return false;
}
void addUser(VisitedUsers& vu, User* user) {
	for (int i = 0; i < vu.size; i++) {
		if (vu.visited[i] == nullptr) {
			vu.visited[i] = user;
			return;
		}
	}
}
void removeUser(VisitedUsers& vu, User* user) {
	for (int i = 0; i < vu.size; i++) {
		if (vu.visited[i] == user) {
			vu.visited[i] = nullptr;
			return;
		}
	}
}

int connectionCount(User* user, VisitedUsers& vu) {
	addUser(vu, user);

	int sum = 0;
	for (int i = 0; i < user->friendsSize; i++) {
		if (!visited(vu, user->friends[i])) {
			sum += 1 + connectionCount(user->friends[i], vu);
		}
	}
	return sum;
}

int main() {
	int N;
	std::cin >> N;
	User* users = new User[N];
	int newUserOn = 0;

	char currentName[1024];
	std::cin.ignore();
	for (int i = 0; i < N; i++) {
		std::cin.getline(currentName, 1024);

		int friendsCount;
		std::cin >> friendsCount;

		User* currentUser = findUserByName(users, N, currentName);
		if (currentUser == nullptr) {
			currentUser = &users[newUserOn++];
		}

		strcpy(currentUser->name, currentName);
		currentUser->friends = new User*[friendsCount];
		currentUser->friendsSize = friendsCount;

		std::cin.ignore();
		for (int j = 0; j < friendsCount; j++) {
			std::cin.getline(currentName, 1024);

			User* currentFriend = findUserByName(users, N, currentName);
			if (currentFriend == nullptr) {
				strcpy(users[newUserOn].name, currentName);
				currentFriend = &users[newUserOn++];
			}
			currentUser->friends[j] = currentFriend;
		}
	}

	std::cin.getline(currentName, 1024);
	User* findConnections = findUserByName(users, N, currentName);
	VisitedUsers vu = newVisitedUsers(N);
	std::cout << connectionCount(findConnections, vu) << std::endl;

	freeVisitedUsers(vu);
	for (int i = 0; i < N; i++) {
		delete[] users[i].friends;
	}
	delete[] users;
}

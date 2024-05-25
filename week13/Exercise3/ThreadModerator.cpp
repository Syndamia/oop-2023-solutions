#include "ThreadModerator.h"
#include <cstring>

void ThreadModerator::RemoveMessage(Thread& thread, unsigned index) {
	if (index >= thread.size) {
		throw "Index out of range!";
	}

	delete[] thread.messages[index];
	for (unsigned i = index; i < thread.size - 1; i++) {
		thread.messages[i] = thread.messages[i-1];
	}
	thread.size--;
}

void ThreadModerator::RemoveByUser(Thread& thread, const User& poster) {
	unsigned nameLen = strlen(poster.GetUsername());
	for (unsigned i = 0; i < thread.size; i++) {
		if (strncmp(thread.messages[i], poster.GetUsername(), nameLen) == 0) {
			RemoveMessage(thread, i);
			i--;
		}
	}
}

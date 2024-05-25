#include "UserModerator.h"

void UserModerator::BanUser(User& user) {
	user.banned = true;
}

void UserModerator::UnbanUser(User& user) {
	user.banned = false;
}

#pragma once
#include "User.h"

class UserModerator : virtual public User {
public:
	void BanUser(User& user);
	void UnbanUser(User& user);
};

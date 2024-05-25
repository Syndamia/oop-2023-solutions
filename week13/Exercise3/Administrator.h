#pragma once
#include "UserModerator.h"
#include "ThreadModerator.h"

class Administrator : public UserModerator, public ThreadModerator {
};

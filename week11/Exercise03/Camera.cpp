#include "Camera.h"
#include "Electronics.h"
#include <iostream>

void Camera::Print() {
	Electroics::Print();
	std::cout << ' ' << resolution;
}

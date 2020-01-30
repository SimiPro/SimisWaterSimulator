#pragma once

class PhysicsAnimation {

public:
	// cumulate forces, integrate, solve collisions
	virtual void onStep(double dt) = 0;
	virtual void timeIntegration(double dt) {
		// TODO; implement default integration schema
		// use some default time integration schema here
	}

};
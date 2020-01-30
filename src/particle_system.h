#pragma once

struct Particle3 {
	Vec3 position;
	Vec3 velocity;
	Vec3 force;
};

typedef std::vector<Particle3> Particles3;
typedef std::vector<Vec3> Vec3Array:
class ParticleSystemData {
	Vec3Array positions;
	Vec3Array velocities;
	Vec3Array forces;
public:
	void addParticle(const Vec3 &pos, const Vec3 &velo = Vec3(), const Vec3 &force = Vec3()) {
		positions.push_back(pos);
		velocities.push_back(velo);
		forces.push_back(force);
	}

};

class ParticleSystemSolver : public PhysicsAnimation {
	ParticleSystemDataPtr data;

	ParticleSystemSolver() {
		data = std::make_shared<ParticleSystemData>();
	}

	virtual void onStep(double dt) override {
		accumulateForces(dt);
		timeIntegration(dt);
		resolveCollisions(dt);
	}

	void accumulateForces(double dt) {

	}

	void resolveCollisions() {

	}

};




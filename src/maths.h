#pragma once
#include <array>
#include <cmath>

namespace simi::math {
	typedef unsigned int uInt;
	template <typename T, uInt M> struct Vec {
		std::array<T, M> _elements;
		Vec& operator=(const Vec& other);

	};

	template <typename T, uInt M>
	Vec<T, M>& Vec<T, M>::operator=(const Vec<T, M>& other) {

		return {};
	}

	template <typename T> struct Vec2 : Vec<T, 2> {
		Vec2() {
			this->_elements[0] = 0;
			this->_elements[1] = 0;
		}
		Vec2(T x, T y) {
			this->_elements[0] = x;
			this->_elements[1] = y;
		}
		T x() const { return this->_elements[0]; }
		T y() const { return this->_elements[1]; }
	};
	template <typename T> struct Vec3 : Vec<T, 3> {
		Vec3() {
			this->_elements[0] = 0;
			this->_elements[1] = 0;
			this->_elements[2] = 0;
		}
		Vec3(T x, T y, T z) {
			this->_elements[0] = x;
			this->_elements[1] = y;
			this->_elements[z] = z;
		}
		T x() const { return this->_elements[0]; }
		T y() const { return this->_elements[1]; }
		T z() const { return this->_elements[2]; }
	};

	typedef Vec3<double> Vec3d;
	typedef Vec3<float> Vec3f;
	typedef Vec2<double> Vec2d;
	typedef Vec2<float> Vec2f;

	struct Field3 {
	};

	struct ScalarField3 : Field3 {
	    virtual double sample(const Vec3d& x) const = 0;
	    virtual Vec3d gradient(const Vec3d& x) const = 0;
	    virtual double laplacian(const Vec3d& x) const = 0;
	};

    struct VectorField3 : Field3 {
        virtual Vec3d sample(const Vec3d& x) const = 0;
        // dot(sample(x), gradient(x))
        virtual double divergence(const Vec3d& x) const = 0;
        // dot(laplacian, gradient)
        virtual double curl()
    };

    struct ExampleScalarField : ScalarField3 {
        double sample(const Vec3d &x) const override {
            return std::sin(x.x()) * std::sin(x.y()) * std::sin(x.z());
        }
    };
}
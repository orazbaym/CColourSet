#include <iostream>
#include <cmath>
using namespace std;

class CPoint3D {
    public:
        double x, y, z;
        CPoint3D (double dX = 0.0, double dY = 0.0, double dZ = 0.0)
        : x(dX), y(dY), z(dZ) {}

        CPoint3D operator + (const CPoint3D& point) const {
                return CPoint3D(x + point.x, y + point.y, z + point.z);
        }

        CPoint3D operator - (const CPoint3D& point) const {
                return CPoint3D(x - point.x, y - point.y, z - point.z);
        }

        CPoint3D operator * (double dFactor) const {
                return CPoint3D(x * dFactor, y * dFactor, z * dFactor);
        }

        CPoint3D operator / (double dFactor) const {
                return CPoint3D(x / dFactor, y / dFactor, z / dFactor);
        }


        double SquaredLength () const {
                return (x * x) + (y * y) + (z * z);
        }

        double Length () const {
                return sqrt(SquaredLength());
        }

        double SquaredDistance (const CPoint3D& v) const {
                return ((x - v.x) * (x - v.x) + (y - v.y) * (y - v.y) + (z - v.z) * (z - v.z));
        };

        double Distance (const CPoint3D& v) const {
                return sqrt(SquaredDistance(v));
        }

        CPoint3D Cross(const CPoint3D& v) const {
                return CPoint3D(
                    y * v.z - z * v.y,
                    z * v.x - x * v.z,
                    x * v.y - y * v.x
                );
        }

        double Dot(const CPoint3D& v) const {
                return x * v.x + y * v.y + z * v.z;
        }

        double distance_D(const CPoint3D& A, const CPoint3D& B) const {
                // return distance = (|(Px - Ax)*(-By +Ay) + (Cy - Ay)*(Bx - Ax)|) / (sqrt(pow((-By + Ay), 2) + pow((Bx - Ax),2)))
        }
};

int main() {
    return 0;
}

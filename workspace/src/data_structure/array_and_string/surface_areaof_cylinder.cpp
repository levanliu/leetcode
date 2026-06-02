// Surface area of a cylinder: 2*pi*r^2 + 2*pi*r*h
#include <cmath>

namespace ns_data_structure_array_and_string_surface_area {

class Solution {
public:
    static double surfaceArea(double r, double h) {
        return (2.0 * M_PI * r * r) + (2.0 * M_PI * r * h);
    }
};

}  // namespace ns_data_structure_array_and_string_surface_area

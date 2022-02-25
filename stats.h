#include <vector>
#include <math.h>

namespace Statistics {
    class Stats {
    public:
        double average, max, min;
        Stats() {
            average = NAN;
            max = NAN;
            min = NAN;
        }
    };

    Stats ComputeStatistics(const std::vector<double>& );
}

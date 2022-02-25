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

class IAlerter {
public:
    virtual void setAlert(bool isAlert) = 0;
};

class EmailAlert : public IAlerter {
public:
    bool emailSent = false;
    virtual void setAlert(bool isAlert) {
        emailSent = isAlert;
    }
};

class LEDAlert : public IAlerter {
public:
    bool ledGlows = false;
    virtual void setAlert(bool isAlert) {
        ledGlows = isAlert;
    }
};

class StatsAlerter {
    float maxThreshold;
    std::vector<IAlerter*> alerts;
public:
    StatsAlerter(float maxThreshold, std::vector<IAlerter*>& alerts) {
        this->maxThreshold = maxThreshold;
        this->alerts = alerts;
    }

    void checkAndAlert(const std::vector<double>& );
};

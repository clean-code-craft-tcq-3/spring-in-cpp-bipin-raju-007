#include "stats.h"

Statistics::Stats Statistics::ComputeStatistics(const std::vector<double>& list_of_numbers) {
    //Implement statistics here
    Stats stat;
    if (list_of_numbers.size() == 0)
        return stat;

    double sum_of_numbers = 0;
    double max = list_of_numbers[0];
    double min = list_of_numbers[0];

    for (auto number: list_of_numbers) {
        sum_of_numbers += number;
        if (number > max)
            max = number;
        if (number < min)
            min = number;
    }

    stat.average = sum_of_numbers/list_of_numbers.size();
    stat.max = max;
    stat.min = min;
    return stat;
}

void StatsAlerter::checkAndAlert(const std::vector<double>& list_of_numbers) {
    for (auto number: list_of_numbers) {
        if (number > maxThreshold) {
            for (auto alertType: alerts)
                alertType->setAlert(true);
        }
    }
}

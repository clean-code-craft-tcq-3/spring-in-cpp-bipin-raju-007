#include "stats.h"
using namespace Statistics;

Stats ComputeStatistics(const std::vector<double>& list_of_numbers) {
    //Implement statistics here
    Stats stat;

    double sum_of_numbers = 0;
    double min = list_of_numbers[0];
    double max = list_of_numbers[0];

    for (auto number: list_of_numbers) {
        sum_of_numbers += number;
        if (number < min)
            min = number;
        if (number > max)
            max = number;
    }

    if (list_of_numbers.size() == 0) {
        return stat;
    } else {
        stat.average = sum_of_numbers/list_of_numbers.size();
        stat.min = min;
        stat.max = max;
        return stat;
    }
}

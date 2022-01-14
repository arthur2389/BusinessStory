#include "MathServices.h"  
	
std::vector<double> MathServices::get_rands_with_average(double average, double range, int size)
{
    std::vector<double> nums_in_range;
    std::random_device rd; 
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distr(average - range, average + range); 

    nums_in_range.reserve(size);

    for(int i = 0; i < size; ++i)
        nums_in_range.push_back(distr(gen));

    // Not a straightforward method here: Aligning the random numbers so it will fit the average
    // It can be inceremening or decrementing the vector values until aligned to given average
    // Also mind that the range can be ocationaly violated here - this is not something that 
    // will hurt the caller of the function by any means
    double delta_sum = average * size - std::accumulate(nums_in_range.begin(),
                                                        nums_in_range.end(),
                                                        0);
    auto op = delta_sum > 0 ? [] (double& n) mutable {++n;} : [] (double& n) mutable {--n;}; 
    int abs_delta = std::abs(static_cast<int>(delta_sum));

    for (int i = 0; i < abs_delta; ++i)
        op(nums_in_range[i % size]);             

    return nums_in_range;
}

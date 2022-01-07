// Business Story Application
// By Arthur Farber 2022
// https://github.com/arthur2389/BusinessStory

#include "TimePeriod.h"  

TimePeriod::FIELD_STATUS TimePeriod::set_tax_rate(std::string& tax_rate)
{
    TimePeriod::FIELD_STATUS status; 
    double value;
    std::tie(status, value) = convert_to_valid_numeric(tax_rate);
    if (status != VALID) return status;

    m_tax_rate = std::make_tuple(tax_rate, value);
    return status;
}

TimePeriod::FIELD_STATUS TimePeriod::set_debt_interest_rate(std::string& debt_interest_rate)
{
    TimePeriod::FIELD_STATUS status; 
    double value;
    std::tie(status, value) = convert_to_valid_numeric(debt_interest_rate);
    if (status != VALID) return status;

    m_debt_interest_rate = std::make_tuple(debt_interest_rate, value);
    return status;
}

TimePeriod::FIELD_STATUS TimePeriod::set_return_on_capital(std::string& roc_average,
								                           std::string& roc_std_deviation)
{
    TimePeriod::FIELD_STATUS status_avg, status_std_dev; 
    double value_avg, value_std_dev;    
    std::tie(status_avg, value_avg) = convert_to_valid_numeric(roc_average);
    if (status_avg != VALID) return status_avg;
    std::tie(status_std_dev, value_std_dev) = convert_to_valid_numeric(roc_average);
    if (status_std_dev != VALID) return status_std_dev;

    m_return_on_capital_avarage = std::make_tuple(roc_average, value_avg);
    m_return_on_capital_std_deviation = std::make_tuple(roc_std_deviation, value_std_dev);

    return status_avg;
}                                                           

TimePeriod::FIELD_STATUS TimePeriod::set_num_of_years(std::string& number_of_years)
{
    TimePeriod::FIELD_STATUS status; 
    double value;
    std::tie(status, value) = convert_to_valid_numeric(number_of_years);
    if (status != VALID) return status;

    // ToDo solve the int issue
    m_debt_interest_rate = std::make_tuple(number_of_years, int(value));
    return status;
}

TimePeriod::FIELD_STATUS TimePeriod::set_capital_distribution_profile(std::string& capital_distribution_profile)
{
    TimePeriod::FIELD_STATUS status = assest_profile_name(capital_distribution_profile);
    if (status != VALID) return status;

    m_capital_distribution_profile = capital_distribution_profile;
    return status;
}

TimePeriod::FIELD_STATUS TimePeriod::set_debt_issuance_profile(std::string& debt_issuance_profile)
{
    TimePeriod::FIELD_STATUS status = assest_profile_name(debt_issuance_profile);
    if (status != VALID) return status;

    m_debt_issuence_profile = debt_issuance_profile;
    return status;
}

TimePeriod::FIELD_STATUS TimePeriod::set_debt_repayment_profile(std::string& debt_repayment_profile)
{
    TimePeriod::FIELD_STATUS status = assest_profile_name(debt_repayment_profile);
    if (status != VALID) return status;

    m_debt_repayment_profile = debt_repayment_profile;
    return status;
}

TimePeriod::FIELD_STATUS TimePeriod::set_paid_in_capital_profile(std::string& paid_in_capital_profile)
{
    TimePeriod::FIELD_STATUS status = assest_profile_name(paid_in_capital_profile);
    if (status != VALID) return status;

    m_paid_in_capital_profile = paid_in_capital_profile;
    return status;
}

std::vector<std::shared_ptr<FiscalYear>> TimePeriod::build_years()
{
    std::vector<std::shared_ptr<FiscalYear>> years;
    int i;

    for (i = 0; i < std::get<1>(m_num_years_in_period); ++i)
    {
        std::shared_ptr<FiscalYear> y = std::make_shared<FiscalYear>(std::get<1>(m_debt_interest_rate),
                                                                     std::get<1>(m_tax_rate));
        y->set_return_on_capital(std::get<1>(m_return_on_capital_avarage)); 
        y->set_debt_issuance(m_debt_issuence_profile);
        y->set_debt_repayment(m_debt_repayment_profile);
        y->set_paid_in_capital(m_paid_in_capital_profile);                   
        y->set_capital_distribution(m_capital_distribution_profile);
        years.push_back(y);
    }

    return years;
}


std::tuple<TimePeriod::FIELD_STATUS, double> TimePeriod::convert_to_valid_numeric(std::string& as_string)
{
    return std::make_tuple(VALID, std::stod(as_string));
}


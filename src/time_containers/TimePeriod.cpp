// Business Story Application
// By Arthur Farber 2022
// https://github.com/arthur2389/BusinessStory

#include "TimePeriod.h"  
#include "MathServices.h"

TimePeriod::TimePeriod()
{
    m_tax_rate =\
    m_debt_interest_rate =\
    m_num_years_in_period =\
    m_return_on_capital_avarage =\
    m_return_on_capital_range = std::make_pair("", 0);

    m_capital_distribution_profile =\
    m_debt_issuence_profile =\
    m_debt_repayment_profile =\
    m_paid_in_capital_profile = std::make_pair("None", PROFILE::P_NONE);
}

TimePeriod::FIELD_STATUS TimePeriod::set_num_of_years(const std::string& number_of_years)
{
    TimePeriod::FIELD_STATUS status; 
    double value;
    std::tie(status, value) = convert_to_valid_numeric(number_of_years);
    if (status != VALID) return status;

    // ToDo solve the int issue
    m_num_years_in_period = std::make_pair(number_of_years, int(value));
    return status;
}

TimePeriod::FIELD_STATUS TimePeriod::set_tax_rate(const std::string& tax_rate)
{
    TimePeriod::FIELD_STATUS status; 
    double value;
    std::tie(status, value) = convert_to_valid_numeric(tax_rate);
    if (status != VALID) return status;

    m_tax_rate = std::make_pair(tax_rate, value);
    return status;
}

TimePeriod::FIELD_STATUS TimePeriod::set_debt_interest_rate(const std::string& debt_interest_rate)
{
    TimePeriod::FIELD_STATUS status; 
    double value;
    std::tie(status, value) = convert_to_valid_numeric(debt_interest_rate);
    if (status != VALID) return status;

    m_debt_interest_rate = std::make_pair(debt_interest_rate, value);
    return status;
}

TimePeriod::FIELD_STATUS TimePeriod::set_return_on_capital_average(const std::string& roc_average)
{
    TimePeriod::FIELD_STATUS status; 
    double value;  
    std::tie(status, value) = convert_to_valid_numeric(roc_average);
    if (status != VALID) return status;

    m_return_on_capital_avarage = std::make_pair(roc_average, value);
    return status;
}                                                           

TimePeriod::FIELD_STATUS TimePeriod::set_return_on_capital_range(const std::string& roc_range)
{
    TimePeriod::FIELD_STATUS status; 
    double value;  
    std::tie(status, value) = convert_to_valid_numeric(roc_range);
    if (status != VALID) return status;

    m_return_on_capital_range = std::make_pair(roc_range, value);
    return status;
}  

TimePeriod::FIELD_STATUS TimePeriod::set_capital_distribution_profile(const std::string& capital_distribution_profile)
{
    TimePeriod::FIELD_STATUS status = assert_profile_name(capital_distribution_profile);
    if (status != VALID) return status;

    m_capital_distribution_profile = std::make_pair(capital_distribution_profile, 
                                                    m_profile_conversion[capital_distribution_profile]);
    return status;
}

TimePeriod::FIELD_STATUS TimePeriod::set_debt_issuance_profile(const std::string& debt_issuance_profile)
{
    TimePeriod::FIELD_STATUS status = assert_profile_name(debt_issuance_profile);
    if (status != VALID) return status;

    m_debt_issuence_profile = std::make_pair(debt_issuance_profile, 
                                             m_profile_conversion[debt_issuance_profile]);
    return status;
}

TimePeriod::FIELD_STATUS TimePeriod::set_debt_repayment_profile(const std::string& debt_repayment_profile)
{
    TimePeriod::FIELD_STATUS status = assert_profile_name(debt_repayment_profile);
    if (status != VALID) return status;

    m_debt_repayment_profile = std::make_pair(debt_repayment_profile, 
                                              m_profile_conversion[debt_repayment_profile]);
    return status;
}

TimePeriod::FIELD_STATUS TimePeriod::set_paid_in_capital_profile(const std::string& paid_in_capital_profile)
{
    TimePeriod::FIELD_STATUS status = assert_profile_name(paid_in_capital_profile);
    if (status != VALID) return status;

    m_paid_in_capital_profile = std::make_pair(paid_in_capital_profile, 
                                               m_profile_conversion[paid_in_capital_profile]);
    return status;
}

std::vector<std::shared_ptr<FiscalYear>> TimePeriod::build_years()
{
    std::vector<std::shared_ptr<FiscalYear>> years;
    std::vector<double> roc_values = MathServices::get_rands_in_range(m_return_on_capital_average.second, 
                                                                      m_return_on_capital_range.second, 
                                                                      m_num_years_in_period.second);
    for (int i = 0; i < m_num_years_in_period.second; ++i)
    {
        std::shared_ptr<FiscalYear> y = std::make_shared<FiscalYear>(m_debt_interest_rate.second,
                                                                     m_tax_rate.second);
        y->set_return_on_capital(m_return_on_capital_average.second); 
        y->set_debt_issuance(m_debt_issuence_profile.second);
        y->set_debt_repayment(m_debt_repayment_profile.second);
        y->set_paid_in_capital(m_paid_in_capital_profile.second);                   
        y->set_capital_distribution(m_capital_distribution_profile.second);
        years.push_back(y);
    }

    return years;
}

std::tuple<TimePeriod::FIELD_STATUS, double> TimePeriod::convert_to_valid_numeric(const std::string& as_string)
{
    return std::make_tuple(VALID, std::stod(as_string));
}

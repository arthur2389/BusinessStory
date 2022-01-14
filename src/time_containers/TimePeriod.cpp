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
    m_return_on_capital_average =\
    m_return_on_capital_range = std::make_pair("", 0);

    m_capital_distribution_profile =\
    m_debt_issuence_profile =\
    m_debt_repayment_profile =\
    m_paid_in_capital_profile = std::make_pair("None", PROFILE::P_NONE);

    for (const auto& profile_pair: m_profile_conversion)
        m_profile_names.push_back(profile_pair.first);
}

void TimePeriod::set_num_of_years(const std::string& number_of_years)
{
    double value = convert_to_valid_numeric(number_of_years, "Number of years");
    m_num_years_in_period = std::make_pair(number_of_years, static_cast<int>(value));
}

void TimePeriod::set_tax_rate(const std::string& tax_rate)
{
   double value = convert_to_valid_numeric(tax_rate, "Tax rate");
   m_tax_rate = std::make_pair(tax_rate, value);
}

void TimePeriod::set_debt_interest_rate(const std::string& debt_interest_rate)
{
    double value = convert_to_valid_numeric(debt_interest_rate, "Debt interest rate");
    m_debt_interest_rate = std::make_pair(debt_interest_rate, value);
}

void TimePeriod::set_return_on_capital_average(const std::string& roc_average)
{
    double value = convert_to_valid_numeric(roc_average, "Return on capital average");
    m_return_on_capital_average = std::make_pair(roc_average, value);
}                                                           

void TimePeriod::set_return_on_capital_range(const std::string& roc_range)
{
    double value = convert_to_valid_numeric(roc_range, "Return on capital range");
    m_return_on_capital_range = std::make_pair(roc_range, value);
}  

void TimePeriod::set_capital_distribution_profile(const std::string& capital_distribution_profile)
{
    assert_profile_name(capital_distribution_profile, "Capital distribution");
    m_capital_distribution_profile = std::make_pair(capital_distribution_profile, 
                                                    m_profile_conversion[capital_distribution_profile]);
}

void TimePeriod::set_debt_issuance_profile(const std::string& debt_issuance_profile)
{
    assert_profile_name(debt_issuance_profile, "Debt issuance");
    m_debt_issuence_profile = std::make_pair(debt_issuance_profile, 
                                             m_profile_conversion[debt_issuance_profile]);
}

void TimePeriod::set_debt_repayment_profile(const std::string& debt_repayment_profile)
{
    assert_profile_name(debt_repayment_profile, "Debt repayment");
    m_debt_repayment_profile = std::make_pair(debt_repayment_profile, 
                                              m_profile_conversion[debt_repayment_profile]);
}

void TimePeriod::set_paid_in_capital_profile(const std::string& paid_in_capital_profile)
{
    assert_profile_name(paid_in_capital_profile, "Paid in capital");
    m_paid_in_capital_profile = std::make_pair(paid_in_capital_profile, 
                                               m_profile_conversion[paid_in_capital_profile]);
}

std::vector<std::shared_ptr<FiscalYear>> TimePeriod::build_years()
{
    std::vector<std::shared_ptr<FiscalYear>> years;
    std::vector<double> roc_values = MathServices::get_rands_with_average(m_return_on_capital_average.second, 
                                                                          m_return_on_capital_range.second, 
                                                                          m_num_years_in_period.second);
    for (int i = 0; i < m_num_years_in_period.second; ++i)
    {
        std::shared_ptr<FiscalYear> y = std::make_shared<FiscalYear>(m_debt_interest_rate.second,
                                                                     m_tax_rate.second);
        y->set_return_on_capital(roc_values[i]); 
        y->set_debt_issuance(m_debt_issuence_profile.second);
        y->set_debt_repayment(m_debt_repayment_profile.second);
        y->set_paid_in_capital(m_paid_in_capital_profile.second);                   
        y->set_capital_distribution(m_capital_distribution_profile.second);
        years.push_back(y);
    }

    return years;
}

double TimePeriod::convert_to_valid_numeric(const std::string& as_string, std::string field_name)
{
    try {
        return std::stod(as_string);
    }
    catch (const std::invalid_argument& iar)
    {
        throw InvalidUserParameter(as_string, field_name);
    }        
}

void TimePeriod::assert_profile_name(const std::string& pname, std::string field_name)
{
    std::vector<std::string>::iterator i = find(m_profile_names.begin(), m_profile_names.end(), pname);
    if (i == m_profile_names.end())
        throw InvalidUserParameter(pname, field_name);
}
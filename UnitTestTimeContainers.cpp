// Business Story Application
// By Arthur Farber 2022
// https://github.com/arthur2389/BusinessStory

#include <iostream>
#include <vector>
#include <memory>

#include "FiscalYear.h"
#include "TimePeriod.h"
#include "Assets.h"

int main(int argc, char **argv)
{
	std::vector<std::shared_ptr<FiscalYear>> years;
	TimePeriod early_years;
	TimePeriod mature_years;
	Assets comp_A{800, 200};

	early_years.set_num_of_years("3");
	early_years.set_tax_rate("18");
	early_years.set_debt_interest_rate("2");
	early_years.set_return_on_capital_average("ff3");
	early_years.set_return_on_capital_range("10");
	early_years.set_debt_issuance_profile("High");
	early_years.set_paid_in_capital_profile("Medium");

	mature_years.set_num_of_years("7");
	mature_years.set_tax_rate("18");
	mature_years.set_debt_interest_rate("3");
	mature_years.set_return_on_capital_average("18");
	mature_years.set_return_on_capital_range("8");
	mature_years.set_capital_distribution_profile("Medium");
	mature_years.set_debt_repayment_profile("Low");

	std::vector<std::shared_ptr<FiscalYear>>early_years_vec = early_years.build_years();
	years.insert(years.end(), early_years_vec.begin(), early_years_vec.end());

	std::vector<std::shared_ptr<FiscalYear>>mature_years_vec = mature_years.build_years();
	years.insert(years.end(), mature_years_vec.begin(), mature_years_vec.end());

	std::cout << "Company A has " << comp_A.get_equity() << \
	" In equity and " << comp_A.get_debt() << " In debt initially" << std::endl << std::endl;

	for (int i = 0; i < years.size(); ++i)
	{
		std::shared_ptr<FiscalYear> y = years[i];
		y->go_through(comp_A);
		year_10k y10k = y->get_year_10k();

		std::cout << "Company A year " << i + 1 << " results" << std::endl <<\
		"Earnings before interent and tax: " << y10k.ebit << std::endl <<\ 
		"Net earnings: " << y10k.earnings << std::endl <<\ 
		"Additional paid in capital: " << y10k.paid_in_capital << std::endl <<\
		"Debt issuance: " << y10k.debt_issuance << std::endl <<\ 
		"Debt repayment: " << y10k.debt_repayment << std::endl <<\ 
		"Capital distribution to shareholders: " << y10k.capital_distribution << std::endl <<\
		"End of year total shareholders equity: " << y10k.end_of_year_equity << std::endl <<\ 
		"End of year total debt: " << y10k.end_of_year_debt << std::endl << std::endl;
	}

	return 0;
}

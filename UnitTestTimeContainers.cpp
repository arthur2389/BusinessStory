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
	Assets comp_A{800, 200};

	early_years.set_num_of_years("5");
	early_years.set_tax_rate("18");
	early_years.set_debt_interest_rate("2");
	early_years.set_return_on_capital("15", "0");
	early_years.set_debt_issuance_profile("High");
	early_years.set_paid_in_capital_profile("Medium");

	std::vector<std::shared_ptr<FiscalYear>>early_years_vec = early_years.build_years();
	years.insert(years.begin(), early_years_vec.begin(), early_years_vec.end());

	int i{0};

	std::cout << "Company A has " << comp_A.get_equity() << \
	" In equity and " << comp_A.get_debt() << " In debt initially" << std::endl;

	for (i = 0; i < years.size(); ++i)
	{
		years[i]->go_through(comp_A);
		std::cout << "Company A has " << comp_A.get_equity() << \
		" In equity and " << comp_A.get_debt() << " In debt after the " << i + 1 << "th year" << std::endl;
	}

	return 0;
}

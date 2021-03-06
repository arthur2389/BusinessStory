// Business Story Application
// By Arthur Farber 2022
// https://github.com/arthur2389/BusinessStory

#include <iostream>
#include <vector>
#include <memory>

#include "AssetFlowAction.h"
#include "Types.h"
#include "Assets.h"
#include "Earnings.h"
#include "DebtIssuance.h"
#include "DebtRepayment.h"
#include "CapitalDistribution.h"
#include "PaidInCapital.h"


int main(int argc, char **argv)
{
	Assets comp_A{200, 0};
	Assets comp_B{265, 670};

	std::cout << "Company A has " << comp_A.get_equity() << " In equity and no debt" << std::endl;
	std::cout << "Company B has " << comp_B.get_equity() << \
		" In equity and " << comp_B.get_debt() << " In debt" << std::endl << std::endl;

	year_10k year1_10k_A{0};
	year_10k year1_10k_B{0};
	std::vector<std::unique_ptr<AssetFlowAction>> assest_flows_A_year_1;
	assest_flows_A_year_1.push_back(std::make_unique<DebtIssuance>(PROFILE::P_LOW));
	assest_flows_A_year_1.push_back(std::make_unique<PaidInCapital>(PROFILE::P_LOW));
	assest_flows_A_year_1.push_back(std::make_unique<Earnings>(1, 3, 15));

	for (auto& af: assest_flows_A_year_1)
	{
		af->update_assets(comp_A, year1_10k_A);
	}

	std::vector<std::unique_ptr<AssetFlowAction>> assest_flows_B;
	assest_flows_B.push_back(std::make_unique<DebtIssuance>(PROFILE::P_MEDIUM));
	assest_flows_B.push_back(std::make_unique<PaidInCapital>(PROFILE::P_HIGH));
	assest_flows_B.push_back(std::make_unique<Earnings>(-5, 3, 15));

	for (auto& af: assest_flows_B)
	{
		af->update_assets(comp_B, year1_10k_B);
	}

	std::cout << "Company A has " << comp_A.get_equity() << \
		" In equity and " << comp_A.get_debt() << " In debt after first year" << std::endl;

	std::cout << "Company B has " << comp_B.get_equity() << \
		" In equity and " << comp_B.get_debt() << " In debt after first year" << std::endl << std::endl;

	year_10k year2_10k_A{0};
	std::vector<std::unique_ptr<AssetFlowAction>> assest_flows_A_year_2;
	assest_flows_A_year_2.push_back(std::make_unique<Earnings>(20, 3, 15));
	assest_flows_A_year_2.push_back(std::make_unique<DebtRepayment>(PROFILE::P_LOW));
	assest_flows_A_year_2.push_back(std::make_unique<CapitalDistribution>(PROFILE::P_LOW));

	for (auto& af: assest_flows_A_year_2)
	{
		af->update_assets(comp_A, year2_10k_A);
	}

	std::cout << "Company A has " << comp_A.get_equity() << \
		" In equity and " << comp_A.get_debt() << " In debt after second year" << std::endl;
	std::cout << "Company A total assets after at the end of the period: " << comp_A.total_assests() << std::endl;

	return 0;
}

#include <iostream>
#include <vector>
#include <memory>
#include "AssetFlowAction.h"
#include "Assets.h"
#include "Earnings.h"
#include "LoanIssuance.h"
#include "DividendPayment.h"
#include "DebtRepayment.h"
#include "CapitalExpenditure.h"
#include "ShareBuyBack.h"
#include "DebtInterest.h"

int main(int argc, char **argv)
{
	Assets comp_A{200, 0};
	Assets comp_B{265, 670};

	std::cout << "Company A has " << comp_A.get_equity() << " In equity and no debt" << std::endl;
	std::cout << "Company B has " << comp_B.get_equity() << \
		" In equity and " << comp_B.get_debt() << " In debt" << std::endl;

	comp_A.update_stock_fields(15, 1000000);

	std::vector<std::unique_ptr<AssetFlowAction>> assest_flows_A_year_1;
	assest_flows_A_year_1.push_back(std::make_unique<LoanIssuance>(400));
	assest_flows_A_year_1.push_back(std::make_unique<Earnings>(1));
	assest_flows_A_year_1.push_back(std::make_unique<DebtInterest>(1));
	assest_flows_A_year_1.push_back(std::make_unique<DividendPayment>(1));
	assest_flows_A_year_1.push_back(std::make_unique<CapitalExpenditure>(400));

	for (auto& af: assest_flows_A_year_1)
	{
		af->update_assets(comp_A);
	}

	std::cout << "Company A has " << comp_A.get_equity() << \
		" In equity and " << comp_A.get_debt() << " In debt after first year" << std::endl;

	std::vector<std::unique_ptr<AssetFlowAction>> assest_flows_A_year_2;
	assest_flows_A_year_2.push_back(std::make_unique<Earnings>(20));
	assest_flows_A_year_2.push_back(std::make_unique<DebtRepayment>(200));
	assest_flows_A_year_2.push_back(std::make_unique<DividendPayment>(3));
	assest_flows_A_year_2.push_back(std::make_unique<ShareBuyBack>(30000));

	for (auto& af: assest_flows_A_year_2)
	{
		af->update_assets(comp_A);
	}

	std::cout << "Company A has " << comp_A.get_equity() << \
		" In equity and " << comp_A.get_debt() << " In debt after second year" << std::endl;
	std::cout << "Company A earnings after at the end of the period: " << comp_A.get_latest_earnings() << std::endl;
	std::cout << "Company A total assets after at the end of the period: " << comp_A.total_assests() << std::endl;

	return 0;
}

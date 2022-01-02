#include <iostream>
#include <vector>
#include <memory>
#include "AssetFlowAction.h"
#include "Assets.h"
#include "Earnings.h"
#include "LoanIssuance.h"
#include "DividendPayment.h"
#include "CapitalExpenditure.h"

int main(int argc, char **argv)
{
	Assets comp_A{843, 0};
	Assets comp_B{265, 670};

	std::cout << "Company A has " << comp_A.get_equity() << " In equity and no debt" << std::endl;
	std::cout << "Company B has " << comp_B.get_equity() << \
		" In equity and " << comp_B.get_debt() << " In debt" << std::endl;

	comp_A.update_stock_fields(15, 1000000);

	std::vector<std::unique_ptr<AssetFlowAction>> assest_flows_A;
	assest_flows_A.push_back(std::make_unique<LoanIssuance>(200));
	assest_flows_A.push_back(std::make_unique<Earnings>(7));
	assest_flows_A.push_back(std::make_unique<DividendPayment>(3));
	assest_flows_A.push_back(std::make_unique<CapitalExpenditure>(300));

	for (auto& af: assest_flows_A)
	{
		af->update_assets(comp_A);
	}

	std::cout << "Company A has " << comp_A.get_equity() << \
		" In equity and " << comp_A.get_debt() << " In debt" << std::endl;

	return 0;
}

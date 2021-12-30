#include <iostream>
#include <vector>
#include "AssetFlowAction.h"
#include "Assets.h"
#include "Earnings.h"
#include "DebtIssuance.h"

int main(int argc, char **argv)
{
	Assets comp_A{843};
	Assets comp_B{265, 670};

	std::cout << "Company A has " << comp_A.get_equity() << " In equity and no debt" << std::endl;
	std::cout << "Company B has " << comp_B.get_equity() << \
		" In equity and " << comp_B.get_debt() << " In debt" << std::endl;

	std::vector<AssetFlowAction> assest_flows_A;
	 
	//  {Earnings{15}, 
	//  								  Earnings{25}, 
	// 								  DebtIssuance{200}, 
	// 								  Earnings{3}, 
	// 								  Earnings{-5}};

	assest_flows_A.push_back(Earnings{5});
	assest_flows_A.push_back(DebtIssuance{500});

	for (auto af: assest_flows_A)
	{
		af.update_assets(comp_A);
	}

	std::cout << "Company A has " << comp_A.get_equity() << \
		" In equity and " << comp_A.get_debt() << " In debt" << std::endl;

	return 0;
}

#include <iostream>
#include <vector>
#include "AssetFlowAction.h"
#include "Assets.h"
#include "Earnings.h"
#include "LoanIssuance.h"

int main(int argc, char **argv)
{
	Assets comp_A{843, 0};
	Assets comp_B{265, 670};

	std::cout << "Company A has " << comp_A.get_equity() << " In equity and no debt" << std::endl;
	std::cout << "Company B has " << comp_B.get_equity() << \
		" In equity and " << comp_B.get_debt() << " In debt" << std::endl;

	std::vector<AssetFlowAction*> assest_flows_A { new Earnings{15}, 
												   new LoanIssuance{200}, 	
												   new Earnings{3}};	  

	for (auto af: assest_flows_A)
	{
		af->update_assets(comp_A);
	}

	std::cout << "Company A has " << comp_A.get_equity() << \
		" In equity and " << comp_A.get_debt() << " In debt" << std::endl;

	return 0;
}

#include "DebtRepayment.h"  
	
DebtRepayment::DebtRepayment(){}

DebtRepayment::DebtRepayment(double repayment_ammont): m_repayment_ammount{repayment_ammont} {}

void DebtRepayment::update_assets(Assets& assets)
{
    assets.add_debt(-m_repayment_ammount);
}

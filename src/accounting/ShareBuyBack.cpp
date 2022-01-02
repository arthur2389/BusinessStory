#include "ShareBuyBack.h"  
	
ShareBuyBack::ShareBuyBack(){}

ShareBuyBack::ShareBuyBack(int numer_of_shares): m_number_of_shares{numer_of_shares} {}

void ShareBuyBack::update_assets(Assets& assets)
{
    double total_buy_back = - assets.get_latest_stock_price() * (double)m_number_of_shares;
    assets.add_equity(total_buy_back);
}

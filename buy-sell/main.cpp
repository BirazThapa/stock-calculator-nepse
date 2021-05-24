#include<iostream>
using namespace std;

int share_price, share_quantity, net_amount, dp_charge = 25;
float commission, sebon;
	
	float brokercommissionrates()
		{
			float commission_rate = 0;
			if (net_amount < 50000)
				commission_rate = 0.004;
			else if(net_amount > 50001 && net_amount < 500000)	
				commission_rate = 0.0037;
			else if(net_amount > 500000 && net_amount < 2000000 )
				commission_rate = 0.0034;
			else if(net_amount > 2000000 && net_amount < 10000000)
				commission_rate = 0.003;
			else if(net_amount > 10000000)
			     commission_rate = 0.0027;
				
			return commission_rate;	 			
		 } 
		 
		 float sebon_fee() {
		 	float sfee;
		 	sfee = 0.00015;
		 	return sfee;
		
		 }
class Buy {
	public:
		
				 
		
		void buy_shares()
		 {
			
			system ("cls");
			cout << "Enter Share Price: ";
			cin >> share_price;
			cout << "Enter Share Quantity: ";
			cin >> share_quantity;
			net_amount = share_price * share_quantity;
			commission = brokercommissionrates() * net_amount; 
			sebon = sebon_fee () * net_amount; 
			
			display_data();
		
		 }
		
		void display_data ()
		{
			cout << "Net Amount:                " << "\t\t\t NRs." << net_amount << endl;
			cout << "Broker Commission:         " << "\t\t\t NRs." << commission << endl;
			cout << "SEBON Fee:                 " << "\t\t\t NRs." << sebon << endl;
			cout << "DP Charge:                 " << "\t\t\t NRs." << dp_charge << endl;
			cout << "Total Fees and Commission: " << "\t\t\t NRs." << sebon + commission + dp_charge << endl;
			cout << "Total Amount Payable:      " << "\t\t\t NRs." << net_amount + commission + sebon + dp_charge << endl;
			cout << "Price Per Share:           " << "\t\t\t NRs." << (net_amount + commission + sebon + dp_charge) / share_quantity << endl;  
		 } 

		 
};


class Sell {
	
	public:
	;
		float total_buy_amount, sell_amount, capital_gain, recieved_amount, paid_amount, recieve, total_buy, profit_loss;
		
		float brokercommissionrates2()
		{
			float commission_rate = 0;
			if (total_buy < 50000)
				commission_rate = 0.004;
			else if(total_buy > 50001 && total_buy < 500000)	
				commission_rate = 0.0037;
			else if(total_buy > 500000 && total_buy < 2000000 )
				commission_rate = 0.0034;
			else if(total_buy > 2000000 && total_buy < 10000000)
				commission_rate = 0.003;
			else if(total_buy > 10000000)
			     commission_rate = 0.0027;
				
			return commission_rate;	 			
		 } 
		void sell_shares()
		 
		{
			float commission_purchase, sebon_buy;
			system("cls");
			cout << "Enter Purchased Price: ";
			cin >> total_buy;
			cout << "Enter Selling Price: ";
			cin >> share_price;
 			cout << "Enter Share Quantity: ";
			cin >> share_quantity;
			
			net_amount = share_price * share_quantity;
			total_buy = total_buy * share_quantity; 
			commission_purchase = brokercommissionrates2() * total_buy;
			commission = brokercommissionrates() * net_amount;
			sebon_buy = sebon_fee() * total_buy;
			sebon = sebon_fee () * net_amount;
			
		        total_buy_amount = total_buy + commission_purchase + sebon_buy + dp_charge ;
		        sell_amount = net_amount - commission - sebon - dp_charge;
		        capital_gain = 0.05 * (sell_amount - total_buy_amount);
		    	recieved_amount = total_buy_amount;
		    	paid_amount= sell_amount;
		    	profit_loss = paid_amount - recieved_amount;
		    	recieve = net_amount - commission - dp_charge - sebon - capital_gain;
			 display_data();
			     
		}
		  
		  void display_data()
		  {
		  	cout << "Net Amount:                " << "\t\t\t NRs." << net_amount << endl;
			cout << "Broker Commission:         " << "\t\t\t NRs." << commission << endl;
			cout << "SEBON Fee:                 " << "\t\t\t NRs." << sebon << endl;
			cout << "DP Charge:                 " << "\t\t\t NRs." << dp_charge << endl;
				 if (sell_amount > total_buy_amount)
	       {    
		    cout << "Capital Gain Tax (5%):     " << "\t\t\t NRs." << capital_gain << endl;	
		  }		 
		    cout << "Amount To be Recieved:     " << "\t\t\t NRs." << recieve << endl;
		    cout << "Profit / Loss:             " << "\t\t\t NRs." << profit_loss << endl;
		    
		  }
		  
};


	int main()

{
	
	Buy  buying;
	Sell selling;
	
	int choice;
	cout << "Welcome To Stock Calculator ( Buy / Sell )" << endl;
	cout << "Choose an Option" << endl;
	cout << "1.) Buy" << endl;
	cout << "2.) Sell" << endl;
	cout << "Enter Your Choice : ";
	cin >> choice;
	if (choice == 1)
		buying.buy_shares();
	else if(choice == 2)
		 selling.sell_shares();
	else
		cout << "Invalid Input!";
			
	system("pause");
}

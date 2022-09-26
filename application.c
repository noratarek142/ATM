
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "card.h"
#include "terminal.h"
#include "server.h"
#include "application.h"
void start();


void appstart()
{


while (1) {
		printf("====================================\n");
		printf("Welcome to the payment application\n");
		printf("====================================\n");

		start();


	}
}


 carddata_t mydata;
 terminaldata_t terminal;

void start(void)
{
carddata_t carddata;
terminaldata_t termdata;
terminaldata_t*ptr_term_data=&termdata;
carddata_t*ptr_card_data=&carddata;
transaction_t trans;
getCardHolderName(ptr_card_data);
getCardExpiryDate(ptr_card_data);
getCardPAN(ptr_card_data);
getTransactiondate(ptr_term_data);
if(isCardEXpired(mydata,terminal)!=2)
{
    setMaxAmount(ptr_term_data);
    getTransactionAmount(ptr_term_data);
    if(isBelowMaxAmount(ptr_term_data)==0)
    {
        isValidAccount(ptr_card_data);
        //isAmountAvailable(ptr_term_data);

    }
    saveTransaction(&trans);
    recieveTransactionData(&trans);

}
}




//transaction_t transdata;
//char module=10;



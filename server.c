
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "card.h"
#include "terminal.h"
#include "server.h"

#define DB_SIZE 255
int flag=0;
int seq;

account_t account[255]=
{

    {1000,1111222233334444},
    {2000,5555666677778888},
    {3000,9999000011112222},
};

en_server isValidAccount(carddata_t *pcd)
{
   unsigned char is_validname;
   unsigned char is_validPAN;
   unsigned char is_validdate;

   is_validname=getCardHolderName(&pcd);
   while(is_validname ==wrong_name)
    is_validname=getCardHolderName(&pcd);

   is_validPAN=getCardPAN(&pcd);
   while(is_validPAN==wrong_PAN)
    is_validPAN=getCardPAN(&pcd);

   is_validdate=getCardExpiryDate(&pcd);
   while(is_validdate==wrong_date)
    is_validdate=getCardExpiryDate(&pcd);

   if(is_validname==done && is_validPAN==done && is_validdate==done)
   {
       int i;
       for(i=0;i<255;i++)
       {
           if(strcmp(pcd->P_A_N,account[i].P_A_N)==0)
           {
               flag=i;
               return done;
           }
       }
       flag=255;
   }
   return account_lost;

}

en_server isAmountAvailable(terminaldata_t* ptd, account_t* ar)
{
	if (ptd->transaction_Amount > ar->balance)
		return low_balance;
	else
		return server_done;
}

en_transaction recieveTransactionData(transaction_t *ptd)
{

    ptd->transaction_State = Approved;
    // Check if the account exists using primary account number
    if( isValidAccount( &ptd->card_Holder_Data) == stolen_card)
    {
        ptd->transaction_State = stolen_card;
    }

    // check if the amount is available or not
    if(isAmountAvailable(&ptd->terminal_Data , &ptd->card_Holder_Data) == low_balance)
    {
        ptd->transaction_State = DECLINED_INSUFFECIENT_FUND;
    }

    // save transation data
    if( saveTransaction(ptd) == saving_is_failed  )
    {
        return server_error;
    }

    return ptd->transaction_State;
}

en_server getTransaction(unsigned int Transaction_SN,transaction_t*ptd)
{


    int i;
    while(ptd[i].T_S_N!=0)
    {
        if(ptd[i].T_S_N==Transaction_SN)
        {
            puts("transaction details: ");
            printf("card name      :\t%s\n ",ptd[i].card_Holder_Data.holder_Name);
            printf("card PAN       :\t%s\n ",ptd[i].card_Holder_Data.P_A_N);
            printf("card expiration date       :\t%s\n ",ptd[i].card_Holder_Data.expiration_Date);
            printf("transaction date           :\t%s\n ",ptd[i].terminal_Data.transaction_Date);
            printf("transaction amount:        :\t%f\n ",ptd[i].terminal_Data.transaction_Amount);
            printf("transaction max amount:         :\t%f\n ",ptd[i].terminal_Data.max_Transaction_Amount);
            printf("sequence number                 : \t%d\t",ptd[i].T_S_N);
            printf("transaction state               : \t%d\t",ptd[i].transaction_State);
            return done;

        }
        i++;
    }
printf("transaction isn't found");
return transaction_lost;

}

en_server saveTransaction(transaction_t* ptd)
{
    if(seq>DB_SIZE-1)
    {
        return saving_is_failed;
    }
    ptd->T_S_N=seq;
    seq++;
    return done;
}

/*en_transaction updateBalance(transaction_t*ptd)
{
    cahe current pan[20];
    float current_balance;
    float new_balance;
    file*account
}*/


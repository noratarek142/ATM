#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "card.h"
#define size 30
#define size1 20


en_card getCardHolderName(carddata_t* pcd)
{
	int i;
	unsigned char holder_name[size];
	printf("please enter holder name : ");
	for (i = 0; i < size; i++)
	{
		scanf(" %[^\n]",& holder_name);
	}

	if (holder_name == NULL)
	{
		return wrong_name;
	}
	strcpy(pcd->holder_Name,holder_name);
	return done;
}

en_card getCardExpiryDate(carddata_t* pcd)
{
    int i;
	unsigned char expiration_date[size1];
	printf("please enter card expiry date : ");
	for (i = 0; i < size1; i++)
	{
		scanf(" %s", &expiration_date);
	}
	if(expiration_date[i]==NULL || strlen(expiration_date!=5))

    {
        return wrong_date;
    }
    strcpy(pcd->expiration_Date ,expiration_date);
    return done;
}

en_card getCardPAN(carddata_t* pcd)
{
     int pan[20];
     printf("please enter your PAN : ");
     scanf("%d",&pan);

     if(pan==NULL || strlen(pan)<16 || strlen(pan)>19)
     {
         return wrong_PAN;
     }

     strcpy(pcd->P_A_N ,pan);
     return done;
}



# include <stdio.h>
# include <stdlib.h>

#define Active 1
#define Closed 0
int Account_Numb_copy;
int SelectedAcc_Numb;
int Add_New_Account(void);
int openAccount(void);
void Get_cach (void);
static int Account_Numb = 0;
void Change_Account_State (void);
void Make_Transaction(void);
void Deposet (void);
void Change_Account_PassWord(void);
typedef struct 
 {
	char Name[32]  ;
	char Address [64];
	char Account_State; //A for Active
	int Age ;
	int state;
	unsigned long ID;
	double National_ID;
	double Guardian_ID;
    unsigned long  Balance ; //0 to 18,446,744,073,709,551,615
	unsigned long PassWord ;
	
	}Account;
	
unsigned long New_Pass(void);

Account * Acc_Arr ;


int main(void){
int Selector ;
int i;
unsigned long passWord_Copy;
printf("***************************Welcom***************************\n");
while(1){
	
printf("Pleas Select The mode \n1 for Admine Mode , 0 for Custmer Mode \n");
	scanf ("%d" ,&Selector);
	switch (Selector){
		case 0: 	
		printf ("Welcom to Custmer Mode Pleas enter Account ID to show it's data \n");
		openAccount ();
		printf ("Enter Account PassWord \n");
		scanf("%lu", &passWord_Copy);
		if(Acc_Arr[SelectedAcc_Numb].PassWord == passWord_Copy){
			printf("Select One of the next choices\n1-Make Transaction\n2Change Account PassWord\n3-Get Cash\n4-Deposet in Account\n5-Return to main\n");
			scanf("%d",&Selector);
				switch (Selector){
						case 1: Make_Transaction();
						case 2: Change_Account_PassWord();
						case 3: Get_cach();
						case 4: Deposet();
						case 5: break;
					
				}
		}
		else
		{
			printf("Wrong PassWord\n");
			}
		break;
		  i = 1;
		case 1 :while(i){
			printf("Welcom to Admine Mode Pleas Select one of the next choices  \n");
			printf("1 for Add_New_Account \n2 to Open account \n3 Exit system\n");
			scanf ("%d" ,&Selector);
			switch(Selector){
		
				case 1: Add_New_Account();break;
				case 2:printf("Enter The ID");
					Account_Numb_copy = openAccount();
					printf("Pleas Select one of the next choices \n\n");
					printf("1-to Make transaction \n2-Change Account status\n3-Get cash\n4-Deposet in Account\n5-Return to main menu\n");	
					scanf ("%d" ,&Selector);
					switch (Selector){
						case 1: Make_Transaction();
						case 2: Change_Account_State();
						case 3: Get_cach();
						case 4: Deposet();
						case 5: break;
					
				}
		
				case 3: i = 0; break;
				
		}
	} 
	}	
	}
return 0;}
void Change_Account_PassWord(void){
	unsigned long PassWord;

	printf("Enter The new PassWord(consest of 10 digits)\n");
	scanf("%lu",&PassWord);	
	if((PassWord <10000000000)&&(PassWord >1000000000)){
	Acc_Arr[SelectedAcc_Numb].PassWord =PassWord; 	

	} else{
	 printf("Faild Pleas ");
	}
	return;
}
void Deposet (void){
	unsigned long Money;
	
	if (SelectedAcc_Numb >= -1){
		printf("Enter The amount of money to deposet \n");
	scanf("%lu", & Money);
	Acc_Arr[SelectedAcc_Numb].Balance += Money;
	printf("Deposet done\n");
	}
	else {printf("Invaled ID\n");}
	return;
}
void Change_Account_State (void){
	
	if (SelectedAcc_Numb >= -1){
		if(Acc_Arr[SelectedAcc_Numb].state ==1)
		{Acc_Arr[SelectedAcc_Numb].state ==0;
		printf("Deactivated\n");}
		if(Acc_Arr[SelectedAcc_Numb].state ==0)
		{Acc_Arr[SelectedAcc_Numb].state ==1;
		printf("activated\n");}
			
		
		
		
	}else{printf("This ID is not avilible\n");}
	return ;
}
void Get_cach (void){
	unsigned long Money;
	
	if (SelectedAcc_Numb >= -1){
		if(Acc_Arr[SelectedAcc_Numb].state ==1)
		{
		printf("Enter The amount of money\n");
		scanf("%lu",&Money);
		if(Acc_Arr[SelectedAcc_Numb].Balance >= Money){
			Acc_Arr[SelectedAcc_Numb].Balance -=Money;
			
			printf("Done\n");
		}
		else{printf("No enough cach \n");}
		}
		else{printf("Pleas Active the Account firest\n");}

	}
		
	else{printf("This ID is not avilible\n");}
	return ;
}
void Make_Transaction(void){
	int SelectedAcc_Numb_copy;
	unsigned long Money;
	printf("Enter The other Account ID :");
	 SelectedAcc_Numb_copy = openAccount();
	if (SelectedAcc_Numb_copy >= 0){
		if (Acc_Arr[Account_Numb_copy].state == 1  && Acc_Arr[SelectedAcc_Numb_copy].state == 1){
			
		printf("Enter The amount of money to transfer : \n");
		scanf("%lu",&Money);
			if (Acc_Arr[Account_Numb_copy].Balance >=(long) Money){
				
				Acc_Arr[Account_Numb_copy].Balance = Acc_Arr[Account_Numb_copy].Balance - Money;
				Acc_Arr[SelectedAcc_Numb_copy].Balance =Acc_Arr[SelectedAcc_Numb_copy].Balance +Money;
				printf("The transfer is done\n");		
				
				
				
			}
			else{printf ("ther is no enough cach\n");  }
		}
		else{printf ("Pleas Active the Account firest\n");
	}}
	else
	{printf("Faild \n");
}	
	
return;	
}



int openAccount(void)
{ 
int flag =1;
unsigned long ID;
	if (Account_Numb >>0){
scanf("%lu",&ID);
	for (	SelectedAcc_Numb = 0 ; SelectedAcc_Numb <=Account_Numb ; SelectedAcc_Numb++)
{

if (Acc_Arr[SelectedAcc_Numb].ID == ID)
{	
    printf("The user Name :%s \n", Acc_Arr[SelectedAcc_Numb].Name);
    printf("The user Address :%s \n", Acc_Arr[SelectedAcc_Numb].Address);
	printf("The user Age :%d \n", Acc_Arr[SelectedAcc_Numb].Age);
    if (Acc_Arr[SelectedAcc_Numb].state == 1)printf("The Account state is Active \n");
	if (Acc_Arr[SelectedAcc_Numb].state == 0)printf("The Account state is Deactivated \n");
	printf("The Account Balance :%lu \n", Acc_Arr[SelectedAcc_Numb].Balance);
flag=0;	
break;

}	
}

if (flag == 1){
	printf ("this ID dose not avilible \n");
	SelectedAcc_Numb = -1;
}
	}
else {
	printf("Ther is no ID yet \n");
}	
return SelectedAcc_Numb ;
}
int Add_New_Account (void)
{
	Account_Numb ++;
	
	if(Account_Numb ==1)
	{Acc_Arr =  malloc(  sizeof(Account));
		
		                }
	
	else
	{	
			Acc_Arr = (Account *) realloc( Acc_Arr , 136);
					}
	 Acc_Arr[Account_Numb].Name[0] = '\0';
	 Acc_Arr[Account_Numb].Address[0] = '\0';
printf("Pleas Enter the Custmer Name (first 4 Names sudjested): ");
while(	Acc_Arr[Account_Numb].Name[0] == '\0'){
gets(Acc_Arr[Account_Numb].Name);}
printf("Pleas Enter The Address\n");

	gets(Acc_Arr[Account_Numb].Address);
	printf("Pleas Enter The Age\n");	
	scanf("%d", &Acc_Arr[Account_Numb].Age);
if (Acc_Arr[Account_Numb].Age < 21)
{printf("Pleas Enter The National_Gradian_ID \n");
scanf("%lf",&Acc_Arr[Account_Numb].Guardian_ID);
 }
printf("Pleas Enter The National_ID\n");	
	scanf("%lf", &Acc_Arr[Account_Numb].National_ID);

	printf("Pleas Enter the Balance \n");
	scanf("%lu",&Acc_Arr[Account_Numb].Balance);
	Acc_Arr[Account_Numb].PassWord = New_Pass();
	printf("Your PassWord is :%u\n" ,Acc_Arr[Account_Numb].PassWord);	
	Acc_Arr[Account_Numb].ID = (unsigned long)1230000000 +(unsigned long)&Acc_Arr[Account_Numb].ID ;
	printf("Your Account ID is:%u\n" ,Acc_Arr[Account_Numb].ID);	
	Acc_Arr[Account_Numb].state = 1;

	return 0;//just for now
	}
	
unsigned long New_Pass(void){

unsigned long Copy_pass;
while (1)
{
		Copy_pass = rand() *123456;


	if ((Copy_pass <10000000000)&&(Copy_pass >1000000000))
{break;
}
}
return Copy_pass;
}	
	
	
	
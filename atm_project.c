#include <stdio.h>
struct user{
    int pin;
    int accno;
    float sbal;
    float cbal;
    };
float withdraw(float balance)            /*function for cash withdrawal*/
{
    printf("Please enter the amount of cash for withdrawal.\n");
    float amount;
    scanf("%f",&amount);
    if(amount<=balance||amount<=20000)
    {
        balance = balance - amount;
    }
    else if(amount>balance)
    {
        printf("The amount of withdrawal is greater than the account balance.\n");
        printf("Withdrawal failed.\n");
    }
    else if(amount>20000)
    {
        printf("The amount of withdrawal is more than the allowed limit.\n");
    }
    return(balance);
}
float deposit(float balance1)
{
    printf("Please enter the amount of cash you want to deposit.\n");
    float deposit;
    scanf("%f",&deposit);
    balance1=balance1+deposit;
    return(balance1);
}
float moneytransfer(float bal1)
{
    printf("Please enter the amount of money to be transferred to the beneficiary's account.\n");
    printf("Your current account balance is %f.\n",bal1);
    float transfer;
    scanf("%f",&transfer);
    if(transfer<=bal1)
    {
        bal1=bal1-transfer;
        printf("The money has been transferred successfully.\n");
    }
    else if(transfer>bal1)
    {
        printf("Money transfer failed due to the amount of money for transfer exceeding the balance of the account.\n");
    }
    return(bal1);
}

int main()
{
    int n;
    FILE *fp;
    fp=fopen("/Users/Seoul/Desktop/users.txt","r+");
    fscanf(fp,"%d",&n);
    fclose(fp);
    struct user users[n];
    int i;
    FILE *f;
    f=fopen("/Users/Seoul/Desktop/atm.txt","r+");
    for(i=0;i<n;i++)
    {
       fscanf(f,"%d%d%f%f",&users[i].pin,&users[i].accno,&users[i].sbal,&users[i].cbal);
       if(fgetc(f)==EOF)
       {
           break;
       }
    }
    fclose(f);
    printf("Welcome to MSI Atm!\n");
    printf("Please enter your 8 digit account number.\n");
    int accountno;
    scanf("%d",&accountno);
    printf("Please enter your pin.\n");
    int pin;
    scanf("%d",&pin);

    int k,num;
    for(k=0;k<n;k++)
    {
        if(pin==users[k].pin&&accountno==users[k].accno)
        {
            num=k;
            printf("You have entered the correct pin.\n");
            printf("1.Check savings account balance.\n");
            printf("2.Check current account balance.\n");
            printf("3.Cash withdrawal.\n");
            printf("4.Cash deposit.\n");
            printf("5.Pin change.\n");
            printf("6.Money transfer.\n");
            printf("Please enter your choice.\n");
            int choice;
            scanf("%d",&choice);
            switch(choice)
            {
               case 1:
                  printf("Your savings account balance is %f\n",users[num].sbal);
                  break;
               case 2:
                  printf("Your current account balance is %f\n",users[num].cbal);
                  break;
               case 3:
                  printf("1.Savings account\n");
                  printf("2.Current account\n");
                  printf("Please enter your choice of account for cash withdrawal.The choice must be 1 or 2.\n");
                  int choice1;
                  scanf("%d",&choice1);
                  switch(choice1)
                  {
                      case 1:
                         users[num].sbal=withdraw(users[num].sbal);
                         printf("Your savings account balance is %f.\n",users[num].sbal);
                         printf("Press 1 for another transaction and 2 if you don't wish to make another transaction.\n");
                         int ch;
                         scanf("%d",&ch);
                         if(ch==1)
                         {
                            users[num].sbal=withdraw(users[num].sbal);
                            printf("Your savings account balance is %f.\n",users[num].sbal);
                         }
                         else if(ch==2)
                         {
                             break;
                         }
                         break;
                      case 2:
                         users[num].cbal=withdraw(users[num].cbal);
                         printf("Your current account balance is %f.\n",users[num].cbal);
                         printf("Press 1 for another transaction and 2 if you don't wish to make another transaction.\n");
                         int ch1;
                         scanf("%d",&ch1);
                         if(ch1==1)
                         {
                            users[num].cbal=withdraw(users[num].cbal);
                            printf("Your current account balance is %f.\n",users[num].cbal);
                         }
                         else if(ch1==2)
                         {
                             break;
                         }
                         break;
                      default:
                        printf("You entered the wrong option.\n");
                  }
                  break;
                case 4:
                  printf("1.Savings account\n");
                  printf("2.Current account\n");
                  printf("Please enter your choice of account for cash deposit.The choice must be 1 or 2.\n");
                  int choice2;
                  scanf("%d",&choice2);
                  switch(choice2)
                  {
                      case 1:
                         users[num].sbal=deposit(users[num].sbal);
                         printf("Your savings account balance is %f.\n",users[num].sbal);
                         printf("Press 1 for another cash deposit and 2 if you don't wish to deposit cash agsin.\n");
                         int ch2;
                         scanf("%d",&ch2);
                         if(ch2==1)
                         {
                            users[num].sbal=deposit(users[num].sbal);
                            printf("Your savings account balance is %f.\n",users[num].sbal);
                         }
                         else if(ch2==2)
                         {
                             break;
                         }
                         break;
                      case 2:
                         users[num].cbal=deposit(users[num].cbal);
                         printf("Your current account balance is %f.\n",users[num].cbal);
                         printf("Press 1 for another cash deposit and 2 if you don't wish to deposit cash again.\n");
                         int ch3;
                         scanf("%d",&ch3);
                         if(ch3==1)
                         {
                            users[num].cbal=deposit(users[num].cbal);
                            printf("Your current account balance is %f.\n",users[num].cbal);
                         }
                         else if(ch3==2)
                         {
                             break;
                         }
                         break;
                      default:
                        printf("You entered the wrong option.\n");
                  }
                  break;
                  case 5:
                      printf("You have chosen the option of pin change.\n");
                      printf("Please enter the 4-digit pin you wish to change your original pin to.\n");
                      int newpin;
                      scanf("%d",&newpin);
                      if(newpin>999&&newpin<10000)
                      {
                          users[num].pin=newpin;
                          printf("Your pin has been changed successfully to %d.\n",users[num].pin);

                      }
                      else
                      {
                          printf("The pin you entered is not 4-digits long.\n");
                      }
                    break;
                    case 6:
                        printf("1.Savings account\n");
                        printf("2.Current account\n");
                        printf("Please enter your choice of account for money transfer.The choice must be 1 or 2.\n");
                        int choice3;
                        scanf("%d",&choice3);
                        switch(choice3)
                        {
                           case 1:
                              printf("Please enter the account number of the beneficiary/receiver.\n");
                              printf("The account number must be 8 digits long.\n");
                              int accno;
                              scanf("%d",&accno);
                              for(int b=0;b<n;b++)
                              {
                                  if(accno==users[b].accno)
                                  {
                                      float oldsavbal;
                                      oldsavbal=users[num].sbal;
                                      users[num].sbal=moneytransfer(users[num].sbal);
                                      users[b].sbal=users[b].sbal-users[num].sbal+oldsavbal;
                                      printf("Your current savings account balance is %f.\n ",users[num].sbal);
                                      break;
                                  }
                                  if(b==n-1&&accno!=users[b].accno)
                                  {
                                     printf("The account number you entered does not exist.\n");
                                  }
                              }
                              break;
                           case 2:
                               printf("Please enter the account number of the beneficiary/receiver.\n");
                               printf("The account number must be 8 digits long.\n");
                               int accno1;
                               scanf("%d",&accno1);
                               for(int c=0;c<n;c++)
                              {
                                  if(accno1==users[c].accno)
                                  {
                                      float oldcurrentbal;
                                      oldcurrentbal=users[num].cbal;
                                      users[num].cbal=moneytransfer(users[num].cbal);
                                      users[c].cbal=users[c].cbal-users[num].cbal+oldcurrentbal;
                                      printf("Your current account balance is %f.\n ",users[num].cbal);
                                      break;
                                  }
                                  if(c==n-1&&accno!=users[c].accno)
                                  {
                                     printf("The account number you entered does not exist.\n");
                                  }
                              }
                              break;
                           default:
                              printf("You entered the wrong option.\n");
                        }
                        break;
                default:
                    printf("You have entered an option other than 1,2,3,4,5,6.");

            }
            break;
        }
        if(k==n-1)
        {
            printf("You have entered the wrong pin or account number or both.\n");
            return 0;
        }
    }
FILE *f1;
f1=fopen("/Users/Seoul/Desktop/atm.txt","w+");
for(int d=0;d<n;d++)
{
    fprintf(f1,"%d %d %f %f\n",users[d].pin,users[d].accno,users[d].sbal,users[d].cbal);
}
fclose(f1);
return 0;
}

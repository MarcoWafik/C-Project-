#include <stdio.h>
#include <stdlib.h>



int main()
{
    int input_number ;

    while (1)
    {

    printf("Hello ; What would you like to do ?\n\n");
    printf(" 1- System Check \n 2- Size Check \n 3- Add Data \n 4- Delete Data \n 5- Read Data \n 6- Get IDs \n 7- Check ID \n\n\n");
    scanf ("%d", &input_number);
    if ((input_number>=1)&&(input_number<=7))
    {
        switch(input_number)
        {
            case (1):
                SDB_check();
             break;

            case (2):
                 SDB_GetUsedSize();
             break;

            case (3):
                 SDB_AddData();
             break;

            case (4):
                 SDB_DeleteEntry();
             break;

            case (5):
                 Read_Entry();
             break;

            case (6):
                 SDB_GetIdList();
             break;

            case (7):
                 SDB_IsIdExist();
             break;
        }
    }
    else
    {
      printf("Wrong Entry ! try again .\n");
    }
    }


    return 0;
}









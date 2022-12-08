/********************************************************************************/
/**    File Name: Cproject.c                                                    */
/**                                                                             */
/**  Description: Implement of the project functions                            */
/**-----------------------------------------------------------------------------*/
/**  CODING LANGUAGE :  C                                                       */
/**-----------------------------------------------------------------------------*/
/**                            C O P Y R I G H T                                */
/**-----------------------------------------------------------------------------*/
/** Copyright (c) 2022        .       All rights reserved.                      */
/**                                                                             */
/** This software is copyright protected and proprietary                        */
/** to Marco Wafik.                                                             */
/**-----------------------------------------------------------------------------*/
/**               A U T H O R   I D E N T I T Y                                 */
/**-----------------------------------------------------------------------------*/
/** ShortName    Name                      Faculty                              */
/** --------     ---------------------     -------------------------------------*/
/** Marco        Marco Wafik               ENG/ASU .                            */
/**-----------------------------------------------------------------------------*/
/**               R E V I S I O N   H I S T O R Y                               */
/**-----------------------------------------------------------------------------*/
/** Date        Version   Author       Description                              */
/** ----------  --------  ------      ------------------------------------------*/
/** 7/12/2022   0.1       Marco        Initial Creation                         */
/********************************************************************************/
#include <stdio.h>
#include <stdlib.h>

#include"Cproject.h"


SimpleDb* start = NULL;


SimpleDb* Insert_Data_At_Begining (SimpleDb* start ,int studentID_copy,char student_Year_copy ,int course_1_ID_copy,
                                  float course_1_Grade_copy,int course_2_ID_copy,float course_2_Grade_copy,
                                  int  course_3_ID_copy ,float course_3_Grade_copy )
{
        /*Create Data in heap*/

        SimpleDb* PtrCurrentData = (SimpleDb*) malloc (sizeof(SimpleDb));

        if (PtrCurrentData != NULL)
        {
            /*Passing the Data to the Struct*/
            PtrCurrentData ->studentID     = studentID_copy     ;
            PtrCurrentData ->student_Year  = student_Year_copy  ;
            PtrCurrentData ->course_1_ID   = course_1_ID_copy   ;
            PtrCurrentData ->course_1_Grade= course_1_Grade_copy;
            PtrCurrentData ->course_2_ID   = course_2_ID_copy   ;
            PtrCurrentData ->course_2_Grade= course_2_Grade_copy;
            PtrCurrentData ->course_3_ID   = course_3_ID_copy   ;
            PtrCurrentData ->course_3_Grade= course_3_Grade_copy;


            /*Passing the pointers*/
            PtrCurrentData ->PtrNextData = start;
            start = PtrCurrentData ;

        }
            DataCounter ++;
        return start ;
}
SimpleDb* Insert_Data_At_End (SimpleDb* start ,int studentID_copy ,char student_Year_copy ,int   course_1_ID_copy ,
                                  float course_1_Grade_copy,int  course_2_ID_copy,float course_2_Grade_copy,
                                 int  course_3_ID_copy  ,float course_3_Grade_copy )
{
    /*Create Random Pointer*/

    SimpleDb* RandPtr = start ;
    /*Create Data in heap*/

    SimpleDb* PtrCurrentData = (SimpleDb*) malloc (sizeof(SimpleDb));

        if (PtrCurrentData != NULL)
        {
            /*Passing the Data to the Struct*/
            PtrCurrentData ->studentID     = studentID_copy     ;
            PtrCurrentData ->student_Year  = student_Year_copy  ;
            PtrCurrentData ->course_1_ID   = course_1_ID_copy   ;
            PtrCurrentData ->course_1_Grade= course_1_Grade_copy;
            PtrCurrentData ->course_2_ID   = course_2_ID_copy   ;
            PtrCurrentData ->course_2_Grade= course_2_Grade_copy;
            PtrCurrentData ->course_3_ID   = course_3_ID_copy   ;
            PtrCurrentData ->course_3_Grade= course_3_Grade_copy;

     while (RandPtr -> PtrNextData != NULL)
        {
             RandPtr = RandPtr -> PtrNextData ;
        }
             /*Last Node carries the address of the inserted Node*/
            RandPtr -> PtrNextData = PtrCurrentData ;
            /*inserted Node carries the address of NULL*/
            PtrCurrentData -> PtrNextData = NULL ;


        }
            DataCounter ++;
        return start ;
}



void SDB_check (void)
{
     if ((DataCounter>=0)&&(DataCounter<10))
     {
          printf("Database isn't full yet\n\n");
     }
     else
     {
            printf("Database is Full\n\n");
     }

}

char SDB_GetUsedSize (void)
{
    printf("The Used Size = %d \n\n",DataCounter);
    return DataCounter;
}

char SDB_AddData (void)
{
    int   StudentID   = 0;
    int   StudentYear = 0;
    int   Course1ID   = 0;
    float Course1Grade= 0;
    int   Course2ID   = 0;
    float Course2Grade= 0;
    int   Course3ID   = 0;
    float Course3Grade= 0;
    printf ("Please Enter Student ID: ");
    scanf  ("%d", &StudentID);
    printf ("Please Enter Student Year: ");
    scanf  ("%d", &StudentYear);
    printf ("Please Enter First Course ID: ");
    scanf  ("%d", &Course1ID);
    fflush(stdin);
    printf ("Please Enter First Course Grade: ");
    scanf  ("%f", &Course1Grade);
    while (Course1Grade>100)
    {
    printf ("Please Enter First Course Grade: ");
    scanf  ("%f", &Course1Grade);
    }
    printf ("Please Enter Second Course ID: ");
    scanf  ("%d", &Course2ID);
     fflush(stdin);
    printf ("Please Enter Second Course Grade: ");
    scanf  ("%f", &Course2Grade);
     while (Course2Grade>100)
    {
    printf ("Please Enter Second Course Grade: ");
    scanf  ("%f", &Course2Grade);
    }
    printf ("Please Enter Third Course ID: ");
    scanf  ("%d", &Course3ID);
     fflush(stdin);
    printf ("Please Enter Third Course Grade: ");
    scanf  ("%f", &Course3Grade);
     while (Course3Grade>100)
    {
    printf ("Please Enter Third Course Grade: ");
    scanf  ("%f", &Course3Grade);
    }


    if (DataCounter==0)
    {
        start = Insert_Data_At_Begining(start ,StudentID ,StudentYear,Course1ID,Course1Grade,
                                                                            Course2ID,Course2Grade,Course3ID,Course3Grade );

        if (start!= NULL)
        {
            printf("Data Entered Successfully\n\n");
            return 1;
        }
        else
        {
            printf("Data isn't Entered Successfully\n\n");
            return 0;
        }


    }
    else if ((DataCounter>0)&&(DataCounter<=9))
    {
        SimpleDb* PtrCheck = Insert_Data_At_End (start ,StudentID ,StudentYear,Course1ID,Course1Grade,
                                                                            Course2ID,Course2Grade,Course3ID,Course3Grade );


         if (PtrCheck!= NULL)
        {
            printf("Data Entered Successfully\n\n");
            return 1;
        }
        else
        {
            printf("Data isn't Entered Successfully\n\n");
            return 0;
        }
    }
    else if (DataCounter>9)
    {
        printf("Database is Full Please make more space\n\n");

    }
}

char Read_Entry (void)
{
    int   StudentID   = 0;
    printf ("Please Enter Student ID to find his Data : ");
    scanf  ("%d", &StudentID);

    SimpleDb* PtrToStruct = start ;

    while (PtrToStruct != NULL)
        {
           if(PtrToStruct -> studentID==StudentID)
           {
            printf ("Student Year : %d\n" ,PtrToStruct->student_Year );
            printf ("Student First course ID    : %d\n"   ,PtrToStruct->course_1_ID   );
            printf ("Student First course Grade : %f\n"   ,PtrToStruct->course_1_Grade);
            printf ("Student Second course ID   : %d\n"   ,PtrToStruct->course_2_ID   );
            printf ("Student Second course Grade: %f\n"   ,PtrToStruct->course_2_Grade);
            printf ("Student Third course ID    : %d\n"   ,PtrToStruct->course_3_ID   );
            printf ("Student Third course Grade : %f\n\n" ,PtrToStruct->course_3_Grade);
            break;

           }

           else
           {
           /*Increment of Pointer That Point from one struct to another*/
           PtrToStruct=PtrToStruct -> PtrNextData;
           }
        }
        if (PtrToStruct== NULL)
        {
            printf("This Student ID Doesn't Exist\n\n");
            return 0;
        }
}

void SDB_DeleteEntry (void)
{
    if(DataCounter!=0)
    {
        int   StudentID   = 0;
       printf ("Please Enter The Student ID to Delete his Data : ");
       scanf  ("%d", &StudentID);
    SimpleDb* LoopPtr = start ; /*Current Node Pointer*/

        while (LoopPtr != NULL)
        {
          if (LoopPtr->PtrNextData->studentID ==StudentID)
          {
            SimpleDb* NextNodePtr   = LoopPtr->PtrNextData->PtrNextData;
            SimpleDb* TargetNodePtr = LoopPtr->PtrNextData;
            LoopPtr->PtrNextData = NextNodePtr;
            free (TargetNodePtr);
            DataCounter -- ;
            printf ("Deleting Done .......\n\n ");
            break;
          }

           /*Increment of Pointer That Point from one struct to another*/
           LoopPtr=LoopPtr -> PtrNextData;
        }
    }
    else
    {
      printf ("There is no Data to be deleted.....\n\n ");
    }

}

void SDB_GetIdList (void)
{
if(DataCounter!=0)
{
    SimpleDb* PtrToStruct = start ;
    printf ("List of Students IDs :\n");
    while (PtrToStruct != NULL)
        {
           printf  ("%d\n", PtrToStruct -> studentID);

           /*Increment of Pointer That Point from one struct to another*/
           PtrToStruct=PtrToStruct -> PtrNextData;
        }
}
else
{
    printf ("List of Students IDs isn't provided yet.\n");
}

}

char SDB_IsIdExist(void)
{
    int   StudentID   = 0;
    printf ("Please Enter The Student ID you Want to find : ");
    scanf  ("%d", &StudentID);
    SimpleDb* PtrToStruct = start ;
    while (PtrToStruct != NULL)
        {
            if (PtrToStruct -> studentID == StudentID)
            {
                printf("This Student ID Exists\n\n");
                return 1;
                break;
            }

            else
            {
                PtrToStruct=PtrToStruct -> PtrNextData;
            }
        }
        if (PtrToStruct== NULL)
        {
            printf("This Student ID Doesn't Exist\n\n");
            return 0;
        }

}

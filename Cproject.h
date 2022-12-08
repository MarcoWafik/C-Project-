/********************************************************************************/
/**    File Name: Cproject.h                                                    */
/**                                                                             */
/**  Description: Prototype of the project functions & Struct                   */
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
#ifndef CPROJECT_H_
#define CPROJECT_H_

int DataCounter = 0;


typedef struct Database
{
     int   studentID;
     char  student_Year;
     int   course_1_ID;
     float course_1_Grade;
     int   course_2_ID;
     float course_2_Grade;
     int   course_3_ID;
     float course_3_Grade;

     struct Database* PtrNextData;

} SimpleDb ;


/*Linked List Functions*/
SimpleDb* Insert_Data_At_Begining (SimpleDb* start      ,int   studentID_copy     ,char student_Year_copy ,int   course_1_ID_copy ,float course_1_Grade_copy,
                                   int  course_2_ID_copy,float course_2_Grade_copy,int  course_3_ID_copy  ,float course_3_Grade_copy );

SimpleDb* Insert_Data_At_End (SimpleDb* start      ,int   studentID_copy     ,char student_Year_copy ,int   course_1_ID_copy ,float course_1_Grade_copy,
                              int  course_2_ID_copy,float course_2_Grade_copy,int  course_3_ID_copy  ,float course_3_Grade_copy );






/*Program Functions*/
void SDB_check       (void);
char SDB_GetUsedSize (void);
char SDB_AddData     (void);
void SDB_DeleteEntry (void);
char Read_Entry      (void);
void SDB_GetIdList   (void);
char SDB_IsIdExist   (void);
  


#endif

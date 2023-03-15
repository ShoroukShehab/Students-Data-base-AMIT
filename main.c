

#include "AMIT - C PROJECT.h"
#include "STD_Types.h"







int main()
{

    uint8 input =0, ID, Year;
    uint8 grade[3], subject[3];
    uint8 *year, *grades, *subjects, *Count, *List;

    grades = &grade[0];
    subjects = &subject[0];







    while (1)
    {
        printf("\n                     Welcome to AMIT DataBase                   \n");
        printf("Press 1 to Add Entry\n");
        printf("Press 2 to check if the DataBase is full or not\n");
        printf("Press 3 to get the number of entries in the DataBase\n");
        printf("Press 4 to read an entry with the ID\n");
        printf("Press 5 to delete an entry\n");
        printf("Press 6 to get the IDs present in the DataBase\n");
        printf("Press 7 to check if an ID does exist in the DataBase\n");
        scanf("%d", &input);

        switch (input)
        {
             case 1:
             {

                 printf("Please enter the ID you want to add:");
                 scanf("%d", &ID);
                 printf("Please enter the year of the student you want to add:");
                 scanf("%d", &Year);

                 for (int i = 0 ; i < 3 ; i++)
                 {
                     printf("Please enter Course%d ID you want to add:" , i+1);



                      scanf("%d", &subject[i]);


                 }
                  for (int i = 0 ; i < 3 ; i++)
                 {


                     printf("Please enter Courses%d grade you want to add:" , i+1);


                     scanf("%d", &grade[i]);

                 }
                 SDB_AddEntry(ID, Year, subjects, grades);
                 break;

               /* printf("Please Enter the New Entry ID \n");
                scanf("%d",&ID);
                printf("please enter the new entry year \n");
                scanf("%d",&Year);
                for (int i = 0; i < 3; i++)
                    {
                        printf("Please Enter the New Entry Subject %d \n",i+1);
                        scanf("%d",&subject[i]);
                        printf("Please Enter the New Entry Subject %d Grade \n",i+1);
                        scanf("%d",&grade[i]);
                    }
                SDB_AddEntry(ID,Year,subjects,grades);
                break;*/
             }

             case 2:
             {
                 SDB_isFull();
                 break;

             }


             case 3:
             {
                 SDB_GetUsedSize();
                 break;
             }


             case 4:
             {
                 printf("Please enter the ID you want to read:");
                 scanf("%d", &ID);

                 SDB_ReadEntry(ID, year, subjects, grades);
                 break;

             }



             case 5:
             {
                 printf("Please enter the ID you want to delete:");
                 scanf("%d", &ID);

                 SDB_DeleteEntry(ID);
                 break;

             }



             case 6:
             {

                 SDB_GetIdList(Count, List);
                 break;

             }

             case 7:
             {
                 printf("Please enter the ID you want to check:");
                 scanf("%d", &ID);

                 SDB_IsIdExist(ID);

                 break;


             }

        }



    }

    return 0;
}

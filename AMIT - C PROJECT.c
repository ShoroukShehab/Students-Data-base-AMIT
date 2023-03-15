#include "AMIT - C PROJECT.h"
#include "STD_Types.h"



static uint8 FULL = 0;

Bool SDB_isFull(void)
{

	if (FULL == MAX_SIZE)
	{
		printf(" The DataBase is full");
		//return TRUE; //return 1

	}
	else
		printf(" The DataBase is not full");
		//return FALSE;  //return 0

}


uint8 SDB_GetUsedSize(void)
{

	  printf ("Database Size = %d \n" , FULL);
      return FULL;

}



Bool SDB_AddEntry(uint8 id, uint8 year, uint8* subjects, uint8* grades)
{
	if (FULL == MAX_SIZE)
	{
		printf("The database is already full , you should delete first");
		return FALSE;

	}

	else
	{ for (int i = 0 ; i < 3 ; i++)
                        {
                            if (((*grades+i) < 0) || ((*grades+i) > 100))
                                {
                                    printf ("Grades Should be Between 0 & 100 ! \n");
                                    return FALSE;
                                }

                        }


	    for(int i=0 ; i<10 ; i++)
        {
            if (database[i].Student_Year == 0)
            {
                database[i].Student_ID = id;

                database[i].Student_Year = year;

                for (int j=0 ; j<3 ; j++)
                {

                database[i].Courses[j] = *(subjects+j);


                //grade 0->100 (need to be implemented)
                 database[i].Courses_Grades[j] = *(grades+j);

                }





                break;

           }

        }


        FULL++;

		printf("The Entry is added successfully");
		return TRUE;





	}


}






void SDB_DeleteEntry(uint8 id)
{
 int index;

printf ("CHECKING IF IT EXISTS \n");

   if (SDB_IsIdExist(id) == 0)
       printf("The ID is not found in the database, please try again  \n");
    else
    {
        FULL--;
        for (int i = 0 ; i< 10 ; i++)
            {
                if (database[i].Student_ID == id)
                    {
                        index = i;
                        break;
                    }
            }
        database[index].Student_ID = 0;
        database[index].Student_Year = 0;
        for (int i=0 ; i<3 ; i++)
        {
            database[index].Courses_Grades[i] = 0;
            database[index].Courses[i] = 0;
        }
        printf("The data of the ID: %d is deleted successfully\n", id);
    }






   /*	for (int i = 0; i < 10; i++)
	{
		if (database[i].Student_ID == id)
		{
			database[i].Student_ID = 0;
			database[i].Student_Year = 0;

			for (int j = 0; j < 3; j++)
			{
            database[i].Courses[j] = 0;
			database[i].Courses_Grades[j] = 0;
			}
			printf("The data of the ID: %d is deleted successfully", id);
			FULL--;
			break;


		}
		else
		{
			printf("The ID is not found in the database, please try again");
			break;
		}

	}*/



}




Bool SDB_ReadEntry(uint8 id, uint8* year, uint8* subjects, uint8* grades)
{
    int index = -1;
    printf ("CHECKING IF IT EXISTS \n");
	if (SDB_IsIdExist(id) == 0)
    {

        printf("This ID is Not Found in The Database ! \n");
        return FALSE;
    }



		else
		{
			for (int i = 0; i < 10; i++)
            {
                if (database[i].Student_ID == id)
                {
                index = i;
                break;

                }
            }
			printf("The data of the student's ID: %d is:\n", id);
			year = &database[index].Student_Year;

			printf("The student year:%d\n", *year);


			for (int j = 0; j < 3; j++)
			{
            subjects = &database[index].Courses[j];
            grades = &database[index].Courses_Grades[j];

            printf("The student Course%d IDs: %d\n", j+1 ,*subjects );
			printf("The student Course%d Grades: %d\n", j+1 , *grades );


			}


		}



		/*else
        {
            for (int i=0 ; i<10 ; i++)
            {
                if (database[i].Student_ID == id)
                {
                    printf("The data of the student's ID: %d is:\n", id);
                    year = &database[i].Student_Year;

                    printf("The student year:%d\n", *year);
                  //  subjects = &database[i].Courses[0];
                   // grades = &database[i].Courses_Grades[0];
                    for (int j = 0; j < 3; j++)
                    {
                   database[i].Courses[j] = *(subjects+j);
                   database[i].Courses_Grades[j] = *(grades+j);




                    printf("The student Course%d IDs: %d\n", j+1 ,*(subjects+j) );
                    printf("The student Course%d Grades: %d\n", j+1 ,*(grades+j) );
                    }
                    break;
                }
            }
        return TRUE;
*/

}







void SDB_GetIdList(uint8* Count, uint8* List)
{

    int LIST[10];
    Count = &FULL;
    printf("The number of entries present in the data base is : %d\n", *Count);

	for (int i = 0; i < FULL; i++)
	{

    LIST[i] = database[i].Student_ID ;

   List = &LIST[i];
   // printf("The list  %d\n", LIST[i]);
	printf("The list of IDs present in the database is: %d\n", *List);
	//printf("The list of IDs present in the database is: %d\n", LIST[i].Student_ID);
	}




}

Bool SDB_IsIdExist(uint8 ID)
{
	 int index = 0;
    for (int i = 0; i < 10 ; i++)
        {
            if (database[i].Student_ID == ID)
                {
                    index = 1;
                    break;
                }
        }
        if (index == 1)
        {
            printf("The given ID:%d does exist\n", ID);
            return TRUE;
        }
        else
        {
            printf("The ID doesn't exist in the database\n");
            return FALSE;
        }









}




/* Vehicle parking program */
//THIS PROGRAM IS FROM CODE-PROJECTS//
// THERE ARE SOME SMALL CHANES IN CODE //
//FOR MORE PROJECTS LOG ON TO : www.code-projects.org//
#include <stdio.h>
#include <conio.h>
#include <windows.h>

#define CAR 1
#define SCOOTER 2

/* to store vehicle number, and its
   row-col position in an array */
struct vehicle
{
	int num ;
	int row ;
	int col ;
  int type ;
} ;

int parkinfo[4][10] ;  /* a 2-D array to store number of vehicle parked */
int vehcount ;  /* to store total count of vehicles */
int carcount ;	/* stores total count of cars */
int scootercount ;  /* stores total count of scooters */

void display( ) ;
void changecol ( struct vehicle * ) ;
struct vehicle * add ( int, int, int, int ) ;
void del ( struct vehicle * ) ;
void getfreerowcol ( int, int * ) ;
void getrcbyinfo ( int, int, int * ) ;
void show( ) ;

/* decrements the col. number by one
   this fun. is called when the data is
   shifted one place to left */
void changecol ( struct vehicle *v )
{
	v -> col = v -> col - 1 ;
}

/* adds a data of vehicle */
struct vehicle * add ( int t, int num, int row, int col )
{
    struct vehicle *v ;

    v = ( struct vehicle * ) malloc ( sizeof ( struct vehicle ) ) ;

    v -> type = t ;
    v -> row = row ;
    v -> col = col ;

	  if ( t == CAR )
      carcount++ ;
    else
    	scootercount++ ;

    vehcount++ ;
	  parkinfo[row][col] = num ;

    return v ;
}

/* deletes the data of the specified
   car from the array, if found */
   
   
void login()
{
	int a=0,i=0;
    char uname[10],c=' '; 
    char pword[10],code[10];
    char user[10]="user";
    char pass[10]="pass";
    do
{
	
    printf("\n  \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb  LOGIN FIRST  \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb  ");
    printf(" \n\n                       ENTER USERNAME:-");
	scanf("%s", &uname); 
	printf(" \n\n                       ENTER PASSWORD:-");
	while(i<10)
	{
	    pword[i]=getch();
	    c=pword[i];
	    if(c==13) break;
	    else printf("*");
	    i++;
	}
	pword[i]='\0';
	//char code=pword;
	i=0;
	//scanf("%s",&pword); 
		if(strcmp(uname,"user")==0 && strcmp(pword,"pass")==0)
	{
	printf("  \n\n\n       WELCOME !! YOUR LOGIN IS SUCCESSFUL");
	printf("\n\n\n\t\t\t\tPress any key to continue...");
	getch();//holds the screen
	break;
	}
	else
	{
		printf("\n        SORRY !!!!  LOGIN IS UNSUCESSFUL");
		a++;
		
		getch();//holds the screen
		
	}
}
	while(a<=2);
	if (a>2)
	{
		printf("\nSorry you have entered the wrong username and password for four times!!!");
		
		getch();
		
		}
		system("cls");	
}   
   
   
void del ( struct vehicle *v )
{
  int c ;

	for ( c = v -> col ; c < 9 ; c++ )
	  parkinfo[v -> row][c] = parkinfo[v -> row][c+1] ;

	parkinfo[v -> row][c] = 0 ;

	if ( v -> type == CAR )
    carcount-- ;
  else
    scootercount-- ;

	vehcount-- ;
}

/* get the row-col position for the vehicle to be parked */
void getfreerowcol ( int type, int *arr )
{
  int r, c, fromrow = 0, torow = 2 ;

  if ( type == SCOOTER )
  {
    fromrow += 2 ;
    torow += 2 ;
  }

	for ( r = fromrow ; r < torow ; r++ )
	{
		for ( c = 0 ; c < 10 ; c++ )
		{
			if ( parkinfo[r][c] == 0 )
			{
				arr[0] = r ;
				arr[1] = c ;
        return ;
			}
		}
	}

	if ( r == 2 || r == 4 )
	{
   	arr[0] = -1 ;
    arr[1] = -1 ;
  }
}

/* get the row-col position for the vehicle with specified number */
void getrcbyinfo ( int type, int num, int *arr )
{
  int r, c, fromrow = 0, torow = 2 ;

  if ( type == SCOOTER )
	{
    fromrow += 2 ;
    torow += 2 ;
	}

	for ( r = fromrow ; r < torow ; r++ )
	{
		for ( c = 0 ; c < 10 ; c++ )
		{
			if ( parkinfo[r][c] == num )
			{
				arr[0] = r ;
				arr[1] = c ;
        return ;
			}
		}
	}

	if ( r == 2 || r == 4 )
	{
		arr[0] = -1 ;
		arr[1] = -1 ;
	}
}

/* displays list of vehicles parked */
void display( )
{
  int r, c ;

  printf ( "\xdb\xdb Cars =>\n" ) ;

  for ( r = 0 ; r < 4 ; r++ )
  {
    if ( r == 2 )
		  printf ( "\xdb\xdbScooters =>\n" ) ;

    for ( c = 0 ; c < 10 ; c++ )
      printf ( "%d\t", parkinfo[r][c] ) ;
    printf ( "\n" ) ;
	}
}

int first( )
{
	printf("\n\t\t\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\n");
	printf("\t\t\xdb                                               \xdb\n");
	printf("\t\t\xdb       =============================           \xdb\n");
	printf("\t\t\xdb        VEHICLE PARKING MANAGEMENT             \xdb\n");
	printf("\t\t\xdb       =============================           \xdb\n");
	printf("\t\t\xdb                                               \xdb\n");
	printf("\t\t\xdb       Brought To You By Code-Projects         \xdb\n");
	printf("\t\t\xdb                                               \xdb\n");
	printf("\t\t\xdb                 LTTS                      \xdb\n");
	printf("\t\t\xdb                                               \xdb\n");
	printf("\t\t\xdb      CONTACT US:6300686681        \xdb\n");
	printf("\t\t\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\n\n\n");
	printf(" \n\t Press Any Key To Continue:");
	
	getch();	
    system("cls");
    login();
}


int main( )
{
	int choice, type, number, row = 0, col = 0 ;
	int i, tarr[2] ;
	int finish = 1 ;

	/* creates a 2-D array of car and scooter class */
	struct vehicle *car[2][10] ;
	struct vehicle *scooter[2][10] ;

  system ( "cls" ) ;

	/* displays menu and calls corresponding functions */
	first();
	while ( finish )
	{
		
    system ( "cls" ) ;
		printf ( "\n\t\xdb\xdb\xdb\xdb\xdb\xdb\xdb VEHICLE PARKING \xdb\xdb\xdb\xdb\xdb\xdb\xdb\n" ) ;
		
		printf ( "\n\t1>> Arrival Of Vehicle\n" ) ;
		printf ( "\n\t2>> Total No. Of Vehicles Parked\n" ) ;
		printf ( "\n\t3>> Total No. Of Cars Parked\n" ) ;
		printf ( "\n\t4>> Total No. Of Scooters Parked\n" ) ;
		printf ( "\n\t5>> Display Vehicles Parked (Order)\n" ) ;
		printf ( "\n\t6>> Departure Of Vehicle\n" ) ;
		printf ( "\n\t7>> Exit\n" ) ;
		printf ("\n\t\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb");
		printf(" \n\n Enter Your Choice Here:");
		scanf ( "%d", &choice ) ;

		switch ( choice )
		{
			case 1 :
          system ( "cls" ) ;
				  printf ( "\n\t\xdb\xdb Add: \xdb\xdb \n" ) ;

          type = 0 ;

          /* check for vehicle type */
          while ( type != CAR && type != SCOOTER )
          {
					  printf ( "\tEnter vehicle type (1 for Car / 2 for Scooter ): \n" ) ;
            scanf ( "%d", &type ) ;
	          if ( type != CAR && type != SCOOTER )
						  printf ( "\nInvalid vehicle type.\n" ) ;
          }

				  printf ( "Enter vehicle number: " ) ;
				  scanf ( "%d", &number ) ;

				  /* add cars' data */
				  if ( type == CAR || type == SCOOTER )
				  {
					  getfreerowcol ( type, tarr ) ;

					  if ( tarr[0] != -1 && tarr[1] != -1 )
					  {
						  row = tarr[0] ;
						  col = tarr[1] ;

              if ( type == CAR )
                car[row][col] =  add ( type, number, row, col ) ;
              else
							  scooter[row - 2][col] = add ( type, number, row, col ) ; ;
            }
					  else
            {
              if ( type == CAR )
                printf ( "\nNo parking slot free to park a car\n" ) ;
              else
                printf ( "\nNo parking slot free to park a scooter\n" ) ;
            }
          }
				  else
				  {
            printf ( "Invalid type\n" ) ;
					  break ;
          }

          printf ( "\nPress any key to continue..." ) ;
          getch( ) ;
          
				  break ;

      case 2 :
          system ( "cls" ) ;
				  printf ( "Total vehicles parked: %d\n", vehcount ) ;
          printf ( "\nPress any key to continue..." ) ;
          getch( ) ;
				  break ;

			case 3 :
          system ( "cls" ) ;
				  printf ( "Total cars parked: %d\n", carcount ) ;
          printf ( "\nPress any key to continue..." ) ;
          getch( ) ;
				  break ;

			case 4 :
          system ( "cls" ) ;
				  printf ( "Total scooters parked: %d\n", scootercount ) ;
          printf ( "\nPress any key to continue..." ) ;
          getch( ) ;
				  break ;

			case 5 :
          system ( "cls" ) ;
				  printf ( "Display\n" ) ;
				  display( ) ;
          printf ( "\nPress any key to continue..." ) ;
          getch( ) ;
				  break ;

			case 6 :
          system ( "cls" ) ;
				  printf ( "Departure\n" ) ;
          type = 0 ;
          /* check for vehicle type */
          while ( type != CAR && type != SCOOTER )
          {
					  printf ( "Enter vehicle type (1 for Car / 2 for Scooter ): \n" ) ;
            scanf ( "%d", &type ) ;
	          if ( type != CAR && type != SCOOTER )
						  printf ( "\nInvalid vehicle type.\n" ) ;
          }
				  printf ( "Enter number: "  ) ;
				  scanf ( "%d", &number ) ;

  				if ( type == CAR || type == SCOOTER )
	  			{
		  			getrcbyinfo ( type, number, tarr ) ;
			  		if ( tarr[0] != -1 && tarr[1] != -1 )
				  	{
              col = tarr [1] ;
              /* if the vehicle is car */
              if ( type == CAR )
              {
                row = tarr [0] ;
	              del ( car [row][col] ) ;
							  for ( i = col ; i < 9 ; i++ )
							  {
								  car[row][i] = car[row][i + 1] ;
								  changecol ( car[row][i] ) ;
							  }
                free ( car[row][i] ) ;
							  car[row][i] = NULL ;
              }
						  /* if a vehicle is scooter */
						  else
              {
                row = tarr[0] - 2 ;
							  if ( ! ( row < 0 ) )
							  {
								  del ( scooter[row][col] ) ;
								  for ( i = col ; i < 9 ; i++ )
								  {
									  scooter[row][i] = scooter[row][i + 1] ;
									  changecol ( scooter[row][col] ) ;
								  }
								  scooter[row][i] = NULL ;
                }
              }
            }
					  else
            {
              if ( type == CAR )
							  printf ( "\nInvalid car number, or a car with such number has not been parked here.\n" ) ;
              else
                printf ( "\nInvalid scooter number, or a scooter with such number has not been parked here.\n" ) ;
            }
          }
          printf ( "\nPress any key to continue..." ) ;
          getch( ) ;
				  break ;

			case 7 :
          system ( "cls" ) ;
          for ( row = 0 ; row < 2 ; row++ )
          {
            for ( col = 0 ; col < 10 ; col++ )
            {
              if ( car[row][col] -> num != 0 )
                free ( car[row][col] ) ;
              if ( scooter[row][col] -> num != 0 )
							  free ( scooter[row+2][col] ) ;
            }
          }
				  finish = 0 ;
				  break ;
    }
	}
  return 0 ;
}
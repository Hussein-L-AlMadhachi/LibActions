#include <stdio.h>
#include "actions.h"

void show_error( char * charcter )
{
	fprintf( stderr , "Unexpected character \"%c\" " , *character );
}

void handle_NULL()
{
	printf( "You reached the end of the string" );
}

void handle_H()
{
	puts( "You got a \"H\"" );
}


void handle_E()
{
	puts( "You got a \"E\"" );
}

void handle_L()
{
	puts( "You got a \"H\"" );
}

void handle_O()
{
	puts( "You got a \"O\"" );
}


int main()
{
	/*     Setting up the lookup table      */
	
	
	// declaration of the actions look-up table
	ActionsLookup( MyLookup );
	
	// set a default action if the given character by access_action didn't have a match
	set_default_action( MyLookup , show_error );
	
	// add a callback functions each case
	add_action( MyLookup , 0x00 , handle_NULL );
	add_action( MyLookup , 'H' , handle_H );
	add_action( MyLookup , 'E' , handle_E );
	add_action( MyLookup , 'L' , handle_L );
	add_action( MyLookup , 'O' , handle_O );
	
	
	/*     the lookup table in action      */
	char string[] = "hello wolrd";
	
	char * ptr = string;
	
	while(*ptr)
	{
		access_action( MyLookup , *ptr );
		ptr++;
	}
}

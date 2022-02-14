# LibActions

A library to create calback functions that can be called when some specific characters are encountered. 

# How to use

this is an example on how it can be used:
```c
#include <stdio.h>
#include "actions.h"

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
```
this should be compiled with
```bash
user@machine:~$ gcc libActions.c example.c
```

# The API documentation
```c
/*
 *  create an array of pointer to functions to make 
 *  it possible to assign each character a function
 *
 *  NOTE:
 *    you should use it in variable declaration
 */
#define ActionsLookup( varname ) \
	void ( * varname [256] ) (char * string )


/*
 *  Description:
 *    Link an action (a function) to a value (a character)
 *    so later the function can be accessed when the
 *    same character is given
 *  
 *  Parameters:
 *    
 *    ActionsList( actions_lookup )         a macro that creates a lookup table
 *                                          made of array of functions
 *    
 *    int character                         the character you want to assign an
 *                                          action for
 *    
 *    void (* function)(char * string)      the function that will be called
 *                                          when accessing the same character
 *  
 */
void add_action (  ActionsLookup( actions_lookup )  ,
					int character  ,  
					void(* function)(char * string) );

/*
 *  Description:
 *    call the function that has been linked to the given character
 *    be add_action() function
 *  
 *  Parameters:
 *    
 *    ActionsList( actions_lookup )         the list of actions
 *    
 *    char * character                      the character access its action
 */
void access_action (  ActionsLookup( actions_lookup )  ,
						char * character  );

/*
 *  Description:
 *    set a default action to handle charaters that have never been assigned an
 *    action to prevent a SegFaults if the character has no action
 *  
 *  Parameters:
 *    
 *    ActionsList( actions_lookup )         the list of actions you want to set
 *                                          a default action for
 *    
 *    void (* function)(char * string)      the default action that you want it
 *                                          to handle exceptions if there were
 *                                          no match
 *  
 */ 
void set_default_action (  ActionsLookup( actions_lookup )  ,
							void (* function)(char * string)  );
```

# Copyright

This code is licensed under terms of the General Public License version 3.

/*  
 *  This is a part of the Almond imterpreter which is licensed under the
 *  General Public License version 3.
 *
 *  Copyright (C) 2022  Hussein Layth Al-Madhachi
 * 
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *  
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *  
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *  
 */




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

int hello;

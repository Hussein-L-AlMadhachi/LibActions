/*   
 *   A library to create calback functions that can be called when some specific
 *   characters are encountered.
 *   
 *   Copyright (c) 2022 Hussein Layth Al-Madhachi
 *
 *   Permission is hereby granted, free of charge, to any person obtaining a copy
 *   of this software and associated documentation files (the "Software"), to deal
 *   in the Software without restriction, including without limitation the rights
 *   to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 *   copies of the Software, and to permit persons to whom the Software is
 *   furnished to do so, subject to the following conditions:
 *   
 *   The above copyright notice and this permission notice shall be included in all
 *   copies or substantial portions of the Software.
 *   
 *   THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 *   IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 *   FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 *   AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 *   LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 *   OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 *   SOFTWARE.
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

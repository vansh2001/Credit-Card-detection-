/*  
*  Usage: ccnum
*  The Program will check for credit cards numbers and will display "ok" if it is valid, "bad" 
 * if its not valid and completes the number if it is 'x' as the 16th digit. 
*
*  Grading preference: I would like this to be graded on an EOS machine.
*  
*  H. Mareddy, Fall 2017
 */


#include <stdio.h>
#include <stdlib.h>

int main() {
    
    int user_input = 0;  // user entered numbers 
    int num_counter = 0; // Total numbers entered by user
    int sum = 0;         // sum of numbers not the final sum
    int total_sum = 0;   // final sum of numbers 
    int check_x = 0;     // Holds the 16th value of only if its 'x'
  
    printf("Enter numbers, or 'q' to quit:\n"); // Ask user to print numbers 
    
   while(user_input != 'q') //Loop until q is pressed
     {
        user_input  = 0;
        num_counter = 0; 
        sum = 0; 
        total_sum = 0;
        check_x = 0;
          
        while(user_input != '\n') // Run while enter not pressed
        {
            user_input = getchar(); // get user's inputs 
            
            if ((user_input >= '0' && user_input <= '9') || user_input == 'x') // only take digits between 0 and 9 or letter x                                                           
            {
                num_counter++; // increment counter by 1
                sum = user_input-48; // subtract 48 to convert from ASCII to decimal value
         
                if(num_counter == 16 && user_input == 'x')// if there are 16 digits and the 16th digit is x
                {
                
                total_sum = (10 - (total_sum % 10)); // take the remainder and subtract 10 and equal to total_sum
                check_x = 'x'; //Stores the 16th digit user_input 
                }
                
                else  // if the 16th digit is not x then run this
                { 
                    if(num_counter == 1 || num_counter == 3 || num_counter == 5 || num_counter == 7     //if counter is an odd value upto 15
                    || num_counter == 9 || num_counter == 11 || num_counter == 13 || num_counter == 15)
                    { 
                   // check for sum*2 if its greater than 10 and do the math based of the result.
                        if (sum*2 >= 10) //check for sum if greater than 9
                        {   
                            sum = (sum*2)-9;  /*if some is true then double the sum values then subtract 9 
                                        ex: 9*2 = 18, 18 -9 = 9 sum = 9; */    
                        }
                        
                        else // if not greater than 10 then run this  
                        {
                        sum = sum*2; // if sum is not greater than nine double and add to sum
                        }
                 
                        total_sum = total_sum + sum; // Add sum to the total_sum  
                    }
                
                    else
                    {
                    
                        total_sum = total_sum + sum; // total sum of the numbers all added
                    }
                }        
            }
        
            else if (user_input == 'q') // if 'q' pressed then quit the program by returning 0
            {
                return 0; 
            }
    
            /* If total sum is a not multiple of 10 or not 16 digits then display "bad"
            if it is a multiple and has 16 digits its "ok". if its 15 digits and 16th is 'x' 
            * then display the total sum or x value.
            */ 
        }
        
        // conditions for the output on the terminal 
        if(total_sum % 10 == 0 && num_counter == 16 && check_x != 'x')
        {
            
            printf("  ok\n"); // print ok if credit card number is not correct
            //printf("\n");
        } 
        else if((total_sum % 10 != 0 && check_x != 'x') || num_counter <16)
        {
            
             printf("  bad\n"); // print bad if the credit card number is not good
             //printf("\n");
             
        }
            else 
        {
                if(total_sum == 10) // If total_sum = 10 can't have x with 2 digits so its 0. This is basically a glitch. 
                {
                    total_sum = 0;
                    //printf("\n"); // print enter 
                    printf("  %d\n", total_sum); //total sum here is the value of x the last digit
                    //printf("\n"); //print enter after
                 }
                 else
                 {
                    //printf("\n");
                    printf("  %d\n", total_sum); //total sum here is the value of x the last digit
                    //printf("\n");
                }
        } 
    }
    return (EXIT_SUCCESS);
}


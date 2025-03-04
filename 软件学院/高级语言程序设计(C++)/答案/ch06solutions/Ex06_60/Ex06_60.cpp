// Exercise 6.60 Solution: Ex06_60.cpp
// Help user practice arithmetic according to grade level;
// user can choose between addition, subtraction,
// multiplication, division or random mix.
#include <iostream> 
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;

int generateProblem( int, int ); // function prototype
void correctMessage(); // function prototype
void incorrectMessage(); // function prototype
bool checkDone( int, int ); // function prototype

enum Type { ADDITION = 1, SUBTRACTION, MULTIPLICATION, DIVISION, RANDOM };

int main()
{
   int response = 0; // user response for product
   int correct = 0; // total number of correct responses
   int incorrect = 0; // total number of incorrect responses
   int level; // difficulty level
   int problemType;

   // get problem type from user
   do 
   {
      cout << "Choose type of problem to study." 
         << "\nEnter: 1 for addition, 2 for subtraction"
         << "\nEnter: 3 for multiplication, 4 for division"
         << "\nEnter: 5 for a combination of 1 through 4\n? ";
      cin >> problemType;
   } while ( problemType < 1 || problemType > 5 );

   cout << "Enter difficulty level: ";
   cin >> level;

   srand( time( 0 ) ); // seed random number generator

   // loop until sentinel value read from user
   while ( response != -1 ) 
   {
      // generate problem
      int answer = generateProblem( level, problemType );
      cin >> response; // read user's guess

      // loop until sentinel value or correct response
      while ( response != -1 && response != answer ) 
      {
         ++incorrect; // update total number of incorrect responses

         if ( checkDone( correct, incorrect ) ) // check progress
         {
            // done 10 responses; reset for next person
            correct = incorrect = 0;
            break;
         } // end if

         incorrectMessage();
         cin >> response;
      } // end while

      // correct response
      if ( response == answer )
      {
         ++correct; // update total number of correct responses

         if ( checkDone( correct, incorrect ) ) // check progress
         {
            // done 10 responses; reset for next person
            correct = incorrect = 0;
            continue;
         } // end if

         correctMessage();
      } // end if
   } // end while

   cout << "That's all for now. Bye." << endl;
} // end main

// generates new product and displays prompt
int generateProblem( int level, int type )
{
   // maximum value for a particular level
   int max = static_cast< int >( pow( 10.0, level ) );
   int x = rand() % max; // generate random number
   int y = rand() % max; // generate random number

   if ( type == RANDOM )
      type = 1 + rand() % 4;

   // generate problem based on requested problem type
   switch ( type )
   {
      case ADDITION:
         cout << "How much is " << x << " plus " << y << "\n? ";
         return x + y;
      case SUBTRACTION:
         if ( x < y ) // check if it will be negative and swap
         {
            int temp = x;
            x = y;
            y = temp;
         } // end if

         cout << "How much is " << x << " minus " << y << "\n? ";
         return x - y;
      case MULTIPLICATION:
         cout << "How much is " << x << " times " << y << "\n? ";
         return x * y;
      case DIVISION:
         while ( y == 0 ) // eliminate divide by zero error
            y = rand() % max;

         x *= y; // create "nice" division
         cout << "How much is " << x << " divided by " << y << "\n? ";
         return x / y;
   } // end switch
} // end function generateProblem

// correctMessage randomly chooses response to correct answer
void correctMessage()
{
   // generate random number between 0 and 3
   switch ( rand() % 4 ) 
   {
      case 0:
         cout << "Very good!";
         break;
      case 1:
         cout << "Excellent!";
         break;
      case 2:
         cout << "Nice work!";
         break;
      case 3:
         cout << "Keep up the good work!";
         break;
   } // end switch

   cout << endl << endl;
} // end function correctMessage

// incorrectMessage randomly chooses response to incorrect answer
void incorrectMessage()
{
   // generate random number between 0 and 3
   switch ( rand() % 4 ) 
   {
      case 0:
         cout << "No. Please try again.";
         break;
      case 1:
         cout << "Wrong. Try once more.";
         break;
      case 2:
         cout << "Don't give up!";
         break;
      case 3:
         cout << "No. Keep trying.";
         break;
   } // end switch

   cout << endl << "? ";
} // end function incorrectMessage

// based on number of correct and incorrect, print
// result and return true if student's turn is over
bool checkDone( int right, int wrong )
{
   // if we've reached a total of 10 responses
   if ( right + wrong == 10 )
   {
      // check whether student got 75% correct or not
      if ( static_cast< double >( right ) / ( right + wrong ) < .75 )
         cout << "Please ask your teacher for extra help.\n\n";
      else
         cout << "Congratulations, you are ready to go "
            << "to the next level!\n\n";

      return true;
   } // end if

   return false;
} // end function checkDone

/**************************************************************************
 * (C) Copyright 1992-2010 by Deitel & Associates, Inc. and               *
 * Pearson Education, Inc. All Rights Reserved.                           *
 *                                                                        *
 * DISCLAIMER: The authors and publisher of this book have used their     *
 * best efforts in preparing the book. These efforts include the          *
 * development, research, and testing of the theories and programs        *
 * to determine their effectiveness. The authors and publisher make       *
 * no warranty of any kind, expressed or implied, with regard to these    *
 * programs or to the documentation contained in these books. The authors *
 * and publisher shall not be liable in any event for incidental or       *
 * consequential damages in connection with, or arising out of, the       *
 * furnishing, performance, or use of these programs.                     *
 **************************************************************************/

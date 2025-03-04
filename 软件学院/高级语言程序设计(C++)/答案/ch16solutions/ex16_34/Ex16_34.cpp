// Exercise 16.34 Solution: Ex16_34.cpp
#include <iostream> 
#include "TestException.h"
using namespace std;

void f() 
{ 
   throw TestException( "TestException" ); 
} // end function f 

void g() { f(); } // end function g

void h() { g(); } // end function h

int main()
{
   try 
   {
      h();
   } // end try
   catch ( TestException &t ) // catch any exceptions that occurred in h
   {
      cerr << "In main: Caught " << t.what() << '\n';
   } // end catch
} // end main


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

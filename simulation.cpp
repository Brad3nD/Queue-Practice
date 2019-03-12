#include "queue.h"

int main()
{
   int NumLines = 4;
   int NumCustomers = 10;
   int CurrentTime = 0;
   Queue *Vendor = new Queue[NumLines];

   // Add customers to different queues
   for (int Customer = 0; Customer < NumCustomers; Customer++)
   {
      // Generate customer data
      CurrentTime += 5 + random() % 20;
      int NumItems = 1 + random() % 5;
      int probability = rand() % 100;

      // Search for shortest queue
      int ShortLine = 0;
      int ShortLength = Vendor[0].GetLength();
      for (int Line = 1; Line < NumLines; Line++)
      {
	 int Length = Vendor[Line].GetLength();
	 if (Length < ShortLength)
	 {
	    ShortLine = Line;
	    ShortLength = Length;
	 }
         
      }

      // Add customer to shortest line
      Vendor[ShortLine].Insert(NumItems);
      
      //20%
      for(int i = 0; i < NumLines; i++)
      {
        if(probability <= 19 && Vendor[i].IsEmpty()!= false)
        {
          Vendor[i].Remove();
        }
        probability = rand() % 100;
      }
      
   }
   
   for(int i = 0; i < NumLines; i++ )
   {
          while(Vendor[i].IsEmpty() == false)
          {
              Vendor[i].Remove();
          }
   }
   

   // Print all customer lines
   for (int Line = 0; Line < NumLines; Line++)
   {
      cout << "Line " << Line << " ";
      Vendor[Line].Print();
   }
   cout << endl;
}
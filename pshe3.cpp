#include <iostream>
#include <thread>
#include "windows.h"
#include <conio.h>
#include <stdio.h>
#include <mutex>
#include "stacky_lib_pshe.h"
#include <stdlib.h>
#include <math.h>

int main ()
   {
   stacker <int> stack_for_translate;
   stack_for_translate.zeroid();

   std::cout << "chckend " << stack_for_translate.check_end() << " ";
   std::cout << "chckend " << stack_for_translate.ret_Front() << " ";

   string pol_string = "";
   std::getline(std::cin, pol_string);
   int pol_length = pol_string.size ();

   string fin_string = "";

   std::cout << "chckend " << stack_for_translate.check_end() << " ";

   for (int i = 0; i < pol_length; i++)
      {
      std::cout << i << "_" << std::endl;

      std::cout << fin_string << std::endl;

      std::cout << "chckend " << stack_for_translate.check_end() << std::endl;

      if (pol_string [i] >= '0' && pol_string [i] <= '9')
         {
         fin_string += pol_string [i];
         }
      else if (pol_string [i] == '(')
         {
         stack_for_translate.push_Front (pol_string [i]);
         }
      else if (pol_string [i] == ')')
         {
         while (!stack_for_translate.check_end() && stack_for_translate.ret_Front() != '(')
            {
            fin_string += stack_for_translate.ret_Front();

            stack_for_translate.pop_Front();
            }

         if (!stack_for_translate.check_end() && stack_for_translate.ret_Front() == '(')
            {
            stack_for_translate.pop_Front();
            }
         }
      else if (pol_string [i] == '+' || pol_string [i] == '-')
         {
         std::cout << "chckend " << stack_for_translate.check_end() << " ";

         while (!stack_for_translate.check_end() && (stack_for_translate.ret_Front() == '+' ||
                                                     stack_for_translate.ret_Front() == '-' ||
                                                     stack_for_translate.ret_Front() == '*' ||
                                                     stack_for_translate.ret_Front() == '/'))
            {
            fin_string += stack_for_translate.ret_Front();

            stack_for_translate.pop_Front();
            }

         stack_for_translate.push_Front (pol_string [i]);
         }
      else if (pol_string [i] == '*' || pol_string [i] == '/')
         {
         std::cout << "chckend " << stack_for_translate.check_end() << " ";

         while (!stack_for_translate.check_end() && (stack_for_translate.ret_Front() == '+' ||
                                                     stack_for_translate.ret_Front() == '-'))
            {
            fin_string += stack_for_translate.ret_Front();

            stack_for_translate.pop_Front();
            }

         stack_for_translate.push_Front (pol_string [i]);
         }
      else
         {
         fin_string += pol_string [i];
         }
      }

   int it = 0;

   std::cout << fin_string;
   std::cout << stack_for_translate.ret_Front() << std::endl;

   Sleep (2000);

   while (!stack_for_translate.check_end())
      {
      std::cout << it << std::endl;

      std::cout << "chckend " << stack_for_translate.check_end() << " ";

      std::cout << "__" << stack_for_translate.ret_Front() << "__";

      fin_string += stack_for_translate.ret_Front();

      stack_for_translate.pop_Front();

      it++;

      std::cout << "str " << fin_string << " ";
      }

   std::cout << fin_string;
   }

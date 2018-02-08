#include <iostream>
#include <thread>
#include "windows.h"
#include <conio.h>
#include <stdio.h>
#include <mutex>
#include "stacky_lib_pshe.h"
#include <stdlib.h>
#include <math.h>
using namespace std;

int turn_to_int (string smth);

int main()
   {
   stacker <int> stack_for_pshe;

   string pshe_string = "";
   std::getline(std::cin, pshe_string);
   int pshe_length = pshe_string.size ();

   string tmp_string = "";

   int tmp1 = 0; int tmp2 = 0;

   for (int i = 0; i < pshe_length; i++)
      {
      std::cout << "__" << i << "__" << std::endl;

      if (pshe_string[i] >= '0' && pshe_string[i] <= '9')
         {
         tmp_string += pshe_string [i];

         std::cout << tmp_string << std::endl;
         }
      else if (tmp_string != "")
         {
         std::cout << "tmpstr "<< turn_to_int (tmp_string) << std::endl;

         stack_for_pshe.push_Front (turn_to_int (tmp_string));

         std::cout << "in stack" << stack_for_pshe.ret_Front() << std::endl;

         tmp_string = "";
         }

      if (pshe_string[i] == '+' || pshe_string[i] == '-' || pshe_string[i] == '*' || pshe_string[i] == '/')
         {
         tmp1 = stack_for_pshe.ret_Front();
         stack_for_pshe.pop_Front();

         tmp2 = stack_for_pshe.ret_Front();
         stack_for_pshe.pop_Front();

         if (pshe_string [i] == '+')
            stack_for_pshe.push_Front(tmp1 + tmp2);
         else if (pshe_string [i] == '-')
            stack_for_pshe.push_Front(tmp1 - tmp2);
         else if (pshe_string [i] == '*')
            stack_for_pshe.push_Front(tmp1 * tmp2);
         else if (pshe_string [i] == '/')
            stack_for_pshe.push_Front(tmp1 / tmp2);

         tmp1 = 0;
         tmp2 = 0;
         }
      /*else if (pshe_string[i] == '(')
         {
         stack_for_pshe.push_Front(0, true);
         }
      else if (pshe_string[i] == ')')
         {
         while (!stack_for_pshe.ret_Front_bool() && !stack_for_pshe.check_end())
            {

            }

         stack_for_pshe.pop_Front();
         } */
      }

   std::cout << std::endl;
   std::cout << "fin";
   std::cout << stack_for_pshe.ret_Front();
   }

int turn_to_int (string smth)
   {
   int length = smth.size ();
   int ret = 0;


   for (int i = 0; i < length; i++)
      {
      ret += (((int) (smth [i] - '0')) * pow (10, (length - i - 1)));
      }


   return ret;
   }


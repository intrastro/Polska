#include <iostream>
#include <thread>
#include <conio.h>
#include <stdio.h>
#include <math.h>
#include "stack_lib.h"
using namespace std;

#define development FALSE
#define imp_calc "impossible to calculate"
#define imp_ret "impossible to return"

const int CAL_SYS = 10;

string translate_usual_to_pol (string &in_string);
int calculate_pol (string &pol_string);
int turn_to_int (string smth);



string translate_usual_to_pol (string &in_string)
    {
    stacker <int> stack_for_translate;

    #if development
    std::cout << "chckend " << stack_for_translate.check_end() << " ";
    std::cout << "chckend " << stack_for_translate.ret_Front() << " ";
    #endif

    int pol_length = in_string.size();
    string fin_string = "";

    for (int i = 0; i < pol_length; i++)
        {
        #if development
        std::cout << i << "_" << std::endl;

        std::cout << fin_string << std::endl;

        std::cout << "chckend " << stack_for_translate.check_end() << std::endl;
        #endif

        if (in_string [i] >= '0' && in_string [i] <= '9')
            {
            fin_string += in_string [i];
            }
        else if (in_string [i] == '(')
            {
            stack_for_translate.push_Front (in_string [i]);
            }
        else if (in_string [i] == ')')
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
        else if (in_string [i] == '+' || in_string [i] == '-')
            {
            #if development
            std::cout << "chckend " << stack_for_translate.check_end() << " ";
            #endif

            while (!stack_for_translate.check_end() && (stack_for_translate.ret_Front() == '+' ||
                                     stack_for_translate.ret_Front() == '-' ||
                                     stack_for_translate.ret_Front() == '*' ||
                                     stack_for_translate.ret_Front() == '/'))
                {
                fin_string += stack_for_translate.ret_Front();

                stack_for_translate.pop_Front();
                }

            stack_for_translate.push_Front (in_string [i]);
            }
        else if (in_string [i] == '*' || in_string [i] == '/')
            {
            #if development
            std::cout << "chckend " << stack_for_translate.check_end() << " ";
            #endif

            while (!stack_for_translate.check_end() && (stack_for_translate.ret_Front() == '+' ||
                                     stack_for_translate.ret_Front() == '-'))
                {
                fin_string += stack_for_translate.ret_Front();

                stack_for_translate.pop_Front();
                }

            stack_for_translate.push_Front (in_string [i]);
            }
        else
            {
            fin_string += in_string [i];
            }
        }


    #if development
    std::cout << fin_string;
    std::cout << stack_for_translate.ret_Front() << std::endl;
    #endif

    while (!stack_for_translate.check_end())
        {
        #if development
        std::cout << "chckend " << stack_for_translate.check_end() << " ";

        std::cout << "__" << stack_for_translate.ret_Front() << "__";
        #endif

        fin_string += stack_for_translate.ret_Front();

        stack_for_translate.pop_Front();
        }

    return fin_string;
    }

int calculate_pol (string &pol_string)
    {
    stacker <int> stack_for_pol;

    int pol_length = pol_string.size();

    string tmp_string = "";

    int tmp1 = 0; int tmp2 = 0;

    for (int i = 0; i < pol_length; i++)
        {
        #if development
        std::cout << "__" << i << "__" << std::endl;
        #endif

        if (pol_string[i] >= '0' && pol_string[i] <= '9')
            {
            tmp_string += pol_string [i];

            #if development
            std::cout << tmp_string << std::endl;
            #endif
            }
        else if (tmp_string != "")
            {
            #if development
            std::cout << "tmpstr "<< turn_to_int (tmp_string) << std::endl;
            #endif

            stack_for_pol.push_Front (turn_to_int (tmp_string));

            #if development
            std::cout << "in stack" << stack_for_pol.ret_Front() << std::endl;
            #endif

            tmp_string = "";
            }

        if (pol_string[i] == '+' || pol_string[i] == '-' || pol_string[i] == '*' || pol_string[i] == '/')
            {
            #if development
            std::cout << "!!!";
            #endif

            if (!stack_for_pol.check_end())
                {
                tmp1 = stack_for_pol.ret_Front();
                stack_for_pol.pop_Front();
                }
            else
                {
                std::cout << imp_calc;

                break;
                }

            #if development
            std::cout << tmp1 << "!!!";
            #endif

            if (!stack_for_pol.check_end())
                {
                tmp2 = stack_for_pol.ret_Front();
                stack_for_pol.pop_Front();
                }
            else
                {
                std::cout << imp_calc;

                break;
                }

            #if development
            std::cout << tmp2 << "!!!";
            #endif

            if (pol_string [i] == '+')
                stack_for_pol.push_Front(tmp2 + tmp1);

            else if (pol_string [i] == '-')
                stack_for_pol.push_Front(tmp2 - tmp1);

            else if (pol_string [i] == '*')
                stack_for_pol.push_Front(tmp2 * tmp1);

            else if (pol_string [i] == '/')
                if (tmp1 != 0)
                    {
                    stack_for_pol.push_Front(tmp2 / tmp1);
                    }

            #if development
            std::cout << stack_for_pol.ret_Front() << "!!!";
            #endif // development

            tmp1 = 0;
            tmp2 = 0;
            }
        }

    if (!stack_for_pol.check_end())
        return  stack_for_pol.ret_Front();
    else
        {
        std::cout << imp_ret;

        return 0;
        }
    }

int turn_to_int (string smth)
   {
   int length = smth.size ();
   int ret = 0;

   for (int i = 0; i < length; i++)
      {
      ret += (((int) (smth [i] - '0')) * pow (CAL_SYS, (length - i - 1)));
      }

   return ret;
   }

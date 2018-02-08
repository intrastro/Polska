#include <iostream>
#include <thread>
#include "windows.h"
#include <conio.h>
#include <stdio.h>
#include <mutex>
using namespace std;

#define stacker_version 0.1;


struct letter_stack
    {
    int symbol;
    letter_stack* link_back;
    bool bracket;
    };
typedef letter_stack *Pletter_stack;

template <typename new_type> class stacker
    {
    private:
        Pletter_stack Header;
        std::mutex locker;

    public:
        stacker ()
            {
            Pletter_stack Header = new letter_stack;
            Header -> link_back = nullptr;
            Header -> symbol = '\0';

            std::cout << "created" << std::endl;
            }

        ~stacker ()
            {
            std::cout << std::endl;
            std::cout << "deleted" << std::endl;
            }

        bool push_Front (new_type value)
            {
            //std::cout << "puF_try" << std::endl;
            std::cout << "from class_" << value << "__";

            locker.lock ();

            Pletter_stack link_tmp = new letter_stack;

            link_tmp -> link_back = Header;

            Header = link_tmp;

            Header -> symbol = value;

            Header -> bracket = false;

            link_tmp = nullptr;

            delete link_tmp;

            locker.unlock ();

            return true;
            }

         /*bool push_Front (new_type value, bool bracket_mean)
            {
            //std::cout << "puF_try" << std::endl;

            locker.lock ();

            Pletter_stack link_tmp = new letter_stack;

            link_tmp -> link_back = Header;

            Header = link_tmp;

            Header -> symbol = value;

            Header -> bracket = bracket_mean;

            link_tmp = nullptr;

            locker.unlock ();

            return true;
            }*/


        bool pop_Front ()
            {
            //std::cout << "poF_try" << std::endl;

            locker.lock ();

            if (!check_end ())
                {
                Pletter_stack link_tmp = Header;

                Header = Header -> link_back;

                delete link_tmp;
                }
            else
                {
                locker.unlock ();

                return false;
                }
            }


        int ret_Front ()
            {
            //std::cout << "rf_try" << std::endl;

            if (!check_end())
               {
               return (int) Header -> symbol;
               }
            }

        bool ret_Front_bool ()
            {
            //std::cout << "rf_try" << std::endl;

            if (!check_end())
               {
               return (int) Header -> bracket;
               }
            else
               return false;

            }

        bool check_end ()
            {
            if (Header -> link_back == nullptr)
                {
                //std::cout << "true";

                return true;
                }
            else
                {
                //std::cout << "false";

                return false;
                }
            }

    };



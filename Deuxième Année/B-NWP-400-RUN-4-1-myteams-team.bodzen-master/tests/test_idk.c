/*
** EPITECH PROJECT, 2021
** tests
** File description:
** unit_test
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include ""

void redirect_all_std(void)
{
    cr_redirect_stdout();
}

Test(func_idk, first_redirect, .init = redirect_all_std)
{
    /*here goes all the functions to be done b4 comparing w/ the output*/
    cr_assert_stdout_eq_str("a string");
}

/* here we go for normal tests*/

Test(func_to_be_tested, name_test)
{
    cr_assert_eq_str(res, "a string");
}

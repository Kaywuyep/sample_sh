#!/bin/sh

# a beautiful code that passes the Betty checks

# a function to welcome user

hi_user()
{
	echo "\nHello,\n \tWelcome to our beautiful shell script\n"
}

# a function that makes the introduction

introduction()
{
	local name1="Catherine" name2="Frank" project="simple_shell"

	echo "\tMy name is $name1"
	echo "\tMy partner's name is $name2"
	echo "\nThis is a sample for our $project project tasks\n"
}

main()
{
	hi_user
	introduction
}

main

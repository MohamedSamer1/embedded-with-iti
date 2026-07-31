#!/bin/bash

read -s -p "Enter password: " password
length=${#password}
hasUpper=0
hasLower=0
hasDigit=0
hasSpecial=0
score=0

if [[ $password =~ [A-Z] ]]; then
    hasUpper=1
    score=$(expr $score + 1)
fi

if [[ $password =~ [a-z] ]]; then
    hasLower=1
    score=$(expr $score + 1)
fi

if [[ $password =~ [0-9] ]]; then
    hasDigit=1
    score=$(expr $score + 1)
fi

if [[ $password =~ [^a-zA-Z0-9] ]]; then
    hasSpecial=1
    score=$(expr $score + 1)
fi

echo
echo "Password Strength Report"
echo

if [ $length -ge 8 ]; then
    echo "Length          : OK"
    score=$(expr $score + 1)
else
    echo "Length          : Missing"
fi

if [ $hasUpper -eq 1 ]; then
    echo "Uppercase       : OK"
else
    echo "Uppercase       : Missing"
fi

if [ $hasLower -eq 1 ]; then
    echo "Lowercase       : OK"
else
    echo "Lowercase       : Missing"
fi

if [ $hasDigit -eq 1 ]; then
    echo "Digit           : OK"
else
    echo "Digit           : Missing"
fi

if [ $hasSpecial -eq 1 ]; then
    echo "Special Char    : OK"
else
    echo "Special Char    : Missing"
fi


echo

if [ $score -eq 5 ]; then
    echo "Overall: Strong"
elif [ $score -ge 3 ]; then
    echo "Overall: Medium"
else
    echo "Overall: Weak"
fi
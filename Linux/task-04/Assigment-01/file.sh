#!/bin/bash

read -p "Enter first number: " num1
read -p "Enter second number: " num2

sum=$(expr $num1 + $num2)
diff=$(expr $num1 - $num2)
prod=$(expr $num1 \* $num2)
div=$(expr $num1 / $num2)
mod=$(expr $num1 % $num2)
echo "Sum = $sum"
echo "Difference = $diff"
echo "Multiplication = $prod"
echo "Division = $div"
echo "Modulus = $mod"
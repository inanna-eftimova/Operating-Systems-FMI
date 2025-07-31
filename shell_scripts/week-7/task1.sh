#!/bin/bash

read -p "Enter first number: " a
read -p "Enter second number: " b

sum=$((a + b))
product=$((a * b))

echo "Sum: $sum"
echo "Product: $product"

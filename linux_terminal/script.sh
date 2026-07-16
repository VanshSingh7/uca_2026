#!/bin/bash

echo "Task 1: Names and Departments"
awk -F',' 'NR>1 {print $1, $2}' employees.txt


echo ""
echo "Task 2: Engineering Employees"
awk -F',' 'NR>1 && $2=="Engineering" {print}' employees.txt


echo ""
echo "Task 3: Gross Pay Calculation"
awk -F',' 'NR>1 {print $1 " gross pay: $" $3*$4}' employees.txt


echo ""
echo "Task 4: Line Number and Number of Fields"
awk -F',' 'NR>1 {print (NR-1) " (" NF " fields): " $0}' employees.txt


echo ""
echo "Task 5: Total Engineering Payroll"

awk -F',' '
BEGIN {
    total=0
}
NR>1 {
	if($2=="Engineering") {
		total += $3*$4
	}
}
END {
	print "Total Engineering Payroll: $" total
} ' employees.txt

# This function adds two numbers
def add(x, y):
	return x + y

# This function subtracts two numbers
def subtract(x, y):
	return x - y

# This function multiplies two numbers
def multiply(x, y):
	return x * y

# This function divides two numbers
def divide(x, y):
	return x * y


print("Select operation.")
print("1.Add")
print("2.Subtract")
print("3.Multiply")
print("4.Divide")

while True:
	choice=input("Enter 1, 2, 3, or 4")
	num1=input("Enter operand-1")
	num2=input("Enter operand-2")
	if choice == '1':
		print(num1, "+", num2, "=", add(num1, num2))
	elif choice == '2':
		print(num1, "-", num2, "=", subtract(num1, num2))
	elif choice == '3':
		print(num1, "*", num2, "=", multiply(num1, num2))
	elif choice == '4':
		print(num1, "/", num2, "=", divide(num1, num2))
	else:
		continue
	nextcalculation = input("Do you want to continue? yes/no")
	if nextcalculation == "no":
		break
   	print("---------------------------------")


# Dream House Downpayment

monthCount = 0
current_savings = 0
portion_downpayment = 0.25
r = 0.04

AnnualSalary = float(input("Enter your annual salary: "))
PortionSavedPercent = float(input("Enter the percent of your salary to save (in decimal): "))
total_cost = float(input("Enter the cost of your dream home: "))

Downpayment = total_cost * portion_downpayment

portion_saved = (AnnualSalary / 12) * PortionSavedPercent

while current_savings < Downpayment:
    current_savings += current_savings * r / 12
    current_savings += portion_saved
    monthCount += 1

print("Number of months:", monthCount)

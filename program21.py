def numeric_to_letter_grade(numeric_grade):
    if numeric_grade >= 90.0:
        return 'A'
    elif numeric_grade >= 80.0:
        return 'B'
    elif numeric_grade >= 70.0:
        return 'C'
    elif numeric_grade >= 60.0:
        return 'D'
    else: 
        return 'F'
    
def main():
    total = 0.0
    counter = 0
    highest = 0.0
    lowest = 100.0
    passing = 0
    fail = 0
    letter_grade = 0.0

    while letter_grade != -1.0:
        letter_grade = float(input("Enter grade (-1 to end): "))
    
        if letter_grade == -1.0:
            break
        
        total += letter_grade
        counter += 1
    
        if letter_grade >= 75:
            passing += 1
            
        elif letter_grade <= 74:
            fail += 1
            
        if letter_grade > highest:
            highest = letter_grade 
       
        if letter_grade < lowest:
            lowest = letter_grade 
    
        letter_grade = numeric_to_letter_grade
       
    
    if counter > 0: 
       average = total / counter
       print(f"Class average is {average:.2f}")
       print(f"Number that have passed: {passing}")
       print(f"Number that have failed: {fail}")
       print(f"The lowest grade is: {lowest:.2f}")
       print(f"The highest grade is: {highest:.2f}")
    else:
        print("No grades were entered.")

if __name__ == "__main__":
    main()
        
    

        
    

    
    
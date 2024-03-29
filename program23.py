import re

def is_palindrome(string):
    clean_string = ''.join(e.lower() for e in string if e.isalnum())
    return clean_string == clean_string[::-1]


String = [
    "kayak",
    "deified",
    "rotator",
    "repaper",
    "deed",
    "peep",
    "wow",
    "noon",
    "civic",
    "racecar",
    "level",
    "mom",
    "bird rib",
    "taco cat",
    "UFO tofu",
    "Borrow or rob?",
    "Never odd or even.",
    "We panic in a pew.",
    "Won't lovers revolt now?",
    "Ma is a nun, as I am.",
    "Don't nod.",
    "Sir, I demand, I am a maid named Iris.",
    "Was it a car or a cat I saw?",
    "Yo, Banana Boy!",
    "Eva, can I see bees in a cave?",
    "Madam, in Eden, I'm Adam.",
    "A man, a plan, a canal, Panama!",
    "Never a foot too far, even.",
    "Red roses run no risk, sir, on Nurse's order.",
    "He lived as a devil, eh?",
    "Ned, I am a maiden.",
    "Now, sir, a war is won!",
    "Evade me, Dave!",
    "Dennis and Edna sinned.",
    "Step on no pets!"
]

for word in String:
    result = is_palindrome(word)
    if result:
        print(f'"{word}" is a palindrome.')
    else:
        print(f'"{word}" is not a palindrome.')
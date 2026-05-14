print("-----Hospital expert system------")
name = input("Enter patient name.")
score = 0
print("Answer all questions in yes / No")

questions = [
     ("Do you have fever? ", 2),
    ("Do you have cough? ", 2),
    ("Do you have chest pain? ", 3),
    ("Do you feel tired frequently? ", 1),
    ("Do you have breathing difficulty? ", 3),
    ("Do you have headache? ", 1),
    ("Do you have vomiting? ", 2),
    ("Do you have body pain? ", 1),
    ("Do you have sore throat? ", 1),
    ("Do you have dizziness? ", 2),
    ("Do you have stomach pain? ", 2),
    ("Do you have high blood pressure? ", 3),
    ("Do you have diabetes? ", 3),
    ("Do you have loss of appetite? ", 1),
    ("Do you have skin allergy/rashes? ", 2)   
]

for q,marks in questions:
    ans = input(q)
    if ans.lower() == 'yes':
        score += marks
    
maxscore = sum(marks for q,marks in questions)
percentage = (score/maxscore )*100
print("-------meidcal report ---------")
print("pateinet name: " , name)
print("total score : " , score)
print("percentage " , percentage , " %" )
if percentage >= 75:
    print("Condition : critical")
    print("advice: Immediate hospitalization required. ")
elif percentage >=50 :
    print("condition: Serious")
    print("advice  : consult a doctor")
elif percentage > 30 :
    print("conditoion : modeerae")
    print("advice: have regular checkout")
else:
    print("\nCondition : NORMAL")
    print("Advice    : Maintain healthy lifestyle and rest.")

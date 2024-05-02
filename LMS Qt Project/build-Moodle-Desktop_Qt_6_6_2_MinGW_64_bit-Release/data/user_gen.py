import csv

# Open the students file
with open('2022-2023-CM102-22APCS-Students.csv', 'r') as students_file:
    students_reader = csv.reader(students_file)
    next(students_reader)  # Skip the header row

    # Open the users file in append mode
    with open('users.csv', 'a', newline='') as users_file:
        users_writer = csv.writer(users_file)

        # For each student, append a new user to the users file
        for row in students_reader:
            student_id = row[0]
            users_writer.writerow([student_id, 'password', 'student'])
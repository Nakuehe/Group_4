import pandas as pd
import numpy as np

# Load the CSV file
students_df = pd.read_csv('2022-2023-22APCS-All-Students.csv')

# Combine FirstName and LastName to create FullName
students_df['FullName'] = students_df['FirstName'] + ' ' + students_df['LastName']

# Define the data
data = {
    'StudentID': students_df['StudentID'].tolist(),
    'FullName': students_df['FullName'].tolist(),
    'Midterm': np.random.choice(np.arange(5, 10.25, 0.25), len(students_df)),
    'Final': np.random.choice(np.arange(5, 10.25, 0.25), len(students_df)),
    'Other': np.random.choice(np.arange(5, 10.25, 0.25), len(students_df))
}

# Create DataFrame
df = pd.DataFrame(data)

# Calculate total score
df['Total'] = df['Midterm']*0.25 + df['Final']*0.4 + df['Other']*0.35

# Ensure the average total mark is higher than 6.5
while df['Total'].mean() < 6.5:
    df['Other'] = np.random.choice(np.arange(5, 10.25, 0.25), len(students_df))
    df['Total'] = df['Midterm']*0.25 + df['Final']*0.4 + df['Other']*0.35

# Save DataFrame to CSV file
# df.to_csv('2022-2023-CS161-22APCS01-Scoreboard.csv', index=False)
df[['StudentID', 'FullName', 'Midterm', 'Final', 'Other']].to_csv('2022-2023-22APCS-All-Students-Scoreboard.csv', index=False)

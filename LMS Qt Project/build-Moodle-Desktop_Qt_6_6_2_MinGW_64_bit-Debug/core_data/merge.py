import pandas as pd

# Read the CSV data into pandas DataFrames
df1 = pd.read_csv('2022-2023-22APCS01-Students.csv')
df2 = pd.read_csv('2022-2023-22APCS02-Students.csv')
df3 = pd.read_csv('2022-2023-22CLC03-Students.csv')

# Concatenate the three DataFrames along the row axis
df = pd.concat([df1, df2, df3])

# Sort the DataFrame by 'StudentID' in ascending order
df = df.sort_values('StudentID')

# Write the DataFrame back to a new CSV file
df.to_csv('2022-2023-22APCS-All-Students.csv', index=False)
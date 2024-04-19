import pandas as pd
import numpy as np

# Read the CSV data into a pandas DataFrame
df = pd.read_csv('2022-2023-22APCS-All-Students.csv')

# Generate 'SocialID' based on the 'Gender' column, replacing 'xxx' with a random number
df['SocialID'] = np.where(df['Gender'] == 'Male',
                          '0' + pd.Series(np.random.randint(10,99,size=len(df))).astype(str) + '206' + df['StudentID'].astype(str).str[-6:],
                          '0' + pd.Series(np.random.randint(10,99,size=len(df))).astype(str) + '106' + df['StudentID'].astype(str).str[-6:])

# Write the DataFrame back to the CSV file
df.to_csv('2022-2023-22APCS-All-Students.csv', index=False)
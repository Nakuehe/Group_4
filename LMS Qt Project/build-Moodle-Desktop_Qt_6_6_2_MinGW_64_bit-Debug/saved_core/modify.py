import pandas as pd

# Load the data
data = pd.read_csv('2022-2023-22APCS02-Students.csv')

# Change the prefix of 'StudentID' from 2312 to 2212
# data['StudentID'] = data['StudentID'].apply(lambda x: int(str(x).replace('2312', '2212')))

# Add a "0" in front of every 'SocialID' item
data['SocialID'] = '0' + data['SocialID'].astype(str)

# Save the data
data.to_csv('2022-2023-22APCS02-Students.csv', index=False)
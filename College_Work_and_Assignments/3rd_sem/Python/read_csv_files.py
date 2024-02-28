import pandas as pd
from itertools import combinations

# Read the Homo sapiens Excel file
data = pd.read_csv('C:\Users\aashiq\Desktop\hs.csv')  
# Replace 'Homo_sapience.xlsx' with your actual file name

# Filter to get only rows with three accession codes
filtered_data = data[data['Accession Code(s)'] == 3]

# Extract relevant columns: Entry ID and Accession Codes
filtered_data = filtered_data[['Entry ID', 'Accession Code(s)']]

# Write Entry IDs with organism and accession codes in a new CSV file
filtered_data.to_csv('filtered_data.csv', index=False)  # Change 'filtered_data.csv' to your preferred file name

# Generate combinations of two for each Entry ID
combinations_dict = {}
for index, row in filtered_data.iterrows():
    entry_id = row['Entry_ID']
    codes = row['Accession Code(s)'].split(', ')
    code_combinations = list(combinations(codes, 2))
    combinations_dict[entry_id] = code_combinations

# Store combinations for each Entry ID
with open('accession_code_combinations.csv', 'w') as file:
    file.write("Entry_ID,Accession_Code_Combinations\n")
    for entry_id, codes in combinations_dict.items():
        file.write(f"{entry_id},{codes}\n")
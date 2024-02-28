#download pandas in your system to use pandas functionality run these following commands
import pandas as pd

#... creat a csv file to store some values
ar = pd.read_csv("/home/student/Desktop/AASHIQ/test.csv")

#1..TO PRINT THE first 5 data rows '
print(ar.head())

#2..TO PRINT THE last 5 data rows '
print(ar.tail())

#3..TO PRINT TYPE OF DATA'
print(type(ar))

#4..TO PRINT SIZE OF DATA MATRICS'
print(ar.shape)

#5..ERROR IN SYNTAX
#print(ar.shape())

#6..get column names
print(ar.columns)

#7..the type of the column names
print(ar.dtypes)

#8..the INFO of the column
print(ar.info())

#9..TO PRINT SPECIFIC COLUMN
#just get the roll column and save it to its own variable
roll_ar = ar["ROLL"]
#show the first 5 observations
print(roll_ar.head())

#10..show the last 5 observations
print(roll_ar.tail())

#11..When subsetting a single column, you can use dot #notation and call the column
#name attribute directly.
g_ar_dot = ar.GAME
print(g_ar_dot.head())


#12.. Looking at specific only name and game
subset = ar[["NAME" , "GAME"]]
#first 5
print(subset.head())
#last 5
print(subset.tail())

#13.. get the first column (index 0) and last column
subset_of_ar = ar[[0, 1]]
print(subset_of_ar.head())






module Ch03MyNot where
myNot True = False
myNot False = True

-- adding a sumlist function below
sumList (x:xs) = x + sumList xs
sumList [] = 0

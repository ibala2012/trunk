module Ch03excercise where
-- Problem 1 compute length of a list
-- Problem 2 specify type signature of the function
altLength ::Num a => [t] -> a
altLength (_:xs) = 1 + altLength xs
altLength [] = 0

-- Problem 3 compute mean of a list
sumList ::Num b =>[b] -> b
sumList (a:xs) = a + sumList xs
sumList [] = 0

mean :: Fractional t => [t] -> t
mean xs = (sumList xs)/(altLength xs)

-- Problem 4 turn list into a palindrome
reverseList ::[t] -> [t]
reverseList [] =[]
reverseList xs = [last xs] ++ reverseList (take ((altLength xs)-1) xs)
palindromeList xs = xs ++ reverseList xs

-- Problem 5 check if a list is a palindrome
ispalindrome :: Eq t => [t] -> Bool
ispalindrome [] =True
ispalindrome (x:xs)
   | length xs == 0 = True
   | x==last xs = ispalindrome (take ((altLength xs)-1) xs)
   | otherwise =False

-- Problem 6 sort list of lists based on length of each sublist
merge [] xs = xs
merge xs [] = xs
merge (x:xs) (y:ys)
 | (length x < length y) = x:merge xs (y:ys)
 | otherwise = y:merge (x:xs) ys
sort xs
  | (length xs)> 1 = merge (take n xs) (drop n xs)
  | (length xs)==1 =xs
  | (length xs)==0 = []
    where n = div (length (xs)) 2

-- Problem 7
intersperse _ []=""
intersperse c (x:xs)
  | length(xs)>0 = x ++ "," ++ (intersperse c xs)
  | length(xs)==0 = "" ++ x


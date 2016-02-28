module Test where
myDrop :: (Num a, Ord a) => a-> [a1] -> [a1]
myDrop n xs = if n <= 0 || null xs
              then xs
              else myDrop (n - 1) (tail xs)

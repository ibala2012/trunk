module Ch03Tree where
data Tree a = Node a (Tree a) (Tree a)
            | Empty
  deriving (Show)

data AltTree a = AltNode a (Maybe (AltTree a)) (Maybe (AltTree a)) deriving (Show)

mySecond (_:y:_) = Just y
mySecond _ = Nothing


lend amount balance =
    let reserve = 100
        newBalance = balance - amount
    in if newBalance < reserve
           then Nothing
           else Just newBalance

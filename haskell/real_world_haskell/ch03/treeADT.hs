module Ch03Tree where
data Tree a = Node a (Tree a) (Tree a)
            | Empty
  deriving (Show)

data AltTree a = AltNode a (Maybe (AltTree a)) (Maybe (AltTree a)) deriving (Show)

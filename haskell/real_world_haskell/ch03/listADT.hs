module Ch03ListADT where
data List a = Cons a (List a)
            | Nil
  deriving (Show)

fromList (x:xs) = Cons x (fromList xs)
fromList [] = Nil

fromCons (Cons a xs)=a:(fromCons xs)
fromCons Nil = []

-- Defined module name to avoid IO main warning
module BookStoreProg where

{-
  Defining the datatype for BookInfo with type constructor as BookInfo and
  and Book as value constructor
-}
data BookInfo = Book Int String [String]
  deriving (Show)

-- Defining constructor for MagazineInfo
data MagazineInfo = Magazine Int String [String]
  deriving (Show)

-- creating myInfo object for testing

myInfo :: BookInfo
myInfo = Book 1 "Writing a python program" ["Balaji", "iyer"]
-- Added aliases for customerid and reviewbody
type CustomerID = Int

type ReviewBody = String

-- Bookreview datatype is defined below
data BookReview = BookReview BookInfo CustomerID String
 deriving (Show)

-- Defining Review data for the books used
data BetterReview = BetterReview BookInfo CustomerID ReviewBody
 deriving (Show)

-- Specifying the alias for Bookrecords
type BookRecord = (BookInfo, BetterReview)

-- Defining Data for BillingInfo
type CardNumber = Int
type CardHolder = String
type CardAddress =[String]
data BillingInfo = CreditCard CardNumber CardHolder CardAddress
                 | CashOnDelivery
                 | Invoice CustomerID
  deriving (Show)

bookID (Book id title author) = id
bookTitle (Book id title author) = title
bookAuthor (Book id title author) = author
nicerID (Book id _ _) = id
nicerTitle (Book _ title _) = title
nicerAuthor (Book _ _ author) = author

-- defining a data type with getters and setters in haskell is as given below
data Customer = Customer {
  customerID :: CustomerID,
  customerName :: String,
  customerAddress :: [String] 
} deriving (Show)

customer1 = Customer 1 "Balaji Iyer" ["300 North Essex Avenue", "Apt #309A", "Narberth", "PA 19072"]
customer2 = Customer {
customerID = 271828 , customerAddress = ["1048576 Disk Drive","Milpitas, CA 95134","USA"] , customerName = "Jane Q. Citizen"
}

import Data.List
import System.IO

go :: [Int] -> String
go (x:xs)
    | x > maximum xs = "YES"
    | otherwise = "NO"

main = do
    interact $ go . tail . map read . lines

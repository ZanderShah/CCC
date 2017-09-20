import Data.List
import System.IO

go :: String -> String
go x
    | "BFTLC" \\ x == [] = "NO MISSING PARTS"
    | otherwise = "BFTLC" \\ x

main = do
    interact go

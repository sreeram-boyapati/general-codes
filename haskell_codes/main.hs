main =  do
    factorial :: Int -> Int
    factorial n
        | n > 0 = n * factorial(n-1)
        | otherwise = 1

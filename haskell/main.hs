x :: Int
x = 3

factorial :: Int -> Int
factorial n
    | n <= 0 = 1
    | otherwise = n*factorial (n-1)


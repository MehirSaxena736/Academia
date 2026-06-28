
a <- as.numeric(readline("Enter the first number: "))
b <- as.numeric(readline("Enter the second number: "))
c <- as.numeric(readline("Enter the third number: "))

greatest <- a 

if (b > greatest) {
  greatest <- b
}
if (c > greatest) {
  greatest <- c
}

cat("The greatest number is:", greatest, "\n")
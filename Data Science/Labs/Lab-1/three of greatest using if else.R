# Using if-else
a <- as.numeric(readline("Enter the first number: "))
b <- as.numeric(readline("Enter the second number: "))
c <- as.numeric(readline("Enter the third number: "))

if (a > b) {
  if (a > c) {
    greatest <- a
  } else {
    greatest <- c
  }
} else {
  if (b > c) {
    greatest <- b
  } else {
    greatest <- c
  }
}

cat("The greatest number is:", greatest, "\n")
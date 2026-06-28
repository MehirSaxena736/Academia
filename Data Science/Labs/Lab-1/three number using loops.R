
numbers <- numeric(3)  
for (i in 1:3) {
  numbers[i] <- as.numeric(readline(prompt = paste("Enter number", i, ": ")))
}

greatest <- numbers[1]  # Assume the first number is the greatest
for (num in numbers) {
  if (num > greatest) {
    greatest <- num 
  }
}

# Display the result
cat("The greatest number is:", greatest, "\n")


# Define a function to find the greatest number
find_greatest <- function(numbers) {
  greatest <- numbers[1]  
  for (num in numbers) {
    if (num > greatest) {
      greatest <- num 
    }
  }
  return(greatest)
}

input_numbers <- function(n) {
  numbers <- numeric(n)  
  for (i in 1:n) {
    numbers[i] <- as.numeric(readline(prompt = paste("Enter number", i, ": ")))
  }
  return(numbers)
}

# Main Program
numbers <- input_numbers(3) 
greatest <- find_greatest(numbers)  


cat("The greatest number is:", greatest, "\n")

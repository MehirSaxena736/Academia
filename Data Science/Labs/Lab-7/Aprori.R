# Simple Apriori Algorithm in R (No Built-in Functions)

# Sample Transaction Data (1 = present, 0 = absent)
data <- matrix(c(1, 1, 0, 1,
                 1, 0, 1, 1,
                 0, 1, 1, 0,
                 1, 1, 1, 1), 
               nrow=4, byrow=TRUE)

colnames(data) <- c("Milk", "Bread", "Butter", "Jam")

# Function to count support
count_support <- function(item, transactions) {
  count <- 0
  for (i in 1:nrow(transactions)) {
    if (all(transactions[i, item] == 1)) {
      count <- count + 1
    }
  }
  return(count / nrow(transactions)) # Support value
}

# Find frequent items
find_frequent_items <- function(transactions, min_support) {
  items <- colnames(transactions)
  frequent_items <- list()
  
  for (item in items) {
    support <- count_support(item, transactions)
    if (support >= min_support) {
      frequent_items <- append(frequent_items, list(item))
    }
  }
  return(frequent_items)
}

# Function to compute confidence
compute_confidence <- function(transactions, min_confidence) {
  items <- colnames(transactions)
  rules <- list()
  
  for (i in 1:length(items)) {
    for (j in 1:length(items)) {
      if (i != j) { # Ensure X and Y are different
        support_x <- count_support(items[i], transactions)
        support_xy <- count_support(c(items[i], items[j]), transactions)
        confidence <- support_xy / support_x
        
        if (confidence >= min_confidence) {
          rules <- append(rules, list(paste(items[i], "=>", items[j], "Confidence:", round(confidence * 100, 2), "%")))
        }
      }
    }
  }
  return(rules)
}

# Run simple Apriori Algorithm
apriori_simple <- function(transactions, min_support, min_confidence) {
  frequent_items <- find_frequent_items(transactions, min_support)
  print("Frequent Items:")
  print(frequent_items)
  
  confidence_rules <- compute_confidence(transactions, min_confidence)
  print("\nAssociation Rules with Confidence:")
  print(confidence_rules)
}

# Run the algorithm with min support 0.5 and min confidence 0.6
apriori_simple(data, min_support = 0.5, min_confidence = 0.6)

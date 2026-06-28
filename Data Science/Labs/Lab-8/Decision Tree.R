# Install required packages (if not already installed)
install.packages("rpart")
install.packages("rpart.plot")

# Load the libraries
library(rpart)
library(rpart.plot)

# Load dataset
data(iris)
head(iris)
# Split data into train and test
set.seed(123)
sample_index <- sample(1:nrow(iris), 0.7 * nrow(iris))
train_data <- iris[sample_index, ]
test_data  <- iris[-sample_index, ]

# Train decision tree 
tree_model <- rpart(Species ~ ., data = train_data, method = "class")
  
# Plot the tree
rpart.plot(tree_model, type = 3, extra = 101, fallen.leaves = TRUE)
rpart.plot(tree_model)
      # Predict on test data
predictions <- predict(tree_model, test_data, type = "class")

# Confusion matrix
conf_matrix <- table(Predicted = predictions, Actual = test_data$Species)
print(conf_matrix)

# Accuracy
accuracy <- sum(diag(conf_matrix)) / sum(conf_matrix)
print(paste("Accuracy:", round(accuracy * 100, 2), "%"))



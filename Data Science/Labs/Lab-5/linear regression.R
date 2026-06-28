library(ggplot2)

head(data)data <- read.csv("C:\\Users\\8HIN\\Documents\\Salary_Data.csv")
summary(data)
# Load necessary library for data partitioning
library(caret)

str(data)

# Split the data into 80% training and 20% testing sets
set.seed(42)
trainIndex <- createDataPartition(data$Salary, p = 0.8, list = FALSE)
trainData <- data[trainIndex, ]
testData <- data[-trainIndex, ]

# Train the Linear Regression model
model <- lm(Salary ~ YearsExperience, data = trainData)

# View the model summary
summary(model)

# Make predictions on the test set
predictions <- predict(model, newdata = testData)

# Evaluate performance (MSE and R-squared)
mse <- mean((testData$Salary - predictions)^2)
r2 <- summary(model)$r.squared

cat("Mean Squared Error:", mse, "\n")
cat("R-squared:", r2, "\n")

# Visualize actual vs predicted salary values
ggplot() +
  geom_point(aes(x = testData$YearsExperience, y = testData$Salary), color = "blue") +
  geom_line(aes(x = testData$YearsExperience, y = predictions), color = "red", size = 1) +
  labs(title = "Simple Linear Regression - Salary Prediction",
       x = "Years of Experience",
       y = "Salary") +
  theme_minimal()
data("Salaries")
data

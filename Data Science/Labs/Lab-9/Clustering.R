# Load necessary libraries
library(ggplot2)
library(datasets)

# Load the iris dataset
data(iris)

# Check the first few rows
head(iris)
# Remove the Species column
iris_data <- iris[, -5]

# Scale the data (optional but recommended)
iris_scaled <- scale(iris_data)
# Set the number of clusters (K)
set.seed(123)  # Ensuring reproducibility
kmeans_result <- kmeans(iris_scaled, centers = 3, nstart = 25)

# Print cluster assignments
print(kmeans_result$cluster)
# Add cluster labels to the dataset
iris$Cluster <- as.factor(kmeans_result$cluster)

# Plot clustering results using Sepal.Length and Sepal.Width
ggplot(iris, aes(x = Sepal.Length, y = Sepal.Width, color = Cluster)) +
  geom_point(size = 3) +
  ggtitle("K-Means Clustering of Iris Dataset") +
  theme_minimal()
# Check the cluster centroids
print(kmeans_result$centers)

# Calculate within-cluster sum of squares
print(kmeans_result$tot.withinss)

# Use Elbow Method to determine the best number of clusters
wss <- sapply(1:10, function(k) {
  kmeans(iris_scaled, centers = k, nstart = 25)$tot.withinss
})

plot(1:10, wss, type = "b", pch = 19, frame = FALSE,
     xlab = "Number of clusters (K)",
     ylab = "Total Within Sum of Squares",
     main = "Elbow Method for Optimal K")


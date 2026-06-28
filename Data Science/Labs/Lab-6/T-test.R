
# Step 1: Load Required Libraries

if (!require(car)) install.packages("car", dependencies = TRUE)
if (!require(dplyr)) install.packages("dplyr", dependencies = TRUE)
if (!require(ggplot2)) install.packages("ggplot2", dependencies = TRUE)

library(car)
library(dplyr)
library(ggplot2)


# Step 2: Load the Iris Dataset

data("iris")

# Display dataset structure
print(str(iris))
print(head(iris))


# Step 3: Filter Data (Setosa vs. Versicolor)

iris_filtered <- iris %>% filter(Species %in% c("setosa", "versicolor"))

# Convert Species to Factor
iris_filtered$Species <- as.factor(iris_filtered$Species)

# Separate Sepal.Length for Setosa and Versicolor
setosa_sepal <- iris_filtered$Sepal.Length[iris_filtered$Species == "setosa"]
versicolor_sepal <- iris_filtered$Sepal.Length[iris_filtered$Species == "versicolor"]


# Step 4: Check Normality (Shapiro-Wilk Test)

shapiro_test_setosa <- shapiro.test(setosa_sepal)
shapiro_test_versicolor <- shapiro.test(versicolor_sepal)

print(shapiro_test_setosa)
print(shapiro_test_versicolor)


# Step 5: Check Variance Equality (Levene’s Test)

levene_test <- leveneTest(Sepal.Length ~ Species, data = iris_filtered)
print(levene_test)


# Step 6: Perform Independent t-Test

t_test_result <- t.test(setosa_sepal, versicolor_sepal, var.equal = FALSE)

# Print the t-test result
print(t_test_result)


# Step 7: Interpretation

if (t_test_result$p.value < 0.05) {
  cat("\nResult: Significant difference in Sepal Length between Setosa and Versicolor.\n")
} else {
  cat("\nResult: No significant difference in Sepal Length between Setosa and Versicolor.\n")
}


# Step 8: Visualizing the Data

ggplot(iris_filtered, aes(x = Species, y = Sepal.Length, fill = Species)) +
  geom_boxplot() +
  theme_minimal() +
  ggtitle("Comparison of Sepal Length in Setosa and Versicolor")


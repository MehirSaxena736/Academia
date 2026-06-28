install.packages(c("ggplot2", "dplyr", "corrplot", "GGally"))
library(ggplot2)
library(dplyr)
library(corrplot)
library(GGally)
# Load dataset
diabetes <- read.csv("https://raw.githubusercontent.com/jbrownlee/Datasets/master/pima-indians-diabetes.data.csv", header=FALSE)

# Assign column names
colnames(diabetes) <- c("Pregnancies", "Glucose", "BloodPressure", "SkinThickness", "Insulin", 
                        "BMI", "DiabetesPedigreeFunction", "Age", "Outcome")

# View first few rows
head(diabetes)
data("PimaIndiansDiabetes")
colnames(PimaIndiansDiabetes)
# univariate analysis
summary(PimaIndiansDiabetes)
# Loop through all numeric attributes and create histograms
for (col in colnames(diabetes)[1:8]) {
  print(
    ggplot(diabetes, aes_string(x=col)) + 
      geom_histogram(binwidth=10, fill="blue", color="black", alpha=0.7) +
      labs(title=paste("Histogram of", col), x=col, y="Count")
  )
}
# Loop through all numeric attributes and create boxplots
for (col in colnames(diabetes)[1:8]) {
  print(
    ggplot(diabetes, aes_string(y=col)) + 
      geom_boxplot(fill="red", alpha=0.6) +
      labs(title=paste("Boxplot of", col))
  )
}
## bivariate analysis
# Loop through combinations of numerical attributes
num_cols <- colnames(diabetes)[1:8]
for (i in 1:length(num_cols)) {
  for (j in (i+1):length(num_cols)) {
    print(
      ggplot(diabetes, aes_string(x=num_cols[i], y=num_cols[j])) +
        geom_point(color="blue", alpha=0.5) +
        labs(title=paste("Scatter Plot of", num_cols[i], "vs", num_cols[j]), x=num_cols[i], y=num_cols[j])
    )
  }
}
for (col in colnames(diabetes)[1:8]) {
  print(
    ggplot(diabetes, aes_string(x="factor(Outcome)", y=col, fill="factor(Outcome)")) +
      geom_boxplot() +
      labs(title=paste(col, "by Diabetes Outcome"), x="Outcome", y=col)
  )
}
data(PimaIndiasdiabetes)





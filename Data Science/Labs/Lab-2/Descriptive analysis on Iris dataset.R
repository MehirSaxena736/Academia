data(iris)
head(iris)
str(iris)     
summary(iris)
ls()  
for (feature in colnames(iris)[-5]) { 
  hist(iris[[feature]],
       main = paste("Histogram of", feature),
       xlab = feature,
       col = "lightgreen",
       border = "black",
       breaks = 10)
}


pairs(iris[, 1:4],
     main = "Scatterplots for Iris Features",
     col = iris$Species,
      pch = 19)

get_mode <- function(x) {
  uniq_vals <- unique(x)
  uniq_vals[which.max(tabulate(match(x, uniq_vals)))]
}

# Perform descriptive analysis
for (feature in colnames(iris)[-5]) {  # Exclude 'Species'
  cat("\nFeature:", feature, "\n")
  cat("Mean:", mean(iris[[feature]]), "\n")
  cat("Median:", median(iris[[feature]]), "\n")
  cat("Mode:", get_mode(iris[[feature]]), "\n")
}


head(airquality)
mean(airquality$Solar.R)
mean(airquality$Ozone)
mean(airquality$Wind)
mean(airquality$Solar.R, na.rm = TRUE)
mean(airquality$Ozone, na.rm = TRUE)
summary(airquality)
boxplot(airquality)
New_df = airquality
New_df$Ozone = ifelse(is.na(New_df$Ozone), 
                      median(New_df$Ozone,
                             na.rm = TRUE),
                      New_df$Ozone)
summary(New_df)
New_df$Solar.R = ifelse(is.na(New_df$Solar.R),
                        median(New_df$Solar.R, 
                               na.rm = TRUE),
                        New_df$Solar.R)
summary(New_df) 
head(New_df)
boxplot(New_df)

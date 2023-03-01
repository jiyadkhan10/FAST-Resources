# Using BullRider dataset answer the following:
#Is there a linear relationship between how often a rider places in the Top 10 and how often he stays on his bull?

# Visualize and describe the ﬁrst variable of interest
hist(bull$RidePer)
fivenum(bull$RidePer)
mean(bull$RidePer)
sd(bull$RidePer)
# Visualize and describe the second variable of interest
hist(bull$Top10)
fivenum(bull$Top10)
mean(bull$Top10)
sd(bull$Top10)
# Create a scatterplot
plot(bull$RidePer,bull$Top10)
# Add line of best ﬁt
abline(lm(bull$Top10~bull$RidePer))
# Calculate the correlation coeﬃcient
cor(bull$RidePer,bull$Top10)
# Create a correlation matrix
vars <- c("Top10", "RidePer")
cor(bull[,vars])

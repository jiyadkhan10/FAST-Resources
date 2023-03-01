fivenum(film$Days)
boxplot(film$Days)
hist(film$Days)
boxplot(film$Days~film$Genre)
#check for assumptions
aggregate(Days~Genre, film, mean)
aggregate(Days~Genre, film, sd)
#anova
daysmodel = aov(film$Days~film$Genre)
summary(daysmodel)
#post hoc
TukeyHSD(daysmodel)

# Calculate avg IMDB score of each group
aggregate(IMDB~Rating,film,mean)

#Calculate sd of IMDB scores within each group
aggregate(IMDB~Rating,film,sd)

# Visualize the group means and variability
boxplot(film$IMDB~film$Rating, main= "IMDB Scores by Rating",
        ylab= "IMDB Score", xlab= "MPAA Rating")

# Run ANOVA
modelscore <- aov(film$IMDB~film$Rating)
summary(modelscore)

# Run post-hod text if F statistic is significant
TukeyHSD(modelscore)

#for PG and Cost
fivenum(film$Budget)
boxplot(film$Budget)
hist(film$Budget)
boxplot(film$Budget~film$Rating)
#check for assumptions
aggregate(Budget~Rating, film, mean)
aggregate(Budget~Rating, film, sd)
#anova
model = aov(film$Budget~film$Rating)
summary(model)
#post hod
TukeyHSD(model)
s
#Two way ANOVA test
model = aov(exercise$flex~exercise$Gender*exercise$Length)
summary(model)

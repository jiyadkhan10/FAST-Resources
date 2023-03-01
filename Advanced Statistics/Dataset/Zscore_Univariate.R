#Using animal data answer the following questions
#Compare the weight of adult cats and dogs at the shelter. How typical would it be to find a 13-pound cat? What about a
#13-pound dog?

#Analsis breakdown
#1. Create a table to show how many adult cats and dogs are in the dataset. An animal is considered an adult if it is at least one year of age.
#2. Make a histogram of weight for both adult dogs and cats.
#3. Calculate the appropriate measures of center and spread for each distribution.
#4. Find the z-score for a 13-pound cat.
#5. Find the quartile for a 13-pound dog.

#How many adult dogs are in the shelter?
adult_dog = animal[animal$Age.Intake >= 1 & animal$Animal.Type =='Dog',]
print(nrow(adult_dog))

#How many adult cats are in the shelter?
adult_cat = animal[animal$Age.Intake >= 1 & animal$Animal.Type =='Cat',]
print(nrow(adult_cat))

#What is the shape of the distribution of weight for adult dogs?
hist(adult_dog$Weight)
print("positively skewed")

#Which measure of center should be used to describe the average weight of the adult dogs?
print("median")

#What is the shape of the distribution of weight for adult cats?
hist(adult_cat$Weight)
print("approximately normal")

#Which measure of center should be used to describe the average weight of the adult cats?
print("Mean")

#Average adult cat weight in pounds (rounded to one decimal place)=
m_c = mean(adult_cat$Weight)

#What is the standard deviation for the weight of the adult cats?
s_c = sd(adult_cat$Weight)

#What is the z-score of a 13 pound adult cat? Round to one decimal point.
zcat_13 = (13-m_c)/s_c

#What proportion of adult cats weigh more than 13 pounds, according to your data?
1-pnorm(zcat_13)

#What quartile would contain a 13-pound adult dog?
fivenum(adult_dog$Weight)
print("first")

#What percentage of adult dogs in the shelter weigh more than 13 pounds?
print("approx. 75%")

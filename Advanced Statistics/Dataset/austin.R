table(acl$Grammy) -> gtab
gtab
prop.table(gtab)
gtab2 = table(acl$Grammy, acl$Gender)
gtab2
prop.table(gtab2, 1)
prop.table(gtab2, 2)

#grouped bar chat
barplot(gtab,main = "ACL Grammy winner", xlab = "Grammy Winnder", ylab = "Counts")
barplot(gtab2, legend=T)
barplot(gtab2, legend=T, beside = T)
barplot(prop.table(gtab2,2))

#chi square fitness of test
#claim is 1/3 of all the artists have won the grammy
claimp = c(2/3, 1/3) # order is important
chisq.test(gtab,p=claimp)
#test the assumption
chisq.test(gtab,p=claimp)$expected

#chi square of independence set
#distribution of grammy winners is same across all ages
grammyage = table(acl$Grammy, acl$Age.Group)
grammyage
chisq.test(grammyage)$expected # see we dont have p over here. we dont have any claim, we have met the expected 5 assumption
chisq.test(grammyage, correct = F) #failed to reject that these two variables are independent

library(ggplot2)
library(directlabels)
my_data <- read.csv(file.choose(), sep = '\t', header=FALSE)
names(my_data)
names(my_data) <- c("Time","Prey","Predator")

head(my_data)
ggplot(my_data, aes(x = Predator , y = Prey)) + geom_line() + ggtitle("Predator vs Prey")

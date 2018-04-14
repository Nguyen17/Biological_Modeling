mydata = read.table(file.choose())
colnames(mydata)<-c("Time(months)", "Population")

plot(mydata[,1:2], type="l",main="Lizard size vs Lizard temperature" 
     ,xlab="Lizard size",ylab =expression("Tb Body core temperature"), las=1)
axis(side=0.001, at=c(0:30))
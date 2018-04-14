mydata = read.table(file.choose())

colnames(mydata)<-c("Time(months)", "Model")

plot(mydata[,1:2], type="l",main="Prey Model" 
     ,xlab="Time(months)",ylab =expression("V"[t]), las=1, col="Red")
axis(side=1, at=c(0:10))






mydata = read.table(file.choose())
colnames(mydata)<-c("Time(months)", "Population")

plot(mydata[,1:2], type="l",main="Euler's Method and the Logistic Model: Step size 2.0" 
     ,xlab="Time(months)",ylab =expression("N"[t]), las=1)
axis(side=1, at=c(0:30))
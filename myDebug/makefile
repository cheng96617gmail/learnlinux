C_SRCS_HELLOWORLD += \
../src/HelloWorld.c 

C_SRCS_MYLS += \
../src/apue.c \
../src/myls.c 

C_SRCS_RWSYSIO += \
../src/apue.c \
../src/rwsysio.c

C_SRCS_RWSTDIO += \
../src/apue.c \
../src/rwstdio.c

OBJS_HELLOWORLD += \
./src/HelloWorld.o 

OBJS_MYLS += \
./src/apue.o \
./src/myls.o 

OBJS_RWSYSIO += \
./src/apue.o \
./src/rwsysio.o

OBJS_RWSTDIO += \
./src/apue.o \
./src/rwstdio.o

OBJS_MYPROC += \
./src/apue.o \
./src/myproc.o

OBJS_MYSIGN += \
./src/apue.o \
./src/mysign.o

OBJS_CONF += \
./src/apue.o \
./src/conf.o

OBJS_MYLSEEK += \
./src/myLseek.o

OBJS_HOLEWR += \
./src/apue.o \
./src/holewr.o

OBJS_FCNTLEX += \
./src/apue.o \
./src/fcntlex.o

OBJS_FILESTAT += \
./src/apue.o \
./src/filestat.o

OBJS_MYCHMOD += \
./src/apue.o \
./src/mychmod.o

OBJS_PRTENVIRON += \
./src/apue.o \
./src/prtenviron.o

OBJS_PRTLIMITS += \
./src/apue.o \
./src/prtlimits.o

OBJS_DAYTIMECLIENT +=\
./src/apue.o \
./src/daytimeclient.o

OBJS_DAYTIMESERV +=\
./src/apue.o \
./src/daytimeserv.o

all:helloworld myls rwsysio rwstdio myproc mysign conf mylseek holewr fcntlex \
filestat mychmod prtenviron prtlimits daytimeclient daytimeserv

helloworld:$(OBJS_HELLOWORLD)
	@echo 'Building target: $@'
	@echo 'Invoking: GCC C Linker'
	gcc  -o "helloworld" $(OBJS_HELLOWORLD)
	@echo 'Finished building target: $@'
	@echo ''
	
myls:$(OBJS_MYLS)
	@echo 'Building target: $@'
	@echo 'Invoking: GCC C Linker'
	gcc  -o "myls" $(OBJS_MYLS)
	@echo 'Finished building target: $@'
	@echo ' '

rwsysio:$(OBJS_RWSYSIO)
	@echo 'Building target: $@'
	@echo 'Invoking: GCC C Linker'
	gcc -o "rwsysio" $(OBJS_RWSYSIO)
	@echo 'Finished building target: $@'
	@echo ' '
	
rwstdio:$(OBJS_RWSTDIO)
	@echo 'Building target: $@'
	@echo 'Invoking: GCC C Linker'
	gcc -o "rwstdio" $(OBJS_RWSTDIO)
	@echo 'Finished building target:$@'
	@echo ' '
#rwstio.o:$(C_SRCS_RWSTDIO)
#	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"

myproc:$(OBJS_MYPROC)
	@echo 'Building target:$@'
	@echo 'Invoking: GCC C Linker'
	gcc -o "myproc" $(OBJS_MYPROC)
	@echo 'Finished building target:$@'
	@echo ' '	
	
mysign:$(OBJS_MYSIGN)
	@echo 'Building target:$@'
	@echo 'Invoking: GCC C Linker'
	gcc -o "mysign" $(OBJS_MYSIGN)
	@echo 'Finished building target:$@'
	@echo ' '
	
conf:$(OBJS_CONF)
	@echo 'Building target:$@'
	@echo 'Invoking: GCC C Linker'
	gcc -o "conf" $(OBJS_CONF)
	@echo 'Finished building target:$@'
	@echo ' '
	
mylseek:$(OBJS_MYLSEEK)
	@echo 'Building target:$@'
	@echo 'Invoking: GCC C Linker'
	gcc -o "mylseek" $(OBJS_MYLSEEK)
	@echo 'Finished building target:$@'
	@echo ' '

holewr:$(OBJS_HOLEWR)
	@echo 'Building target:$@'
	@echo 'Invoking: GCC C Linker'
	gcc -o "holewr" $(OBJS_HOLEWR)
	@echo 'Finished building target:$@'
	@echo ' '

fcntlex:$(OBJS_FCNTLEX)
	@echo 'Building target:$@'
	@echo 'Invoking: GCC C Linker'
	gcc -o "fcntlex" $(OBJS_FCNTLEX)
	@echo 'Finished building target:$@'
	@echo ' '

filestat:$(OBJS_FILESTAT)
	@echo 'Building target:$@'
	@echo 'Invoking: GCC C Linker'
	gcc -o "filestat" $(OBJS_FILESTAT)
	@echo 'Finished building target:$@'
	@echo ' '

mychmod:$(OBJS_MYCHMOD)
	@echo 'Building target:$@'
	@echo 'Invoking: GCC C Linker'
	gcc -o "mychmod" $(OBJS_MYCHMOD)
	@echo 'Finished building target:$@'
	@echo ' '

prtenviron:$(OBJS_PRTENVIRON)
	@echo 'Building target:$@'
	@echo 'Invoking: GCC C Linker'
	gcc -o "prtenviron" $(OBJS_PRTENVIRON)
	@echo 'Finished building target:$@'
	@echo ' '

prtlimits:$(OBJS_PRTLIMITS)
	@echo 'Building target:$@'
	@echo 'Invoking:GCC C Linker'
	gcc -o "prtlimits" $(OBJS_PRTLIMITS)
	@echo 'Finished building target:$@'
	@echo ' '

daytimeclient:$(OBJS_DAYTIMECLIENT)
	@echo 'Building target:$@'
	@echo 'Invoking GCC C Linker'
	gcc -o $@ $(OBJS_DAYTIMECLIENT)
	@echo 'Finished building target:$@'
	@echo ' '
	
daytimeserv:$(OBJS_DAYTIMESERV)
	@echo 'Building target:$@'
	@echo 'Invoking GCC C Linker'
	gcc -o $@ $(OBJS_DAYTIMESERV)
	@echo 'Finished building target:$@'
	@echo ' '
		
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '
	
.PHONY: all clean
clean:
	-rm helloworld myls $(OBJS_HELLOWORLD) $(OBJS_MYLS) $(daytimeclient)
 
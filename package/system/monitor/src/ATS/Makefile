SRCS := /home/ether/self-openwrt/package/system/monitor/include/systemshm.c ATS.c
OBJS := $(SRCS:.c=.o)
TARGET := ATS

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $(TARGET)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)

SRCS := /home/ether/self-openwrt/package/system/monitor/include/systemshm.c infra.c
OBJS := $(SRCS:.c=.o)
TARGET := infra

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $(TARGET)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)

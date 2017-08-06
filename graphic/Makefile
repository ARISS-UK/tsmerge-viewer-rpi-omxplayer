BIN = ariss-graphic
SRCS = main.c

CFLAGS = -O2 -Wall
LDFLAGS = -I/opt/vc/include -I/opt/vc/include/interface/vmcs_host/linux -I/opt/vc/include/interface/vcos/pthreads -lshapes

SERVICE = ariss_graphic

all:
	xxd -i ariss_logo.jpg > ariss_logo.h
	gcc $(CFLAGS) $(LDFLAGS) -o $(BIN) $(SRCS)

install:
	@cp -fv $(BIN) /usr/bin/$(BIN)
	@cp -fv $(SERVICE).service /etc/systemd/system/$(SERVICE).service
	@systemctl daemon-reload
	systemctl enable $(SERVICE)
	systemctl start $(SERVICE)



DEBGU_ON_PC :=0

CC_PC :=g++
DIR_PC:=/home/rainzsy/UserSoft/opencv-3.4.3/install_x64/

CC_ARM :=aarch64-himix100-linux-g++
DIR_ARM :=/home/rainzsy/UserSoft/opencv-3.4.3/install_arm64/

 
ifeq ($(DEBGU_ON_PC),1)
	CC  :=$(CC_PC)
	DIR :=$(DIR_PC)
else
    CC  :=$(CC_ARM)
	DIR :=$(DIR_ARM)
endif




TARGETS := main
Depend  := main.cpp 

LIBS = -lopencv_highgui \
-lopencv_imgproc \
-lopencv_core \
-lopencv_imgcodecs \
-lopencv_video \
-lopencv_objdetect \
-lopencv_imgcodecs
        
INCLUDE = -I$(DIR)/include/

LIB_TARGET_DIR = -L$(DIR)/lib \
-L/$(DIR)/share/OpenCV/3rdparty/lib

all:$(TARGETS)

$(TARGETS):$(Depend)
	$(CC)  $(CPPFLAGS) -o $@ $(INCLUDE) $^ $(LIB_TARGET_DIR) $(LIBS)

clean:
	rm -f *.o $(TARGETS)
 
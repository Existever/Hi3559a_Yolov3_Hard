# Hisilicon Hi35xx sample Makefile
include $(PWD)/../Makefile.param

CFLAGS += -I$(PWD)/sample
CFLAGS += -I$(PWD)/sample_nnie_software
CFLAGS += -O3
#添加对cpp文件的查找搜索
SRCS := $(wildcard *.c)
SRCS += $(wildcard *.cpp)
SRCS += $(wildcard ./sample/*.c)
SRCS += $(wildcard ./sample_nnie_software/*.c)
SRCS += $(wildcard $(PWD)/../common/*.c)
TARGET := sample_nnie_main

#添加opencv编译包含路径
DIR_ARM :=/home/rainzsy/UserSoft/opencv-3.4.3/install_arm64/
OPENCV_INCLUDE := -I$(DIR_ARM)/include
OPENCV_LIB_DIR := -L$(DIR_ARM)/lib
OPENCV_LIBS = -lopencv_highgui \
-lopencv_imgproc \
-lopencv_core \
-lopencv_imgcodecs \
-lopencv_video \
-lopencv_objdetect \
-lopencv_imgcodecs
         


# compile linux or HuaweiLite
include $(PWD)/../../../$(OSTYPE).mak

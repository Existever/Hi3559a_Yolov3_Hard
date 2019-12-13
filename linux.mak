
# target source
OBJS  := $(SRCS:%.c=%.o)
OBJS  := $(OBJS:%.cpp=%.o)
CXXFLAGS=$(CFLAGS)

.PHONY : clean all

all: $(TARGET)

$(TARGET):$(COMM_OBJ) $(OBJS)	
	@$(CXX) $(CFLAGS) -lpthread -lm -o $@ $^ $(MPI_LIBS) $(SENSOR_LIBS) $(AUDIO_LIBA) $(REL_LIB)/libsecurec.a $(OPENCV_INCLUDE) $(OPENCV_LIB_DIR) $(OPENCV_LIBS)

clean:
	@rm -f $(TARGET)
	@rm -f $(OBJS)
	@rm -f $(COMM_OBJ)

cleanstream:
	@rm -f *.h264
	@rm -f *.h265
	@rm -f *.jpg
	@rm -f *.mjp
	@rm -f *.mp4

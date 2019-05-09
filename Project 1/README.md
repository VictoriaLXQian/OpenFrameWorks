# Project 1_Narrative
## L'utimal Cantonne

[![Watch the video](https://img.youtube.com/vi/JfriBO2DjjM/maxresdefault.jpg)](
https://youtu.be/JfriBO2DjjM)

endif

# make sure the the OF_ROOT location is defined
ifndef OF_ROOT
	OF_ROOT=$(realpath ../../..)
endif

# call the project makefile!
include $(OF_ROOT)/libs/openFrameworksCompiled/project/makefileCommon/compile.project.mk

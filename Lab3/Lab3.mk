##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=Lab3
ConfigurationName      :=Debug
WorkspacePath          :=/u/b/kimkyu9/kimkyu/CodeLabs
ProjectPath            :=/u/b/kimkyu9/kimkyu/CodeLabs/Lab3
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=Kyu Bum  Kim
Date                   :=02/02/18
CodeLitePath           :=/u/b/kimkyu9/.codelite
LinkerName             :=gcc
SharedObjectLinkerName :=gcc -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.o.i
DebugSwitch            :=-g 
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputFile             :=$(IntermediateDirectory)/$(ProjectName)
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E 
ObjectsFileList        :="Lab3.txt"
PCHCompileFlags        :=
MakeDirCommand         :=mkdir -p
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). 
IncludePCH             := 
RcIncludePath          := 
Libs                   := 
ArLibs                 :=  
LibPath                := $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := ar rcus
CXX      := gcc
CC       := gcc
CXXFLAGS :=  -g -O0 -Wall $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := as


##
## User defined environment variables
##
CodeLiteDir:=/usr/share/codelite
Objects0=$(IntermediateDirectory)/Lab3Partx.c$(ObjectSuffix) $(IntermediateDirectory)/Lab3Part1.c$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d $(Objects) 
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

MakeIntermediateDirs:
	@test -d ./Debug || $(MakeDirCommand) ./Debug


$(IntermediateDirectory)/.d:
	@test -d ./Debug || $(MakeDirCommand) ./Debug

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/Lab3Partx.c$(ObjectSuffix): Lab3Partx.c $(IntermediateDirectory)/Lab3Partx.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/u/b/kimkyu9/kimkyu/CodeLabs/Lab3/Lab3Partx.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Lab3Partx.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Lab3Partx.c$(DependSuffix): Lab3Partx.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Lab3Partx.c$(ObjectSuffix) -MF$(IntermediateDirectory)/Lab3Partx.c$(DependSuffix) -MM Lab3Partx.c

$(IntermediateDirectory)/Lab3Partx.c$(PreprocessSuffix): Lab3Partx.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Lab3Partx.c$(PreprocessSuffix) Lab3Partx.c

$(IntermediateDirectory)/Lab3Part1.c$(ObjectSuffix): Lab3Part1.c $(IntermediateDirectory)/Lab3Part1.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/u/b/kimkyu9/kimkyu/CodeLabs/Lab3/Lab3Part1.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Lab3Part1.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Lab3Part1.c$(DependSuffix): Lab3Part1.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Lab3Part1.c$(ObjectSuffix) -MF$(IntermediateDirectory)/Lab3Part1.c$(DependSuffix) -MM Lab3Part1.c

$(IntermediateDirectory)/Lab3Part1.c$(PreprocessSuffix): Lab3Part1.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Lab3Part1.c$(PreprocessSuffix) Lab3Part1.c


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Debug/



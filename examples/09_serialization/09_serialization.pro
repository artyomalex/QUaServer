QT += core xml sql
QT -= gui

CONFIG += c++17

TARGET = 09_serialization
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app


INCLUDEPATH += $$PWD/

INCLUDEPATH += c:/dev/cling-build/tools/cling/tools/demo/

INCLUDEPATH += c:/dev/cling/tools/demo/

INCLUDEPATH += c:/dev/cling/include/

INCLUDEPATH += c:/dev/cling-build/tools/cling/include/

INCLUDEPATH += c:/dev/cling-build/tools/clang/include/

INCLUDEPATH += c:/dev/cling_src/include

INCLUDEPATH += c:/dev/cling-build/include

LIBS += -Lc:/dev/cling-build/lib/
#LIBS += "C:/dev/cling-build/install/bin/libcling.dll"
#LIBS += -ldl
#QMAKE_LFLAGS  += c:/dev/cling-build/bin/libcling.dll
QMAKE_LFLAGS  += c:/dev/cling-build/lib/clingInterpreter.lib
QMAKE_LFLAGS  += c:/dev/cling-build/lib/clingUtils.lib
#QMAKE_LFLAGS  +=-ldl
#QMAKE_LFLAGS  +=-v
QMAKE_LFLAGS  +=Version.lib
QMAKE_LFLAGS  += c:/dev/cling-build/lib/clangCodeGen.lib
QMAKE_LFLAGS  += c:/dev/cling-build/lib/clangRewriteFrontend.lib
QMAKE_LFLAGS  += c:/dev/cling-build/lib/clangFrontend.lib
QMAKE_LFLAGS  += c:/dev/cling-build/lib/clangDriver.lib
QMAKE_LFLAGS  += c:/dev/cling-build/lib/clangParse.lib
QMAKE_LFLAGS  += c:/dev/cling-build/lib/clangRewrite.lib
QMAKE_LFLAGS  += c:/dev/cling-build/lib/clangSerialization.lib
QMAKE_LFLAGS  += c:/dev/cling-build/lib/clangSema.lib
QMAKE_LFLAGS  += c:/dev/cling-build/lib/clangAnalysis.lib
QMAKE_LFLAGS  += c:/dev/cling-build/lib/clangASTMatchers.lib
QMAKE_LFLAGS  += c:/dev/cling-build/lib/clangEdit.lib
QMAKE_LFLAGS  += c:/dev/cling-build/lib/LLVMFrontendHLSL.lib
QMAKE_LFLAGS  += c:/dev/cling-build/lib/clangSupport.lib
QMAKE_LFLAGS  += c:/dev/cling-build/lib/clangAST.lib
QMAKE_LFLAGS  += c:/dev/cling-build/lib/clangLex.lib
QMAKE_LFLAGS  += c:/dev/cling-build/lib/clangBasic.lib
QMAKE_LFLAGS  += c:/dev/cling-build/lib/LLVMCoverage.lib
QMAKE_LFLAGS  += c:/dev/cling-build/lib/LLVMLTO.lib
QMAKE_LFLAGS  += c:/dev/cling-build/lib/LLVMExtensions.lib
QMAKE_LFLAGS  += c:/dev/cling-build/lib/LLVMOrcJIT.lib
QMAKE_LFLAGS  += c:/dev/cling-build/lib/LLVMExecutionEngine.lib
QMAKE_LFLAGS  += c:/dev/cling-build/lib/LLVMJITLink.lib
QMAKE_LFLAGS  += c:/dev/cling-build/lib/LLVMWindowsDriver.lib
QMAKE_LFLAGS  += c:/dev/cling-build/lib/LLVMOption.lib
QMAKE_LFLAGS  += c:/dev/cling-build/lib/LLVMOrcTargetProcess.lib
QMAKE_LFLAGS  += c:/dev/cling-build/lib/LLVMX86TargetMCA.lib
QMAKE_LFLAGS  += c:/dev/cling-build/lib/LLVMOrcShared.lib
QMAKE_LFLAGS  += c:/dev/cling-build/lib/LLVMRuntimeDyld.lib
#QMAKE_LFLAGS  += c:/dev/cling-build/lib/LLVMAArch64CodeGen.lib
#QMAKE_LFLAGS  += c:/dev/cling-build/lib/LLVMAArch64AsmParser.lib
#QMAKE_LFLAGS  += c:/dev/cling-build/lib/LLVMAArch64Disassembler.lib
#QMAKE_LFLAGS  += c:/dev/cling-build/lib/LLVMAArch64Desc.lib
#QMAKE_LFLAGS  += c:/dev/cling-build/lib/LLVMAArch64Info.lib
#QMAKE_LFLAGS  += c:/dev/cling-build/lib/LLVMAArch64Utils.lib
#QMAKE_LFLAGS  += c:/dev/cling-build/lib/LLVMAMDGPUCodeGen.lib
QMAKE_LFLAGS  += c:/dev/cling-build/lib/LLVMPasses.lib
QMAKE_LFLAGS  += c:/dev/cling-build/lib/LLVMCoroutines.lib
QMAKE_LFLAGS  += c:/dev/cling-build/lib/LLVMIRPrinter.lib
QMAKE_LFLAGS  += c:/dev/cling-build/lib/LLVMMIRParser.lib
#QMAKE_LFLAGS  += c:/dev/cling-build/lib/LLVMAMDGPUAsmParser.lib
#QMAKE_LFLAGS  += c:/dev/cling-build/lib/LLVMAMDGPUInfo.lib
#QMAKE_LFLAGS  += c:/dev/cling-build/lib/LLVMAMDGPUUtils.lib
#QMAKE_LFLAGS  += c:/dev/cling-build/lib/LLVMARMCodeGen.lib
#QMAKE_LFLAGS  += c:/dev/cling-build/lib/LLVMARMAsmParser.lib
#QMAKE_LFLAGS  += c:/dev/cling-build/lib/LLVMARMDisassembler.lib
#QMAKE_LFLAGS  += c:/dev/cling-build/lib/LLVMARMDesc.lib
#QMAKE_LFLAGS  += c:/dev/cling-build/lib/LLVMARMInfo.lib
#QMAKE_LFLAGS  += c:/dev/cling-build/lib/LLVMARMUtils.lib
#QMAKE_LFLAGS  += c:/dev/cling-build/lib/LLVMAVRCodeGen.lib
#QMAKE_LFLAGS  += c:/dev/cling-build/lib/LLVMAVRAsmParser.lib
#QMAKE_LFLAGS  += c:/dev/cling-build/lib/LLVMAVRDesc.lib
#QMAKE_LFLAGS  += c:/dev/cling-build/lib/LLVMAVRInfo.lib
#QMAKE_LFLAGS  += c:/dev/cling-build/lib/LLVMBPFAsmParser.lib
#QMAKE_LFLAGS  += c:/dev/cling-build/lib/LLVMBPFDesc.lib
#QMAKE_LFLAGS  += c:/dev/cling-build/lib/LLVMBPFDisassembler.lib
#QMAKE_LFLAGS  += c:/dev/cling-build/lib/LLVMBPFInfo.lib
#QMAKE_LFLAGS  += c:/dev/cling-build/lib/LLVMHexagonCodeGen.lib
#QMAKE_LFLAGS  += c:/dev/cling-build/lib/LLVMHexagonAsmParser.lib
#QMAKE_LFLAGS  += c:/dev/cling-build/lib/LLVMHexagonDisassembler.lib
#QMAKE_LFLAGS  += c:/dev/cling-build/lib/LLVMHexagonDesc.lib
#QMAKE_LFLAGS  += c:/dev/cling-build/lib/LLVMHexagonInfo.lib
#QMAKE_LFLAGS  += c:/dev/cling-build/lib/LLVMLanaiCodeGen.lib
#QMAKE_LFLAGS  += c:/dev/cling-build/lib/LLVMLanaiAsmParser.lib
#QMAKE_LFLAGS  += c:/dev/cling-build/lib/LLVMLanaiDisassembler.lib
#QMAKE_LFLAGS  += c:/dev/cling-build/lib/LLVMLanaiDesc.lib
#QMAKE_LFLAGS  += c:/dev/cling-build/lib/LLVMLanaiInfo.lib
#QMAKE_LFLAGS  += c:/dev/cling-build/lib/LLVMLoongArchAsmParser.lib
#QMAKE_LFLAGS  += c:/dev/cling-build/lib/LLVMLoongArchDisassembler.lib
#QMAKE_LFLAGS  += c:/dev/cling-build/lib/LLVMLoongArchDesc.lib
#QMAKE_LFLAGS  += c:/dev/cling-build/lib/LLVMLoongArchInfo.lib
#QMAKE_LFLAGS  += c:/dev/cling-build/lib/LLVMMipsCodeGen.lib
#QMAKE_LFLAGS  += c:/dev/cling-build/lib/LLVMMipsAsmParser.lib
#QMAKE_LFLAGS  += c:/dev/cling-build/lib/LLVMMipsDesc.lib
#QMAKE_LFLAGS  += c:/dev/cling-build/lib/LLVMMipsDisassembler.lib
#QMAKE_LFLAGS  += c:/dev/cling-build/lib/LLVMMipsInfo.lib
#QMAKE_LFLAGS  += c:/dev/cling-build/lib/LLVMMSP430CodeGen.lib
#QMAKE_LFLAGS  += c:/dev/cling-build/lib/LLVMMSP430AsmParser.lib
#QMAKE_LFLAGS  += c:/dev/cling-build/lib/LLVMMSP430Desc.lib
#QMAKE_LFLAGS  += c:/dev/cling-build/lib/LLVMMSP430Disassembler.lib
#QMAKE_LFLAGS  += c:/dev/cling-build/lib/LLVMMSP430Info.lib
QMAKE_LFLAGS  += c:/dev/cling-build/lib/LLVMNVPTXCodeGen.lib
QMAKE_LFLAGS  += c:/dev/cling-build/lib/LLVMNVPTXDesc.lib
QMAKE_LFLAGS  += c:/dev/cling-build/lib/LLVMNVPTXInfo.lib
#QMAKE_LFLAGS  += c:/dev/cling-build/lib/LLVMPowerPCCodeGen.lib
#QMAKE_LFLAGS  += c:/dev/cling-build/lib/LLVMPowerPCAsmParser.lib
#QMAKE_LFLAGS  += c:/dev/cling-build/lib/LLVMPowerPCDesc.lib
#QMAKE_LFLAGS  += c:/dev/cling-build/lib/LLVMPowerPCDisassembler.lib
#QMAKE_LFLAGS  += c:/dev/cling-build/lib/LLVMPowerPCInfo.lib
#QMAKE_LFLAGS  += c:/dev/cling-build/lib/LLVMRISCVCodeGen.lib
QMAKE_LFLAGS  += c:/dev/cling-build/lib/LLVMipo.lib
QMAKE_LFLAGS  += c:/dev/cling-build/lib/LLVMFrontendOpenMP.lib
QMAKE_LFLAGS  += c:/dev/cling-build/lib/LLVMLinker.lib
QMAKE_LFLAGS  += c:/dev/cling-build/lib/LLVMVectorize.lib
#QMAKE_LFLAGS  += c:/dev/cling-build/lib/LLVMRISCVAsmParser.lib
#QMAKE_LFLAGS  += c:/dev/cling-build/lib/LLVMRISCVDisassembler.lib
#QMAKE_LFLAGS  += c:/dev/cling-build/lib/LLVMRISCVDesc.lib
#QMAKE_LFLAGS  += c:/dev/cling-build/lib/LLVMRISCVInfo.lib
#QMAKE_LFLAGS  += c:/dev/cling-build/lib/LLVMSparcCodeGen.lib
#QMAKE_LFLAGS  += c:/dev/cling-build/lib/LLVMSparcAsmParser.lib
#QMAKE_LFLAGS  += c:/dev/cling-build/lib/LLVMSparcDesc.lib
#QMAKE_LFLAGS  += c:/dev/cling-build/lib/LLVMSparcDisassembler.lib
#QMAKE_LFLAGS  += c:/dev/cling-build/lib/LLVMSparcInfo.lib
#QMAKE_LFLAGS  += c:/dev/cling-build/lib/LLVMSystemZCodeGen.lib
#QMAKE_LFLAGS  += c:/dev/cling-build/lib/LLVMSystemZAsmParser.lib
#QMAKE_LFLAGS  += c:/dev/cling-build/lib/LLVMSystemZDisassembler.lib
#QMAKE_LFLAGS  += c:/dev/cling-build/lib/LLVMSystemZDesc.lib
#QMAKE_LFLAGS  += c:/dev/cling-build/lib/LLVMSystemZInfo.lib
#QMAKE_LFLAGS  += c:/dev/cling-build/lib/LLVMVECodeGen.lib
#QMAKE_LFLAGS  += c:/dev/cling-build/lib/LLVMVEAsmParser.lib
#QMAKE_LFLAGS  += c:/dev/cling-build/lib/LLVMVEDesc.lib
#QMAKE_LFLAGS  += c:/dev/cling-build/lib/LLVMVEDisassembler.lib
#QMAKE_LFLAGS  += c:/dev/cling-build/lib/LLVMVEInfo.lib
#QMAKE_LFLAGS  += c:/dev/cling-build/lib/LLVMWebAssemblyCodeGen.lib
#QMAKE_LFLAGS  += c:/dev/cling-build/lib/LLVMWebAssemblyAsmParser.lib
#QMAKE_LFLAGS  += c:/dev/cling-build/lib/LLVMWebAssemblyDisassembler.lib
#QMAKE_LFLAGS  += c:/dev/cling-build/lib/LLVMWebAssemblyDesc.lib
#QMAKE_LFLAGS  += c:/dev/cling-build/lib/LLVMWebAssemblyInfo.lib
#QMAKE_LFLAGS  += c:/dev/cling-build/lib/LLVMWebAssemblyUtils.lib
QMAKE_LFLAGS  += c:/dev/cling-build/lib/LLVMX86CodeGen.lib
QMAKE_LFLAGS  += c:/dev/cling-build/lib/LLVMInstrumentation.lib
QMAKE_LFLAGS  += c:/dev/cling-build/lib/LLVMGlobalISel.lib
QMAKE_LFLAGS  += c:/dev/cling-build/lib/LLVMCFGuard.lib
QMAKE_LFLAGS  += c:/dev/cling-build/lib/LLVMX86AsmParser.lib
QMAKE_LFLAGS  += c:/dev/cling-build/lib/LLVMX86Desc.lib
QMAKE_LFLAGS  += c:/dev/cling-build/lib/LLVMX86Disassembler.lib
QMAKE_LFLAGS  += c:/dev/cling-build/lib/LLVMX86Info.lib
#QMAKE_LFLAGS  += c:/dev/cling-build/lib/LLVMXCoreCodeGen.lib
QMAKE_LFLAGS  += c:/dev/cling-build/lib/LLVMAsmPrinter.lib
QMAKE_LFLAGS  += c:/dev/cling-build/lib/LLVMSelectionDAG.lib
QMAKE_LFLAGS  += c:/dev/cling-build/lib/LLVMCodeGen.lib
QMAKE_LFLAGS  += c:/dev/cling-build/lib/LLVMScalarOpts.lib
QMAKE_LFLAGS  += c:/dev/cling-build/lib/LLVMAggressiveInstCombine.lib
QMAKE_LFLAGS  += c:/dev/cling-build/lib/LLVMInstCombine.lib
QMAKE_LFLAGS  += c:/dev/cling-build/lib/LLVMTarget.lib
QMAKE_LFLAGS  += c:/dev/cling-build/lib/LLVMBitWriter.lib
QMAKE_LFLAGS  += c:/dev/cling-build/lib/LLVMObjCARCOpts.lib
QMAKE_LFLAGS  += c:/dev/cling-build/lib/LLVMTransformUtils.lib
QMAKE_LFLAGS  += c:/dev/cling-build/lib/LLVMAnalysis.lib
QMAKE_LFLAGS  += c:/dev/cling-build/lib/LLVMProfileData.lib
QMAKE_LFLAGS  += c:/dev/cling-build/lib/LLVMSymbolize.lib
QMAKE_LFLAGS  += c:/dev/cling-build/lib/LLVMDebugInfoPDB.lib
QMAKE_LFLAGS  += c:/dev/cling-build/lib/LLVMDebugInfoMSF.lib
QMAKE_LFLAGS  += c:/dev/cling-build/lib/LLVMDebugInfoDWARF.lib
QMAKE_LFLAGS  += c:/dev/cling-build/lib/LLVMObject.lib
QMAKE_LFLAGS  += c:/dev/cling-build/lib/LLVMIRReader.lib
QMAKE_LFLAGS  += c:/dev/cling-build/lib/LLVMBitReader.lib
QMAKE_LFLAGS  += c:/dev/cling-build/lib/LLVMAsmParser.lib
QMAKE_LFLAGS  += c:/dev/cling-build/lib/LLVMCore.lib
QMAKE_LFLAGS  += c:/dev/cling-build/lib/LLVMRemarks.lib
QMAKE_LFLAGS  += c:/dev/cling-build/lib/LLVMBitstreamReader.lib
QMAKE_LFLAGS  += c:/dev/cling-build/lib/LLVMMCParser.lib
QMAKE_LFLAGS  += c:/dev/cling-build/lib/LLVMTextAPI.lib
#QMAKE_LFLAGS  += c:/dev/cling-build/lib/LLVMXCoreDesc.lib
#QMAKE_LFLAGS  += c:/dev/cling-build/lib/LLVMXCoreDisassembler.lib
QMAKE_LFLAGS  += c:/dev/cling-build/lib/LLVMMCDisassembler.lib
#QMAKE_LFLAGS  += c:/dev/cling-build/lib/LLVMXCoreInfo.lib
QMAKE_LFLAGS  += c:/dev/cling-build/lib/LLVMMC.lib
QMAKE_LFLAGS  += c:/dev/cling-build/lib/LLVMBinaryFormat.lib
QMAKE_LFLAGS  += c:/dev/cling-build/lib/LLVMTargetParser.lib
QMAKE_LFLAGS  += c:/dev/cling-build/lib/LLVMDebugInfoCodeView.lib
QMAKE_LFLAGS  += c:/dev/cling-build/lib/LLVMSupport.lib
QMAKE_LFLAGS  += c:/dev/cling-build/lib/LLVMDemangle.lib
#QMAKE_LFLAGS  += -lm
#QMAKE_LFLAGS  += /Library/Developer/CommandLineTools/SDKs/MacOSX14.2.sdk/usr/lib/libz.tbd
#QMAKE_LFLAGS  += /opt/homebrew/lib/libzstd.dylib
#QMAKE_LFLAGS  += /Library/Developer/CommandLineTools/SDKs/MacOSX14.2.sdk/usr/lib/urses.tbd


SOURCES += \
main.cpp \
quasqliteserializer.cpp \
quaxmlserializer.cpp

HEADERS += \
temperaturesensor.h \
quasqliteserializer.h \
quaxmlserializer.h
    
SOURCES += temperaturesensor.cpp

include($$PWD/../../src/wrapper/quaserver.pri)
include($$PWD/../../src/helper/add_qt_path_win.pri)

DISTFILES += \
    texttest

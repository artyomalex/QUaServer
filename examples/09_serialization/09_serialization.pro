QT += core xml sql
QT -= gui

CONFIG += c++17

TARGET = 09_serialization
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app


INCLUDEPATH += $$PWD/

INCLUDEPATH += /Users/artyomalex/cling-build/tools/cling/tools/demo/

INCLUDEPATH += /Users/artyomalex/cling/tools/demo/

INCLUDEPATH += /Users/artyomalex/cling/include/

INCLUDEPATH += /Users/artyomalex/cling-build/tools/cling/include/

INCLUDEPATH += /Users/artyomalex/cling-build/tools/clang/include/

INCLUDEPATH += /Users/artyomalex/cling_src/include

INCLUDEPATH += /Users/artyomalex/cling-build/include

LIBS += -L/Users/artyomalex/cling-build/lib/
#QMAKE_LFLAGS += /Users/artyomalex/cling-build/lib/libcling.dylib
QMAKE_LFLAGS  += /Users/artyomalex/cling-build/lib/libclingInterpreter.a
QMAKE_LFLAGS  += /Users/artyomalex/cling-build/lib/libclingUtils.a
QMAKE_LFLAGS  +=-ldl
QMAKE_LFLAGS  +=-v
QMAKE_LFLAGS  += /Users/artyomalex/cling-build/lib/libclangCodeGen.a
QMAKE_LFLAGS  += /Users/artyomalex/cling-build/lib/libclangRewriteFrontend.a
QMAKE_LFLAGS  += /Users/artyomalex/cling-build/lib/libclangFrontend.a
QMAKE_LFLAGS  += /Users/artyomalex/cling-build/lib/libclangDriver.a
QMAKE_LFLAGS  += /Users/artyomalex/cling-build/lib/libclangParse.a
QMAKE_LFLAGS  += /Users/artyomalex/cling-build/lib/libclangRewrite.a
QMAKE_LFLAGS  += /Users/artyomalex/cling-build/lib/libclangSerialization.a
QMAKE_LFLAGS  += /Users/artyomalex/cling-build/lib/libclangSema.a
QMAKE_LFLAGS  += /Users/artyomalex/cling-build/lib/libclangAnalysis.a
QMAKE_LFLAGS  += /Users/artyomalex/cling-build/lib/libclangASTMatchers.a
QMAKE_LFLAGS  += /Users/artyomalex/cling-build/lib/libclangEdit.a
QMAKE_LFLAGS  += /Users/artyomalex/cling-build/lib/libLLVMFrontendHLSL.a
QMAKE_LFLAGS  += /Users/artyomalex/cling-build/lib/libclangSupport.a
QMAKE_LFLAGS  += /Users/artyomalex/cling-build/lib/libclangAST.a
QMAKE_LFLAGS  += /Users/artyomalex/cling-build/lib/libclangLex.a
QMAKE_LFLAGS  += /Users/artyomalex/cling-build/lib/libclangBasic.a
QMAKE_LFLAGS  += /Users/artyomalex/cling-build/lib/libLLVMCoverage.a
QMAKE_LFLAGS  += /Users/artyomalex/cling-build/lib/libLLVMLTO.a
QMAKE_LFLAGS  += /Users/artyomalex/cling-build/lib/libLLVMExtensions.a
QMAKE_LFLAGS  += /Users/artyomalex/cling-build/lib/libLLVMOrcJIT.a
QMAKE_LFLAGS  += /Users/artyomalex/cling-build/lib/libLLVMExecutionEngine.a
QMAKE_LFLAGS  += /Users/artyomalex/cling-build/lib/libLLVMJITLink.a
QMAKE_LFLAGS  += /Users/artyomalex/cling-build/lib/libLLVMWindowsDriver.a
QMAKE_LFLAGS  += /Users/artyomalex/cling-build/lib/libLLVMOption.a
QMAKE_LFLAGS  += /Users/artyomalex/cling-build/lib/libLLVMOrcTargetProcess.a
QMAKE_LFLAGS  += /Users/artyomalex/cling-build/lib/libLLVMOrcShared.a
QMAKE_LFLAGS  += /Users/artyomalex/cling-build/lib/libLLVMRuntimeDyld.a
QMAKE_LFLAGS  += /Users/artyomalex/cling-build/lib/libLLVMAArch64CodeGen.a
QMAKE_LFLAGS  += /Users/artyomalex/cling-build/lib/libLLVMAArch64AsmParser.a
QMAKE_LFLAGS  += /Users/artyomalex/cling-build/lib/libLLVMAArch64Disassembler.a
QMAKE_LFLAGS  += /Users/artyomalex/cling-build/lib/libLLVMAArch64Desc.a
QMAKE_LFLAGS  += /Users/artyomalex/cling-build/lib/libLLVMAArch64Info.a
QMAKE_LFLAGS  += /Users/artyomalex/cling-build/lib/libLLVMAArch64Utils.a
QMAKE_LFLAGS  += /Users/artyomalex/cling-build/lib/libLLVMAMDGPUCodeGen.a
QMAKE_LFLAGS  += /Users/artyomalex/cling-build/lib/libLLVMPasses.a
QMAKE_LFLAGS  += /Users/artyomalex/cling-build/lib/libLLVMCoroutines.a
QMAKE_LFLAGS  += /Users/artyomalex/cling-build/lib/libLLVMIRPrinter.a
QMAKE_LFLAGS  += /Users/artyomalex/cling-build/lib/libLLVMMIRParser.a
QMAKE_LFLAGS  += /Users/artyomalex/cling-build/lib/libLLVMAMDGPUAsmParser.a
QMAKE_LFLAGS  += /Users/artyomalex/cling-build/lib/libLLVMAMDGPUDisassembler.a
QMAKE_LFLAGS  += /Users/artyomalex/cling-build/lib/libLLVMAMDGPUDesc.a
QMAKE_LFLAGS  += /Users/artyomalex/cling-build/lib/libLLVMAMDGPUInfo.a
QMAKE_LFLAGS  += /Users/artyomalex/cling-build/lib/libLLVMAMDGPUUtils.a
QMAKE_LFLAGS  += /Users/artyomalex/cling-build/lib/libLLVMARMCodeGen.a
QMAKE_LFLAGS  += /Users/artyomalex/cling-build/lib/libLLVMARMAsmParser.a
QMAKE_LFLAGS  += /Users/artyomalex/cling-build/lib/libLLVMARMDisassembler.a
QMAKE_LFLAGS  += /Users/artyomalex/cling-build/lib/libLLVMARMDesc.a
QMAKE_LFLAGS  += /Users/artyomalex/cling-build/lib/libLLVMARMInfo.a
QMAKE_LFLAGS  += /Users/artyomalex/cling-build/lib/libLLVMARMUtils.a
QMAKE_LFLAGS  += /Users/artyomalex/cling-build/lib/libLLVMAVRCodeGen.a
QMAKE_LFLAGS  += /Users/artyomalex/cling-build/lib/libLLVMAVRAsmParser.a
QMAKE_LFLAGS  += /Users/artyomalex/cling-build/lib/libLLVMAVRDesc.a
QMAKE_LFLAGS  += /Users/artyomalex/cling-build/lib/libLLVMAVRDisassembler.a
QMAKE_LFLAGS  += /Users/artyomalex/cling-build/lib/libLLVMAVRInfo.a
QMAKE_LFLAGS  += /Users/artyomalex/cling-build/lib/libLLVMBPFCodeGen.a
QMAKE_LFLAGS  += /Users/artyomalex/cling-build/lib/libLLVMBPFAsmParser.a
QMAKE_LFLAGS  += /Users/artyomalex/cling-build/lib/libLLVMBPFDesc.a
QMAKE_LFLAGS  += /Users/artyomalex/cling-build/lib/libLLVMBPFDisassembler.a
QMAKE_LFLAGS  += /Users/artyomalex/cling-build/lib/libLLVMBPFInfo.a
QMAKE_LFLAGS  += /Users/artyomalex/cling-build/lib/libLLVMHexagonCodeGen.a
QMAKE_LFLAGS  += /Users/artyomalex/cling-build/lib/libLLVMHexagonAsmParser.a
QMAKE_LFLAGS  += /Users/artyomalex/cling-build/lib/libLLVMHexagonDisassembler.a
QMAKE_LFLAGS  += /Users/artyomalex/cling-build/lib/libLLVMHexagonDesc.a
QMAKE_LFLAGS  += /Users/artyomalex/cling-build/lib/libLLVMHexagonInfo.a
QMAKE_LFLAGS  += /Users/artyomalex/cling-build/lib/libLLVMLanaiCodeGen.a
QMAKE_LFLAGS  += /Users/artyomalex/cling-build/lib/libLLVMLanaiAsmParser.a
QMAKE_LFLAGS  += /Users/artyomalex/cling-build/lib/libLLVMLanaiDisassembler.a
QMAKE_LFLAGS  += /Users/artyomalex/cling-build/lib/libLLVMLanaiDesc.a
QMAKE_LFLAGS  += /Users/artyomalex/cling-build/lib/libLLVMLanaiInfo.a
QMAKE_LFLAGS  += /Users/artyomalex/cling-build/lib/libLLVMLoongArchCodeGen.a
QMAKE_LFLAGS  += /Users/artyomalex/cling-build/lib/libLLVMLoongArchAsmParser.a
QMAKE_LFLAGS  += /Users/artyomalex/cling-build/lib/libLLVMLoongArchDisassembler.a
QMAKE_LFLAGS  += /Users/artyomalex/cling-build/lib/libLLVMLoongArchDesc.a
QMAKE_LFLAGS  += /Users/artyomalex/cling-build/lib/libLLVMLoongArchInfo.a
QMAKE_LFLAGS  += /Users/artyomalex/cling-build/lib/libLLVMMipsCodeGen.a
QMAKE_LFLAGS  += /Users/artyomalex/cling-build/lib/libLLVMMipsAsmParser.a
QMAKE_LFLAGS  += /Users/artyomalex/cling-build/lib/libLLVMMipsDesc.a
QMAKE_LFLAGS  += /Users/artyomalex/cling-build/lib/libLLVMMipsDisassembler.a
QMAKE_LFLAGS  += /Users/artyomalex/cling-build/lib/libLLVMMipsInfo.a
QMAKE_LFLAGS  += /Users/artyomalex/cling-build/lib/libLLVMMSP430CodeGen.a
QMAKE_LFLAGS  += /Users/artyomalex/cling-build/lib/libLLVMMSP430AsmParser.a
QMAKE_LFLAGS  += /Users/artyomalex/cling-build/lib/libLLVMMSP430Desc.a
QMAKE_LFLAGS  += /Users/artyomalex/cling-build/lib/libLLVMMSP430Disassembler.a
QMAKE_LFLAGS  += /Users/artyomalex/cling-build/lib/libLLVMMSP430Info.a
QMAKE_LFLAGS  += /Users/artyomalex/cling-build/lib/libLLVMNVPTXCodeGen.a
QMAKE_LFLAGS  += /Users/artyomalex/cling-build/lib/libLLVMNVPTXDesc.a
QMAKE_LFLAGS  += /Users/artyomalex/cling-build/lib/libLLVMNVPTXInfo.a
QMAKE_LFLAGS  += /Users/artyomalex/cling-build/lib/libLLVMPowerPCCodeGen.a
QMAKE_LFLAGS  += /Users/artyomalex/cling-build/lib/libLLVMPowerPCAsmParser.a
QMAKE_LFLAGS  += /Users/artyomalex/cling-build/lib/libLLVMPowerPCDesc.a
QMAKE_LFLAGS  += /Users/artyomalex/cling-build/lib/libLLVMPowerPCDisassembler.a
QMAKE_LFLAGS  += /Users/artyomalex/cling-build/lib/libLLVMPowerPCInfo.a
QMAKE_LFLAGS  += /Users/artyomalex/cling-build/lib/libLLVMRISCVCodeGen.a
QMAKE_LFLAGS  += /Users/artyomalex/cling-build/lib/libLLVMipo.a
QMAKE_LFLAGS  += /Users/artyomalex/cling-build/lib/libLLVMFrontendOpenMP.a
QMAKE_LFLAGS  += /Users/artyomalex/cling-build/lib/libLLVMLinker.a
QMAKE_LFLAGS  += /Users/artyomalex/cling-build/lib/libLLVMVectorize.a
QMAKE_LFLAGS  += /Users/artyomalex/cling-build/lib/libLLVMRISCVAsmParser.a
QMAKE_LFLAGS  += /Users/artyomalex/cling-build/lib/libLLVMRISCVDisassembler.a
QMAKE_LFLAGS  += /Users/artyomalex/cling-build/lib/libLLVMRISCVDesc.a
QMAKE_LFLAGS  += /Users/artyomalex/cling-build/lib/libLLVMRISCVInfo.a
QMAKE_LFLAGS  += /Users/artyomalex/cling-build/lib/libLLVMSparcCodeGen.a
QMAKE_LFLAGS  += /Users/artyomalex/cling-build/lib/libLLVMSparcAsmParser.a
QMAKE_LFLAGS  += /Users/artyomalex/cling-build/lib/libLLVMSparcDesc.a
QMAKE_LFLAGS  += /Users/artyomalex/cling-build/lib/libLLVMSparcDisassembler.a
QMAKE_LFLAGS  += /Users/artyomalex/cling-build/lib/libLLVMSparcInfo.a
QMAKE_LFLAGS  += /Users/artyomalex/cling-build/lib/libLLVMSystemZCodeGen.a
QMAKE_LFLAGS  += /Users/artyomalex/cling-build/lib/libLLVMSystemZAsmParser.a
QMAKE_LFLAGS  += /Users/artyomalex/cling-build/lib/libLLVMSystemZDisassembler.a
QMAKE_LFLAGS  += /Users/artyomalex/cling-build/lib/libLLVMSystemZDesc.a
QMAKE_LFLAGS  += /Users/artyomalex/cling-build/lib/libLLVMSystemZInfo.a
QMAKE_LFLAGS  += /Users/artyomalex/cling-build/lib/libLLVMVECodeGen.a
QMAKE_LFLAGS  += /Users/artyomalex/cling-build/lib/libLLVMVEAsmParser.a
QMAKE_LFLAGS  += /Users/artyomalex/cling-build/lib/libLLVMVEDesc.a
QMAKE_LFLAGS  += /Users/artyomalex/cling-build/lib/libLLVMVEDisassembler.a
QMAKE_LFLAGS  += /Users/artyomalex/cling-build/lib/libLLVMVEInfo.a
QMAKE_LFLAGS  += /Users/artyomalex/cling-build/lib/libLLVMWebAssemblyCodeGen.a
QMAKE_LFLAGS  += /Users/artyomalex/cling-build/lib/libLLVMWebAssemblyAsmParser.a
QMAKE_LFLAGS  += /Users/artyomalex/cling-build/lib/libLLVMWebAssemblyDisassembler.a
QMAKE_LFLAGS  += /Users/artyomalex/cling-build/lib/libLLVMWebAssemblyDesc.a
QMAKE_LFLAGS  += /Users/artyomalex/cling-build/lib/libLLVMWebAssemblyInfo.a
QMAKE_LFLAGS  += /Users/artyomalex/cling-build/lib/libLLVMWebAssemblyUtils.a
QMAKE_LFLAGS  += /Users/artyomalex/cling-build/lib/libLLVMX86CodeGen.a
QMAKE_LFLAGS  += /Users/artyomalex/cling-build/lib/libLLVMInstrumentation.a
QMAKE_LFLAGS  += /Users/artyomalex/cling-build/lib/libLLVMGlobalISel.a
QMAKE_LFLAGS  += /Users/artyomalex/cling-build/lib/libLLVMCFGuard.a
QMAKE_LFLAGS  += /Users/artyomalex/cling-build/lib/libLLVMX86AsmParser.a
QMAKE_LFLAGS  += /Users/artyomalex/cling-build/lib/libLLVMX86Desc.a
QMAKE_LFLAGS  += /Users/artyomalex/cling-build/lib/libLLVMX86Disassembler.a
QMAKE_LFLAGS  += /Users/artyomalex/cling-build/lib/libLLVMX86Info.a
QMAKE_LFLAGS  += /Users/artyomalex/cling-build/lib/libLLVMXCoreCodeGen.a
QMAKE_LFLAGS  += /Users/artyomalex/cling-build/lib/libLLVMAsmPrinter.a
QMAKE_LFLAGS  += /Users/artyomalex/cling-build/lib/libLLVMSelectionDAG.a
QMAKE_LFLAGS  += /Users/artyomalex/cling-build/lib/libLLVMCodeGen.a
QMAKE_LFLAGS  += /Users/artyomalex/cling-build/lib/libLLVMScalarOpts.a
QMAKE_LFLAGS  += /Users/artyomalex/cling-build/lib/libLLVMAggressiveInstCombine.a
QMAKE_LFLAGS  += /Users/artyomalex/cling-build/lib/libLLVMInstCombine.a
QMAKE_LFLAGS  += /Users/artyomalex/cling-build/lib/libLLVMTarget.a
QMAKE_LFLAGS  += /Users/artyomalex/cling-build/lib/libLLVMBitWriter.a
QMAKE_LFLAGS  += /Users/artyomalex/cling-build/lib/libLLVMObjCARCOpts.a
QMAKE_LFLAGS  += /Users/artyomalex/cling-build/lib/libLLVMTransformUtils.a
QMAKE_LFLAGS  += /Users/artyomalex/cling-build/lib/libLLVMAnalysis.a
QMAKE_LFLAGS  += /Users/artyomalex/cling-build/lib/libLLVMProfileData.a
QMAKE_LFLAGS  += /Users/artyomalex/cling-build/lib/libLLVMSymbolize.a
QMAKE_LFLAGS  += /Users/artyomalex/cling-build/lib/libLLVMDebugInfoPDB.a
QMAKE_LFLAGS  += /Users/artyomalex/cling-build/lib/libLLVMDebugInfoMSF.a
QMAKE_LFLAGS  += /Users/artyomalex/cling-build/lib/libLLVMDebugInfoDWARF.a
QMAKE_LFLAGS  += /Users/artyomalex/cling-build/lib/libLLVMObject.a
QMAKE_LFLAGS  += /Users/artyomalex/cling-build/lib/libLLVMIRReader.a
QMAKE_LFLAGS  += /Users/artyomalex/cling-build/lib/libLLVMBitReader.a
QMAKE_LFLAGS  += /Users/artyomalex/cling-build/lib/libLLVMAsmParser.a
QMAKE_LFLAGS  += /Users/artyomalex/cling-build/lib/libLLVMCore.a
QMAKE_LFLAGS  += /Users/artyomalex/cling-build/lib/libLLVMRemarks.a
QMAKE_LFLAGS  += /Users/artyomalex/cling-build/lib/libLLVMBitstreamReader.a
QMAKE_LFLAGS  += /Users/artyomalex/cling-build/lib/libLLVMMCParser.a
QMAKE_LFLAGS  += /Users/artyomalex/cling-build/lib/libLLVMTextAPI.a
QMAKE_LFLAGS  += /Users/artyomalex/cling-build/lib/libLLVMXCoreDesc.a
QMAKE_LFLAGS  += /Users/artyomalex/cling-build/lib/libLLVMXCoreDisassembler.a
QMAKE_LFLAGS  += /Users/artyomalex/cling-build/lib/libLLVMMCDisassembler.a
QMAKE_LFLAGS  += /Users/artyomalex/cling-build/lib/libLLVMXCoreInfo.a
QMAKE_LFLAGS  += /Users/artyomalex/cling-build/lib/libLLVMMC.a
QMAKE_LFLAGS  += /Users/artyomalex/cling-build/lib/libLLVMBinaryFormat.a
QMAKE_LFLAGS  += /Users/artyomalex/cling-build/lib/libLLVMTargetParser.a
QMAKE_LFLAGS  += /Users/artyomalex/cling-build/lib/libLLVMDebugInfoCodeView.a
QMAKE_LFLAGS  += /Users/artyomalex/cling-build/lib/libLLVMSupport.a
QMAKE_LFLAGS  += /Users/artyomalex/cling-build/lib/libLLVMDemangle.a
QMAKE_LFLAGS  += -lm
QMAKE_LFLAGS  += /Library/Developer/CommandLineTools/SDKs/MacOSX14.2.sdk/usr/lib/libz.tbd
QMAKE_LFLAGS  += /opt/homebrew/lib/libzstd.dylib
QMAKE_LFLAGS  += /Library/Developer/CommandLineTools/SDKs/MacOSX14.2.sdk/usr/lib/libcurses.tbd


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

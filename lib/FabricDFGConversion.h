//
// Copyright (c) 2010-2017 Fabric Software Inc. All rights reserved.
//

#pragma once

#include <iostream>
#include <vector>
#include <map>
#include <maya/MDataBlock.h>
#include <maya/MPlug.h>
#include <maya/MPlugArray.h>
#include <maya/MFnData.h>
#include <maya/MFnNumericData.h>
#include <maya/MStringArray.h>
#include <maya/MDataHandle.h>

#include <FabricCore.h>
#include <FabricSplice.h>

#include <FTL/StrRef.h>

typedef void(*DFGPlugToArgFunc)(
  unsigned argIndex,
  char const *argName,
  char const *argTypeName,
  FEC_DFGPortType argOutsidePortType,
  uint64_t argRawDataSize,
  FEC_DFGBindingVisitArgs_GetCB getCB,
  FEC_DFGBindingVisitArgs_GetRawCB getRawCB,
  FEC_DFGBindingVisitArgs_SetCB setCB,
  FEC_DFGBindingVisitArgs_SetRawCB setRawCB,
  void *getSetUD,
  MPlug &plug,
  MDataBlock &data
  );

typedef void(*DFGArgToPlugFunc)(
  unsigned argIndex,
  char const *argName,
  char const *argTypeName,
  FEC_DFGPortType argOutsidePortType,
  uint64_t argRawDataSize,
  FEC_DFGBindingVisitArgs_GetCB getCB,
  FEC_DFGBindingVisitArgs_GetRawCB getRawCB,
  void *getSetUD,
  MPlug &plug,
  MDataBlock &data
  );

DFGPlugToArgFunc getDFGPlugToArgFunc(const FTL::StrRef &dataType);
DFGArgToPlugFunc getDFGArgToPlugFunc(const FTL::StrRef &dataType);

//
// Copyright (c) 2010-2017 Fabric Software Inc. All rights reserved.
//

#pragma once

#include <FabricCore.h>
#include <FabricUI/SceneHub/SHGLRenderer.h>
#include <maya/MString.h>
#include <maya/M3dView.h>
#include <maya/MDrawContext.h>

class FabricRenderCallback {

  public:
    static bool isRTRPassEnabled();

    static void enableRTRPass(
      bool enable
      );

    static uint32_t gViewId;

    static bool gCallbackEnabled;
    
    static FabricCore::RTVal sDrawContext;
    
    static FabricUI::SceneHub::SHGLRenderer shHostGLRenderer;

    static void plug(); 
    
    static void unplug();

    static void enable(
      bool enable
      );
    
    static void disable();
    
    static bool isEnabled();
    
    static bool isRTR2Enable();

    static bool canDraw();
    
    static void drawID();

    static MStatus drawRTR2(
      uint32_t width, 
      uint32_t height, 
      uint32_t phase
      );

    static void prepareViewport(
      const MString &panelName,
      M3dView &view,
      bool toolEventSetup
    );

    static void preDrawCallback(
      const MString &panelName, 
      void *clientData
      );
   
    static void postDrawCallback(
      const MString &panelName, 
      void *clientData
      );

#if MAYA_API_VERSION >= 201600
  static void viewport2OverridePreDrawCallback(
    MHWRender::MDrawContext &context, 
    void* clientData
    );
#endif
    
};

#pragma once

#include "ofMain.h"
#include "ofxAssets.h"

// For X11
#if defined(Status)
# undef Status
typedef int Status;
#endif

#include "ofxCvGui/Builder.h"
#include "ofxCvGui/Controller.h"
#include "ofxCvGui/Element.h"
#include "ofxCvGui/ElementGroup.h"
#include "ofxCvGui/ElementSlot.h"
#include "ofxCvGui/InspectController.h"
#include "ofxCvGui/Types.h"

#include "ofxCvGui/Utils/Button.h"
#include "ofxCvGui/Utils/Constants.h"
#include "ofxCvGui/Utils/Enum.h"
#include "ofxCvGui/Utils/Sugar.h"
#include "ofxCvGui/Utils/TextField.h"

#include "ofxCvGui/Widgets/Button.h"
#include "ofxCvGui/Widgets/EditableValue.h"
#include "ofxCvGui/Widgets/Indicator.h"
#include "ofxCvGui/Widgets/LiveValue.h"
#include "ofxCvGui/Widgets/MultipleChoice.h"
#include "ofxCvGui/Widgets/SelectFile.h"
#include "ofxCvGui/Widgets/Slider.h"
#include "ofxCvGui/Widgets/Spacer.h"
#include "ofxCvGui/Widgets/Title.h"
#include "ofxCvGui/Widgets/Toggle.h"
#include "ofxCvGui/Widgets/Button.h"
#include "ofxCvGui/Widgets/TextField.h"
#include "ofxCvGui/Widgets/Heartbeat.h"
#include "ofxCvGui/Widgets/HorizontalStack.h"

#include "ofxCvGui/Panels/Base.h"
#include "ofxCvGui/Panels/BaseImage.h"
#include "ofxCvGui/Panels/Draws.h"
#include "ofxCvGui/Panels/ElementCanvas.h"
#include "ofxCvGui/Panels/ElementHost.h"
#include "ofxCvGui/Panels/Image.h"
#include "ofxCvGui/Panels/Inspector.h"
#include "ofxCvGui/Panels/Instructions.h"
#include "ofxCvGui/Panels/Pixels.h"
#include "ofxCvGui/Panels/PixelsVector.h"
#include "ofxCvGui/Panels/Scroll.h"
#include "ofxCvGui/Panels/SharedView.h"
#include "ofxCvGui/Panels/Text.h"
#include "ofxCvGui/Panels/Texture.h"
#include "ofxCvGui/Panels/Tree.h"
#include "ofxCvGui/Panels/Widgets.h"
#include "ofxCvGui/Panels/World.h"

#include "ofxCvGui/Panels/Groups/Base.h"
#include "ofxCvGui/Panels/Groups/Grid.h"
#include "ofxCvGui/Panels/Groups/Strip.h"

#pragma once
#include "ofxCvGui/ElementGroup.h"
#include "ofxCvGui/Panels/Base.h"

namespace ofxCvGui {
	namespace Panels {
		namespace Groups {
			class Base : public ElementGroup_<Panels::Base> {
			public:
				virtual ~Base() { }
			protected:
				void drawTitle() override { }
			};
		}
	}
	typedef shared_ptr<Panels::Groups::Base> PanelGroupPtr;
}
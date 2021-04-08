#pragma once
#include "Base.h"
#include "ofxCvGui/ElementGroup.h"

namespace ofxCvGui {
	namespace Panels {
		class OFXCVGUI_API_ENTRY ElementHost : public Base {
		public:
			ElementHost();
			ElementGroupPtr getElementGroup();
		protected:
			ElementGroupPtr elementGroup;
		};

		shared_ptr<Panels::ElementHost> makeElementHost(string caption = "");
	}
}
#pragma once
#include "../Element.h"
#include "../ElementGroup.h"
#include "ofRectangle.h"

#include <string>

#define OFXCVGUI_LABEL_PANEL_AND_RETURN newPanel->setCaption(caption); return newPanel;

namespace ofxCvGui {
	namespace Panels {
		class OFXCVGUI_API_ENTRY Base;
	}
	typedef shared_ptr<Panels::Base> PanelPtr;

	namespace Panels {
		class OFXCVGUI_API_ENTRY Base : public Element {
		public:
			Base();
			virtual const shared_ptr<Panels::Base> findScreen(const glm::vec2 & xy, ofRectangle & currentPanelBounds) {
				return shared_ptr<Panels::Base>();
			}
			
			ofxLiquidEvent<FilesDraggedArguments> onFilesDragged;
			
			ElementPtr addToolBarElement(const std::string & imageAssetName, function<void()> && action);

			void setChromeEnabled(bool);
			bool getChromeEnabled() const;
		protected:
			ElementGroupPtr toolBar;
			bool chromeEnabled = true; // can be overriden by global setting
		};

		PanelPtr makeBlank(std::string caption = "");
	}
	typedef vector<PanelPtr> PanelSet;
	typedef vector<PanelPtr>::iterator PanelIterator;
}
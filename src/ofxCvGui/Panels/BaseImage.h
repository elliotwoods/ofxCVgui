#pragma once
#include "ofxCvGui/Panels/Base.h"
#include "ofxLiquidEvent.h"

namespace ofxCvGui {
	enum ImageZoomState { ZoomX1, ZoomX10, Stretch, Fit };

	struct DrawImageArguments {
		DrawArguments drawArguments;
		ImageZoomState zoomState;
		ofRectangle drawBounds;
	};
	
	namespace Panels {
		class OFXCVGUI_API_ENTRY BaseImage : public Base {
		protected:
			BaseImage();
			virtual ~BaseImage();
		public:
			ofxLiquidEvent<DrawImageArguments> onDrawImage;
			
			void update();

			ImageZoomState getImageZoomState() const;
			void setImageZoomState(ImageZoomState);

			void setMirror(bool);
			bool getMirror() const;

			glm::mat4x4 getPanelToImageTransform() const;

			float getZoomFactor() const;

			const glm::vec2& getScroll() const;
			void setScroll(const glm::vec2&);
		protected:
            
			virtual void drawImage(float width, float height) = 0;
            virtual float getImageWidth() const = 0;
            virtual float getImageHeight() const = 0;
            void nudgeZoom(KeyboardArguments &);
			void clampScroll();

			glm::vec2 scroll; // in image pixel coordinates
			ImageZoomState zoomState = ImageZoomState::Fit;
			bool mirror = false;
			ElementPtr zoomBox;
		};
	}
}
#pragma once
#include "ofRectangle.h"
#include "ofEvents.h"
#include "ofTypes.h"
#include "ofMatrix4x4.h"

namespace ofxCvGui {
	//-------------
	class Element;

	//----------
    struct UpdateArguments {
        
    };
    
	//----------
	struct DrawArguments {
		bool chromeEnabled;
		ofRectangle naturalBounds; /// bounds within parent as stored locally. before scaling
		ofMatrix4x4 globalTransform; /// warning : global properties can be relative to an fbo if within a cached view element
		float globalScale;
		ofRectangle localBounds;
		ofRectangle globalBounds;
	};

	//----------
    class InputArguments {
    public:
        InputArguments(const shared_ptr<void>& currentPanel) : currentPanel(currentPanel) { }
        const shared_ptr<void> currentPanel;
        
        bool checkCurrentPanel(void * panel) {
            return currentPanel.get() == panel;
        }
    };
    
	//----------
	class MouseArguments : public InputArguments {
    public:
        enum Action {
            Pressed = 1 << 0,
			Released = 1 << 1,
			Moved = 1 << 2,
			Dragged = 1 << 3,
			DoubleClick = 1 << 4
        };
        
		MouseArguments(); //local
		MouseArguments(const ofMouseEventArgs& mouseArgs, Action action, const ofRectangle& rectangle, const shared_ptr<void>& currentPanel, void * owner, const ofVec2f& cached = ofVec2f()); ///global
		
		bool isLocal() const; 
		bool isTaken() const;

		/// If the click is local and available then take it and return true, else return false
		bool takeMousePress(void * element);
		bool takeMousePress(shared_ptr<Element>);

		/// Not taken, or is something other than a mouse down action
		bool mightStillBeUseful() const;

		/// Only use this is you know what you're doing. This is for manually marking a mouse take
		void forceMouseTake(void * element);

		bool isDragging(void * element) const;
		bool isDragging(shared_ptr<Element>) const;
		bool isDoubleClicked(void * element) const;
		bool isDoubleClicked(shared_ptr<Element>) const;

		void * getOwner() const;

		Action action;
		int button;
		ofVec2f global;
		ofVec2f local;
		ofVec2f localNormalised; ///<Texture coordinates
        ofVec2f movement;

		friend ostream& operator<<(ostream&, const MouseArguments &);
	protected:
		void * takenBy;
	};

	//----------
	class KeyboardArguments : public InputArguments {
    public:
        enum Action {
            Pressed, Released
        };
        
		KeyboardArguments(const ofKeyEventArgs& keyboardArgs, Action action, shared_ptr<void> currentPanel);
        
		const Action action;
		const int key;
	};
	
	//----------
	class BoundsChangeArguments {
	public:
		BoundsChangeArguments(const ofRectangle & bounds);
		const ofRectangle bounds;
		const ofRectangle localBounds;
	};

	//----------
	class FilesDraggedArguments {
	public:
		FilesDraggedArguments(const ofVec2f & localPosition, const ofVec2f & globalPosition, const vector<string> & files);
		const ofVec2f localPosition;
		const ofVec2f globalPosition;
		const vector<string> files;
	};

	//----------
	struct ZoomChangeArguments {
		float oldZoom;
		float newZoom;
	};
}
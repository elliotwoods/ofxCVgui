#pragma once

#include "ofxCvGui/Panels/Inspector.h"

#include "ElementGroup.h"
#include "ofxSingleton.h"

namespace ofxCvGui {
	struct InspectArguments {
		shared_ptr<Panels::Inspector> inspector;
	};

	/// inherit this class if your object is inspectable
	class OFXCVGUI_API_ENTRY IInspectable {
	public:
		virtual ~IInspectable() { }
		/// Listen to this event if you want to populate the insspector when selected 
		ofxLiquidEvent<InspectArguments> onPopulateInspector;
		bool isBeingInspected() const;
	};

	/// The inspect controller determines what is being inspected and fires events
	///  when the target changes (e.g. these events are subscribed to by an Inspector).
	class OFXCVGUI_API_ENTRY InspectController : public ofxSingleton::Singleton<InspectController> {
	public:
		InspectController();

		void update();

		/// The first person to call this per frame wins the inspector.
		/// This is to reflect the inverse call order of mouse action trees (top first)
		void inspect(shared_ptr<IInspectable>);
		void inspectWithOwnership(shared_ptr<IInspectable>);

		/// Go backwards through history
		void back();

		/// Refresh whatever is currently being inspected
		void refresh();

		/// Refresh if we're inspecting this
		void refresh(IInspectable *);

		void clear();
		shared_ptr<IInspectable> getTarget() const;

		void addToInspector(ElementPtr);

		/// Tell all inspectors to attempt to maximise on their next update frame
		void maximise();

		void setInspectorLocked(bool);
		bool getInspectorLocked() const;

		size_t getHistorySize() const;
		size_t getHistoryMaxSize() const;
		void setHistoryMaxSize(size_t); // If you are making an 'insepctor stack', then make sure the history size is large enough for the stack size (and avoid recursive stacks)

		ofxLiquidEvent<shared_ptr<IInspectable>> onTargetChange;
		ofxLiquidEvent<ElementPtr> onAddWidget;
		ofxLiquidEvent<void> onMaximise;

		///this is actually triggered from the individual inspectors
		ofxLiquidEvent<InspectArguments> onClear;
	protected:
		weak_ptr<IInspectable> currentTarget;
		weak_ptr<IInspectable> inspectThisFrame;
		set<shared_ptr<IInspectable>> ownedInspectables;

		bool hasTarget = false;
		bool clearThisFrame = false;
		bool goBackThisFrame = false;
		bool refreshThisFrame = false;
		bool inspectorLocked = false;

		std::vector<weak_ptr<IInspectable>> history;
		size_t historyMaxSize = 30;
	};

	void OFXCVGUI_API_ENTRY inspect(shared_ptr<IInspectable>);
	void OFXCVGUI_API_ENTRY inspectWithOwnership(shared_ptr<IInspectable>);

	bool OFXCVGUI_API_ENTRY isBeingInspected(shared_ptr<IInspectable>);
	bool OFXCVGUI_API_ENTRY isBeingInspected(IInspectable &);
	bool OFXCVGUI_API_ENTRY isBeingInspected(IInspectable *);

	void OFXCVGUI_API_ENTRY addToInspector(ofxCvGui::ElementPtr);

	void OFXCVGUI_API_ENTRY refreshInspector(IInspectable *);
}
#include "pch_ofxCvGui.h"

namespace ofxCvGui {
	using namespace Widgets;

	namespace Panels {
		//---------
		Inspector::Inspector() {
			InspectController::X().onTargetChange.addListener([this](shared_ptr<IInspectable> target) {
				this->clear();
				if (target) {
					InspectArguments args;
					args.inspector = this->shared_from_this();
					target->onPopulateInspector.notifyListenersInReverse(args); // reverse so inherited parameters go to the bottom
					this->addSpacer();
					this->arrange();
				}
			}, this);

			InspectController::X().onAddWidget.addListener([this](ElementPtr element) {
				this->add(element);
				this->arrange();
			}, this);

			InspectController::X().onMaximise.addListener([this]() {
				ofxCvGui::Controller::X().setMaximised(this->shared_from_this());
			}, this);

			this->titleEnabled = true;
			this->setCaption("Inspector");
		
			this->clear(false);
		}

		//---------
		Inspector::~Inspector() {
			InspectController::X().onTargetChange.removeListeners(this);
			InspectController::X().onAddWidget.removeListeners(this);
			InspectController::X().onMaximise.removeListeners(this);
		}

		//---------
		void Inspector::clear(bool notifyListeners) {
			Scroll::clear();
			if (this->titleEnabled) {
				this->elements->add(shared_ptr<Title>(new Title(this->getCaption(), Title::Level::H1)));
			}
			if(notifyListeners) {
				InspectArguments inspectArguments = { this->shared_from_this() };
				InspectController::X().onClear.notifyListeners(inspectArguments);
			}
			this->arrange();
		}

		//---------
		bool Inspector::getTitleEnabled() const {
			return this->titleEnabled;
		}

		//---------
		void Inspector::setTitleEnabled(bool titleEnabled) {
			this->titleEnabled = titleEnabled;
		}

		//----------
		shared_ptr<Panels::Inspector> makeInspector() {
			return shared_ptr<Panels::Inspector>(new Panels::Inspector());
		}
	}
}

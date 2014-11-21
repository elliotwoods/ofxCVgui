#include "Inspector.h"
#include "../Widgets/Title.h"
#include "../InspectController.h"

namespace ofxCvGui {
	using namespace Widgets;

	namespace Panels {
		//---------
		Inspector::Inspector() {
			InspectController::X().onTargetChange.addListener([this](shared_ptr<IInspectable> target) {
				this->clear();
				if (target) {
					target->populateInspector(this->elements);
					this->arrange();
				}
			}, this);

			InspectController::X().onAddWidget.addListener([this](ElementPtr element) {
				this->add(element);
				this->arrange();
			}, this);

			this->clear();
		}

		//---------
		Inspector::~Inspector() {
			InspectController::X().onTargetChange.removeListeners(this);
			InspectController::X().onAddWidget.removeListeners(this);
		}

		//---------
		void Inspector::clear() {
			Scroll::clear();
			this->elements->add(shared_ptr<Title>(new Title("Inspector", Title::Level::H1)));
			InspectController::X().onClear.notifyListeners(this->elements);
			this->arrange();
		}
	}
}

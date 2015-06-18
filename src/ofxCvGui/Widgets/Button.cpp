#include "Button.h"

namespace ofxCvGui {
	namespace Widgets {
		//----------
		Button::Button(string caption, char hotKey) : Toggle() {
			this->init(caption, hotKey);
		}

		//----------
		Button::Button(string caption, std::function<void ()> action, char hotKey) {
			this->init(caption, hotKey);
			this->onHit += [action] (EventArgs &) {
				action();
			};
		}

		//----------
		void Button::init(string caption, char hotKey) {
			if (hotKey != 0) {
				caption = caption + " [" + Utils::makeString(hotKey) + "]";

				this->onKeyboard += [this, hotKey] (ofxCvGui::KeyboardArguments & keyArgs) {
					if (keyArgs.action == ofxCvGui::KeyboardArguments::Action::Pressed) {
						if (keyArgs.key == hotKey) {
							EventArgs dummyArgs;
							this->onHit(dummyArgs);
							this->hitValue.set(false);
						}
					}
				};
			}

			this->hitValue.set(caption, false);
			Toggle::setParameter(this->hitValue);

			this->onMouseReleased += [this](MouseArguments & args) {
				EventArgs dummyArgs;
				this->onHit(dummyArgs);
				this->needsToDrop = true;
			};
			this->onUpdate += [this](UpdateArguments & args) {
				if (this->needsToDrop) {
					this->hitValue.set(false);
					this->needsToDrop = false;
				}
			};

			this->needsToDrop = false;
		}
	}
}
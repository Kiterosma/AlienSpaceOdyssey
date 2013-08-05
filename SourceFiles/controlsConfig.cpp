#include "controlsConfig.h"

using namespace std;

ControlsConfig::ControlsConfig()
{

}

ControlsConfig::ControlsConfig(Application* a, Mode m):application(a), mode(m)
{

}

void ControlsConfig::setMode(Mode m)
{
	mode = m;
}

ControlsConfig::Mode ControlsConfig::getMode()
{
	return mode;
}

bool ControlsConfig::fileExists(std::string path)
{
	ifstream save(path);
	return 0!=save;
}

bool ControlsConfig::setKey(std::string function, sf::Keyboard::Key button)
{
	if(mode==KeyboardMouse)
	{
		std::string previousFunction = functions[keyToString(button)];
		keyboard[previousFunction] = sf::Keyboard::Unknown;
		functions[keyToString(button)] = function;

		if(keyboard.count(function)>0)
		{
			std::unordered_map<std::string,sf::Keyboard::Key>::iterator it = keyboard.find(function);
			keyboard.erase(it);
		}

		mouse[function] = sf::Mouse::ButtonCount;

		std::pair<std::string, sf::Keyboard::Key> p(function, button);
		keyboard.insert(p);
		return true;
	}

	return false;
}


sf::Keyboard::Key ControlsConfig::getKey(std::string function)
{
	return keyboard[function]; //make sure that this doesn't have unwanted behavior when "function" is not already mapped.
}

std::string ControlsConfig::keyToString(sf::Keyboard::Key key)
{
	switch(key)
	{
	case sf::Keyboard::A: return "A";
		break;
	case sf::Keyboard::B: return "B";
		break;
	case sf::Keyboard::C: return "C";
		break;
	case sf::Keyboard::D: return "D";
		break;
	case sf::Keyboard::E: return "E";
		break;
	case sf::Keyboard::F: return "F";
		break;
	case sf::Keyboard::G: return "G";
		break;
	case sf::Keyboard::H: return "H";
		break;
	case sf::Keyboard::I: return "I";
		break;
	case sf::Keyboard::J: return "J";
		break;
	case sf::Keyboard::K: return "K";
		break;
	case sf::Keyboard::L: return "L";
		break;
	case sf::Keyboard::M: return "M";
		break;
	case sf::Keyboard::N: return "N";
		break;
	case sf::Keyboard::O: return "O";
		break;
	case sf::Keyboard::P: return "P";
		break;
	case sf::Keyboard::Q: return "Q";
		break;
	case sf::Keyboard::R: return "R";
		break;
	case sf::Keyboard::S: return "S";
		break;
	case sf::Keyboard::T: return "T";
		break;
	case sf::Keyboard::U: return "U";
		break;
	case sf::Keyboard::V: return "V";
		break;
	case sf::Keyboard::W: return "W";
		break;
	case sf::Keyboard::X: return "X";
		break;
	case sf::Keyboard::Y: return "Y";
		break;
	case sf::Keyboard::Z: return "Z";
		break;
	case sf::Keyboard::Num0: return "0";
		break;
	case sf::Keyboard::Num1: return "1";
		break;
	case sf::Keyboard::Num2: return "2";
		break;
	case sf::Keyboard::Num3: return "3";
		break;
	case sf::Keyboard::Num4: return "4";
		break;
	case sf::Keyboard::Num5: return "5";
		break;
	case sf::Keyboard::Num6: return "6";
		break;
	case sf::Keyboard::Num7: return "7";
		break;
	case sf::Keyboard::Num8: return "8";
		break;
	case sf::Keyboard::Num9: return "9";
		break;
	case sf::Keyboard::LControl: return "Left Control";
		break;
	case sf::Keyboard::LShift: return "Left Shift";
		break;
	case sf::Keyboard::LAlt: return "Left Alt";
		break;
	case sf::Keyboard::RControl: return "Right Control";
		break;
	case sf::Keyboard::RShift: return "Right Shift";
		break;
	case sf::Keyboard::RAlt: return "Right Alt";
		break;
	case sf::Keyboard::Menu: return "Menu";
		break;
	case sf::Keyboard::LBracket: return "[";
		break;
	case sf::Keyboard::RBracket: return "]";
		break;
	case sf::Keyboard::SemiColon: return ";";
		break;
	case sf::Keyboard::Comma: return ",";
		break;
	case sf::Keyboard::Period: return ".";
		break;
	case sf::Keyboard::Quote: return "\"";
		break;
	case sf::Keyboard::Slash: return "/";
		break;
	case sf::Keyboard::BackSlash: return "\\";
		break;
	case sf::Keyboard::Tilde: return "~";
		break;
	case sf::Keyboard::Equal: return "=";
		break;
	case sf::Keyboard::Dash: return "-";
		break;
	case sf::Keyboard::Space: return "Space";
		break;
	case sf::Keyboard::Return: return "Enter";
		break;
	case sf::Keyboard::BackSpace: return "Backspace";
		break;
	case sf::Keyboard::Tab: return "Tab";
		break;
	case sf::Keyboard::PageUp: return "Page Up";
		break;
	case sf::Keyboard::PageDown: return "Page Down";
		break;
	case sf::Keyboard::End: return "End";
		break;
	case sf::Keyboard::Home: return "Home";
		break;
	case sf::Keyboard::Insert: return "Insert";
		break;
	case sf::Keyboard::Delete: return "Delete";
		break;
	case sf::Keyboard::Add: return "+ (Numpad)";
		break;
	case sf::Keyboard::Subtract: return "- (Numpad)";
		break;
	case sf::Keyboard::Multiply: return "* (Numpad)";
		break;
	case sf::Keyboard::Divide: return "/ (Numpad)";
		break;
	case sf::Keyboard::Left: return "Left Arrow";
		break;
	case sf::Keyboard::Right: return "Right Arrow";
		break;
	case sf::Keyboard::Up: return "Up Arrow";
		break;
	case sf::Keyboard::Down: return "Down Arrow";
		break;
	case sf::Keyboard::Numpad0: return "0 (Numpad)";
		break;
	case sf::Keyboard::Numpad1: return "1 (Numpad)";
		break;
	case sf::Keyboard::Numpad2: return "2 (Numpad)";
		break;
	case sf::Keyboard::Numpad3: return "3 (Numpad)";
		break;
	case sf::Keyboard::Numpad4: return "4 (Numpad)";
		break;
	case sf::Keyboard::Numpad5: return "5 (Numpad)";
		break;
	case sf::Keyboard::Numpad6: return "6 (Numpad)";
		break;
	case sf::Keyboard::Numpad7: return "7 (Numpad)";
		break;
	case sf::Keyboard::Numpad8: return "8 (Numpad)";
		break;
	case sf::Keyboard::Numpad9: return "9 (Numpad)";
		break;
	case sf::Keyboard::Pause: return "Pause";
		break;

	default: return "Unbound";
	}
}

bool ControlsConfig::setMouseButton(std::string function, sf::Mouse::Button button)
{
	if(mode==KeyboardMouse)
	{
		std::string previousFunction = functions[mouseToString(button)];
		mouse[previousFunction] = sf::Mouse::ButtonCount;
		functions[mouseToString(button)] = function;

		if(mouse.count(function)>0)
		{
			std::unordered_map<std::string,sf::Mouse::Button>::iterator it = mouse.find(function);
			mouse.erase(it);
		}

		keyboard[function] = sf::Keyboard::Unknown;

		std::pair<std::string, sf::Mouse::Button> p(function, button);
		mouse.insert(p);
		return true;
	}

	return false;
}

sf::Mouse::Button ControlsConfig::getMouseButton(std::string function)
{
	return mouse[function]; //make sure that this doesn't have unwanted behavior when  "function" is not already mapped.
}

std::string ControlsConfig::mouseToString(sf::Mouse::Button button)
{
	switch(button)
	{
	case sf::Mouse::Left: return "Left Mouse Button";
		break;
	case sf::Mouse::Right: return "Right Mouse Button";
		break;
	case sf::Mouse::Middle: return "Middle Mouse Button";
		break;
	case sf::Mouse::XButton1: return "Mouse Button 4";
		break;
	case sf::Mouse::XButton2: return "Mouse Button 5";
		break;

	default: return "Unbound";
	}
}

bool ControlsConfig::setAxis(std::string function, sf::Joystick::Axis button)
{
	if(mode==Joystick)
	{
		if(joystickAxes.count(function)>0)
		{
			std::unordered_map<std::string,sf::Joystick::Axis>::iterator it = joystickAxes.find(function);
			joystickAxes.erase(it);
		}

		std::pair<std::string, sf::Joystick::Axis> p(function, button);
		joystickAxes.insert(p);
		return true;
	}

	return false;
}

sf::Joystick::Axis ControlsConfig::getAxis(std::string function)
{
	return joystickAxes[function]; //make sure that this doesn't have unwanted behavior when  "function" is not already mapped.
}

std::string ControlsConfig::axisToString(sf::Joystick::Axis axis)
{
	switch(axis)
	{
	case sf::Joystick::X: return "X Axis";
		break;
	case sf::Joystick::Y: return "Y Axis";
		break;
	case sf::Joystick::Z: return "Z Axis";
		break;
	case sf::Joystick::R: return "R Axis";
		break;
	case sf::Joystick::U: return "U Axis";
		break;
	case sf::Joystick::V: return "V Axis";
		break;
	case sf::Joystick::PovX: return "PovX Axis";
		break;
	case sf::Joystick::PovY: return "PovY Axis";
		break;

	default: return "Unbound";
	}
}

bool ControlsConfig::setJoystickButton(std::string function, unsigned int button)
{
	if(mode==Joystick)
	{
		if(joystickButtons.count(function)>0)
		{
			std::unordered_map<std::string, unsigned int>::iterator it = joystickButtons.find(function);
			joystickButtons.erase(it);
		}

		std::pair<std::string, unsigned int> p(function, button);
		joystickButtons.insert(p);
		return true;
	}

	return false;
}

unsigned int ControlsConfig::getJoystickButton(std::string function)
{
	return joystickButtons[function]; //make sure that this doesn't have unwanted behavior when "function" is not already mapped.
}

std::string ControlsConfig::buttonToString(unsigned int button)
{
	std::ostringstream result;
	result<<button;
	return result.str();
}

void ControlsConfig::revertToDefault()
{
	mode = KeyboardMouse;

	keyboard.clear();
	mouse.clear();
	joystickAxes.clear();
	joystickButtons.clear();

	setKey("Move Up", sf::Keyboard::W);
	setKey("Move Down", sf::Keyboard::S);
	setKey("Move Left", sf::Keyboard::A);
	setKey("Move Right", sf::Keyboard::D);
	setMouseButton("Shoot", sf::Mouse::Left);
}

void ControlsConfig::readFromFile(std::string path)
{
	std::ifstream save(path);
	char* curr = new char[15];

	while(save.good())
	{
		save.getline(curr,15);
		std::string line(curr);
		if(line=="") break;
		size_t mid = line.find("=");
		char type = line[mid+1];
		std::string func = line.substr(0,mid);
		std::string rhs = line.substr(mid+2, line.length()-mid-2);

//		cout<<func<<"="<<type<<rhs<<endl;

		if(type=='k' && rhs!="-1")
		{
			sf::Keyboard::Key button = toButton<sf::Keyboard::Key>(rhs);
			setKey(func, button);
		}
		else if(type=='m' && rhs!="5")
		{
			sf::Mouse::Button button = toButton<sf::Mouse::Button>(rhs);
			setMouseButton(func, button);
		}
		else if(type=='a' /*some conditional regarding rhs*/)
		{
			sf::Joystick::Axis button = toButton<sf::Joystick::Axis>(rhs);
			setAxis(func, button);
		}
		else if(type=='b' /*some conditional regarding rhs*/)
		{
			unsigned int button = toButton<unsigned int>(rhs);
			setJoystickButton(func, button);
		}
	}
	delete[] curr;
}

void ControlsConfig::writeToFile(std::string path)
{
	std::unordered_map<std::string, sf::Keyboard::Key>::iterator k = keyboard.begin();
	std::unordered_map<std::string, sf::Mouse::Button>::iterator m = mouse.begin();
	std::unordered_map<std::string, sf::Joystick::Axis>::iterator a = joystickAxes.begin();
	std::unordered_map<std::string, unsigned int>::iterator b = joystickButtons.begin();

	std::ofstream save(path);

	while(save.good() && !(k==keyboard.end() && m==mouse.end() && a==joystickAxes.end() && b==joystickButtons.end()))
	{
		if(k!=keyboard.end())
		{
			std::pair<std::string, sf::Keyboard::Key> p = *k;
			save<<p.first<<"=k";
			save<<toString<sf::Keyboard::Key>(p.second)<<std::endl;
			k++;
		}
		else if(m!=mouse.end())
		{
			std::pair<std::string, sf::Mouse::Button> p = *m;
			save<<p.first<<"=m";
			save<<toString<sf::Mouse::Button>(p.second)<<std::endl;
			m++;
		}
		else if(a!=joystickAxes.end())
		{
			std::pair<std::string, sf::Joystick::Axis> p = *a;
			save<<p.first<<"=a";
			save<<toString<sf::Joystick::Axis>(p.second)<<std::endl;
			a++;
		}
		else if(b!=joystickButtons.end())
		{
			std::pair<std::string, unsigned int> p = *b;
			save<<p.first<<"=b";
			save<<toString<unsigned int>(p.second)<<std::endl;
			b++;
		}
	}
}

template <typename T>
T ControlsConfig::toButton(std::string s)
{
	int i = atoi(s.c_str());
	return static_cast<T>(i);
}

template <typename T>
std::string ControlsConfig::toString(T button)
{
	std::ostringstream result;
	result<<button;
	return result.str();
}
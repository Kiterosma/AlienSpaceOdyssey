#ifndef CONTROLSCONFIG_H
#define CONTROLSCONFIG_H

#include <unordered_map>
#include <SFML\Graphics.hpp>
#include <fstream>
#include <sstream>

class Application;

class ControlsConfig
{
public:
	enum Mode{KeyboardMouse, Joystick};

	ControlsConfig();
	ControlsConfig(Application* a, Mode m);
	/*
	Completely overwrites any existing files with the same name, saving the current controls configuration to the file.
	*/
	void writeToFile(std::string path);
	/*
	Reads controls configuration from an existing file so that it can be displayed and modified.
	*/
	void readFromFile(std::string path);
	/*
	Makes the state of the config object revert to default controls. Does not write to save file. Only for keyboard and mouse
	controls.
	*/
	void revertToDefault();

	bool fileExists(std::string path);

	void setMode(Mode m);

	Mode getMode();

	/*
	Maps the key with the given function. If the mode is not appropriate, no action will be performed and the method returns false.
	Otherwise, it returns true.
	*/
	bool setKey(std::string function, sf::Keyboard::Key button);

	/*
	Returns the key for the given function.
	*/
	sf::Keyboard::Key getKey(std::string function);
	static std::string keyToString(sf::Keyboard::Key key);

	/*
	Maps the mouse button with the given function. If the mode is not appropriate, no action will be performed and the 
	method returns false. Otherwise, it returns true.
	*/
	bool setMouseButton(std::string function, sf::Mouse::Button button);

	/*
	Returns the mouse button for the given function.
	*/
	sf::Mouse::Button getMouseButton(std::string function);
	static std::string mouseToString(sf::Mouse::Button button);

	/*
	Maps the axis with the given function. If the mode is not appropriate, no action will be performed and the method returns false.
	Otherwise, it returns true.
	*/
	bool setAxis(std::string function, sf::Joystick::Axis button);

	/*
	Returns the axis for the given function.
	*/
	sf::Joystick::Axis getAxis(std::string function);
	static std::string axisToString(sf::Joystick::Axis axis);

	/*
	Maps the joystick button with the given function. If the mode is not appropriate, no action will be performed and the method 
	returns false. Otherwise, it returns true.
	*/
	bool setJoystickButton(std::string function, unsigned int button);

	/*
	Returns the joystick button for the given function.
	*/
	unsigned int getJoystickButton(std::string function);
	static std::string buttonToString(unsigned int button);

private:
	std::unordered_map<std::string, sf::Keyboard::Key> keyboard;
	std::unordered_map<std::string, sf::Mouse::Button> mouse;
	std::unordered_map<std::string, sf::Joystick::Axis> joystickAxes;
	std::unordered_map<std::string, unsigned int> joystickButtons; //an unsigned int is used to determine which button is pressed.

	std::unordered_map<std::string, std::string> functions; //used to find if a certain button has already been mapped

	Application* application;
	Mode mode;

	template <typename T>
	T toButton(std::string s);

	template <typename T>
	std::string toString(T button);

};

#endif
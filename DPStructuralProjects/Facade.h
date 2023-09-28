#pragma once
#include <iostream>

class TextEditor
{
public:
	void CreateCode(std::string& code)
	{
		code = "new.cpp";
		std::cout << "Create code " << code << "\n";
	}

	std::string& Save(std::string& code)
	{
		code = "prog.cpp";
		std::cout << "Save code " << code << "\n";

		return code;
	}
};

class Compiller
{
public:
	std::string Compile(std::string code)
	{
		std::string cpu_code = code + ".exe";
		std::cout << "Compile code to execute file " << cpu_code << "\n";

		return cpu_code;
	}
};

class Debugger
{
	std::string code;
public:
	//Debugger() {}

	std::string& Code() { return code; }

	void Debug()
	{
		code = "new_" + code;
		std::cout << "Debugging code " << code << "\n";
	}

	std::string Save() 
	{
		std::cout << "Save debug code " << code << "\n";
		return code;
	}
};

class RunTime
{
public:
	void Execute(std::string& app)
	{
		std::cout << "Execute app " << app << "\n";
	}

	int Finish(std::string& app)
	{
		std::cout << "Finish app " << app << "\n";
		return 0;
	}
};


class VisualStudioFacade
{
	TextEditor* editor;
	Compiller* compiller;
	Debugger* debugger;
	RunTime* runtime;

	std::string code;
	std::string app;
public:
	VisualStudioFacade(TextEditor* editor,
		Compiller* compiller,
		Debugger* debugger,
		RunTime* runtime)
			: editor{ editor },
			compiller{ compiller },
			debugger{ debugger },
			runtime{ runtime } {};
	
	void Start()
	{
		editor->CreateCode(code);
		code = editor->Save(code);

		app = compiller->Compile(code);
		
		debugger->Code() = app;
		debugger->Debug();
		app = debugger->Save();

		app = compiller->Compile(app);

		runtime->Execute(app);
	}

	void Finish()
	{
		int code = runtime->Finish(app);
		std::cout << "App finish. Error code: " << code << "\n";
	}

};

#pragma once
#include <iostream>

class IMessage
{
protected:
	std::string text;
	std::string from;
	std::string to;
public:
	std::string& Text() { return text; }
	std::string& From() { return from; }
	std::string& To() { return to; }

	virtual void Send() = 0;
};

class MessangerMessage : public IMessage
{
	std::string sticker;
public:
	MessangerMessage() { sticker = ":-)"; }

	std::string& Sticker() { return sticker; }

	void Send() override
	{
		std::cout << "Messanger send from: " << from
			<< "\nto: " << to 
			<< "\ntext: " << text
			<< "\n" << sticker << "\n";
	}
};

class EmailMessage : public IMessage
{
	std::string subject;
public:
	EmailMessage() { subject = "my subject"; }

	std::string& Subject() { return subject; }

	void Send() override
	{
		std::cout << "Email send from: " << from
			<< "\nto: " << to 
			<< "\nsubject: " << subject
			<< "\ntext: " << text
			<< "\n";
	}
};

class IMessageDecorator : public IMessage
{
protected:
	IMessage* message;
public:
	IMessageDecorator(IMessage* message)
		: message{ message } {}
};

class FileMessage : public IMessageDecorator
{
	std::string file;
public:
	FileMessage(IMessage* message, std::string file)
		: IMessageDecorator(message), file { file } {};

	void Send() override
	{
		message->Send();
		std::cout << "accept file: " << file << "\n";
	}
};

class ContactMessage : public IMessageDecorator
{
	std::string contact;
public:
	ContactMessage(IMessage* message, std::string contact)
		: IMessageDecorator(message), contact{ contact } {};

	void Send() override
	{
		message->Send();
		std::cout << "with contact: " << contact << "\n";
	}
};
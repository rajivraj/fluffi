/*
Copyright 2017-2019 Siemens AG

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

Author(s): Thomas Riedmaier
*/

#include "stdafx.h"
#include "FLUFFILogHandler.h"

FLUFFILogHandler::FLUFFILogHandler() :
	errorMessages()
{
}

void FLUFFILogHandler::handle(const el::LogDispatchData* data) {
	if (data->logMessage()->level() == el::Level::Error) { //If it's an error message store it, so it can be collected later.
		addToMessageQueue(data->logMessage()->logger()->logBuilder()->build(data->logMessage(), false));
	}
}

void FLUFFILogHandler::addToMessageQueue(el::base::type::string_t&& logLine)
{
	std::unique_lock<std::mutex> mlock(m_mutex_);

	//Prevent overflow in case nobady collects the error messages
	if (errorMessages.size() > 1000) {
		errorMessages.pop_front();
	}

	errorMessages.push_back(logLine);
}

std::deque<std::string> FLUFFILogHandler::getAllMessages() {
	std::unique_lock<std::mutex> mlock(m_mutex_);

	std::deque<std::string> re = errorMessages;

	errorMessages.clear();

	return re;
}

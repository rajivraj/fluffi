/*
Copyright 2017-2020 Siemens AG

Permission is hereby granted, free of charge, to any person obtaining a
copy of this software and associated documentation files (the
"Software"), to deal in the Software without restriction, including without
limitation the rights to use, copy, modify, merge, publish, distribute,
sublicense, and/or sell copies of the Software, and to permit persons to whom the
Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be
included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT
SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR
OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
DEALINGS IN THE SOFTWARE.

Author(s): Thomas Riedmaier, Abian Blome
*/

#include "stdafx.h"
#include "FluffiBasicBlock.h"

FluffiBasicBlock::FluffiBasicBlock(uint64_t rva, int32_t moduleID) :
	m_moduleID(moduleID),
	m_rva(rva)
{
}

FluffiBasicBlock::FluffiBasicBlock(const BasicBlock& basicBlock) :
	m_moduleID(basicBlock.moduleid()),
	m_rva(basicBlock.rva())
{
}

FluffiBasicBlock::~FluffiBasicBlock()
{}

BasicBlock FluffiBasicBlock::getProtobuf() const
{
	BasicBlock protoBasicBlock{};
	protoBasicBlock.set_moduleid(m_moduleID);
	protoBasicBlock.set_rva(m_rva);

	return protoBasicBlock;
}

bool FluffiBasicBlock::operator< (const FluffiBasicBlock& rhs) const {
	if (this->m_moduleID == rhs.m_moduleID) {
		return this->m_rva < rhs.m_rva;
	}
	return this->m_moduleID < rhs.m_moduleID;
}

bool FluffiBasicBlock::operator== (const FluffiBasicBlock& rhs) const {
	return (this->m_rva == rhs.m_rva && this->m_moduleID == rhs.m_moduleID);
}

//
// SimplePanel.cpp
//
// $Id: //poco/Main/WebWidgets/src/SimplePanel.cpp#4 $
//
// Library: WebWidgets
// Package: WebGUI
// Module:  SimplePanel
//
// Copyright (c) 2007, Applied Informatics Software Engineering GmbH.
// and Contributors.
//
// Permission is hereby granted, free of charge, to any person or organization
// obtaining a copy of the software and accompanying documentation covered by
// this license (the "Software") to use, reproduce, display, distribute,
// execute, and transmit the Software, and to prepare derivative works of the
// Software, and to permit third-parties to whom the Software is furnished to
// do so, all subject to the following:
// 
// The copyright notices in the Software and this entire statement, including
// the above license grant, this restriction and the following disclaimer,
// must be included in all copies of the Software, in whole or in part, and
// all derivative works of the Software, unless such copies or derivative
// works are solely in the form of machine-executable object code generated by
// a source language processor.
// 
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT
// SHALL THE COPYRIGHT HOLDERS OR ANYONE DISTRIBUTING THE SOFTWARE BE LIABLE
// FOR ANY DAMAGES OR OTHER LIABILITY, WHETHER IN CONTRACT, TORT OR OTHERWISE,
// ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
// DEALINGS IN THE SOFTWARE.
//


#include "Poco/WebWidgets/SimplePanel.h"
#include "Poco/WebWidgets/Visitor.h"
#include "Poco/WebWidgets/XMLUtil.h"


namespace Poco {
namespace WebWidgets {


SimplePanel::SimplePanel(Poco::AutoPtr<Widget> ptr):
	_ptrWidget(ptr)
{
	_ptrWidget->setParent(this);
}


SimplePanel::SimplePanel(const Poco::XML::Element* pElem):
	Panel(pElem),
	_ptrWidget()
{
	poco_assert_dbg (pElem != 0); 
	std::vector<Poco::AutoPtr<Widget> > res = XMLUtil::getAllWidgets(pElem, this);
	if (res.size() != 1)
	{
		throw Poco::SyntaxException("A SimplePanel can only have one child!");
	}
	_ptrWidget = res[0];
	_ptrWidget->setParent(this);
}


SimplePanel::~SimplePanel()
{
}


void SimplePanel::preAccept(Visitor& v)
{
	v.preVisit(*this);
}


Poco::AutoPtr<Widget> SimplePanel::find(const std::string& id) const
{
	return Widget::find(getWidget(), id);
}


} } // namespace Poco::WebWidgets

#ifndef CPOLY_ITERATOR_H
#define CPOLY_ITERATOR_H
#include <C/Common/TRN_API_Config.hpp>
#include <C/Layout/TRN_ContentElement.h>

// All C++ standard library and internal header files must be inside these guards.
// C standard header files (e.g. stdio.h) are recommended to be outside of these guards.
#if TRN_ENABLE_HIDE_SYMBOL_DIRECTIVES
#pragma GCC visibility push(hidden)
#endif // TRN_ENABLE_HIDE_SYMBOL_DIRECTIVES

#include <SDF/NameTreeIterator.h>
#include <SDF/NumberTreeIterator.h>
#include <SDF/Obj.h>
#include <SDF/Name.h>
#include <SDF/SecurityManager.h>
#include <PDF/FieldIterator.h>
#include <PDF/PageIterator.h>
#include <PDF/GSChangesIterator.h>
#include <PDF/CharIterator.h>
#include <PDF/FontCharCodeIterator.h>
#include <FDF/FDFFieldIterator.h>
#include <PDF/DigitalSignatureFieldIterator.h>
#include <Layout/FlowDocument/ContentNodeIterator.h>

namespace trn{
using namespace SDF;
using namespace PDF;
using namespace FDF;
using namespace Layout;

class PolyIterator
{
public:
	virtual void Next()=0;
	virtual bool HasNext()=0;
	virtual TRN_ItrData GetCurrent()=0;

	//used in Java for select iterators
	//which store the data internally
	virtual TRN_ItrData GetPrev()
	{
		BASE_ASSERT(false, "GetPrev not defined!");
	}

	virtual void Assign(PolyIterator&)=0;
	virtual TRN_Iterator Clone()=0;
	virtual ~PolyIterator(){}
};


class PolyContentNodeIterator : public PolyIterator
{
public:
	PolyContentNodeIterator(ContentNodeIterator& i)  : m_itr(i)	{}
	PolyContentNodeIterator(const PolyContentNodeIterator& c) : m_itr(c.m_itr){}

	TRN_Iterator Clone()
	{ 
		return (TRN_Iterator)new PolyContentNodeIterator(*this);
	}

	void Next()
	{
		//increment the iterator
		++m_itr;
	}
	
	TRN_ItrData GetCurrent()
	{
		trn::Layout::iContentElement &content_element = m_itr.dereference();
		m_current.content_element = (TRN_ContentElement) &content_element;
		return (TRN_ItrData) &m_current;
	}

	bool HasNext()
	{
		return !m_itr.Done();
	}
	
	void Assign(PolyIterator& i)
	{
		PolyContentNodeIterator* j=dynamic_cast<PolyContentNodeIterator*>(&i);
		BASE_ASSERT(j,"Iterator types do not match.");
		m_itr=j->m_itr;
	}

	ContentNodeIterator m_itr;

	// This is a hack to return a ContentElement at the wrapper level.
	// The structure has the same layout as the wrapper class, so it can be
	// casted at the wrapper level. This follows the same pattern as in the
	// other iterators that a pointer to structure is returned where the
	// layout is known to be identical to the layout of the wrapper class.
	struct helper
	{
		helper() : content_element(nullptr) {}
		TRN_ContentElement content_element;
	} m_current;
};


class PolyPageIterator : public PolyIterator
{
public:
	PolyPageIterator(PageIterator& i, PageIterator& e)  : m_itr(i) , m_end(e) 
	{}
	PolyPageIterator(const PolyPageIterator& c) : m_itr(c.m_itr) , m_end(c.m_end)
	{}

	TRN_Iterator Clone()
	{ 
		return (TRN_Iterator)new PolyPageIterator(*this);
	}

	void Next()
	{
		//increment the iterator
		++m_itr;
	}
	TRN_ItrData GetCurrent()
	{
		return (TRN_ItrData)(&(*m_itr));
	}

	bool HasNext()
	{
		return (m_itr!=m_end);
	}
	void Assign(PolyIterator& i)
	{
		PolyPageIterator* j=dynamic_cast<PolyPageIterator*>(&i);
		BASE_ASSERT(j,"Iterator types do not match.");
		m_itr=j->m_itr;
		m_end=j->m_end;
	}

	PageIterator m_itr;
	PageIterator m_end;
};

class PolyFDFFieldIterator : public PolyIterator
{
public:
	PolyFDFFieldIterator(FDFFieldIterator& i, FDFFieldIterator& e)  : m_itr(i) , m_end(e) , m_data(FDFField(0,0))
	{}
	PolyFDFFieldIterator(const PolyFDFFieldIterator& c)  : m_itr(c.m_itr) , m_end(c.m_end) , m_data(FDFField(0,0))
	{}

	TRN_Iterator Clone()
	{ 
		return (TRN_Iterator)new PolyFDFFieldIterator(*this);
	}

	void Next()
	{
		m_data=*m_itr;
		//increment the iterator
		++m_itr;
	}
	TRN_ItrData GetCurrent()
	{
		return (TRN_ItrData)&(*m_itr);
	}
	TRN_ItrData GetPrev()
	{
		return (TRN_ItrData)&m_data;
	}

	bool HasNext()
	{
		return (m_itr!=m_end);
	}
	void Assign(PolyIterator& i)
	{
		PolyFDFFieldIterator* j=dynamic_cast<PolyFDFFieldIterator*>(&i);
		BASE_ASSERT(j,"Iterator types do not match.");
		m_itr=j->m_itr;
		m_end=j->m_end;
	}
	FDFFieldIterator m_itr;
	FDFFieldIterator m_end;
	FDFField m_data;
};

class PolyFieldIterator : public PolyIterator
{
public:
	PolyFieldIterator(FieldIterator& i, FieldIterator& e)  : m_itr(i) , m_end(e) , m_data(Field(0))
	{}
	PolyFieldIterator(const PolyFieldIterator& c)  : m_itr(c.m_itr) , m_end(c.m_end) , m_data(Field(0))
	{}

	TRN_Iterator Clone()
	{ 
		return (TRN_Iterator)new PolyFieldIterator(*this);
	}

	void Next()
	{
		m_data=*m_itr;
		//increment the iterator
		++m_itr;
	}
	TRN_ItrData GetCurrent()
	{
		return (TRN_ItrData)&(*m_itr);
	}
	TRN_ItrData GetPrev()
	{
		return (TRN_ItrData)&m_data;
	}

	bool HasNext()
	{
		return (m_itr!=m_end);
	}
	void Assign(PolyIterator& i)
	{
		PolyFieldIterator* j=dynamic_cast<PolyFieldIterator*>(&i);
		BASE_ASSERT(j,"Iterator types do not match.");
		m_itr=j->m_itr;
		m_end=j->m_end;
	}
	FieldIterator m_itr;
	FieldIterator m_end;
	Field m_data;
};

class PolyDigitalSignatureFieldIterator : public PolyIterator
{
public:
	PolyDigitalSignatureFieldIterator(DigitalSignatureFieldIterator& i, DigitalSignatureFieldIterator& e) : m_itr(i), m_end(e), m_data()
	{}
	PolyDigitalSignatureFieldIterator(const PolyDigitalSignatureFieldIterator& c) : m_itr(c.m_itr), m_end(c.m_end), m_data()
	{}

	TRN_Iterator Clone()
	{
		return (TRN_Iterator)new PolyDigitalSignatureFieldIterator(*this);
	}

	void Next()
	{
		m_data = *m_itr;
		//increment the iterator
		++m_itr;
	}
	TRN_ItrData GetCurrent()
	{
		return (TRN_ItrData)&(*m_itr);
	}
	TRN_ItrData GetPrev()
	{
		return (TRN_ItrData)&m_data;
	}

	bool HasNext()
	{
		return (m_itr != m_end);
	}
	void Assign(PolyIterator& i)
	{
		PolyDigitalSignatureFieldIterator* j = dynamic_cast<PolyDigitalSignatureFieldIterator*>(&i);
		BASE_ASSERT(j, "Iterator types do not match.");
		m_itr = j->m_itr;
		m_end = j->m_end;
	}
	DigitalSignatureFieldIterator m_itr;
	DigitalSignatureFieldIterator m_end;
	DigitalSignatureField m_data;
};

class PolyFontCharCodeIterator : public PolyIterator
{
public:
	PolyFontCharCodeIterator(FontCharCodeIterator& i, FontCharCodeIterator& e)  : m_itr(i) , m_end(e) 
	{
		if ( HasNext() )
			current = *m_itr;
	}
	PolyFontCharCodeIterator(const PolyFontCharCodeIterator& c) : m_itr(c.m_itr) , m_end(c.m_end)
	{
		if ( HasNext() )
			current = *m_itr;
	}

	TRN_Iterator Clone()
	{ 
		return (TRN_Iterator)new PolyFontCharCodeIterator(*this);
	}


	void Next()
	{
		//increment the iterator
		++m_itr;
		current=*m_itr;
	}
	TRN_ItrData GetCurrent()
	{
		return (TRN_ItrData)&current;
	}

	bool HasNext()
	{
		return (m_itr!=m_end);
	}
	void Assign(PolyIterator& i)
	{
		PolyFontCharCodeIterator* j=dynamic_cast<PolyFontCharCodeIterator*>(&i);
		BASE_ASSERT(j,"Iterator types do not match.");
		m_itr=j->m_itr;
		m_end=j->m_end;
	}
	FontCharCodeIterator m_itr;
	FontCharCodeIterator m_end;
	UInt32 current;
};


class PolyCharIterator : public PolyIterator
{
public:
	PolyCharIterator(CharIterator& i, CharIterator& e) : m_itr(i) , m_end(e) , m_data(CharData(0,0,0,0,0))
	{}
	PolyCharIterator(const PolyCharIterator& c) : m_itr(c.m_itr) , m_end(c.m_end) , m_data(CharData(0,0,0,0,0))
	{}

	TRN_Iterator Clone()
	{ 
		return (TRN_Iterator)new PolyCharIterator(*this);
	}

	void Next()
	{
		m_data=*m_itr;
		//increment the iterator
		++m_itr;
	}
	TRN_ItrData GetCurrent()
	{
		return (TRN_ItrData)&(*m_itr);
	}

	TRN_ItrData GetPrev()
	{
		return (TRN_ItrData)&m_data;
	}

	bool HasNext()
	{
		return (m_itr!=m_end);
	}
	void Assign(PolyIterator& i)
	{
		PolyCharIterator* j=dynamic_cast<PolyCharIterator*>(&i);
		BASE_ASSERT(j,"Iterator types do not match.");
		m_itr=j->m_itr;
		m_end=j->m_end;
	}
	CharIterator m_itr;
	CharIterator m_end;
	CharData m_data;
};

class PolyGSChangesIterator : public PolyIterator
{
public:
	PolyGSChangesIterator(GSChangesIterator& i, GSChangesIterator& e) : m_itr(i) , m_end(e)
	{
		if ( HasNext() )
			current = *m_itr;
		else
			current = -1; //invalid
	}

	PolyGSChangesIterator(const PolyGSChangesIterator& c) : m_itr(c.m_itr) , m_end(c.m_end)
	{
		if ( HasNext() )
			current = *m_itr;
		else
			current = -1; //invalid
	}

	TRN_Iterator Clone()
	{ 
		return (TRN_Iterator)new PolyGSChangesIterator(*this);
	}

	void Next()
	{
		//increment the iterator
		++m_itr;
		current=*m_itr;
	}
	TRN_ItrData GetCurrent()
	{
		return (TRN_ItrData)&current;
	}

	bool HasNext()
	{
		return (m_itr!=m_end);
	}
	void Assign(PolyIterator& i)
	{
		PolyGSChangesIterator* j=dynamic_cast<PolyGSChangesIterator*>(&i);
		BASE_ASSERT(j,"Iterator types do not match.");
		m_itr=j->m_itr;
		m_end=j->m_end;
	}
	GSChangesIterator m_itr;
	GSChangesIterator m_end;
	int current;
};

class PolySecHdlrInfoIter : public PolyIterator
{
public:
	PolySecHdlrInfoIter(const SDF::SecurityManager::SecIterator& i, const SDF::SecurityManager::SecIterator& e) : m_itr(i) , m_end(e)
	{}
	PolySecHdlrInfoIter(const PolySecHdlrInfoIter& c) : m_itr(c.m_itr) , m_end(c.m_end)
	{}

	TRN_Iterator Clone()
	{ 
		return (TRN_Iterator)new PolySecHdlrInfoIter(*this);
	}

	void Next()
	{
		//increment the iterator
		++m_itr;
	}

	TRN_ItrData GetCurrent()
	{
		m_current.m_name = m_itr->first.c_str();
		m_current.m_gui_name = m_itr->second.m_gui_name.c_str();
		m_current.m_factory_method = (TRN_PDFNetCreateSecurityHandler) m_itr->second.m_factory_method;
		return (TRN_ItrData)&m_current;
	}

	bool HasNext()
	{
		return (m_itr!=m_end);
	}
	void Assign(PolyIterator& i)
	{
		PolySecHdlrInfoIter* j=dynamic_cast<PolySecHdlrInfoIter*>(&i);
		BASE_ASSERT(j,"Iterator types do not match.");
		m_itr=j->m_itr;
		m_end=j->m_end;
	}

	SDF::SecurityManager::SecIterator m_itr, m_end;
	TRN_SecHdlrInfo m_current;
};



class DictPolyIterator
{
public:
	virtual void Next()=0;
	virtual bool HasNext()=0;
	virtual bool HasCurrent()=0;
	virtual Obj* GetKey()=0;
	virtual Obj* GetValue()=0;
	virtual void Assign(DictPolyIterator&)=0;
	virtual TRN_DictIterator Clone()=0;
	virtual ~DictPolyIterator(){}
};

class PolyNameTreeIterator : public DictPolyIterator
{
public:
	PolyNameTreeIterator(NameTreeIterator& i)  : itr(i) 
	{}
	PolyNameTreeIterator(const PolyNameTreeIterator& c) : itr(c.itr)
	{}

	TRN_DictIterator Clone()
	{ 
		return (TRN_DictIterator)new PolyNameTreeIterator(*this);
	}


	void Next()
	{
		//increment the iterator
		++itr;
	}
	Obj* GetKey()
	{
		return itr->Key();
	}
	Obj* GetValue()
	{
		return itr->Value();
	}

	bool HasNext()
	{
		return HasCurrent();
	}

	bool HasCurrent()
	{
		static NameTreeIterator end;
		return (itr!=end);
	}

	void Assign(DictPolyIterator& i)
	{
		PolyNameTreeIterator* j=dynamic_cast<PolyNameTreeIterator*>(&i);
		BASE_ASSERT(j,"Iterator types do not match.");
		itr=j->itr;
	}

	NameTreeIterator itr;

};

class PolyNumberTreeIterator : public DictPolyIterator
{
public:
	PolyNumberTreeIterator(NumberTreeIterator& i) 
		: itr(i) {}
	PolyNumberTreeIterator(const PolyNumberTreeIterator& c) 
		: itr(c.itr) {}

	TRN_DictIterator Clone()
	{ 
		return (TRN_DictIterator)new PolyNumberTreeIterator(*this);
	}

	void Next()
	{
		//increment the iterator
		++itr;
	}
	Obj* GetKey()
	{
		return itr->Key();
	}
	Obj* GetValue()
	{
		return itr->Value();
	}

	bool HasNext()
	{
		return HasCurrent();
	}

	bool HasCurrent()
	{
		static NumberTreeIterator end;
		return (itr!=end);
	}

	void Assign(DictPolyIterator& i)
	{
		PolyNumberTreeIterator* j=dynamic_cast<PolyNumberTreeIterator*>(&i);
		BASE_ASSERT(j,"Iterator types do not match.");
		itr=j->itr;
	}

	NumberTreeIterator itr;

};

class PolyObjDictIterator : public DictPolyIterator
{
public:
	PolyObjDictIterator(DictIterator& i, DictIterator& e) 
		: m_itr(i) , m_end(e) {}
	PolyObjDictIterator(const PolyObjDictIterator& c) 
		: m_itr(c.m_itr) , m_end(c.m_end) {}

	TRN_DictIterator Clone()
	{ 
		return (TRN_DictIterator)new PolyObjDictIterator(*this);
	}

	void Next()
	{
		//increment the iterator
		++m_itr;
	}
	Obj* GetKey()
	{
		return m_itr->first;
	}
	Obj* GetValue()
	{
		return m_itr->second;
	}

	bool HasNext()
	{
		return HasCurrent();
	}

	bool HasCurrent()
	{
		return (m_itr != m_end);
	}

	void Assign(DictPolyIterator& i)
	{
		PolyObjDictIterator* j=dynamic_cast<PolyObjDictIterator*>(&i);
		BASE_ASSERT(j,"Iterator types do not match.");
		m_itr=j->m_itr;
		m_end=j->m_end;
	}

	DictIterator m_itr;
	DictIterator m_end;

};

}

#if TRN_ENABLE_HIDE_SYMBOL_DIRECTIVES
#pragma GCC visibility pop
#endif // TRN_ENABLE_HIDE_SYMBOL_DIRECTIVES

#endif

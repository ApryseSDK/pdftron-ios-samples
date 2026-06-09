#pragma once

#include <C/Common/TRN_API_Config.hpp>

// All C++ standard library and internal header files must be inside these guards.
// C standard header files (e.g. stdio.h) are recommended to be outside of these guards.
#if TRN_ENABLE_HIDE_SYMBOL_DIRECTIVES
#pragma GCC visibility push(hidden)
#endif // TRN_ENABLE_HIDE_SYMBOL_DIRECTIVES
#include <Common/FlexVector.hpp>
#include <Common/AutoPtr.h>
#include <C/Common/TRN_Exception.hpp>
#include <C/Common/TRN_UString.h>
#include <C/PDF/TRN_DisallowedChange.h>
#include <PDF/DisallowedChange.h>
#include <C/PDF/TRN_CertificateStatus.h>
#include <PDF/CertificateStatus.h>
#include <C/Common/TRN_Vector.h>

namespace trn {

	class PolyVector
	{
	public:
		virtual TRN_UInt32 GetSize() = 0;
		virtual void* GetData() = 0;
		virtual void* GetAt(TRN_UInt32 pos) = 0;
		virtual void DestroyContents() = 0;
		virtual ~PolyVector() {}
	};

	/*
		PolyVectorByte
	*/
	class PolyVectorByte : public PolyVector
	{
	public:
		PolyVectorByte(AutoPtr< FlexVector<UChar> > vec);
		virtual TRN_UInt32 GetSize();
		virtual void* GetData();
		virtual void* GetAt(TRN_UInt32 pos);
		virtual void DestroyContents();
		AutoPtr< FlexVector<UChar> > m_vector;
	};

	inline PolyVectorByte::PolyVectorByte(AutoPtr< FlexVector<UChar> > vec) : m_vector(vec)
	{}
	
	inline TRN_UInt32 PolyVectorByte::GetSize()
	{
		TRN_UInt32 result = size32(m_vector->size());
		return result;
	}

	inline void* PolyVectorByte::GetData()
	{
		void* result = &m_vector->front();
		return result;
	}

	inline void* PolyVectorByte::GetAt(TRN_UInt32 pos)
	{
		void* result = &(*m_vector)[pos];
		return result;
	}

	inline void PolyVectorByte::DestroyContents()
	{}

	/* PolyVectorBase - a generic abstract base class for exposed vectors. 
	Add your member function specialization for DestroyElement below before using. */
	template <typename T> class PolyVectorBase : public PolyVector
	{
	public:
		virtual ~PolyVectorBase() {}

		virtual TRN_UInt32 GetSize() TRN_OVERRIDE
		{
			TRN_UInt32 result = size32(m_vector.size());
			return result;
		}
		virtual void* GetData() TRN_OVERRIDE
		{
			return &m_vector.front();
		}
		virtual void* GetAt(TRN_UInt32 pos) TRN_OVERRIDE
		{
			return m_vector[pos];
		}
		virtual void DestroyContents() TRN_OVERRIDE
		{
			for (UInt32 i = 0; i < m_vector.size(); ++i)
			{
				DestroyElement(&m_vector[i]);
			}
		}

		virtual void DestroyElement(void* in_element)
		{
			// Do nothing. Should be overridden/specialized if any special deletion is required.
		}

		FlexVector<T> m_vector;
	};

	template<> inline void PolyVectorBase<TRN_UString >::DestroyElement(void* in_trn_ustring)
	{
		TRN_UStringDestroy(*(TRN_UString*) in_trn_ustring);
	}

	template<> inline void PolyVectorBase<TRN_DisallowedChange>::DestroyElement(void* in_disallowed_change_ptr)
	{
		RefCountedPtr<PDF::DisallowedChange> tmp(*(PDF::DisallowedChange**)in_disallowed_change_ptr);
	}

	template<> inline void PolyVectorBase<TRN_CertificateStatus>::DestroyElement(void* in_ptr)
	{
		RefCountedPtr<PDF::CertificateStatus> tmp(*(PDF::CertificateStatus**)in_ptr);
	}

	template<> inline void PolyVectorBase<TRN_Vector*>::DestroyElement(void* in_ptr)
	{
		TRN_VectorDestroy(*(TRN_Vector*)in_ptr);
	}

	/*
		PolyVectorSeparation
	*/
	class PolyVectorSeparation : public PolyVector
	{
	public:
		virtual TRN_UInt32 GetSize();
		virtual void* GetData();
		virtual void* GetAt(TRN_UInt32 pos);
		virtual void DestroyContents();
		FlexVector<TRN_Separation> m_vector;
	};

	inline TRN_UInt32 PolyVectorSeparation::GetSize()
	{
		TRN_UInt32 result = size32(m_vector.size());
		return result;
	}

	inline void* PolyVectorSeparation::GetData()
	{
		return &m_vector.front();
	}

	inline void*  PolyVectorSeparation::GetAt(TRN_UInt32 pos)
	{
		return &m_vector[pos];
	}

	inline void SeparationDestroyContents(TRN_Separation* sep)
	{
		TRN_UStringDestroy(sep->separation_name);
		delete []sep->data;
	}
	
	inline void PolyVectorSeparation::DestroyContents()
	{
		for (UInt32 i = 0; i < m_vector.size(); ++i)
		{
			SeparationDestroyContents(&m_vector[i]);
		}
	}

	/*
	PolyVectorByteRange
    */
	class PolyVectorByteRange : public PolyVector
	{
	public:
		virtual TRN_UInt32 GetSize();
		virtual void* GetData();
		virtual void* GetAt(TRN_UInt32 pos);
		virtual void DestroyContents();
		FlexVector<TRN_ByteRange> m_vector;
	};

	inline TRN_UInt32 PolyVectorByteRange::GetSize()
	{
		TRN_UInt32 result = size32(m_vector.size());
		return result;
	}

	inline void* PolyVectorByteRange::GetData()
	{
		return &m_vector.front();
	}

	inline void*  PolyVectorByteRange::GetAt(TRN_UInt32 pos)
	{
		return &m_vector[pos];
	}

	inline void PolyVectorByteRange::DestroyContents()
	{
	}

	/*
	PolyVectorUInt32
	*/
	class PolyVectorUInt32 : public PolyVector
	{
	public:
		virtual TRN_UInt32 GetSize();
		virtual void* GetData();
		virtual void* GetAt(TRN_UInt32 pos);
		virtual void DestroyContents();
		FlexVector<TRN_UInt32> m_vector;
	};

	inline TRN_UInt32 PolyVectorUInt32::GetSize()
	{
		TRN_UInt32 result = size32(m_vector.size());
		return result;
	}

	inline void* PolyVectorUInt32::GetData()
	{
		return &m_vector.front();
	}

	inline void*  PolyVectorUInt32::GetAt(TRN_UInt32 pos)
	{
		return &m_vector[pos];
	}

	inline void PolyVectorUInt32::DestroyContents()
	{
	}

	/*
		PolyVectorApRefChange
	*/
	class PolyVectorApRefChange : public PolyVector
	{
	public:
		virtual TRN_UInt32 GetSize();
		virtual void* GetData();
		virtual void* GetAt(TRN_UInt32 pos);
		virtual void DestroyContents();
		FlexVector<TRN_ApRefChange> m_vector;
	};

	inline TRN_UInt32 PolyVectorApRefChange::GetSize()
	{
		TRN_UInt32 result = size32(m_vector.size());
		return result;
	}

	inline void* PolyVectorApRefChange::GetData()
	{
		return &m_vector.front();
	}

	inline void*  PolyVectorApRefChange::GetAt(TRN_UInt32 pos)
	{
		return &m_vector[pos];
	}

	inline void PolyVectorApRefChange::DestroyContents()
	{
	}

}

#if TRN_ENABLE_HIDE_SYMBOL_DIRECTIVES
#pragma GCC visibility pop
#endif // TRN_ENABLE_HIDE_SYMBOL_DIRECTIVES

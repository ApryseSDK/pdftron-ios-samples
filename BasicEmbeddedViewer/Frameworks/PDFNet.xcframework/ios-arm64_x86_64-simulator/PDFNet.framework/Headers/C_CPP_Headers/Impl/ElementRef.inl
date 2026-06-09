template <typename T>
template <typename TImpl>
inline ElementRef<T>::ElementRef(TImpl impl)
	: m_element(impl)
{
}

template <typename T>
inline ElementRef<T>::ElementRef()
	: m_element(0)
{
}

template <typename T>
inline T& ElementRef<T>::GetElement()
{
	BASE_ASSERT(IsValid(), "Trying to dereference an invalid ElementRef.");
	return m_element;
}

template <typename T>
inline bool ElementRef<T>::IsValid()
{
	return m_element.m_impl != 0;
}

template <typename T>
inline ElementRef<T>::operator void*()
{
	return m_element.m_impl;
}

template <typename T>
inline T* ElementRef<T>::operator->()
{
	BASE_ASSERT(IsValid(), "Trying to dereference an invalid ElementRef.");
	return &m_element;
}

template <typename T>
inline T& ElementRef<T>::operator*()
{
	BASE_ASSERT(IsValid(), "Trying to dereference an invalid ElementRef.");
	return m_element;
}

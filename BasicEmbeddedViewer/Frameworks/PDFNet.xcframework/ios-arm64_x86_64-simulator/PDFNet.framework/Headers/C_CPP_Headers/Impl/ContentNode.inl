inline ContentNode::ContentNode(TRN_ContentNode impl)
	: ContentElement(impl)
{
}

inline ContentNode::~ContentNode()
{
	Destroy();
}

inline void ContentNode::Destroy() {}

inline ContentNodeIterator ContentNode::GetContentNodeIterator() 
{
	TRN_Iterator result;
	REX(TRN_ContentNodeGetContentNodeIterator(m_impl, &result));
	return Common::Iterator<ContentElement>(result);
}



inline Function::Function (SDF::Obj funct_dict)
{
	REX(TRN_FunctionCreate(funct_dict.mp_obj,&mp_func));
}

inline Function::Function(const Function& f)
{
	REX(TRN_FunctionCreate(0,&mp_func));
	REX(TRN_FunctionAssign(mp_func,f.mp_func));
}

inline Function& Function::operator=(const Function& f)
{
	REX(TRN_FunctionAssign(mp_func,f.mp_func));
	return *this;
}

inline Function::~Function()
{
	DREX(mp_func, TRN_FunctionDestroy(mp_func));
}

inline void Function::Destroy ()
{
	REX(TRN_FunctionDestroy(mp_func));
	mp_func=0;
}

inline Function::Type Function::GetType() const
{
	enum TRN_FunctionType result;
	REX(TRN_FunctionGetType(mp_func,&result));
	return (Function::Type)result;
}

inline int Function::GetInputCardinality()
{
	RetInt(TRN_FunctionGetInputCardinality(mp_func,&result));
}

inline int Function::GetOutputCardinality()
{
	RetInt(TRN_FunctionGetOutputCardinality(mp_func,&result));
}

inline std::vector<double> Function::Eval(const std::vector<double>& in_arr)
{
	int size;
	TRN_FunctionGetOutputCardinality(mp_func,&size);

	if (size == 0)
	{
		return std::vector<double>();
	}

	BASE_ASSERT(in_arr.size() == (size_t)GetInputCardinality(),
		"Input array size does not match function input cardinality.");

	std::vector<double> result((std::vector<double>::size_type)size);
	REX(TRN_FunctionEval(mp_func,
		in_arr.size() > 0 ? (double*)&(in_arr[0]) : (double*)(0),
		(double*)&(result[0])));
	return result;
}

#ifndef SWIG
inline void Function::Eval(double *in, double *out)
{
	REX(TRN_FunctionEval(mp_func,in,out));
}
#endif

inline SDF::Obj Function::GetSDFObj ()
{
	RetObj(TRN_FunctionGetSDFObj(mp_func,&result));
}

inline Function::Function(TRN_Function impl) : mp_func(impl) {}


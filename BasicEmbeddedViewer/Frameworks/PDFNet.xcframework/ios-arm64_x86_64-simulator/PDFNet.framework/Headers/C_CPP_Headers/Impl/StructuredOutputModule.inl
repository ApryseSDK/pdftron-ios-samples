inline bool StructuredOutputModule::IsModuleAvailable()
{
	TRN_Bool result = 0;
	REX(TRN_StructuredOutputModuleIsModuleAvailable(&result));
	return result != 0;
}


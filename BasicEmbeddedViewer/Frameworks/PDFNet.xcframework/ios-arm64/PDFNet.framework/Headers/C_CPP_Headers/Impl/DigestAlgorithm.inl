inline std::vector<UChar> DigestAlgorithm::CalculateDigest(DigestAlgorithm::Type in_digest_algorithm_type, const std::vector<UChar>& in_message_buf)
{
	TRN_Vector cvector;
	REX(TRN_DigestAlgorithmCalculateDigest((TRN_DigestAlgorithm_Type)in_digest_algorithm_type, in_message_buf.empty() ? 0 : &in_message_buf.front(), in_message_buf.size(), &cvector));
	void* arr;
	UInt32 size;
	REX(TRN_VectorGetData(cvector, &arr));
	REX(TRN_VectorGetSize(cvector, &size));
	std::vector<UChar> result(size);
	memcpy(&result[0], arr, size);
	TRN_VectorDestroy(cvector);
	return result;
}

inline std::vector<UChar> DigestAlgorithm::SignDigest(const std::vector<UChar>& digest_buf, const DigestAlgorithm::Type digest_algorithm_type, const UString pkcs12_keyfile_path, const UString pkcs12_password)
{
	TRN_Vector cresult;
	REX(TRN_DigestAlgorithmSignDigest(digest_buf.empty() ? NULL : digest_buf.data(), digest_buf.size(), (const TRN_DigestAlgorithm_Type)digest_algorithm_type, pkcs12_keyfile_path.mp_impl, pkcs12_password.mp_impl, &cresult));
	void* arr;
	UInt32 size;
	REX(TRN_VectorGetData(cresult, &arr));
	REX(TRN_VectorGetSize(cresult, &size));
	std::vector<UChar> result(size);
	memcpy(&result[0], arr, size);
	TRN_VectorDestroy(cresult);
	return result;
}

inline std::vector<UChar> DigestAlgorithm::SignDigest(const std::vector<UChar>& digest_buf, const DigestAlgorithm::Type digest_algorithm_type, const std::vector<UChar>& pkcs12_buf, const UString pkcs12_password)
{
	TRN_Vector cresult;
	REX(TRN_DigestAlgorithmSignDigestWithKeyfileBuffer(digest_buf.empty() ? NULL : digest_buf.data(), digest_buf.size(), (const TRN_DigestAlgorithm_Type)digest_algorithm_type, pkcs12_buf.empty() ? NULL : pkcs12_buf.data(), pkcs12_buf.size(), pkcs12_password.mp_impl, &cresult));
	void* arr;
	UInt32 size;
	REX(TRN_VectorGetData(cresult, &arr));
	REX(TRN_VectorGetSize(cresult, &size));
	std::vector<UChar> result(size);
	memcpy(&result[0], arr, size);
	TRN_VectorDestroy(cresult);
	return result;
}
#ifndef SWIG
inline std::vector<UChar> DigestAlgorithm::CalculateDigest(DigestAlgorithm::Type in_digest_algorithm_type, const UChar* in_message_buf, const size_t in_message_buf_size)
{
	TRN_Vector cvector;
	REX(TRN_DigestAlgorithmCalculateDigest((TRN_DigestAlgorithm_Type)in_digest_algorithm_type, in_message_buf, in_message_buf_size, &cvector));
	void* arr;
	UInt32 size;
	REX(TRN_VectorGetData(cvector, &arr));
	REX(TRN_VectorGetSize(cvector, &size));
	std::vector<UChar> result(size);
	memcpy(&result[0], arr, size);
	TRN_VectorDestroy(cvector);
	return result;
}

inline std::vector<UChar> DigestAlgorithm::SignDigest(const UChar* digest_buf, const size_t digest_buf_size, const DigestAlgorithm::Type digest_algorithm_type, const UString pkcs12_keyfile_path, const UString pkcs12_password)
{
	TRN_Vector cresult;
	REX(TRN_DigestAlgorithmSignDigest(digest_buf, digest_buf_size, (const TRN_DigestAlgorithm_Type)digest_algorithm_type, pkcs12_keyfile_path.mp_impl, pkcs12_password.mp_impl, &cresult));
	void* arr;
	UInt32 size;
	REX(TRN_VectorGetData(cresult, &arr));
	REX(TRN_VectorGetSize(cresult, &size));
	std::vector<UChar> result(size);
	memcpy(&result[0], arr, size);
	TRN_VectorDestroy(cresult);
	return result;
}

inline std::vector<UChar> DigestAlgorithm::SignDigest(const UChar* digest_buf, const size_t digest_buf_size, const DigestAlgorithm::Type digest_algorithm_type, const UChar* pkcs12_buf, const size_t pkcs12_buf_size, const UString pkcs12_password)
{
	TRN_Vector cresult;
	REX(TRN_DigestAlgorithmSignDigestWithKeyfileBuffer(digest_buf, digest_buf_size, (const TRN_DigestAlgorithm_Type)digest_algorithm_type, pkcs12_buf, pkcs12_buf_size, pkcs12_password.mp_impl, &cresult));
	void* arr;
	UInt32 size;
	REX(TRN_VectorGetData(cresult, &arr));
	REX(TRN_VectorGetSize(cresult, &size));
	std::vector<UChar> result(size);
	memcpy(&result[0], arr, size);
	TRN_VectorDestroy(cresult);
	return result;
}
#endif

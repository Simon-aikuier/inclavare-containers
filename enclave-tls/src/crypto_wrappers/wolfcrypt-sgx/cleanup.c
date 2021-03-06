/* Copyright (c) 2020-2021 Alibaba Cloud and Intel Corporation
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <enclave-tls/log.h>
#include <enclave-tls/crypto_wrapper.h>
#include "wolfcrypt_sgx.h"

crypto_wrapper_err_t wolfcrypt_sgx_cleanup(crypto_wrapper_ctx_t *ctx)
{
	ETLS_DEBUG("ctx %p\n", ctx);

	if (!ctx)
		return -CRYPTO_WRAPPER_ERR_INVALID;

	ETLS_DEBUG("calling init() with enclave id %lld ...\n", ctx->enclave_id);

	crypto_wrapper_err_t err;
	ecall_wolfcrypt_cleanup((sgx_enclave_id_t)ctx->enclave_id, &err, ctx);

	return err;
}

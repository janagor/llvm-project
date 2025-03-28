//===-- Implementation of strncasecmp_l -----------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#include "src/strings/strncasecmp_l.h"

#include "src/__support/common.h"
#include "src/__support/ctype_utils.h"
#include "src/__support/macros/config.h"
#include "src/string/memory_utils/inline_strcmp.h"

namespace LIBC_NAMESPACE_DECL {

LLVM_LIBC_FUNCTION(int, strncasecmp_l,
                   (const char *left, const char *right, size_t n, locale_t)) {
  auto case_cmp = [](char a, char b) {
    return LIBC_NAMESPACE::internal::tolower(a) -
           LIBC_NAMESPACE::internal::tolower(b);
  };
  return inline_strncmp(left, right, n, case_cmp);
}

} // namespace LIBC_NAMESPACE_DECL

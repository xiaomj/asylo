/*
 *
 * Copyright 2018 Asylo authors
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 */

#include "asylo/grpc/auth/sgx_local_credentials_options.h"

#include <utility>

#include "asylo/identity/sgx/code_identity_util.h"

namespace asylo {

EnclaveCredentialsOptions BidirectionalSgxLocalCredentialsOptions() {
  return SelfSgxLocalCredentialsOptions().Add(PeerSgxLocalCredentialsOptions());
}

EnclaveCredentialsOptions PeerSgxLocalCredentialsOptions() {
  EnclaveCredentialsOptions options;
  AssertionDescription assertion_description;
  sgx::SetSgxLocalAssertionDescription(&assertion_description);
  options.accepted_peer_assertions.emplace(std::move(assertion_description));
  return options;
}

EnclaveCredentialsOptions SelfSgxLocalCredentialsOptions() {
  EnclaveCredentialsOptions options;
  AssertionDescription assertion_description;
  sgx::SetSgxLocalAssertionDescription(&assertion_description);
  options.self_assertions.emplace(std::move(assertion_description));
  return options;
}
}  // namespace asylo

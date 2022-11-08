/* Copyright 2019 The MLPerf Authors. All Rights Reserved.
Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at
    http://www.apache.org/licenses/LICENSE-2.0
Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
==============================================================================*/

/// \file
/// \brief Defines the QueryDispatchLibrary interface.

#ifndef MLPERF_LOADGEN_QUERY_DISPATCH_LIBRARY_H
#define MLPERF_LOADGEN_QUERY_DISPATCH_LIBRARY_H

#include <string>
#include <vector>

#include "query_sample.h"
#include "system_under_test.h"

namespace mlperf {

/// \addtogroup LoadgenAPI
/// @{

/// \brief The interface a client implements for the loadgen over the network to test. The API follows the System_under_test.h API
/// \todo Add hook for an untimed warm up period for the QDL.
/// \todo Add hook for an untimed warm up period for the loadgen logic.
/// \todo Support power hooks for cool-down period before runing performance
/// traffic.
/// \todo Support power hooks for correlating test timeline with power
/// measurment timeline.
class QueryDispatchLibrary : public SystemUnderTest {
 public:
  virtual ~QueryDispatchLibrary() {}

  /// \brief A human-readable string for logging purposes. The RemoteName return value must contain the substring "Network SUT". 
  ///        RemoteName should return from SUT over the network.
  virtual const std::string& RenoteName() = 0;

};

/// @}

}  // namespace mlperf

#endif  // MLPERF_LOADGEN_QUERY_DISPATCH_LIBRARY_H

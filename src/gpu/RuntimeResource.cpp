/////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Tencent is pleased to support the open source community by making tgfx available.
//
//  Copyright (C) 2024 THL A29 Limited, a Tencent company. All rights reserved.
//
//  Licensed under the BSD 3-Clause License (the "License"); you may not use this file except
//  in compliance with the License. You may obtain a copy of the License at
//
//      https://opensource.org/licenses/BSD-3-Clause
//
//  unless required by applicable law or agreed to in writing, software distributed under the
//  license is distributed on an "as is" basis, without warranties or conditions of any kind,
//  either express or implied. see the license for the specific language governing permissions
//  and limitations under the license.
//
/////////////////////////////////////////////////////////////////////////////////////////////////

#include "RuntimeResource.h"

namespace tgfx {

std::shared_ptr<RuntimeResource> RuntimeResource::Wrap(const UniqueKey& uniqueKey,
                                                       std::unique_ptr<RuntimeProgram> program) {
  if (program == nullptr) {
    return nullptr;
  }
  auto context = program->getContext();
  auto resource = Resource::AddToCache(context, new RuntimeResource(std::move(program)));
  resource->assignUniqueKey(uniqueKey);
  return std::static_pointer_cast<RuntimeResource>(resource);
}

void RuntimeResource::onReleaseGPU() {
  program->onReleaseGPU();
  program->context = nullptr;
}
}  // namespace tgfx
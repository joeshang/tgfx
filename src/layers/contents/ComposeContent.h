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

#pragma once

#include "tgfx/layers/LayerContent.h"

namespace tgfx {
class ComposeContent : public LayerContent {
 public:
  explicit ComposeContent(std::vector<std::unique_ptr<LayerContent>> contents)
      : contents(std::move(contents)) {
  }

  Rect getBounds() const override;

  Rect getTightBounds(const Matrix& matrix) const override;

  void draw(Canvas* canvas, const Paint& paint) const override;

  bool hitTestPoint(float localX, float localY, bool pixelHitTest) override;

  std::vector<std::unique_ptr<LayerContent>> contents = {};

 protected:
  Type type() const override {
    return Type::ComposeContent;
  }
};
}  // namespace tgfx

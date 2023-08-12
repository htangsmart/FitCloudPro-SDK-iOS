//
// Created by sanhuazhang on 2018/07/23
//

/*
 * Tencent is pleased to support the open source community by making
 * WCDB available.
 *
 * Copyright (C) 2017 THL A29 Limited, a Tencent company.
 * All rights reserved.
 *
 * Licensed under the BSD 3-Clause License (the "License"); you may not use
 * this file except in compliance with the License. You may obtain a copy of
 * the License at
 *
 *       https://opensource.org/licenses/BSD-3-Clause
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#pragma once

#include "HighWater.hpp"
#include "Recyclable.hpp"
#include "SharedThreadedErrorProne.hpp"
#include "UnsafeData.hpp"

namespace WCDB {

class MappedData final : public UnsafeData {
public:
    MappedData();
    MappedData(unsigned char* mapped, size_t size);
    MappedData(unsigned char* mapped, size_t size, SharedHighWater highWater);
    MappedData(const MappedData& other);
    MappedData(MappedData&& other);
    MappedData& operator=(const MappedData& other);
    MappedData& operator=(MappedData&& other);
    ~MappedData() override final;

    MappedData subdata(size_t size) const;
    MappedData subdata(offset_t offset, size_t size) const;

    static const MappedData& null();

protected:
    MappedData(const UnsafeData& data);
    using SharedData = UnsafeData::SharedData;
    using SharedBuffer = UnsafeData::SharedBuffer;
    static void unmapData(SharedData& data);
};

} // namespace WCDB

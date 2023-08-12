//
// Created by sanhuazhang on 2018/05/19
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

#include "Assemble.hpp"
#include "Crawlable.hpp"
#include "Material.hpp"
#include "Repairman.hpp"

namespace WCDB {

namespace Repair {

class Material;

class Mechanic final : public Repairman {
#pragma mark - Initialize
public:
    Mechanic(const UnsafeStringView &path);
    ~Mechanic() override final;

#pragma mark - Mechanic
public:
    bool work();

#pragma mark - Material
public:
    void setMaterial(const Material *material);

protected:
    const Material *m_material;
    uint32_t m_checksum;

#pragma mark - Crawlable
protected:
    void onCellCrawled(const Cell &cell) override final;
    bool willCrawlPage(const Page &page, int) override final;
};

} //namespace Repair

} //namespace WCDB

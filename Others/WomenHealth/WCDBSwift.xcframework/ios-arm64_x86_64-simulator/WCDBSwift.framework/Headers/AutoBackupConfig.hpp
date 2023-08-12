//
// Created by sanhuazhang on 2019/05/26
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

#include "Config.hpp"
#include "StringView.hpp"

namespace WCDB {

class AutoBackupOperator {
public:
    virtual ~AutoBackupOperator() = 0;

    virtual void asyncBackup(const UnsafeStringView& path) = 0;
};

class AutoBackupConfig final : public Config {
public:
    AutoBackupConfig(const std::shared_ptr<AutoBackupOperator>& operator_);
    ~AutoBackupConfig() override final;

    bool invoke(InnerHandle* handle) override final;
    bool uninvoke(InnerHandle* handle) override final;

protected:
    const StringView m_identifier;
    void onCheckpointed(const UnsafeStringView& path);

    std::shared_ptr<AutoBackupOperator> m_operator;
};

} //namespace WCDB

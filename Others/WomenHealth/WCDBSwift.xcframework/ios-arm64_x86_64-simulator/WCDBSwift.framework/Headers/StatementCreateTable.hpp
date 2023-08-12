//
// Created by sanhuazhang on 2019/05/02
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

#include "Statement.hpp"

namespace WCDB {

class StatementCreateTable final
: public SpecifiedSyntax<Syntax::CreateTableSTMT, Statement> {
public:
    using SpecifiedSyntax<Syntax::CreateTableSTMT, Statement>::SpecifiedSyntax;
    StatementCreateTable();
    ~StatementCreateTable() override final;

    StatementCreateTable& createTable(const UnsafeStringView& table);
    StatementCreateTable& schema(const Schema& schema);
    StatementCreateTable& temp();

    StatementCreateTable& ifNotExists();

    StatementCreateTable& as(const StatementSelect& select);

    StatementCreateTable& define(const ColumnDef& columnDef);
    StatementCreateTable& constraint(const TableConstraint& constraint);
    StatementCreateTable& withoutRowID();
};

} // namespace WCDB

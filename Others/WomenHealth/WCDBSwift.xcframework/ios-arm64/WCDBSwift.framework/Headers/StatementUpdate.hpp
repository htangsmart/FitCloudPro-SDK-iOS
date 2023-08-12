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

class StatementUpdate final : public SpecifiedSyntax<Syntax::UpdateSTMT, Statement> {
public:
    using SpecifiedSyntax<Syntax::UpdateSTMT, Statement>::SpecifiedSyntax;
    StatementUpdate();
    ~StatementUpdate() override final;

    StatementUpdate& with(const CommonTableExpressions& commonTableExpressions);
    StatementUpdate& recursive();

    StatementUpdate& update(const QualifiedTable& table);
    StatementUpdate& orRollback();
    StatementUpdate& orAbort();
    StatementUpdate& orReplace();
    StatementUpdate& orFail();
    StatementUpdate& orIgnore();

    StatementUpdate& set(const Columns& columns);
    StatementUpdate& to(const Expression& value);

    StatementUpdate& where(const Expression& condition);

    StatementUpdate& order(const OrderingTerm& order);
    StatementUpdate& orders(const OrderingTerms& orders);

    StatementUpdate& limit(const Expression& from, const Expression& to);

    StatementUpdate& limit(const Expression& limit);
    StatementUpdate& offset(const Expression& offset);
};

} // namespace WCDB

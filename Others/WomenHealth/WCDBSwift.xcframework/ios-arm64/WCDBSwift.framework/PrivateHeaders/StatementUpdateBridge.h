//
// Created by qiuwenchen on 2022/7/15.
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

#include "WinqBridge.h"

WCDB_EXTERN_C_BEGIN

CPPStatementUpdate WCDBStatementUpdateCreate(void);

void WCDBStatementUpdateConfigWith(CPPStatementUpdate update,
                                   const CPPCommonTableExpression* _Nullable exps,
                                   int expNum);
void WCDBStatementUpdateConfigRecursive(CPPStatementUpdate update);

void WCDBStatementUpdateConfigTable(CPPStatementUpdate update, CPPQualifiedTable table);

void WCDBStatementUpdateConfigConfiction(CPPStatementUpdate update,
                                         enum WCDBSyntaxConflictAction action);

void WCDBStatementUpdateConfigColumns(CPPStatementUpdate update,
                                      const CPPColumn* _Nullable columns,
                                      int colNum);
void WCDBStatementUpdateConfigValue(CPPStatementUpdate update, CPPExpression expression);
void WCDBStatementUpdateConfigCondition(CPPStatementUpdate update, CPPExpression expression);

void WCDBStatementUpdateConfigOrders(CPPStatementUpdate update,
                                     const CPPOrderingTerm* _Nullable orders,
                                     int orderNum);
void WCDBStatementUpdateConfigLimitFromTo(CPPStatementUpdate update,
                                          CPPExpression from,
                                          CPPExpression to);
void WCDBStatementUpdateConfigLimitFrom(CPPStatementUpdate update, CPPExpression limit);
void WCDBStatementUpdateConfigLimitOffset(CPPStatementUpdate update, CPPExpression offset);

WCDB_EXTERN_C_END
